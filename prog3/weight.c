#include <stdio.h>
#include <math.h>
#include <string.h>

int main(void) {
	int wt_lb, ht_in;

	printf("Please enter your weight in whole pounds: ");
	scanf("%d", &wt_lb);
	printf("Please enter your height in whole inches: ");
	scanf("%d", &ht_in);

	double bmi = (double)703*wt_lb/pow(ht_in, 2);
	char status[12] = "";
	
	if (bmi < 18.5) {
		strcpy(status, "underweight");
	} else if (bmi >= 18.5 && bmi <= 24.9) {
		strcpy(status, "normal");
	} else if (bmi >= 25.0 && bmi <= 29.9) {
		strcpy(status, "overweight");
	} else {
		strcpy(status, "obese");
	}

	printf("You have a BMI of %.1lf, and your weight status is %s.", bmi, status);

	return 0;
}