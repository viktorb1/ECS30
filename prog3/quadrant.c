#include <stdio.h>
#include <string.h>

int main() {
	printf("Please enter the x and y coordinates: ");
	double x, y;
	scanf("%lf %lf", &x, &y);

	char quad[10] = "";

	if (x == 0) {
		if (y == 0) {
			strcpy(quad, "the origin");
		} else {
			strcpy(quad, "on the y axis");
		}
	} else if (y == 0) {
		strcpy(quad, "on the x axis");
	}

	if (x > 0 && y > 0) {
		strcpy(quad, "in quadrant I");
	} else if (x < 0 && y > 0) {
		strcpy(quad, "in quadrant II");
	} else if (x < 0 && y < 0) {
		strcpy(quad, "in quadrant III");
	} else  if (x > 0 && y < 0) {
		strcpy(quad, "in quadrant IV");
	}

	printf("(%.1lf, %.1lf) is %s", x, y, quad);
	
	return 0;
}