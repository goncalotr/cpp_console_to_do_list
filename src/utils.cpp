// utils.cpp

#include "./../inc/program.hpp"

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
	std::cout << "\r                 \r" << std::endl; // adjust spaces to the max length of loading X
}

void waitForEnter() {
	//std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
	std::cout << std::endl << "Press Enter to continue...";
	std::cin.get();
}

int clearConsole() {
	#ifdef _WIN32
		system("cls");
	#else
		system("clear");
	#endif
	return 0;
}

void displayTasks(const std::vector<Task>& taskList) {
	std::cout << "\n--- Current Task List ---\n";

	for (size_t i = 0; i < taskList.size(); ++i) {
		const Task currentTask = taskList[i];
		std::cout << (i + 1) << ". ";
		if (currentTask.getCompleted()) {
			std::cout << "✅ ";
		} else {
			std::cout << "❌ ";
		}
		std::cout << currentTask.getDescription() << std::endl;
	}

	std::cout << "\n-------------------------\n";
}
