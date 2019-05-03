#pragma once
#include"tianchai_12039.h"


void run_tianchai_12039() {
	get_input_data();
	dfs_12039(1,1);
	printf("%d\n", total_prime_12039);
}

void get_input_data() {
	scanf("%d %d", &n_12039, &k_12039);
	for (int i = 1; i <= n_12039; i++) {
		scanf("%d", &array_12039[i]);
	}
}
bool is_prime(int num) {
	for (int i = 2; i < sqrt(num); i++) {
		if (num%i==0) {
			return false;
		}
	}
	return true;
}

void dfs_12039(int loop,int x) {
	if (x == k_12039+1) {
		if (is_prime(sum_12039)) {
			total_prime_12039++;
		}
		return;
	}
	for (int i = loop; i <= n_12039; i++) {
		if (book_12039[i] == 0) {
			book_12039[i] = 1;
			sum_12039 += array_12039[i];
			dfs_12039(i+1,x + 1);
			sum_12039 -= array_12039[i];
			book_12039[i] = 0;
		}
	}
}