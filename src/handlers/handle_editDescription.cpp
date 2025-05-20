// handle_editDescription.cpp

#include "./../../inc/menu_handlers.hpp"

void handleEditDescription(std::vector<Task>& tasks) {

	// no tasks
	if (tasks.empty()) {
		std::cout << "No tasks to mark. Add some tasks first!\n";
		waitForEnter();
		return;
	}

	std::cout << "\n--- Edit Task Description ---\n";

	int taskNumber;
	std::cout << "Enter the number of the task to edit (or 0 to cancel): ";
	std::cin >> taskNumber;
	if (std::cin.fail()) {
		std::cout << "Invalid input. Please enter a number.\n";
		std::cin.clear();
		std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
		waitForEnter();
		return;
	}
	std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

	if (taskNumber == 0) {
		std::cout << "Edit operation cancelled.\n";
		return;
	}

	if (taskNumber > 0 && static_cast<size_t>(taskNumber) <= tasks.size()) {
		Task& taskToEdit = tasks[taskNumber - 1];

		std::cout << "Current description: " << taskToEdit.getDescription() << std::endl;
		std::cout << "Enter new description: ";
		std::string newDescription;
		std::getline(std::cin, newDescription);

		if (newDescription.empty()) {
			std::cout << "New description cannot be empty. Task not changed.\n";
		} else {
			taskToEdit.setDescription(newDescription);
			std::cout << "Task description updated successfully!\n";
		}

	} else {
		std::cout << "Invalid task number. No task edited.\n";
	}
	waitForEnter();
}
