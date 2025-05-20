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
				handleRemoveTask(tasks);
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