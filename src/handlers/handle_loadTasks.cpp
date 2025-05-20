// handle_loadTasks

#include "./../../inc/menu_handlers.hpp"

void handleLoadTasks(std::vector<Task>& tasks, const std::string& filename) {

	// open file
	std::ifstream inFile(filename.c_str());
	if (!inFile.is_open()) {
		std::cerr << "Error: Could not open file '" << filename << "' for loading." << std::endl;
		waitForEnter();
		return;
	}

	// clear existing tasks
	tasks.clear();

	// read lines from file
	std::string line;
	while (std::getline(inFile, line)) {
		if(line.empty()) {
			continue;
		}

		size_t delimiterPos = line.find('|');
		if (delimiterPos == std::string::npos) {
			std::cerr << "Warning: Missing '|': " << line << std::endl;
			continue;
		}

		std::string statusStr = line.substr(0, delimiterPos);
		std::string description = line.substr(delimiterPos + 1);

		if (description.empty() && statusStr.length() + 1 == line.length()) {
			std::cerr << "Warning: Description empty in line: " << line << std::endl;
		} else if (description.empty()) {
			std::cerr << "Warning: Description empty in line: " << line << " Note: there is more content in the line." << std::endl;
		}

		// convert status string to boolean and create task
		bool completed = false;
		if (statusStr == "1") {
			completed = true;
		} else if (statusStr != "0") {
			std::cerr << "Warning: Error in status: " << statusStr << " for task '" << description << "'. Assuming not completed." << std::endl;
		}

		// create and add the task
		tasks.push_back(description);
		if (completed) {
			tasks.back().setComplete();
		}
	}

	inFile.close();
	std::cout << "Tasks loaded successfully from '" << filename << "'.\n";
	waitForEnter();
}
