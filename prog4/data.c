#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

int main(int argc, char** argv) {
	FILE *fp = fopen(argv[1], "r");

	if (argc != 2) {
		printf("Incorrect number of arguments. Please try again\n");
		exit(EXIT_FAILURE);
	}
	
	int num = 0;
	double* data;
	int i = 0;

	fscanf(fp, "%d", &num);
	data = malloc(num*sizeof(double));

	for (i = 0; i < num; i++) {
		fscanf(fp, "%lf", &data[i]);
	}

	double low = data[0], high = data[0], ave = data[0], sd, sum_squares = 0;

	for (i = 1; i < num; i++) {
		if (data[i] < low) {
			low = data[i];
		}

		if (data[i] > high) {
			high = data[i];
		}

		ave = ave + ((data[i] - ave)/(i+1));
	}

	for (i = 0; i < num; i++) {
		sum_squares += pow(data[i] - ave, 2);
	}

	sd = pow(sum_squares/num, 0.5);

	printf("Smallest: %6.2lf\n", low);
	printf("Largest:  %6.2lf\n", high);
	printf("Average:  %6.2lf\n", ave);
	printf("Standard deviation: %6.3lf\n", sd);

	fclose(fp);
	return 0;
}