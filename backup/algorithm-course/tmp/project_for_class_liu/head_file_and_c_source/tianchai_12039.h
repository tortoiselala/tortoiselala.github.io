#pragma once
#include"generic_head.h"
#include"math.h"
#define array_size_12039 23
int n_12039, k_12039;
int array_12039[array_size_12039];
int book_12039[array_size_12039];
int sum_12039;
int total_prime_12039;

void run_tianchai_12039();

void get_input_data();
bool is_prime(int num);
void dfs_12039(int loop,int x);