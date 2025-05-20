// handle_sortTasks.cpp

#include "./../../inc/menu_handlers.hpp"

// A-Z
bool compareTasksByDescriptionAsc(const Task& a, const Task& b) {
	return a.getDescription() < b.getDescription();
}

// Z-A
bool compareTasksByDescriptionDesc(const Task& a, const Task& b) {
	return a.getDescription() > b.getDescription();
}

// Incomplete first
bool compareTasksByCompletion(const Task& a, const Task& b) {
	if (!a.getCompleted() && b.getCompleted()) {
		return true;
	}

	// b is not complete and comes first
	if (a.getCompleted() && !b.getCompleted()) {
		return false;
	}

	return (a.getDescription() < b.getDescription());
}

void handleSortTasks(std::vector<Task>& tasks) {

	if (!checkTaskListEmpty(tasks, "sort")) {
		return;
	}

	std::cout << "\n--- Sort Tasks ---\n";
	std::cout << "1. By Description (A-Z)\n";
	std::cout << "2. By Description (Z-A)\n";
	std::cout << "3. By Completion Status (Incomplete first)\n";
	std::cout << "0. Cancel\n";
	std::cout << "Enter sort choice: ";

	int sortChoice;
	std::cin >> sortChoice;
	if (std::cin.fail()) {
		std::cout << "Invalid input. Please enter a number.\n";
		std::cin.clear();
		std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
		waitForEnter();
		return;
	}
	std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

	switch (sortChoice) {
		case 1:
			std::sort(tasks.begin(), tasks.end(), compareTasksByDescriptionAsc);
			std::cout << "Tasks sorted by description (A-Z).\n";
			break;

		case 2:
			std::sort(tasks.begin(), tasks.end(), compareTasksByDescriptionDesc);
			std::cout << "Tasks sorted by description (Z-A).\n";
			break;

		case 3:
			std::sort(tasks.begin(), tasks.end(), compareTasksByCompletion);
			std::cout << "Tasks sorted by completion status (incomplete first).\n";
			break;

		case 0:
			std::cout << "Sort operation cancelled.\n";
			return;

		default:
			std::cout << "Invalid sort choice.\n";
			return;
	}

	waitForEnter();
}
