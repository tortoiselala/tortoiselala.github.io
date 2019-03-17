#include"book_chapter_3_lenson_1_fill_number.h"


void run_book_chapter_3_fill_9_blacks_with_9_number() {
	int count = 0;
	for (int loop_1 = 0; loop_1 < size; loop_1++) {
		book_fill[loop_1] ++;
		for (int loop_2 = 0; loop_2 < size; loop_2++) {
			if (book_fill[loop_2] == 0) {
				book_fill[loop_2]++;
				for (int loop_3 = 0; loop_3 < size; loop_3++) {
					if (book_fill[loop_3] == 0) {
						book_fill[loop_3]++;
						for (int loop_4 = 0; loop_4 < size; loop_4++) {
							if (book_fill[loop_4] == 0) {
								book_fill[loop_4]++;
								for (int loop_5 = 0; loop_5 < size; loop_5++) {
									if (book_fill[loop_5] == 0) {
										book_fill[loop_5]++;
										for (int loop_6 = 0; loop_6 < size; loop_6++) {
											if (book_fill[loop_6] == 0) {
												book_fill[loop_6]++;
												for (int loop_7 = 0; loop_7 < size; loop_7++) {
													if (book_fill[loop_7] == 0) {
														book_fill[loop_7]++;
														for (int loop_8 = 0; loop_8 < size; loop_8++) {
															if (book_fill[loop_8] == 0) {
																book_fill[loop_8]++;
																for (int loop_9 = 0; loop_9 < size; loop_9++) {
																	if (book_fill[loop_9] == 0) {
																		book_fill[loop_9]++;
																		if ((loop_1 + 1) * 100 + (loop_2 + 1) * 10 + (loop_3 + 1) + (loop_4 + 1) * 100 + (loop_5 + 1) * 10 + (loop_6 + 1) == (loop_7 + 1) * 100 + (loop_8 + 1) * 10 + (loop_9 + 1)) {
																			printf("%d%d%d + %d%d%d = %d%d%d\n", loop_1 + 1, loop_2 + 1, loop_3 + 1, loop_4 + 1, loop_5 + 1, loop_6 + 1, loop_7 + 1, loop_8 + 1, loop_9 + 1);
																			count++;
																		}
																		book_fill[loop_9] = 0;
																	}
																}
																book_fill[loop_8] = 0;
															}
														}
														book_fill[loop_7] = 0;
													}
												}
												book_fill[loop_6] = 0;
											}
										}
										book_fill[loop_5] = 0;
									}
								}
								book_fill[loop_4] = 0;
							}
						}
						book_fill[loop_3] = 0;
					}
				}
				book_fill[loop_2] = 0;
			}
		}
		book_fill[loop_1] = 0;
	}
	printf("total: %d\n", count);
}
