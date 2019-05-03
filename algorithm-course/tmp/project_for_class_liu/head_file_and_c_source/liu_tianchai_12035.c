#include"liu_tianchai_12035.h"

int n_liu_12035, m_liu_12035, x_liu_12035, y_liu_12035;
int map_liu_12035[101][101];
int sum_liu_12035;
int book_liu_12035[101][101];


void run_liu_tianchai_12035() {
	scanf("%d%d%d%d", &n_liu_12035, &m_liu_12035, &x_liu_12035, &y_liu_12035);
	for (int i = 1; i <= n_liu_12035; i++)
	{
		for (int j = 1; j <= m_liu_12035; j++)
		{
			scanf("%d", &map_liu_12035[i][j]);
		}
	}
	sum_liu_12035 = 0;
	dfs1_liu_tianchai_12035(x_liu_12035, y_liu_12035);
	printf("%d", sum_liu_12035);
}

void dfs1_liu_tianchai_12035(int a, int b)
{
	sum_liu_12035++;
	book_liu_12035[a][b] = 1;
	if (a - 1>0 && map_liu_12035[a - 1][b] != 0 && book_liu_12035[a - 1][b] == 0)
	{
		dfs1_liu_tianchai_12035(a - 1, b);
	}
	if (b - 1>0 && map_liu_12035[a][b - 1] != 0 && book_liu_12035[a][b - 1] == 0)
	{
		dfs1_liu_tianchai_12035(a, b - 1);
	}
	if (a + 1 <= n_liu_12035 && map_liu_12035[a + 1][b] != 0 && book_liu_12035[a + 1][b] == 0)
	{
		dfs1_liu_tianchai_12035(a + 1, b);
	}
	if (b + 1 <= m_liu_12035 && map_liu_12035[a][b + 1] != 0 && book_liu_12035[a][b + 1] == 0)
	{
		dfs1_liu_tianchai_12035(a, b + 1);
	}
}
