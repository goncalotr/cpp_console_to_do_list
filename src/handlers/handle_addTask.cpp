// handle_addTask.cpp

#include "./../../inc/menu_handlers.hpp"

void handleAddTask(std::vector<Task>& tasks) {
	std::cout  << "Enter task description: ";
	std::string description;
	std::getline(std::cin, description);
	if (description.empty()) {
		std::cout << "Task description cannot be empty. \n";
		return;
	}
	
	std::cout << "Enter due date (e.g., YYYY-MM-DD, or leave blank): ";
	std::string dueDate;
	std::getline(std::cin, dueDate);

	Task newTask(description, dueDate);
	tasks.push_back(newTask);

	std::cout << "Task Added: \"" << description << "\"";
	if (!dueDate.empty()) {
		std::cout << " (Due: " << dueDate << ")";
	}
	std::cout << std::endl;
}
