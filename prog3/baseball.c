#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char** argv) {

	if (argc != 2) {
		printf("Incorrect number of arguments. Please try again\n");
		exit(EXIT_FAILURE);
	}

	FILE* fp = fopen(argv[1], "r");

	int i, player_num, hits = 0, total = 0;

	char str[100] = "";
	while (fscanf(fp, "%d %s", &player_num, str) == 2) {
		for (i = 0; i < strlen(str); i++) {
			if (str[i] == 'H') {
				hits++;
				total++;
			} else if (str[i] == 'O') {
				total++;
			}
		}
		printf("Player %d's record: %s\nPlayer %d's batting average: %.3lf\n\n", player_num, str, player_num, (double)hits/total);
		hits = 0, total = 0;
	}

	fclose(fp);
	return 0;
}