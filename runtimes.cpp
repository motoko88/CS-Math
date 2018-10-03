/**
 * @author Cameron Brenke
 * @date 2018.10.03
 *
 * You can use and modify this code in anyway. However, if you use it on your website, job, or at
 * school all I ask is you give me credit, by at the very least including the link to this file
 * in the header of your program.
 */

#include <iostream>
#include <cmath>

/**
 * Computes a log using a different base.
 *
 * @param  b New Base
 * @param  x Number to take log of.
 */
float log_b(float b, float x) {
	return log(x) / log(b);
}

/**
 * Computes the number of times a loop runs.
 *
 * @param N     Input Size
 * @param start Value at which i starts.
 */
void expcounter(unsigned long N, unsigned long start) {
	int count = 0;
	for (unsigned long i = start; i < N; i*=i) {
		// printf("i=%lu\n", i); // Uncomment here to see the current i value.
		count++;
	}
	std::cout << count << " | ";
}

int main(int argc, char const *argv[]) {
	if (argc != 2) {
		printf("Usage: %s <N>\n", argv[0]);
		return 1;
	}

	unsigned long N = atoi(argv[1]);
	int max = 10;

	for (int i = 2; i < max; i++) {
		for (int j = 1; j < 8; j++) {
			if (N > 0) {
				std::cout << i << " | ";
				std::cout << pow(N, j) << " | ";
				expcounter(pow(N, j), i);
				std::cout << ceil(log_b(2, log_b(i, pow(N, j)))) << "\n";
			}
		}
		std::cout << "\n";
		N = atoi(argv[1]);
	}

	return 0;
}