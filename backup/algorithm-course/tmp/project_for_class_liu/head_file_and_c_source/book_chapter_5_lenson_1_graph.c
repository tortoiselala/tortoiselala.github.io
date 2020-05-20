#include"book_chapter_5_lenson_1_graph.h"

int book_chapter_5_lenson_1_graph[101], sum_chapter_5_lenson_1_graph, n_chapter_5_lenson_1_graph, e_chapter_5_lenson_1_graph[101][101];

void run_chapter_5_lenson_1_graph() {
	int m;
	scanf("%d %d", &n_chapter_5_lenson_1_graph, &m);
	//初始化二维矩阵
	for (int i = 1; i <= n_chapter_5_lenson_1_graph; i++) {
		for (int j = 1; j <= n_chapter_5_lenson_1_graph; j++) {
			if (i == j) {
				e_chapter_5_lenson_1_graph[i][j] = 0;
			}
			else {
				e_chapter_5_lenson_1_graph[i][j] = 9999999;//假设为无穷大
			}
		}
	}

	//读入顶点的边
	int a, b;
	for (int i = 1; i <= m; i++) {
		scanf("%d %d", &a, &b);
		e_chapter_5_lenson_1_graph[a][b] = 1;
		e_chapter_5_lenson_1_graph[b][a] = 1;//无向图
	}

	//从1号顶点出发
	book_chapter_5_lenson_1_graph[1] = 1;
	dfs_chapter_5_lenson_1_graph(1);
	system("pause");
	return;
}

void dfs_chapter_5_lenson_1_graph(int cur) {//cur为当前顶点的编号
	printf("%d ", cur);
	sum_chapter_5_lenson_1_graph++;//每访问过一个顶点,sum+1
	if (sum_chapter_5_lenson_1_graph == n_chapter_5_lenson_1_graph) {
		return;//所有顶点都已经访问过则直接退出
	}
	for (int i = 1; i <= n_chapter_5_lenson_1_graph; i++) {//从一号顶点开始尝试，看那些顶点与当前顶点想连
		//判断当前顶点cur到顶点i是否有边，并判断顶点i是否已经访问过
		if (e_chapter_5_lenson_1_graph[cur][i] == 1 && book_chapter_5_lenson_1_graph[i] == 0) {
			book_chapter_5_lenson_1_graph[i] = 1;//标记访问
			dfs_chapter_5_lenson_1_graph(i);//继续访问
		}
	}
	return;
}