#include"prim_algorithm.h"

/*
首先使用邻接表去存储图，在这里我使用数组形式的邻接表，有兴趣可以去查一查链表形式的邻接表
*/
//宏定义 graph_max_num_edge         20         假设图的每个顶点边的数目不超过20
#define graph_max_num_edge 20
//宏定义 graph_max_num_vertex       20         假设图的顶点数不超过20
#define graph_max_num_vertex 20
//宏定义 inf 9999  无穷大数
#define inf 9999
/*
结构体 graph 图的基础存储单位  使用结构数组来存储图的信息
	第一列为起始顶点  后续所有列都为终止顶点
		起始顶点中vertex存储起始顶点编号
		起始顶点中num_edge_or_length存储该起始顶点有几条边

		终止顶点中vertex存储终止节点编号
		终止节点中num_edge_or_length存储起始节点到终止节点的边的权值
*/
struct graph {
	int vertex;
	int num_edge_or_length;
	bool is_used;

};

struct road {
	int start;
	int end;
	int length;
};

struct graph input_graph[graph_max_num_vertex][graph_max_num_edge];

struct road result_road[graph_max_num_vertex];
//num_vertex, num_edge 为输入参数注解中的n,m
int num_vertex, num_edge;
//标记顶点是否以访问
bool book_prim_algorithm[graph_max_num_vertex];


void run_prim_algorithm() {
	data_input_prim_algorithm();
	prim_main_logic();



	for (int i = 1; i <= result_road[0].length; i++) {
		printf("node_start:%d\tnode_end:%d\tnode_length:%d\n", result_road[i].start, result_road[i].end, result_road[i].length);
	}
}
/*
图的数据输入函数，输入格式参考luogu.org P3366[模板]最小生成树
	第一行包含两个整数N、M，表示该图共有N个结点和M条无向边。（N<=5000，M<=200000）注：根据合适情况调整宏定义

	接下来M行每行包含三个整数Xi、Yi、Zi，表示有一条长度为Zi的无向边连接结点Xi、Yi
*/
void data_input_prim_algorithm() {

	scanf("%d%d", &num_vertex, &num_edge);

	for (int i = 0; i < num_edge; i++) {
		int vertex_start, vertex_end, vertex_length;
		scanf("%d%d%d", &vertex_start, &vertex_end, &vertex_length);

		input_graph[vertex_start][0].num_edge_or_length++;
		input_graph[vertex_start][0].vertex = vertex_start;
		input_graph[vertex_start][input_graph[vertex_start][0].num_edge_or_length].vertex = vertex_end;
		input_graph[vertex_start][input_graph[vertex_start][0].num_edge_or_length].num_edge_or_length = vertex_length;
		
		input_graph[vertex_end][0].num_edge_or_length++;
		input_graph[vertex_end][0].vertex = vertex_end;
		input_graph[vertex_end][input_graph[vertex_end][0].num_edge_or_length].vertex = vertex_start;
		input_graph[vertex_end][input_graph[vertex_end][0].num_edge_or_length].num_edge_or_length = vertex_length;
	}
}

/*
生成树的主要逻辑处理函数，对于选边过程中使用堆来优化时间复杂度，先不使用，有兴趣可以自己来尝试一下
主要变量注解：
	book[]标记顶点是否已访问
*/

void prim_main_logic() {
	book_prim_algorithm[1] = 1;

	for (int i = 0; i < num_edge - 1; i++) {
		min_edge_prim_algorithm();
	}
}

/*
寻找和未标记节点相连，且距离最小的边
*/
void  min_edge_prim_algorithm() {
	
	for (int m = 1; m < num_vertex; m++) {
		/*
		三个变量分别存储找到的最小的边的信息
		int min_edge_start_vertex = inf;
		int min_edge_end_vertex = inf;
		int min_edge_length = inf;
		*/
		int min_edge_start_vertex = inf;
		int min_edge_end_vertex = inf;
		int min_edge_length = inf;
		/*
		该循环根据限制条件，寻找最小边
		*/
		for (int i = 1; i <= num_vertex; i++) {
			if (book_prim_algorithm[i] == true) {
				for (int j = 1; j <= input_graph[i][0].num_edge_or_length; j++) {
					if (input_graph[i][j].is_used == false && book_prim_algorithm[input_graph[i][j].vertex] == false && input_graph[i][j].num_edge_or_length < min_edge_length) {

						min_edge_start_vertex = i;
						min_edge_end_vertex = input_graph[i][j].vertex;
						min_edge_length = input_graph[i][j].num_edge_or_length;
					}
				}
			}
		}
		/*
		当该边有效时
		*/
		if (min_edge_start_vertex != inf && min_edge_end_vertex != inf && min_edge_length != inf) {
			/*
			将邻接表中的is_used属性改为true，因为是无向图，所以要更改两个地方的
			*/
			for (int i = 1; i <= input_graph[min_edge_start_vertex][0].num_edge_or_length; i++) {
				if (input_graph[min_edge_start_vertex][i].vertex == min_edge_end_vertex) {
					input_graph[min_edge_start_vertex][i].is_used = true;
					break;
				}
			}
			for (int i = 1; i <= input_graph[min_edge_end_vertex][0].num_edge_or_length; i++) {
				if (input_graph[min_edge_end_vertex][i].vertex == min_edge_start_vertex) {
					input_graph[min_edge_end_vertex][i].is_used = true;
					break;
				}
			}
			/*
			标记该点已被访问
			*/
			book_prim_algorithm[min_edge_end_vertex] = true;
			/*
			统计路径信息
			*/
			result_road[0].length++;
			result_road[result_road[0].length].start = min_edge_start_vertex;
			result_road[result_road[0].length].end = min_edge_end_vertex;
			result_road[result_road[0].length].length = min_edge_length;
		}
	}
}
