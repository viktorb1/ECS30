#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char* read_word_to_str();
char* get_longest_suffix(char* first_word, char* second_word);

int main() {
	printf("Input first word: ");
	char* first_word = read_word_to_str();
	printf("Input second word: ");
	char* second_word = read_word_to_str();
	char* suffix = get_longest_suffix(first_word, second_word);
	printf("Longest common suffix: %s", suffix);
	return 0;
}

char* read_word_to_str() {
	int c, n = 20, i = 0;
	char* word = malloc(sizeof(char)*n);

	c = getchar();

	while (c != '\n' && c != EOF) {

		if (i >= n) {
			n += 20;
			char* word = realloc(word, sizeof(char)*n);
		}

		word[i] = c;
		i++;
		c = getchar();
	}

	word[i] = '\0';
	return word;
}

char* get_longest_suffix(char* first_word, char* second_word) {
	int w1i = strlen(first_word), w2i = strlen(second_word), i = 0;
	char* suffix = NULL;

	if (w1i > w2i) {
		suffix = malloc(sizeof(char)*(w1i+1));
		i = w1i;
	} else {
		suffix = malloc(sizeof(char)*(w2i+1));
		i = w2i;
	}

	suffix[i] = '\0';

	while (first_word[w1i-1] == second_word[w2i-1] && i > 0) {
		i--;
		suffix[i] = first_word[w1i-1];
		w1i--;
		w2i--;
	}

	suffix = &suffix[i];
	return suffix;
}