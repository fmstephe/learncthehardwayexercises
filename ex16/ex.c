#include <stdio.h>
#include <assert.h>
#include <stdlib.h>

struct Person {
	char *name;
	int age;
	int height;
	int weight;
};

char *strcopy(char *s) {
	char *copy = malloc(sizeof(s));
	for (int i = 0; s[i] != '\0'; i++) {
		copy[i] = s[i];
	}
	return copy;
}

struct Person *Person_create(char *name, int age, int height, int weight) {
	struct Person *who = malloc(sizeof(struct Person));
	assert(who != NULL);
	who -> name = strcopy(name);
	who -> age = age;
	who -> height = height;
	who -> weight = weight;
	return who;
}

void Person_free(struct Person *who) {
	assert(who != NULL);
	free(who->name);
	free(who);
}

void Person_print(struct Person *who) {
	printf("%s\n",who->name);
	printf("Age:\t %d\n",who->age);
	printf("Height:\t %d\n",who->height);
	printf("Weight:\t %d\n",who->weight);
}

int main (int argc, char *argv[]) {
	// Make two person structures
	struct Person *joe = Person_create("Joe Alex", 32, 64, 140);
	struct Person *frank = Person_create("Frank Blank", 20, 72, 180);
	//
	printf("Joe's pointer is at memory location: %p, pointing to %p \n", &joe, joe);
	Person_print(joe);
	printf("Frank's pointer is at memory location: %p, pointing to %p \n", &frank, frank);
	Person_print(frank);
	//
	joe->age += 20;
	joe->height += 2;
	joe->weight += 40;
	Person_print(joe);
	//
	frank->age += 20;
	frank->weight += 20;
	Person_print(frank);
	//
	printf("Joe is at memory location: %p\n", joe);
	Person_free(joe);
	printf("Joe is at memory location: %p\n", joe);
	printf("Frank is at memory location: %p\n", frank);
	Person_free(frank);
	printf("Frank is at memory location: %p\n", frank);
}
