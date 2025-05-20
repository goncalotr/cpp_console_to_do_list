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

			// add task
			case 1:
				handleAddTask(tasks);
				break;

			// view tasks
			case 2:
				handleViewTasks(tasks);
				break;

			// mark completed
			case 3:
				handleMarkTaskCompleted(tasks);
				break;

			// remove tasks
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

			// save tasks
			case 5:
				std::cout << "Saving tasks..." << std::endl;
				break;

			// load tasks
			case 6:
				std::cout << "Loading tasks..." << std::endl;
				break;

			// exit program
			case 0:
				std::cout << "Exiting program." << std::endl;
				break;

			// option not valid
			default:
				std::cout << "Invalid choice. Please try again." << std::endl;

		}
	} while (choice != 0);

	return 0;
}