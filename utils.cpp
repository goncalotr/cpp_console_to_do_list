
#include "program.hpp"

void delay(int ms) {
	clock_t end_time = clock() + ms * CLOCKS_PER_SEC / 1000;
	while (clock() < end_time) {
		// wait
	}
}

void loadingAnimation(int duration_ms) {
	const char spinner[] = "|/-\\";
	int spinnerLength = sizeof(spinner) - 1;
	int steps = duration_ms / 100;

	for (int i =0; i < steps; i++) {
		std::cout << "\rLoading " << spinner[i % spinnerLength] << std::flush;
		delay(100);
	}
	std::cout << "\r Loading Ended!" << std::endl;
}
