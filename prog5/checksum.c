#include <stdio.h>
#include <stdlib.h>

int main() {
	printf("Line: ");
	int sum = 0;
	int i = getchar();
	
	if (i == '.')
		return EXIT_SUCCESS;

	while(i != '\n') {

		sum += i;

		sum = sum % 64;
		i = getchar();
	}

	sum += ' ';

	printf("Checksum: %c", sum);
	return EXIT_SUCCESS;
}