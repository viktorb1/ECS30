#include <stdio.h>

double population(int year);

int main() {
	printf("Enter a year after 1990> ");
	int year;
	scanf("%d", &year);

	FILE* fp = fopen("pop.txt", "w");
	fprintf(fp, "Predicted Gotham City population for %d (in thousands): %0.3lf\n", year, population(year));
	fclose(fp);

	return 0;
}

double population(int year) {
	#define initial 52.966
	#define rate 2.184
	#define initialyear 1990

	return initial+rate*(year-initialyear);
}