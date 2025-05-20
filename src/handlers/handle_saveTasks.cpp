// handle_saveTasks.cpp

#include "./../../inc/menu_handlers.hpp"

void handleSaveTasks(const std::vector<Task>& tasks, const std::string& filename) {

	// create output file
	std::ofstream outFile(filename.c_str());

	// open file
	if (!outFile.is_open()) {
		std::cerr << "Error: Could not open file '" << filename << "' for saving." << std::endl;
		waitForEnter();
		return;
	}

	// loop through tasks and write each one
	for (size_t i = 0; i < tasks.size(); ++i) {

		// const reference at index i
		const Task& current_task_element  = tasks[i];

		bool completed = current_task_element.getCompleted();
		std::string description = current_task_element.getDescription();
		outFile << (completed ? '1' : '0') << "|" << description << '\n';
	}

	// close file
	outFile.close();
	std::cout << "Tasks saved successfully to '" << filename << "'\n";
	waitForEnter();
}
