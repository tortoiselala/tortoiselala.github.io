#include"book_chapter_4_leson_1_dfs.h"

int a[10], book[10], n;

void dfs(int step) {
	if (step == n + 1) {
		for (int i = 1; i <= n; i++) {
			printf("%d", a[i]);
		}
		putchar('\n');
		return;
	}
	for (int i = 1; i <= n; i++) {
		if (book[i] == 0) {
			a[step] = i;
			book[i] = 1;

			dfs(step + 1);
			book[i] = 0;
		}
	}
	return;
}

int run_book_chapter_4_leson_1_dfs() {
	scanf("%d", &n);
	dfs(1);
	system("pause"); 
	return 0;
}
