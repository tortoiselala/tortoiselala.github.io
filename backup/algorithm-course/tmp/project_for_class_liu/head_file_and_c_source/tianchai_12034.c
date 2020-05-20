#pragma once
#include"tianchai_12034.h"

#define size_liu_tainchai_12034 100

int n_12304, m_12304, x_12304, y_12304;
char map_12304[size_liu_tainchai_12034][size_liu_tainchai_12034];
int sum_12304;
int Z_12304[size_liu_tainchai_12034][size_liu_tainchai_12034];
int book_12304[size_liu_tainchai_12034][size_liu_tainchai_12034];


void Xiaomie(int p, int q);
void dfs1(int a, int b);
int run_tianchai_12304();



int run_tianchai_12304()
{
	scanf("%d%d%d%d", &n_12304, &m_12304, &x_12304, &y_12304);
	for (int i = 0; i < n_12304; i++)
	{
		scanf("%s", map_12304[i]);
	}
	dfs1(x_12304, y_12304);
	printf("%d", sum_12304);
	return 0;
}

void Xiaomie(int p, int q)
{
	int p1 = p, q1 = q;
	while (map_12304[p - 1][q] != '#')
	{
		if (map_12304[p - 1][q] == 'G')
		{
			Z_12304[p1][q1]++;
			
		}
		p--;
	}
	p = p1, q = q1;
	while (map_12304[p][q + 1] != '#')
	{
		if (map_12304[p][q + 1] == 'G')
		{
			Z_12304[p1][q1]++;
		
		}
		q++;
	}
	p = p1, q = q1;
	while (map_12304[p + 1][q] != '#')
	{
		if (map_12304[p + 1][q] == 'G')
		{
			Z_12304[p1][q1]++;
			
		}
		p++;
	}
	p = p1, q = q1;
	while (map_12304[p][q - 1] != '#')
	{
		if (map_12304[p][q - 1] == 'G')
		{
			Z_12304[p1][q1]++;
			
		}
		q--;
	}
}
void dfs1(int a, int b)
{
	Xiaomie(a, b);
	sum_12304 = Z_12304[a][b] > sum_12304 ? Z_12304[a][b] : sum_12304;

	book_12304[a][b] = 1;
	if (a > 1 && map_12304[a - 1][b] == '.' && book_12304[a - 1][b] == 0)
	{
		dfs1(a - 1, b);
	}
	if (b > 1 && map_12304[a][b - 1] == '.'&& book_12304[a][b - 1] == 0)
	{
		dfs1(a, b - 1);
	}
	if (a <= n_12304 && map_12304[a + 1][b] == '.'&& book_12304[a + 1][b] == 0)
	{
		dfs1(a + 1, b);
	}
	if (b <= m_12304 && map_12304[a][b + 1] == '.'&& book_12304[a][b + 1] == 0)
	{
		dfs1(a, b + 1);
	}
}
