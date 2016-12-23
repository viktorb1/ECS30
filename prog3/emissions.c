#include <stdio.h>

void checkifexceeds(int option, int odo, double grams_pm);

int main() {
	printf("(1) Carbon monoxide\n(2) Hydrocarbons\n(3) Nitrogen oxides\n(4) Nonmethane hydrocarbons\n");
	int option, odo;
	double grams_pm;
	scanf("%d", &option);
	printf("Enter number of grams emitted per mile>> ");
	scanf("%lf", &grams_pm);
	printf("Enter odometer reading>> ");
	scanf("%d", &odo);
	checkifexceeds(option, odo, grams_pm);
	return 0;
}

void checkifexceeds(int option, int odo, double grams_pm) {
	if (option == 1) {
		if (odo > 50000 && grams_pm < 4.2) {
			printf("Emissions do not exceed permitted level of 4.2 grams/mile.");
		} else if (odo <= 50000 && grams_pm < 3.4) {
			printf("Emissions do not exceed permitted level of 3.4 grams/mile.");
		} else if (odo > 50000 && grams_pm > 4.2) {
			printf("Emissions exceed permitted level of 4.2 grams/mile.");
		} else  if (odo <= 50000 && grams_pm > 3.4) {
			printf("Emissions exceed permitted level of 3.4 grams/mile.");
		}
	} else if (option == 2) {
		if (odo > 50000 && grams_pm < 0.39) {
			printf("Emissions do not exceed permitted level of 4.2 grams/mile.");
		} else if (odo <= 50000 && grams_pm < 0.31) {
			printf("Emissions do not exceed permitted level of 3.4 grams/mile.");
		} else if (odo > 50000 && grams_pm > 0.39) {
			printf("Emissions exceed permitted level of 4.2 grams/mile.");
		} else  if (odo <= 50000 && grams_pm > 0.31) {
			printf("Emissions exceed permitted level of 3.4 grams/mile.");
		}
	} else if (option == 3) {
		if (odo > 50000 && grams_pm < 0.5) {
			printf("Emissions do not exceed permitted level of 4.2 grams/mile.");
		} else if (odo <= 50000 && grams_pm < 0.4) {
			printf("Emissions do not exceed permitted level of 3.4 grams/mile.");
		} else if (odo > 50000 && grams_pm > 0.5) {
			printf("Emissions exceed permitted level of 4.2 grams/mile.");
		} else  if (odo <= 50000 && grams_pm > 0.4) {
			printf("Emissions exceed permitted level of 3.4 grams/mile.");
		}
	} else if (option == 4) {
		if (odo > 50000 && grams_pm < 0.31) {
			printf("Emissions do not exceed permitted level of 4.2 grams/mile.");
		} else if (odo <= 50000 && grams_pm < 0.25) {
			printf("Emissions do not exceed permitted level of 3.4 grams/mile.");
		} else if (odo > 50000 && grams_pm > 0.31) {
			printf("Emissions exceed permitted level of 4.2 grams/mile.");
		} else  if (odo <= 50000 && grams_pm > 0.25) {
			printf("Emissions exceed permitted level of 3.4 grams/mile.");
		}
	}
}