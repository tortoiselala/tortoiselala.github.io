#include"luogu_P3378.h"

#define N 1000001
#define max_int 99999
struct heap {
	int heap_array[N];
	int heap_length;
	int heap_start;
};

struct heap heap_min;

void run_luogu_P3378() {
	int num_instruction;
	heap_min.heap_length = 0;
	heap_min.heap_start = 1;
	scanf("%d", &num_instruction);
	for (int i = 0; i < num_instruction; i++) {
		int instruction;
		scanf("%d", &instruction);
		instruction_parse_luogu_P3378(instruction);
	}
}

void instruction_parse_luogu_P3378(int instruction) {

	if (instruction == 1){
		heap_min.heap_length++;
		scanf("%d", &heap_min.heap_array[heap_min.heap_length]);
		for (int i = heap_min.heap_length / 2; i > 0; i--) {
			heap_maintain(i);
		}
	}
	else if (instruction == 2){
		printf("%d\n", heap_min.heap_array[heap_min.heap_start]);
	}
	else if (instruction == 3){
		/*
		这里将删去的数字应该改为极大值，因为我们构造的是一个最小堆， 将极大值会移动到数组末尾
		之后发现这种方法会导致一种错误，在向下调整的过程中，我们并不能确保极大值会调整到数组末尾，所以
		在这里选择将数组最后一个元素的值移动到堆首，这样就可以避免值存储的问题
		*/
		heap_min.heap_array[heap_min.heap_start] = heap_min.heap_array[heap_min.heap_length];
		heap_min.heap_length--;
		heap_maintain(heap_min.heap_start);
              		
	}
}

void heap_maintain(int target_maintain_num) {
	if (target_maintain_num > heap_min.heap_length / 2) {
		return;
	}
	/*
	这里应该选择左右子节点中最小的一个进行交换
	*/

	int min_of_two_child = 0;
	int index_of_min_child = 0;
	if (target_maintain_num * 2 + 1 > heap_min.heap_length) {
		min_of_two_child = heap_min.heap_array[target_maintain_num * 2];
		index_of_min_child = target_maintain_num * 2;
	}
	else {
		if (heap_min.heap_array[target_maintain_num * 2] < heap_min.heap_array[target_maintain_num * 2 + 1]) {
			min_of_two_child = heap_min.heap_array[target_maintain_num * 2];
			index_of_min_child = target_maintain_num * 2;
		}
		else {
			min_of_two_child = heap_min.heap_array[target_maintain_num * 2 + 1];
			index_of_min_child = target_maintain_num * 2 + 1;
		}
	}
	/*
	如果发生交换，再去维护交换后的那个子节点，否则维护结束，返回
	*/

	if (heap_min.heap_array[target_maintain_num] > min_of_two_child) {
		heap_min.heap_array[index_of_min_child] = heap_min.heap_array[target_maintain_num];
		heap_min.heap_array[target_maintain_num] = min_of_two_child;
		heap_maintain(index_of_min_child);
	}
}