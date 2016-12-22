#include <stdio.h>

int main() {
	printf("Please enter the takeoff speed of the jet in km/hr > ");
	int takeoff_speed;
	scanf("%d", &takeoff_speed);
	printf("Please enter the catapult distance in meters > ");
	int cata_dist;
	scanf("%d", &cata_dist);
	double sec = 1.0/(takeoff_speed*1000)*cata_dist*3600*2;
	double acc = takeoff_speed/3.6/sec;
	printf("The jet would accelerate at %.2lf m/s^2 for %.2lf seconds.", acc, sec);
	return 0;
}