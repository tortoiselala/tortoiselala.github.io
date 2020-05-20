#include"book_chapter_3_lenson_3_matches_equation.h"

#define n 18
#define size 10
#define max_number 1111
int matches_number[size] = { 6,2,5,5,4,5,6,3,7,6 };
int matches_add = 2;
int matches_equal = 2;

void run_book_chapter_3_lenson_3_matches_equation() {
	for (int i = 0; i <= max_number; i++) {
		for (int j = 0; j <= max_number; j++) {
			int result = i + j;
			if (n == count_matches(result) + count_matches(i)+ count_matches(j) + matches_add + matches_equal) {
				printf("%d + %d = %d\n", i, j, result);
			}
		}
	}
}
int count_matches(int i) {
	int count = 0;
	if (i == 0) {
		count = matches_number[i];
	}
	else {
		while (i > 0) {
			count += matches_number[i % 10];
			i /= 10;
		}
	}
	return count;
}