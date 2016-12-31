#include <stdio.h>
#include <stdlib.h>

int main(int argc, char** argv) {
	int piels, coors, bud, iron_city;

	if (argc != 2) {
		printf("Incorrect number of arguments. Please try again!\n");
		exit(EXIT_FAILURE);
	}

	FILE* fp = fopen(argv[1], "r");

	fscanf(fp, "%d %d %d %d", &piels, &coors, &bud, &iron_city);

	int brand, quantity;

	while(fscanf(fp, "%d %d", &brand, &quantity) == 2) {
		if (brand == 1) {
			piels += quantity;
		} else if (brand == 2) {
			coors += quantity;
		} else if (brand == 3) {
			bud += quantity;
		} else if (brand == 4) {
			iron_city += quantity;
		}
	}

	printf("Piels:     %4d\n", piels);
	printf("Coors:     %4d\n", coors);
	printf("Bud:       %4d\n", bud);
	printf("Iron City: %4d\n", iron_city);

	fclose(fp);
	return 0;
}