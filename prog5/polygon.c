#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int get_corners(FILE *fp, double* x, double* y);
void output_corners(FILE *outputfp, double* x, double* y, int numofrows);
double polygon_area(double *x, double *y);

int main(int argc, char **argv) {
	double x[20], y[20];
	#define ARRAY_SIZE 20

	if (argc != 3) {
		printf("Error. Quitting.\n");
		exit(EXIT_FAILURE);
	}
		
	FILE *fp = fopen(argv[1], "r");
	FILE *outputfp = fopen(argv[2], "w");

	int numofrows = get_corners(fp, x, y);
	output_corners(outputfp, x, y, numofrows);
	double area = polygon_area(x, y);
	printf("The area is %.1lf.\n", area);

	fclose(fp);
	fclose(outputfp);

	return 0;
}

int get_corners(FILE *fp, double* x, double* y) {
	int i = 0;

	while(fscanf(fp, "%lf %lf", &x[i], &y[i]) == 2 && i < ARRAY_SIZE)
		i++;

	x[i] = '\0';
	y[i] = '\0';

	return i;
}

void output_corners(FILE *outputfp, double* x, double* y, int numofrows) {
	int i;
	for (i = 0; i < numofrows; i++) {
		fprintf(outputfp, "%.1lf\t%.1lf\n", x[i], y[i]);
	}
}

double polygon_area(double *x, double *y) {
	double area = 0;
	int i = 0;

	while(x[i+1] != '\0') {
		area += (x[i+1] + x[i])*(y[i+1]-y[i]);
		i++;
	}

	area *= 0.5;
	return fabs(area);
}