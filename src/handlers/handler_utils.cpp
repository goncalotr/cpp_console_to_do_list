// handler_utils.cpp

#include "./../../inc/program.hpp"

bool checkTaskListEmpty(std::vector<Task>& tasks, const std::string& operationName) {
	if (tasks.empty()) {
		std::cout << "No tasks to " << operationName << ". Add some tasks first!\n";
		waitForEnter();
		return false;
	}

	return true;
}
