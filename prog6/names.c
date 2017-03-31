#include <stdio.h>

int main(int argc, char** argv) {
	FILE *fp = fopen(argv[1], "r");
	return 0;
}

read_names();
sort();
write_names();
free_memory();