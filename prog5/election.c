#include <stdio.h>
#include <stdlib.h>

void read_file(int electionData[6][5], int argc, char** argv);
void sort(int electionData[6][5], char candidateabcd[4]);
void show_table(int electionData[6][5], char candidateabcd[4]);
void declare_winner(int electionData[6][5], char candidateabcd[4]);

int main(int argc, char** argv) {
	int electionData[6][5];
	char candidateabcd[4] = {'A','B','C','D'};
	
	read_file(electionData, argc, argv);
	sort(electionData, candidateabcd);
	show_table(electionData, candidateabcd);
	declare_winner(electionData, candidateabcd);

	return EXIT_SUCCESS;
}

void read_file(int electionData[6][5], int argc, char** argv) {
	if (argc != 2) {
		printf("Error. Quitting.\n");
		exit(EXIT_FAILURE);
	}

	FILE* fp = fopen(argv[1], "r");

	for (int i = 0; i < 5; i++) {
		for (int j = 0; j < 5; j++) {
			fscanf(fp, "%d", &electionData[i][j]);
		}
	}

	for (int j = 0; j < 5; j++) {

		electionData[5][j] = 0;

		for (int i = 0; i < 5; i++) {

			electionData[5][j] += electionData[i][j];
		}
	}
}

void sort(int electionData[6][5], char candidateabcd[4]) {
	int temp[6][5];
	char tempabcd;

	for (int i = 0; i < 3; i++) {
		for (int j = 1; j < 4-i; j++) {
			if (electionData[5][j+1] > electionData[5][j]) {
			
				for(int k = 0; k < 6; k++) {
					temp[k][j] = electionData[k][j];
					electionData[k][j] = electionData[k][j+1];
					electionData[k][j+1] = temp[k][j];
				}

				tempabcd = candidateabcd[j-1];
				candidateabcd[j-1] = candidateabcd[j];
				candidateabcd[j] = tempabcd;
			}
		}

	}
}

void show_table(int electionData[6][5], char candidateabcd[4]) {
	printf("           Candidate  Candidate  Candidate  Candidate\n");
	printf("Precinct       %c          %c          %c          %c    \n", candidateabcd[0], candidateabcd[1], candidateabcd[2], candidateabcd[3]);

	for (int i = 0; i < 5; i++) {
		for (int j = 0; j < 5; j++) {
			printf("  %4d     ", electionData[i][j]);
		}
		printf("\n");
	}

	printf("Total:       %4d       %4d       %4d       %4d\n\n", electionData[5][1], electionData[5][2], electionData[5][3], electionData[5][4]);
}

void declare_winner(int electionData[6][5], char candidateabcd[4]) {
	double highestvotepercent = (double)electionData[5][1] / (electionData[5][1] + electionData[5][2] + electionData[5][3] + electionData[5][4]);

	if (highestvotepercent >= 0.50) {
		printf("Candidate %c is the winner.", candidateabcd[0]);
	} else {
		printf("Candidates %c and %c will have a runoff.", candidateabcd[0], candidateabcd[1]);
	}
}