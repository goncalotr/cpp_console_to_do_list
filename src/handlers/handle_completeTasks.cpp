// handle_completeTask.cpp

#include "./../../inc/menu_handlers.hpp"

void handleMarkTaskCompleted(std::vector<Task>& tasks) {

	// no tasks
	if (tasks.empty()) {
		std::cout << "No tasks to mark. Add some tasks first!\n";
		waitForEnter();
		return;
	}

	// task list
	std::cout << "\n--- Mark Task as Completed ---\n";
	displayTasks(tasks);

	// input operation number
	int taskNumber;
	std::cout << "Enter the number of the task to mark as completed (or 0 to cancel): ";
	std::cin >> taskNumber;
	if (std::cin.fail()) {
		std::cout << "Invalid input. Please enter a number. \n";
		std::cin.clear();
		std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
		waitForEnter();
		return;
	}
	std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

	if (taskNumber == 0) {
		std::cout << "Operation cancelled.\n";
		waitForEnter();
		return;
	}

	// validate option
	if (taskNumber > 0 && static_cast<size_t>(taskNumber) <= tasks.size()) {

		// non-const reference because the task will be modified
		Task& taskToMark = tasks[taskNumber - 1];

		if (taskToMark.getCompleted()) {
			std::cout << "Task \"" << taskToMark.getDescription() << "\" is already marked as completed. \n";
		} else {
			taskToMark.setComplete();
			std::cout << "Task \"" << taskToMark.getDescription() << "\" marked as completed! \n";
		}
	} else {
		std::cout << "Invalid task number. Please enter a number from the list. \n";
	}

	waitForEnter();
}
