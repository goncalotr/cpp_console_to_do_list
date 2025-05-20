// main.cpp

#include "./../inc/program.hpp"

void displayMenu() {
	std::cout << std::endl << "--- To-Do List Menu ---"<< std::endl;
	std::cout << std::endl << "1. Add Task"<< std::endl;
	std::cout << std::endl << "2. View Tasks"<< std::endl;
	std::cout << std::endl << "3. Mark Task as Completed"<< std::endl;
	std::cout << std::endl << "4. Remove Task"<< std::endl;
	std::cout << std::endl << "5. Save Tasks to File"<< std::endl;
	std::cout << std::endl << "6. Load Tasks to File Task"<< std::endl;
	std::cout << std::endl << "0. Exit" << std::endl;
	std::cout << std::endl << "--- Menu End ---"<< std::endl << std::endl;
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

		int taskNumber;
		switch (choice) {
			case 1: {
				handleAddTask(tasks);
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

				// no tasks
				if (tasks.empty()) {
					std::cout << "No tasks to mark. Add some tasks first!\n";
					waitForEnter();
					break;
				}

				// task list
				std::cout << "\n--- Mark Task as Completed ---\n";
				displayTasks(tasks);

				// input operation number
				//int taskNumber;
				std::cout << "Enter the number of the task to mark as completed (or 0 to cancel): ";
				std::cin >> taskNumber;
				if (std::cin.fail()) {
					std::cout << "Invalid input. Please enter a number. \n";
					std::cin.clear();
					std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
					waitForEnter();
					break;
				}
				std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

				if (taskNumber == 0) {
					std::cout << "Operation cancelled.\n";
					waitForEnter();
					break;
				}

				// validate option
				if (taskNumber > 0 && static_cast<size_t>(taskNumber) <= tasks.size()) {

					// non-const reference because the task will be modified
					Task& taskToMark = tasks[taskNumber - 1];

					if (taskToMark.getCompleted()) {
						std::cout << "Task \"" << taskToMark.getDescription() << "\" is already marked as completed. \n";
					} else {
						taskToMark.setComplete();
						std::cout << "Task \"" << taskToMark.getDescription() << "\" marked as completed! \n";
					}
				} else {
					std::cout << "Invalid task number. Please enter a number from the list. \n";
				}

				waitForEnter();
				break;

			case 4:

				// no tasks
				if (tasks.empty()) {
					std::cout << "No tasks to remove. Add some tasks first!\n";
					waitForEnter();
					break;
				}

				// task list
				std::cout << "\n--- Select Task to Remove ---\n";
				displayTasks(tasks);

				// input operation number
				//int taskNumber;
				std::cout << "Enter the number of the task to remove (or 0 to cancel): ";
				std::cin >> taskNumber;
				if (std::cin.fail()) {
					std::cout << "Invalid input. Please enter a number. \n";
					std::cin.clear();
					std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
					waitForEnter();
					break;
				}
				std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

				if (taskNumber == 0) {
					std::cout << "Operation cancelled.\n";
					waitForEnter();
					break;
				}

				if (taskNumber > 0 && static_cast<size_t>(taskNumber) <= tasks.size()) {
					size_t indexToRemove = static_cast<size_t>(taskNumber - 1);
					std::string removedTaskDescription = tasks[indexToRemove].getDescription();
					tasks.erase(tasks.begin() + indexToRemove);

					std::cout << "Task \"" << removedTaskDescription << "\" removed successfully!\n";
				} else {
					std::cout << "Invalid task number. No task removed. \n";
				}

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