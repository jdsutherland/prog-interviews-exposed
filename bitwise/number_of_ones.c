#include <assert.h>

static int count_one_bits(int n) {
	int count = 0;
	for (; n; n = (unsigned int)n >> 1) {
		if (n & 1) {
			count++;
		}
	}
	return count;
}

int main() {
	assert(count_one_bits(5) == 2);
	assert(count_one_bits(0) == 0);
	assert(count_one_bits(1) == 1);
	assert(count_one_bits(-1) == 32);
}
