#include <stdio.h>
#include <math.h>

void display_instructions(char choice1, char choice2, char ismanual, double total);
double calc_baking_time(char choice1, char choice2, char ismanual);

int main() {
	printf("Are you making white or sweet bread (w or s)? ");
	char choice1, choice2, ismanual;
	scanf("%c", &choice1);
	getchar();

	printf("Is this a single or double loaf (s or d)? ");
	scanf("%c", &choice2);
	getchar();

	printf("Are you going to bake manually (y or n)? ");
	scanf("%c", &ismanual);
	getchar();

	double t = calc_baking_time(choice1, choice2, ismanual);
	display_instructions(choice1, choice2, ismanual, t);

	return 0;
}

void display_instructions(char choice1, char choice2, char ismanual, double total) {
	int pk, pr, sk, sr, ls, fr, b_min, b_sec, c;

	if (choice1 == 'w' || choice1 == 'W') {
		pk = 15, pr = 60, sk = 18, sr = 20, ls = 2, fr = 75, b_min = 45, b_sec = 0, c = 30;
	} else {
		pk = 20, pr = 60, sk = 33, sr = 30, ls = 2, fr = 75, b_min = 35, b_sec = 0, c = 30;
	}

	if (choice2 == 'd' || choice2 == 'D') {
		int b = b_min*1.5;
		b_sec = (b_min*1.5 - b)*60;
		b_min = b_min*1.5;
	}

	printf("Primary kneading: %d minutes\n", pk);
	printf("Primary rising: %d minutes\n", pr);
	printf("Secondary kneading: %d minutes\n", sk);
	printf("Secondary rising: %d minutes\n", sr);
	printf("Loaf shaping: %d seconds\n", ls);

	if (ismanual == 'n' || ismanual == 'N') {
		printf("Final rising: %d minutes\n", fr);
		printf("Baking: %d minutes %d seconds\n", b_min, b_sec);
		printf("Cooling: %d minutes\n", c);
	} else {
		printf("You should remove the dough for manual baking.\n");
	}

	int t = total;
	int t_sec = round((total - t)*60);
	printf("\nFor a total baking time of %d minutes and %d seconds.", t, t_sec);
}

double calc_baking_time(char choice1, char choice2, char ismanual) {
	double total = 0, b_min = 0;

	if (choice1 == 'w' || choice1 == 'W') {
		total = 15 + 60 + 18 + 20 + 2/60.0;
		b_min = 45;
	} else {
		total = 20 + 60 + 33 + 30 + 2/60.0;
		b_min = 35;
	}

	if (ismanual == 'n' || ismanual == 'N') {
		if (choice2 == 'd' || choice2 == 'D') {
			b_min = b_min*1.5;
		}
		total += 75 + 30 + b_min;
	}

	return total;
}