#include <stdio.h>
#include <math.h>

int main() {
	printf("Please enter the length and width of the yard > ");
	int yardl, yardw;
	scanf("%d %d", &yardl, &yardw);
	printf("Please enter the length and width of the house > ");
	int housel, housew;
	scanf("%d %d", &housel, &housew);

	int sqft = (yardl*yardw) - (housel*housew);
	double time = (double)sqft/2/60;
	int min = (int)time;
	int sec = round((time - min)*60);

	printf("%d square feet will take %d minutes and %d seconds to cut.\n", sqft, min, sec);
	
	return 0;
}