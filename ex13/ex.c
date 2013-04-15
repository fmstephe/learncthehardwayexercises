#include <stdio.h>

int main (int argc, char *argv[]) {
	printf("%d\n", 'A' - 'a');
	printf("%d, %d\n", 'A', 'Z');
	printf("%d, %d\n", 'a', 'z');
	if (argc != 2) {
		printf("ERROR: You need one argument\n");
		return 1;
	}
	int i = 0;
	for (i = 0; argv[1][i] != '\0'; i++) {
		char letter = argv[1][i];
		if (letter < 'a') {
			letter += 'a' - 'A'; // To lower case for ascii
		}
		switch (letter) {
			case 'a':
			//case 'A':
				printf("%d '%c'\n", i, letter);
				break;
			case 'e':
			//case 'E':
				printf("%d '%c'\n", i, letter);
				break;
			case 'i':
			//case 'I':
				printf("%d '%c'\n", i, letter);
				break;
			case 'o':
			//case 'O':
				printf("%d '%c'\n", i, letter);
				break;
			case 'u':
			//case 'U':
				printf("%d '%c'\n", i, letter);
				break;
			case 'y':
			//case 'Y':
				if (i > 2) {
					printf("%d '%c'\n", i, letter);
					break;
				}
			default:
				printf("%d %c is not a vowel\n", i, letter);
				break;
		}
	}
	return 0;
}
