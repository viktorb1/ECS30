#include <stdio.h>

int get_problem(void);
void get2_pt(double *x1, double *y1, double *x2, double *y2);
void get_pt_slope(double *x1, double *x2, double *slope);
void slope_intcpt_from2_pt(double x1, double y1, double x2, double y2, double *slope, double *intcpt);
double intcpt_from_pt_slope(double x1, double y1, double slope);
void display2_pt(double x1, double y1, double x2, double y2); 
void display_pt_slope(double x1, double y1, double slope);
void display_slope_intcpt(double slope, double intcpt);

int main() {
	char do_another = 'y';

	while (do_another == 'y' || do_another == 'Y') {
		int choice = get_problem();

		double x1, y1, x2, y2;
		double slope, intcpt;

		if(choice == 1) {
			get2_pt(&x1, &y1, &x2, &y2);
			slope_intcpt_from2_pt(x1, y1, x2, y2, &slope, &intcpt);
			display2_pt(x1, y1, x2, y2);
		} else {
			get_pt_slope(&x1, &y1, &slope);
			intcpt = intcpt_from_pt_slope(x1, y1, slope);
			display_pt_slope(x1, y1, slope);
		}

		display_slope_intcpt(slope, intcpt);

		printf("\nDo another conversion (Y or N)=> ");
		scanf("%c", &do_another);
		scanf("%c", &do_another);

		if (do_another == 'y' || do_another == 'Y') 
			printf("\n");
	}

	return 0;
}

int get_problem(void) {
	printf("Select the form that you would like to convert to slope-intercept form:\n");
	printf("1) Two-point form (you know two points on the line)\n");
	printf("2) Point-slope form (you know the line's slope and one point)\n=> ");

	int choice = 0;
	scanf("%d", &choice);

	while (choice != 1 && choice != 2) {
		printf("Please try again\n");
		scanf("%d", &choice);
	}

	return choice;
}

void get2_pt(double *x1, double *y1, double *x2, double *y2) {
	printf("\nEnter the x-y coordinates of the first point separated by a space=> ");
	scanf("%lf %lf", x1, y1);
	printf("Enter the x-y coordinates of the second point separated by a space=> ");
	scanf("%lf %lf", x2, y2);
}

void get_pt_slope(double *x1, double *x2, double *slope) {
	printf("\nEnter the slope=> ");
	scanf("%lf", slope);
	printf("Enter the x-y coordinates of the point separated by a space=> ");
	scanf("%lf %lf", x1, x2);
}

void slope_intcpt_from2_pt(double x1, double y1, double x2, double y2, double *slope, double *intcpt) {
	*slope = (y2 - y1) / (x2 - x1);
	*intcpt = y1 - *slope*x1;
}

double intcpt_from_pt_slope(double x1, double y1, double slope) {
	double intcpt = y1 - slope*x1;
	return intcpt;
}

void display2_pt(double x1, double y1, double x2, double y2) {
	printf("\nTwo-point form\n");
	printf("        (%.2lf - %.2lf)\n", y2, y1);
	printf("    m = -------------\n");
	printf("        (%.2lf - %.2lf)\n", x2, x1);
}

void display_pt_slope(double x1, double y1, double slope) {
	printf("\nPoint-slope form\n");
	printf("	y - %.2lf = %.2lf(x - %.2lf)\n", y1, slope, x1);
}

void display_slope_intcpt(double slope, double intcpt) {
	printf("\nSlope-intercept form\n");

	if (intcpt > 0) {
		printf("	y = %.2lfx + %.2lf\n", slope, intcpt);
	} else {
		printf("	y = %.2lfx - %.2lf\n", slope, intcpt*-1);
	}

}