#include"book_chapter_7_lenson_4.h"

int f_book_chapter_7_lenson_4[1000] = 0, 
	n_book_chapter_7_lenson_4,
	m_book_chapter_7_lenson_4, 
	k_book_chapter_7_lenson_4, 
	sum_book_chapter_7_lenson_4;


//主程序
int run_book_chapter_7_lenson_4() {
	int x, y;
	scanf("%d%d", &n_book_chapter_7_lenson_4, &m_book_chapter_7_lenson_4);
	//初始化
	init_book_chapter_7_lenson_4();

	for (int i = 1; i <= n_book_chapter_7_lenson_4; i++) {
		scanf("%d %d", &x, &y);
		merge_book_chapter_7_lenson_4(x, y);
	}

	//最后扫描有多少个独立的犯罪团伙
	for (int i = 1; i <= n_book_chapter_7_lenson_4; i++) {
		if (f_book_chapter_7_lenson_4[i] = i) {
			sum_book_chapter_7_lenson_4++;
		}
	}

	system("pause");
	return 0;
}



//这里是初始化，数组里面存的是自己数组下标的编号
void init_book_chapter_7_lenson_4() {
	for (int i = 1; i <= n_book_chapter_7_lenson_4; i++) {
		f_book_chapter_7_lenson_4[i] = i;
	}
}

int getf_book_chapter_7_lenson_4(int v) {
	if (f_book_chapter_7_lenson_4[v] == v) {
		return v;
	}
	else {
		//这里是路径压缩，每次在函数返回的时候，顺带将路上遇到的人的boss
		//更改为最后找到的boss编号，也就是boss的最高领导人编号
		f_book_chapter_7_lenson_4[v] = getf_book_chapter_7_lenson_4(f_book_chapter_7_lenson_4[v]);
		return f_book_chapter_7_lenson_4[v];
	}
}
//1 2 3 4 5 6 7 8 9 10
//5 5 5 3 5 5 8 8 9 10
//（7,9）


//这里是合并两个子集的函数
void merge_book_chapter_7_lenson_4(int v, int u) {
	int boss_1 = getf_book_chapter_7_lenson_4(u);
	int boss_2 = getf_book_chapter_7_lenson_4(v);//boss_1,boss_2分别是两个集合的boss

	if (boss_1 != boss_2) {//判断两个节点是否在统一集合中，即是否为同一个祖先
		f_book_chapter_7_lenson_4[boss_2] = boss_1;//靠左原则， 左边的变成右边的boss
	}
}