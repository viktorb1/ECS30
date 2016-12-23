#include <stdio.h>

int main() {
	int weekday_mins, night_mins, weekend_mins;

	printf("Please enter the number of weekday minutes, night minutes: ");
	scanf("%d %d", &weekday_mins, &night_mins);
	printf("Please enter the number of weekend minutes: ");
	scanf("%d", &weekend_mins);

	printf("\nWeekday minutes: %d, night minutes: %d, weekend minutes: %d\n", weekday_mins, night_mins, weekend_mins);

	
	#define FLAT_RATE 3999
	#define ADD_CHARGE 40
	#define CENTS_PER_DOLLAR 100
	#define MONTHLY_LIMIT 600
	#define TAX_PERCENT 0.0525

	double pretax_bill = 0;

	if (weekday_mins < 600) {
		pretax_bill = (double)FLAT_RATE/CENTS_PER_DOLLAR;
	} else {
		pretax_bill = (double)(FLAT_RATE + (weekday_mins-MONTHLY_LIMIT)*ADD_CHARGE)/CENTS_PER_DOLLAR;
	}

	double taxes = pretax_bill*TAX_PERCENT;
	double total_bill = pretax_bill + taxes;

	printf("Average minute cost: $%.2lf\n\n", total_bill/(weekday_mins+night_mins+weekend_mins));

	printf("Pretax bill: $%6.2lf\n", pretax_bill);
	printf("Taxes:       $%6.2lf\n", taxes);
	printf("Total bill:  $%6.2lf\n", total_bill);

	return 0;
}