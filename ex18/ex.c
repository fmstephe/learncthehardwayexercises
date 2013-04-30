#include<stdlib.h>
#include<errno.h>
#include<stdio.h>
#include<string.h>

void die(const char *msg) {
	if (errno) {
		perror(msg);
	} else {
		printf("Error: %s", msg);
	}
	exit(1);
}

typedef int (*cmpr_fn)(int a, int b);

int *bubble_sort(int *nums, int size, cmpr_fn cmpr) {
	int mem_size = size * sizeof(int);
	int temp = 0;
	int *target = malloc(mem_size);
	if (!target) die("Unable to malloc target");
	memcpy(target, nums, mem_size);
	for (int i = 0; i < size; i++) { // We can probably make this more efficient
		for (int j = 0; j < size - 1; j++) {
			if (cmpr(target[j], target[j+1]) > 0) {
				temp = target[j+1];
				target[j+1] = target[j];
				target[j] = temp;
			}
		}
	}
	return target;
}

int sorted_order(int a, int b) {
	return a - b;
}

int reverse_order(int a, int b) {
	return b - a;
}

int strange_order(int a, int b) {
	if (a == 0 || b == 0) {
		return 0;
	}
	return a % b;
}

void test_sorting(int *nums, int size, cmpr_fn cmpr) {
	int *sorted = bubble_sort(nums, size, cmpr);
	if (!sorted) die("Failed to sort");
	for (int i = 0; i < size; i++) {
		printf("%d,", sorted[i]);
	}
	printf("\n");
	free(sorted);
}

int main (int argc, char *argv[]) {
	if (argc < 2) die("Usage 'ex 1 9 3 4 6 7'");
	int size = argc - 1;
	char **inputs = argv+1;
	int *nums = malloc(size * sizeof(int));
	for (int i = 0; i < size; i++) {
		nums[i] = atoi(inputs[i]);
	}
	test_sorting(nums, size, sorted_order);
	test_sorting(nums, size, reverse_order);
	test_sorting(nums, size, strange_order);
}
