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

void displayMenu() {
	std::cout << COLOR_CYAN << "---  To-Do List Menu  ---" << COLOR_RESET << std::endl;
	std::cout << "1. Add Task" << std::endl;
	std::cout << "2. Remove Task"<< std::endl;
	std::cout << "3. Mark Task as Completed" << std::endl;
	std::cout << "4. Mark Task as Not Complete" << std::endl;
	std::cout << "5. Edit Description" << std::endl;
	std::cout << "6. Sort Tasks" << std::endl;
	std::cout << "7. Save Tasks to File" << std::endl;
	std::cout << "8. Load Tasks from File" << std::endl;
	std::cout << "9. View Tasks" << std::endl;
	std::cout << "0. Exit" << std::endl;
	std::cout << COLOR_CYAN << "-------------------------" << COLOR_RESET << std::endl;
}

void displayTasks(const std::vector<Task>& taskList) {
	std::cout << COLOR_CYAN << "\n--- Current Task List ---\n" << COLOR_RESET;

	if (taskList.empty()) {
		std::cout << "No tasks yet!" << std::endl;
		return;
	}

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
}
