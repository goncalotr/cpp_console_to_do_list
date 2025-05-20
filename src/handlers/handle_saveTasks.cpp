// handle_saveTasks.hpp

#include "./../../inc/menu_handlers.hpp"

void handleSaveTasks(const std::vector<Task>& tasks, const std::string& filename) {

	// create output file
	std::ofstream outFile(filename);

	// open file
	if (!outFile.is_open()) {
		std::cerr << "Error: Could not open file '" << filename << "' for saving." << std::endl;
		waitForEnter();
		return;
	}

	// loop through tasks and write each one
	for (const Task& task : tasks) {
		bool completed = task.getCompleted();
		std::string description = task.getDescription();
		outFile << (completed ? '1' : '0') << "|" << description << '\n';
	}

	// close file
	outFile.close();
	std::cout << "Tasks saved successfully to '" << filename << "'\n";
	waitForEnter();
}
