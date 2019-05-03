#include"book_chapter_4_lenson_5_island_task.h"

/*

染色法
通过对已经访问完毕的节点做出标记，添加color参数


当需要统计总共有多少个小岛时，只需要尝试对所有小岛进行染色，而不必担心重复的工作

这种算法通常被应用于求图的独立子图的个数(先记住)，该算法名称为:Fooldfill漫水填充法
*/
struct note {
	int x;
	int y;
};

void run_book_chapter_4_lenson_5_island_task() {
	struct note que[2501];
	int head, tail;
	int a[51][51];
	int book[51][51] = { 0 };
	int sum, maax = 0, mx, my, n, m, startx, starty, tx, ty;


	int next[4][2] = {
		{0, 1},
		{1, 0},
		{0,-1},
		{-1,0}
	};

	scanf("%d %d %d", &n, &m, &startx, &starty);

	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++) {
			scanf("%d", &a[i][j]);
		}
	}
	//队列初始化
	head = 1;
	tail = 1;
	//往队列插入降落的起始坐标
	que[tail].x = startx;
	que[tail].y = starty;

	tail++;

	book[startx][starty] = 1;
	sum = 1;

	//当队列不为空时循环

	while (head < tail) {
		//枚举四个方向
		for (int k = 0; k <= 3; k++) {
			//计算下一步的坐标
			tx = que[head].x + next[k][0];
			ty = que[head].y + next[k][1];

			//判断是否越界
			if (tx<1 || tx>n || ty<1 || ty>m) {
				continue;
			}

			//判断是否是陆地或者是否曾经走过
			if (a[tx][ty] > 0 && book[tx][ty] == 0) {
				sum++;
				//每个点入队一次，所以要标记这个点已经走过
				book[tx][ty] = 1;
				//将新扩展的点加入队列
				que[tail].x = tx;
				que[tail].y = ty;
				tail++;
			}
		}
		head++;//当一个点扩展完毕，再向下扩展   想一想广度优先搜索
	}

	printf("%d\n", sum);
	getchar();
	getchar();
}