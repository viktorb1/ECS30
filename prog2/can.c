#include <stdio.h>
#include <stdlib.h>
#include <math.h>

double surfacearea(double radius, double height);
void instructions();

int main() {
	instructions();

	FILE* fp = fopen("cans.txt", "r");
	if (fp == NULL) {
		printf("File not found\n");
		exit(EXIT_FAILURE);
	}

	double radius, height, cost_per_sq_cm;
	int quantity;

	while (fscanf(fp, "%lf %lf %lf %d", &radius, &height, &cost_per_sq_cm, &quantity) == 4) {
		double sa = surfacearea(radius, height);
		int i = 1;
		printf("Each can #%d has surface area %.3lf, and the run will cost $%.3lf.\n", i, sa, sa*cost_per_sq_cm*quantity);
		i++;
	}

	fclose(fp);

	return 0;
}

double surfacearea(double radius, double height) {
	return M_PI*pow(radius, 2)+(2*radius*M_PI*height);

}

void instructions() {
	printf("This program calculates the cost of materials for three open-top cylindrical\n");
	printf("containers. It reads the radius, height, cost per square centimeter, and\n");
	printf("quantity for each container from the file cans.txt. Each line in cans.txt has\n");
	printf("the format: radius height cost_per_sq_cm quantity.\n\n");
}