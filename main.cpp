
#include "program.hpp"

void displayMenu() {
	std::cout << std::endl << "--- To-Do List Menu ---"<< std::endl;
	std::cout << std::endl << "1. Add Task"<< std::endl;
	std::cout << std::endl << "2. View Tasks"<< std::endl;
	std::cout << std::endl << "3. Mark Task as Completed"<< std::endl;
	std::cout << std::endl << "4. Remove Task"<< std::endl;
	std::cout << std::endl << "5. Save Tasks to File"<< std::endl;
	std::cout << std::endl << "6. Load Tasks to File Task"<< std::endl;
	std::cout << std::endl << "0. Exit" << std::endl;
	std::cout << std::endl << "Enter your choice: ";
}

int main (int argc, char** argv) {

	(void) argc;
	(void) argv;

	std::vector<Task> tasks;

	int choice;

	do {
		std::system("clear");
		displayMenu();
		std::cin >> choice;
		if (std::cin.fail()) {
			std::cout << "Invalid input. Please enter a number. \n";
			std::cin.clear(); // clear error flags
			std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
			choice = -1;
			continue;
		}
		std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

		switch (choice) {
			case 1: {
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
				break;
			}
			case 2:
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
					}
				}

				std::cout  << " ------------------ " << std::endl;
				waitForEnter();
				break;

			case 3:
				std::cout  << "Marking tasks as completed" << std::endl;
				loadingAnimation(2000);
				waitForEnter();
				break;

			case 4:
				std::cout  << "Removing task..." << std::endl;
				loadingAnimation(2000);
				waitForEnter();
				break;

			case 5:
				std::cout << "Saving tasks..." << std::endl;
				break;

			case 6:
				std::cout << "Loading tasks..." << std::endl;
				break;

			case 0:
				std::cout << "Exiting program." << std::endl;
				break;

			default:
				std::cout << "Invalid choice. Please try again." << std::endl;

		}
	} while (choice != 0);

	return 0;
}