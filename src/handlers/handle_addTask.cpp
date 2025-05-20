// handle_addTask.cpp

#include "./../../inc/menu_handlers.hpp"

void handleAddTask(std::vector<Task>& tasks) {
	std::cout  << "Enter task description: ";
	std::string description;

	std::getline(std::cin, description);
	if (description.empty()) {
		std::cout << "Task description cannot be empty. \n";
	} else {
		Task newTask(description);
		tasks.push_back(newTask);
	}
	std::cout << "Task Added: \"" << description << "\"" << std::endl;
}
