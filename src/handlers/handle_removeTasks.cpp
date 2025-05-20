// handle_removeTasks.cpp

#include "./../../inc/menu_handlers.hpp"

void handleRemoveTask(std::vector<Task>& tasks) {
	// no tasks
	if (tasks.empty()) {
		std::cout << "No tasks to remove. Add some tasks first!\n";
		waitForEnter();
		return;
	}

	// task list
	std::cout << "\n--- Select Task to Remove ---\n";
	displayTasks(tasks);

	// input operation number
	int taskNumber;
	std::cout << "Enter the number of the task to remove (or 0 to cancel): ";
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

	if (taskNumber > 0 && static_cast<size_t>(taskNumber) <= tasks.size()) {
		size_t indexToRemove = static_cast<size_t>(taskNumber - 1);
		std::string removedTaskDescription = tasks[indexToRemove].getDescription();
		tasks.erase(tasks.begin() + indexToRemove);

		std::cout << "Task \"" << removedTaskDescription << "\" removed successfully!\n";
	} else {
		std::cout << "Invalid task number. No task removed. \n";
	}

	waitForEnter();
}
