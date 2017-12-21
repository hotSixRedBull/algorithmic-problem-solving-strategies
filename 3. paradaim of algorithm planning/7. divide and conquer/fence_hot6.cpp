#include <iostream>
using namespace std;
/*var*/
#define MAXLEN 20000
class bunch {
public:
	int height;
	int numberOfWood;
	int size() {
		return height*numberOfWood;
	}
};
bunch fence[MAXLEN], merged[MAXLEN];
int siz;
/*func*/
bool can_be_merged(int a, int b) {
	if ((a<0) || (b<0) || (b<a) || (b>siz) || (a>siz))
		return false;
	if ((merged[a].height <= merged[b].height)
		&& ((merged[a].numberOfWood + merged[b].numberOfWood)*merged[a].height > merged[b].size()))
		return true;
	 if ((merged[b].height <= merged[a].height)
		&& ((merged[a].numberOfWood + merged[b].numberOfWood)*merged[b].height > merged[a].size()))
		return true;
	return false;
}
void merge(int a, int b) {
	if ((a<0) || (b<0) || (b<a) || (b>siz) || (a>siz))
		return;
	if ((merged[a].height <= merged[b].height)
		&& ((merged[a].numberOfWood + merged[b].numberOfWood)*merged[a].height > merged[b].size())) {
		merged[a].numberOfWood += merged[b].numberOfWood;
		merged[b] = merged[a];
	}
	else if ((merged[b].height <= merged[a].height)
		&& ((merged[a].numberOfWood + merged[b].numberOfWood)*merged[b].height > merged[a].size())) {
		merged[b].numberOfWood += merged[a].numberOfWood;
		merged[a] = merged[b];
	}
}
void split(int start, int end) {
	if (start == end) {
		merged[start] = fence[start];
	}
	else {
		if ((end - start) % 2 == 0) {//odd
			int center = (end - start) / 2 + start;
			merged[center] = fence[center];
			split(start, center - 1);
			split(center + 1, end);
			bool left = can_be_merged(center - 1, center), right = can_be_merged(center, center + 1);
			if (left&&right) {
				merge(center - 1, center);
				merge(center, center + 1);
			}
			else if (left) {
				merge(center - 1, center);
			}
			else if (right) {
				merge(center, center + 1
