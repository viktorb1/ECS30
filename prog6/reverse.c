#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int reverse_words(char* input, char** output);
void print_words(char** output, int num_words);

int main() {
	char input[80];
	char** output = malloc(40*sizeof(char*));

	printf("Input: ");
	fgets(input, 80, stdin);

	int i = 0;
	for (i = 0; i < strlen(input); i++) {
		if (input[i] == '\n') {
			input[i] = '\0';
		}
	}

	int num_words = reverse_words(input, output);
	printf("Reversed: ");
	print_words(output, num_words);
	free(output);
	return 0;
}

int reverse_words(char* input, char** output) {
	int i = 0;

	output[i] = strtok(input, " ");

	while (output[i] != NULL) {
		i++;
		output[i] = strtok(NULL, " ");
	}

	return i;
}

void print_words(char** output, int num_words) {
	num_words--;

	while (num_words >= 0) {
		printf("%s ", output[num_words]);
		num_words--;
	}
}