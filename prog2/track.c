#include <stdio.h>

void instructions(void);

int main(void) {
	instructions();
	printf("Minutes for the runner: ");
	int minutes;
	scanf("%d", &minutes);
	printf("Seconds for the runner: ");
	double seconds;
	scanf("%lf", &seconds);

	#define feetinmile 5280
	#define metersinmile 1609.34

	float totalsec = seconds+minutes*60;
	printf("That is %.1lf feet per second, and %.2lf meters per second.", feetinmile/totalsec, metersinmile/totalsec);

	return 0;
}

void instructions(void) {
	printf("This program will ask for the minutes and seconds for the time it\ntook for a runner to run a mile. The program will then calculate\nthe feet per second and meters per second for that runner.\n\n");
}