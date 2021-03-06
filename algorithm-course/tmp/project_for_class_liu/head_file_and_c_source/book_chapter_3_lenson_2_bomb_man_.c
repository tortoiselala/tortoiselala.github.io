#include"book_chapter_3_lenson_2_bomb_man_.h"

#define bomb_n 13
#define bomb_m 13

char bomb_map[bomb_n][bomb_m] = {
	{'#','#','#','#','#','#','#','#','#','#','#','#','#' },
	{'#','G','G','.','G','G','G','#','G','G','G','.','#' },
	{'#','#','#','.','#','G','#','G','#','G','#','G','#' },
	{'#','.','.','.','.','.','.','.','#','.','.','G','#' },
	{'#','G','#','.','#','#','#','.','#','G','#','G','#',},
	{'#','G','G','.','G','G','G','.','#','.','G','G','#',},
	{'#','G','#','.','#','G','#','.','#','.','#','.','#',},
	{'#','#','G','.','.','.','G','.','.','.','.','.','#',},
	{'#','G','#','.','#','G','#','#','#','.','#','G','#',},
	{'#','.','.','.','G','#','G','G','G','.','G','G','#',},
	{'#','G','#','.','#','G','#','G','#','.','#','G','#',},
	{'#','G','G','.','G','G','G','#','G','.','G','G','#',},
	{'#','#','#','#','#','#','#','#','#','#','#','#','#',}
};

int map_result[bomb_n][bomb_m];

void run_book_chapter_3_lenson_2_bomb_man() {
	traverse_map();
	print_result_map();
}

void traverse_map() {
	for (int i = 0; i < bomb_n; i++) {
		for (int j = 0; j < bomb_m; j++) {
			if (bomb_map[i][j] == '.') {
				map_result[i][j] = count_x(i, j) + count_y(i, j);
			}
		}
	}
}

void print_result_map() {
	for (int i = 0; i < bomb_n; i++) {
		for (int j = 0; j < bomb_m; j++) {
			printf("%d\t", map_result[i][j]);
		}
		printf("\n");
	}
}
int count_x(int point_x, int point_y) {
	int count = 0;
	int temp_x = point_x;
	while (bomb_map[temp_x][point_y] != '#') {
		if (bomb_map[temp_x][point_y] == 'G') {
			count++;
		}
		temp_x++;
	}
	temp_x = point_x;
	while (bomb_map[temp_x][point_y] != '#') {
		if (bomb_map[temp_x][point_y] == 'G') {
			count++;
		}
		temp_x--;
	}
	return count;
}
int count_y(int point_x, int point_y) {
	int count = 0;
	int temp_y = point_y;
	while (bomb_map[point_x][temp_y] != '#') {
		if (bomb_map[point_x][temp_y] == 'G') {
			count++;
		}
		temp_y++;
	}
	temp_y = point_y;
	while (bomb_map[point_x][temp_y] != '#') {
		if (bomb_map[point_x][temp_y] == 'G') {
			count++;
		}
		temp_y--;
	}
	return count;
}

/*
??????????????????????????????????????????????????i,j????????????????????????????????1,11??????????????????????
????????????????????????????????????????????????????????????????????
??????????????????????????????????????????????
*/