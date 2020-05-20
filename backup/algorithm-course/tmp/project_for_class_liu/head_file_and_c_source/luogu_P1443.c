#include"luogu_P1443.h"

#define map_x 3
#define map_y 3
#define point_x 1
#define point_y 1

int map[map_x + 1][map_y + 1];

void run_luogu_P1443() {
	init_map(-1, map_x + 1, map_y + 1);
	map[point_x][point_y] = 0;
	dfs_P1443(1, 1, 0);
	print_result_dfs();
}

void init_map(int num, int x, int y) {
	for (int i = 1; i <= x; i++) {
		for (int j = 1; j <= y; j++) {
			map[i][j] = num;
		}
	}
}

void dfs_P1443(int i, int j, int step) {
	if (i - 2 >= 1 && j - 1 >= 1 && map[i - 2][j - 1] == -1) {
		map[i - 2][j - 1] = step + 1;
		dfs_P1443(i - 2, j - 1, step + 1);
	}
	if (i - 2 >= 1 && j + 1 <= map_y && map[i - 2][j + 1] == -1) {
		map[i - 2][j + 1] = step + 1;
		dfs_P1443(i - 2, j + 1, step + 1);
	}
	if (i - 1 >= 1 && j + 2 <= map_y && map[i - 1][j + 2] == -1) {
		map[i - 1][j + 2] = step + 1;
		dfs_P1443(i - 1, j + 2, step + 1);
	}
	if (i + 1 <= map_x && j + 2 <= map_y && map[i + 1][j + 2] == -1) {
		map[i + 1][j + 2] = step + 1;
		dfs_P1443(i + 1, j + 2, step + 1);
	}
	if (i +2 <= map_x && j + 1 <= map_y && map[i+2][j+1] == -1) {
		map[i +2][j +1] = step + 1;
		dfs_P1443(i +2, j +1, step + 1);
	}
	if (i +2<=map_x && j - 1 >= 1 && map[i+2][j-1] == -1) {
		map[i +2][j - 1] = step + 1;
		dfs_P1443(i +2, j - 1, step + 1);
	}
	if (i +1<=map_x && j - 2 >= 1 && map[i+1][j-2] == -1) {
		map[i +1][j - 2] = step + 1;
		dfs_P1443(i +1, j - 2, step + 1);
	}
	if (i -1 >= 1 && j - 2 >= 1 && map[i-1][j-2] == -1) {
		map[i - 1][j - 2] = step + 1;
		dfs_P1443(i - 1, j - 2, step + 1);
	}

}

void print_result_dfs() {
	for (int i = 1; i < map_x + 1; i++) {
		for (int j = 1; j < map_y + 1; j++) {
			printf("%-5d", map[i][j]);
		}
		putchar('\n');
	}
}