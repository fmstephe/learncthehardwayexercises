#include <stdio.h>

int main (int argc, char *argv[]) {
	int i = 0;
	// Go through each string in argv
	// NB: argv[0] contains the name of the application being run
	for (i = 0; i < argc; i++) {
		printf("arg %d: %s\n", i, argv[i]);
	}

	// Let's make our own array of strings
	char *states[] = { "California", "Oregon", "Washington", "Texas" };
	int num_states = 4;

	for (i = 0; i < num_states; i++) {
		printf("State %d: %s\n", i, states[i]);
	}

	return 0;
}
