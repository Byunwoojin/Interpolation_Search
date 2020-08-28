#include <stdio.h>
int interpolate_search(int list[], int size, int key);
void main() {
	int size = 12;
	int key = 39;
	int pos;
	int list[] = {2,3,5,7,8,10,13,20,25,39,45,55 };
	pos = interpolate_search(list, size, key);
	printf("%d is in %d\n", key, pos);
	key = 2;
	pos = interpolate_search(list, size, key);
	printf("%d is in %d\n", key, pos);
	key = 55;
	pos = interpolate_search(list, size, key);
	printf("%d is in %d\n", key, pos);
}
int interpolate_search(int list[], int size, int key) {
	int pos;
	int left = 0;
	int right = size - 1;
	while (left <= right) {
		pos = left + (key - list[left]) * (right - left) / (list[right] - list[left]);
		if (list[pos] < key)
			left = pos + 1;
		else if (key < list[pos])
			right = pos - 1;
		else
			return pos;
	}
	return -1;
}
