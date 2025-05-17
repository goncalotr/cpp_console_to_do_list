
#include "program.hpp"

void delay(int ms) {
	clock_t end_time = clock() + ms * CLOCKS_PER_SEC / 1000;
	while (clock () < end_time) {
		// wait
	}
}
