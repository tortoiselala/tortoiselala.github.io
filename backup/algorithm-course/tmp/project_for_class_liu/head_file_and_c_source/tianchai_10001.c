#include"tianchai_10001.h"


int run_tianchai_10001() {
	int apple[10];
	int max_high;
	int count = 0;
	for (int i = 0; i < 10; i++) {
		scanf("%d", &apple[i]);
	}
	scanf("%d", &max_high);
	max_high += 30;
	for (int i = 0; i < 10; i++) {
		if (apple[i] <= max_high) {
			count++;
		}
	}
	return count;
}
