#include <stdio.h>
#include <stdbool.h>

// little endian has LSB at lowest address
// use a (char *) pointer (1 byte) to examine the first byte
static bool is_little_endian() {
	int one = 1;
	char *ptr = (char *)&one;
	return (*ptr);
}

int main(int argc, char *argv[])
{
	const char *endianness = is_little_endian() ? "little" : "big";
	printf("%s endian\n", endianness);
}
