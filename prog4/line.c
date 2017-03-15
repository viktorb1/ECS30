//https://searchcode.com/file/34980860/Bil102/HW03/HW03_111044029.c

int get_problem();
void get2_pt(int *x1, int *y1, int *x2, int *y2);
void get_pt_slope(double *slope, int *s_x1, int *s_x2);
void slope_intcpt_from2_pt(int x1, int y1, int x2, int y2, double *slope, double *yint);
void intcpt_from_pt_slope(int x1, int y1, double *slope, double *yint);


#include <stdio.h>

int main() {
	int problem = get_problem();
	printf("%d", problem);
	return 0;
}


int get_problem() {
	printf("Select the form that you would like to convert to slope-intercept form:\n");
	printf("1) Two-point form (you know two points on the line)\n");
	printf("2) Point-slope form (you know the line's slope and one point)\n");
	printf("=> ");

	int p;
	scanf("%d", &p);

	return p;	
}

void get2_pt(int *x1, int *y1, int *x2, int *y2) {
	printf("Enter the x-y coordinates of the first point separated by a space=> ");
	scanf("%d %d", x1, y1);
	printf("Enter the x-y coordinates of the second point separated by a space=> ");
	scanf("%d %d", x2, y2);
}

void get_pt_slope(double *slope, int *s_x1, int *s_x2) {
	printf("Enter the slope=> ");
	scanf("%lf", slope);
	printf("Enter the x-y coordinates of the point separated by a space=> ");
	scanf("%d %d", s_x1, s_x2);
}

void slope_intcpt_from2_pt(int x1, int y1, int x2, int y2, double *slope, double *yint) {
	slope = (double)(x2-x1)/(y2-y1);
	yint = y1 - (slope * x1 );
}

void intcpt_from_pt_slope(int x1, int y1, double *slope, double *yint) {

}