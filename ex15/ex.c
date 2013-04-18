#include <stdio.h>

int main (int argc, char *argv[]) {
	// Create two arrays we care about
	int ages[] = {23, 43, 12, 89, 2};
	char *names[] = {"Alan", "Francis Michael Stephens", "Mary", "John", "Lisa"};
	int count = sizeof(ages) / sizeof(int);

	// setup pointers to the start of the arrays
	int *age_ptr = ages;
	char **name_ptr = names;
	int **age_ptr_ptr = &age_ptr;

	printf("\n\n");
	printf("Sizeof -> age_ptr: %ld, name_ptr %ld, age_value %ld, name_value %ld\n\n", sizeof(age_ptr), sizeof(name_ptr), sizeof(*age_ptr), sizeof(*name_ptr));
	printf("age_ptr:\t\t %ld\n", age_ptr);
	printf("name_ptr:\t\t %ld\n", name_ptr);
	printf("age_ptr_ptr:\t\t %ld\n", age_ptr_ptr);
	printf("*age_ptr:\t\t %ld\n", *age_ptr);
	printf("*name_ptr:\t\t %ld\n", *name_ptr);
	printf("*age_ptr_ptr:\t\t %ld\n\n", *age_ptr_ptr);

	printf("\nName Pointers as Pointers\n\n");
	// I'm going to take a guess and say this is printing out addresses on the stack
	for (int i = 0; i < count; i++) {
		char **cur_ptr = name_ptr+i;
		char **next_ptr = name_ptr+(i+1);
		printf("cur: %ld, next: %ld, diff: %ld\n", cur_ptr, next_ptr, next_ptr - cur_ptr);
	}

	printf("\nName Pointers as Longs\n\n");
	// I'm going to take a guess and say this is printing out addresses on the stack
	for (int i = 0; i < count; i++) {
		int *cur_ptr = name_ptr+i;
		int *next_ptr = name_ptr+(i+1);
		printf("cur: %ld, next: %ld, diff: %ld\n", cur_ptr, next_ptr, next_ptr - cur_ptr);
	}

	printf("\nName Pointers Value (i.e. what they point at)\n\n");
	// I'm going to take a guess and say this is printing out addresses on the stack
	for (int i = 0; i < count; i++) {
		long cur_ptr = *(name_ptr+i);
		long next_ptr = *(name_ptr+(i+1));
		printf("cur: %ld, long: %ld, next: %ld, diff: %ld\n", *(name_ptr+i), cur_ptr, (name_ptr+(i+1)), next_ptr - cur_ptr);
	}

	printf("\nName Pointers Value (i.e. what they point at)\n\n");
	// Also guessing this is printing addresses in the heap
	for (int i = 0; i < count; i++) {
		printf("idx: %ld, addr: %ld, diff: %ld, age_ptr: %ld, age_ptr_addr: %ld\n", i, *(name_ptr+i), *(name_ptr+i+1)-*(name_ptr+i), *(age_ptr+i), age_ptr+i);
	}

	/*
	// second way using pointers
	for (int i = 0; i < count; i++) {
		printf("%s is %d years old\n", *(name_ptr+i), *(age_ptr+i));
	}

	printf("---\n");

	// Third way, pointers are just arrays
	for (int i = 0; i < count; i++) {
		printf("%s is %d years old again\n", name_ptr[i], age_ptr[i]);
	}
	*/

	printf("---\n");

	// fourth way with pointers in a stupid complex way
	for (name_ptr = names, age_ptr = ages; (name_ptr - names) < count; name_ptr++, age_ptr++) {
		printf("%s lived %d years so far\n", *name_ptr, *age_ptr);
	}

	return 0;
}
