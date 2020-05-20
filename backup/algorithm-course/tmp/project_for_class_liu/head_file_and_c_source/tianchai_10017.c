/*
题目10017的函数定义文件，运行入口为run_10017
*/
#include"tianchai_10017.h"


#define n 101
#define name_size 20
char name[n][name_size + 1];			//姓名
int average_final_exam[n];				//期末平均成绩
int comment_grade[n];					//班级评议成绩
char is_crdre[n];						//是否学生干部
char is_west[n];						//是否西部学生
int total_publish_paper[n];				//发表的论文总数量
int total_scholarship[n];				//总奖学金数量
int N;									//学生总数
int max_total_schoolarship;
int serial_number_of_max;
int total_schoolarship_of_all_student;



void run_10017() {
	input_info();
	conut_schoolarship();
	print_result();
}

void input_info() {
	scanf("%d", &N);					//输入学生总数
	for (int i = 0; i < N; i++) {		//循环输入学生各项信息
		scanf("%s %d %d %c %c %d", name[i], &average_final_exam[i], &comment_grade[i], &is_crdre[i], &is_west[i], &total_publish_paper[i]);
	}
}
void conut_schoolarship() {
	for (int i = 0; i < N; i++) {
		if (average_final_exam[i] > 80 && total_publish_paper[i] >= 1) {
			total_scholarship[i] += 8000;
		}
		if (average_final_exam[i] > 85 && comment_grade[i] > 80) {
			total_scholarship[i] += 4000;
		}
		if (average_final_exam[i] > 90) {
			total_scholarship[i] += 2000;
		}
		if (average_final_exam[i] > 85 && is_west[i] == 'Y') {
			total_scholarship[i] += 1000;
		}
		if (comment_grade[i] > 80 && is_crdre[i] == 'Y') {
			total_scholarship[i] += 850;
		}
		total_schoolarship_of_all_student += total_scholarship[i];
		if (total_scholarship[i] > max_total_schoolarship) {
			max_total_schoolarship = total_scholarship[i];
			serial_number_of_max = i;
		}
	}
}
void print_result() {
	//输出结果
	printf("%s\n%d\n%d", name[serial_number_of_max], max_total_schoolarship, total_schoolarship_of_all_student);
}