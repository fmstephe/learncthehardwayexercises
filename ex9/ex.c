#include <stdio.h>

int main (int argc, char *argv[]) {
	int numbers[4] = {0};
	char name[8] = {'a'};

	// first, print them out raw
	printf("numbers %d %d %d %d\n", numbers[0], numbers[1], numbers[2], numbers[3]);

	printf("name each: %c %c %c %c\n", name[0], name[1], name[2], name[3]); // too many

	printf("name: %s\n", name);

	// setup the numbers

	numbers[0] = 1;
	numbers[1] = 2;
	numbers[2] = 3;
	numbers[3] = 4;

	// setup the name
	name[0] = 'F';
	name[1] = 'r';
	name[2] = 'a';
	name[3] = 'n';
	name[4] = 'c';
	name[5] = 'i';
	name[6] = 's';
	name[7] = '\0';

	// the print them out initialised
	printf("numbers %d %d %d %d\n", numbers[0], numbers[1], numbers[2], numbers[3]);

	printf("name each: %c %c %c %c %c %c %c %c\n", name[0], name[1], name[2], name[3], name[4], name[5], name[6], name[7]);

	printf("name: %s\n", name);

	char *alt = "Francis";

	printf("alt: %s\n", alt);

	printf("alt each: %c %c %c %c %c %c %c %c\n", alt[0], alt[1], alt[2], alt[3], alt[4], alt[5], alt[6], alt[7]);

	return 0;
}
