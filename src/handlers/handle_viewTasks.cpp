// handle_viewTasks.cpp

#include "./../../inc/menu_handlers.hpp"

void handleViewTasks(const std::vector<Task>& tasks) {
	std::cout  << " --- Your Tasks --- " << std::endl;
	loadingAnimation(500);

	if (tasks.empty()) {
		std::cout << "No tasks yet!" << std::endl;
	} else {

		for (size_t i = 0; i < tasks.size(); ++i) {
			// getting reference to task to not copy it
			// const because we are only reading not changing
			const Task& currentTask = tasks[i];
			std::cout << (i + 1) << ". ";

			if (currentTask.getCompleted()) { 
				std::cout << "✅ ";
			} else {
				std::cout << "❌ ";
			}

			std::cout << currentTask.getDescription() << std::endl;

			if (!currentTask.getDueDate().empty()) {
				std::cout << " (Due: " << currentTask.getDueDate() << ")";
			}
			std::cout << std::endl;
		}
	}

	std::cout << " ------------------ " << std::endl;
	waitForEnter();
}
