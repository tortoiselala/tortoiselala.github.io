#include"book_chapter_4_lenson_6_plumber_game.h"

int a_plumber_game[51][51];
int book_plumber_game[51][51], n_plumber_game, m_plumber_game, flag = 0;
struct note_plumber_game {
	int x;//横坐标
	int y;//纵坐标
}s[100];
int top = 0;
void run_book_chapter_4_lenson_6_plumber_game() {
	scanf("%d %d", &n_plumber_game, &m_plumber_game);
	for (int i = 1; i <= n_plumber_game; i++) {
		for (int j = 1; j <= m_plumber_game; j++) {
			scanf("%d", &a_plumber_game[i][j]);
		}
	}

	//开始搜索(1,1)
	dfs_book_chapter_4_lenson_6_plumber_game(1, 1, 1);
	//判断是否找到铺设方案
	if (flag == 0) {
		printf("impossible\n");
	}
	putchar('\n');
	system("pause");
}

void dfs_book_chapter_4_lenson_6_plumber_game(int x, int y , int front) {

	//判断是否到达终点
	if (x == n_plumber_game && y == m_plumber_game + 1) {
		flag = 1;//找到铺设方案

		for (int i = 1; i <= top; i++) {
			printf(" (%d, %d) ", s[i].x, s[i].y);
		}
		return;
	}

	//判断是否越界
	if (x<1 || x>n_plumber_game || y<1 || y>m_plumber_game) {
		return;
	}
	//使用当前管道，并标记
	book_plumber_game[x][y] = 1;

	//将当前尝试的坐标入栈
	top++;
	s[top].x = x;
	s[top].y = y;

	//当前管道是直管的情况
	if (a_plumber_game[x][y] >= 5 && a_plumber_game[x][y] <= 6) {
		//进水口在左边的情况
		if (front == 1) {
			dfs_book_chapter_4_lenson_6_plumber_game(x, y + 1, 1);//只能使用5号摆放方式
		}
		if (front == 2) {
			dfs_book_chapter_4_lenson_6_plumber_game(x + 1, y, 2);//只能使用6号摆放方式
		}
		if (front == 3) {
			dfs_book_chapter_4_lenson_6_plumber_game(x, y - 1, 3);;//只能使用5号摆放方式
		}
		if (front == 4) {
			dfs_book_chapter_4_lenson_6_plumber_game(x - 1, y, 4);//只能使用6号摆放方式
		}

		//当前水管是弯道的情况
		if (a_plumber_game[x][y] >= 1 && a_plumber_game[x][y] <= 4) {
			if (front == 1) {//进水口在左边
				dfs_book_chapter_4_lenson_6_plumber_game(x + 1, y, 2);//3号状态
				dfs_book_chapter_4_lenson_6_plumber_game(x - 1, y, 4);//4号状态	
			}
			if (front == 2) {//进水口在上边
				dfs_book_chapter_4_lenson_6_plumber_game(x, y + 1, 1);//1号状态
				dfs_book_chapter_4_lenson_6_plumber_game(x, y - 1, 3);//4号状态	
			}
			if (front == 3) {//进水口在右边
				dfs_book_chapter_4_lenson_6_plumber_game(x - 1, y, 4);//1号状态
				dfs_book_chapter_4_lenson_6_plumber_game(x + 1, y, 2);//2号状态	
			}
			if (front == 4) {//进水口在下边
				dfs_book_chapter_4_lenson_6_plumber_game(x, y + 1 , 1);//2号状态
				dfs_book_chapter_4_lenson_6_plumber_game(x, y - 1 , 3);//3号状态	
			}
		}
		book_plumber_game[x][y] = 0;//取消标记
		top--;
		return;
	}
}