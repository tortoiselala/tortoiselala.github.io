#pragma once
#include"book_chapter_3_lenson_4_fully_arranged.h"

#define number 123

int number_list[30];
int book[30];
void run_book_chapter_3_lenson_4_fully_arranged() {
	int length = split_number(number);
	printf("result = %d", n_factorial(length));
}

int  split_number(int i) {
	int loop = 0;
	while (i > 0) {
		number_list[loop] = i % 10;
		i /= 10;
		loop++;
	}
	return loop;
}
/*
¼ÆËãnµÄ½×³Ë
*/
int n_factorial(int n) {
	int result = 1;
	for (int i = 1; i <= n; i++) {
		result *= i;
	}
	return result;
}
