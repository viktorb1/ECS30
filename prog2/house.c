#include <stdio.h>

void instructions();

int main() {
	instructions();

	printf("Please enter the initial cost, fuel cost, and tax rate: ");
	int house, fuel;
	double tax;
	scanf("%d %d %lf", &house, &fuel, &tax);

	double total = (house*tax*5.0)+house+(fuel*5.0);
	printf("The total cost is $%.2lf", total);
	return 0;
}

void instructions() {
	printf("This program determines the total cost of owning a home for five years.\n");
	printf("The user will enter initial cost in whole dollars, annual fuel costs in\n");
	printf("whole dollars, and the annual tax rate as a real number.\n\n");
}