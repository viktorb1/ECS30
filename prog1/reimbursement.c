#include <stdio.h>

int main() {
	printf("MILEAGE REIMBURSEMENT CALCULATOR\n");
	printf("Enter beginning odometer reading=> ");
	double odo_start, odo_end;
	scanf("%lf", &odo_start);
	printf("Enter ending odometer reading=> ");
	scanf("%lf", &odo_end);

	#define rate 0.35 
	printf("You traveled %.1lf miles. At $.35 per mile, your reimbursement is $%.2lf.", odo_end-odo_start, rate*(odo_end-odo_start));
	return 0;
}