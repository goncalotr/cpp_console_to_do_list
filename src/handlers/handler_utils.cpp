// handler_utils.cpp

#include "./../../inc/program.hpp"

void checkTasksExist(std::vector<Task>& tasks) {
	if (tasks.empty()) {
		std::cout << "No tasks to mark. Add some tasks first!\n";
		waitForEnter();
		return;
	}
}
