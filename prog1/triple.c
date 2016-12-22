#include <stdio.h>
#include <math.h>

int main() {
	printf("Please enter two integers with the first larger than the second > ");
	int m, n;
	scanf("%d %d", &m, &n);

	int s1 = pow(m, 2) - pow(n, 2);
	int s2 = 2*m*n;
	int hyp = pow(m, 2) + pow(n, 2);

	printf("The Pythagorean triple of %d and %d is %d, %d, and %d.", m, n, s1, s2, hyp);
	return 0;
}