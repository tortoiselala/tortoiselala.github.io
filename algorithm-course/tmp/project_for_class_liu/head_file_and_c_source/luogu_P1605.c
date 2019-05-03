#include"luogu_P1605.h"

#define num_point 25
#define map_size 6
int N, M, T;
int SX, SY, FX, FY;
int point[num_point][2];
int map_P1605[map_size][map_size];
int count_luogu_P1605;


void run_luogu_P1605() {
	
	scanf("%d %d %d", &N, &M, &T);
	scanf("%d %d %d %d", &SX, &SY, &FX, &FY);
	for (int i = 0; i < T; i++) {
		scanf("%d %d", &point[i][0], &point[i][1]);
	}

	map_P1605[SX][SY] = 1;

	dfs_P1605(SX, SY);
	printf("result = %d", count_luogu_P1605);
}

void dfs_P1605(int x, int y) {
	if (x == FX && y == FY) {
		count_luogu_P1605++;
		return;
	}
	if (x - 1 >= 1  && is_point_can_reach(x - 1, y) && map_P1605[x - 1][y ] == 0) {
		map_P1605[x - 1][y] = 1;
		dfs_P1605(x - 1, y );
		map_P1605[x - 1][y] = 0;
	}
	if (  y + 1 <= M && is_point_can_reach(x, y+ 1) && map_P1605[x][y + 1] == 0) {
		map_P1605[x ][y + 1] = 1;
		dfs_P1605(x , y +1);
		map_P1605[x][y + 1] = 0;
	}
	if (x + 1 <=N  && is_point_can_reach(x +1, y ) && map_P1605[x + 1][y] == 0) {
		map_P1605[x +1][y] = 1;
		dfs_P1605(x + 1, y);
		map_P1605[x + 1][y] = 0;
	}
	if ( y - 1 >= 1 && is_point_can_reach(x , y - 1) && map_P1605[x ][y - 1] == 0) {
		map_P1605[x ][y - 1] = 1;
		dfs_P1605(x , y - 1);
		map_P1605[x][y - 1] = 0;
	}
}

bool is_point_can_reach(int x, int y) {
	for (int i = 0; i < T; i++) {
		if (x == point[i][0] && y == point[i][1]) {
			return false;
		}
	}
	return true;
}