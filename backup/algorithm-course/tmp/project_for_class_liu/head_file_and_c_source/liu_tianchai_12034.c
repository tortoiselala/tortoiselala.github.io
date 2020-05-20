#include"liu_tianchai_12034.h"



int n, m, x, y;
char map_liu_tianchai_12034[51][51];
int sum;
int Z[51][51];
int book[51][51];
void Xiaomie_liu_tianchai_12034(int p, int q)
{
	int p1 = p, q1 = q;
	while (map_liu_tianchai_12034[p - 1][q] != '#')
	{
		if (map_liu_tianchai_12034[p - 1][q] == 'G')
		{
			Z[p][q]++;
		}
		p--;
	}
	p = p1, q = q1;
	while (map_liu_tianchai_12034[p][q + 1] != '#')
	{
		if (map_liu_tianchai_12034[p][q + 1] == 'G')
		{
			Z[p][q]++;
		}
		q++;
	}
	p = p1, q = q1;
	while (map_liu_tianchai_12034[p + 1][q] != '#')
	{
		if (map_liu_tianchai_12034[p + 1][q] == 'G')
		{
			Z[p][q]++;
		}
		p++;
	}
	p = p1, q = q1;
	while (map_liu_tianchai_12034[p][q - 1] != '#')
	{
		if (map_liu_tianchai_12034[p][q - 1] == 'G')
		{
			Z[p][q]++;
		}
		q--;
	}
}
void dfs1_liu_tianchai_12034(int a, int b)
{
	Xiaomie(a, b);
	if (Z[a][b]>sum)
	{
		sum = Z[a][b];
	}
	book[a][b] = 1;
	if (a>1 && map_liu_tianchai_12034[a - 1][b] == '.' && book[a - 1][b] == 0)
	{
		dfs1(a - 1, b);
	}
	if (b>1 && map_liu_tianchai_12034[a][b - 1] == '.'&& book[a][b - 1] == 0)
	{
		dfs1(a, b - 1);
	}
	if (a<=n && map_liu_tianchai_12034[a + 1][b] == '.'&& book[a + 1][b] == 0)
	{
		dfs1(a + 1, b);
	}
	if (b<=m  && map_liu_tianchai_12034[a][b + 1] == '.'&& book[a][b + 1] == 0)
	{
		dfs1(a, b + 1);
	}
}
int run_liu_tianchai_12034()
{
	scanf("%d%d%d%d", &n, &m, &x, &y);
	for (int i = 0; i<n; i++)
	{
		scanf("%s", map_liu_tianchai_12034[i]);
	}
	sum = 0;
	dfs1(x, y);
	printf("%d", sum);
	return 0;
}
