#include"liu_tianchai_12039.h"


int n_liu_tianchai_12039, k_liu_tianchai_12039;
int sum_liu_tianchai_12039;
int x_liu_tianchai_12039[21];
int book_liu_tianchai_12039[21];
int s_liu_tianchai_12039[21];


void run_liu_tianchai_12039() {

	scanf("%d%d", &n_liu_tianchai_12039, &k_liu_tianchai_12039);

	for (int i = 1; i <= n_liu_tianchai_12039; i++)
	{
		scanf("%d", &x_liu_tianchai_12039[i]);
	}
	sum_liu_tianchai_12039 = 0; 

	dfs1_liu_tianchai_12039(k_liu_tianchai_12039, 1,1);

	printf("%d", sum_liu_tianchai_12039);

}


int isPrime_liu_tianchai_12039(int b)
{
	int count;
	count = 0;
	for (int i = 2; i <= b - 1; i++)
	{
		if (b%i == 0)
		{
			count++;
			return 0;
		}
	}
	if (count == 0)
	{
		return 1;
	}
}
void dfs1_liu_tianchai_12039(int x, int y,int loop)
{
	//第一个问题
	//寻找第一个加数 y = 1
	//寻找第二个加数 y = 2
	//寻找第三个加数 y = 3
	//x 一直为 3
	//3<3是否成立


	//第二个问题
	//3 + 7 + 19 = 29
	//7 + 3 + 19 = 29
	//这两个表达式是否代表的是同一种结果
	if (y <= x)
	{
		for (int i = loop; i <= n_liu_tianchai_12039; i++)
		{
			if (book_liu_tianchai_12039[i] == 0)
			{
				book_liu_tianchai_12039[i] = 1;
				dfs1_liu_tianchai_12039(x, y + 1,i+1);
				book_liu_tianchai_12039[i] = 0;
			}
		}
	}
	if (y > x)
	{
		int a = 0;
		for (int i = 1; i <= n_liu_tianchai_12039; i++) {
			if (book_liu_tianchai_12039[i] == 1) {
				a += x_liu_tianchai_12039[i];
			}
		}
		if (isPrime_liu_tianchai_12039(a) == 1) {
			sum_liu_tianchai_12039++;
		}
	}
}
