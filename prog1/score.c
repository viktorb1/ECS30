#include <stdio.h>

int main() {
	printf("Enter desired grade> ");
	char grade;
	scanf("%c",&grade);
	printf("Enter minimum average required> ");
	double min_av, cur_av, final_percent;
	scanf("%lf",&min_av);
	printf("Enter current average in course> ");
	scanf("%lf", &cur_av);
	printf("Enter how much the final counts as a percentage of the course grade> ");
	scanf("%lf", &final_percent);
	double score_needed = (min_av - (cur_av*(100-final_percent)/100))/(final_percent/100);
	printf("\nYou need a score of %.2lf on the final to get a %c.", score_needed, grade);
	return 0;
}