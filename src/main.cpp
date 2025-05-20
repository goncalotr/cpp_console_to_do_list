// main.cpp

#include "./../inc/program.hpp"

const std::string FILENAME = "tasks.txt";

int main (int argc, char** argv) {

	(void) argc;
	(void) argv;

	std::vector<Task> tasks;

	int choice;

	do {
		std::system("clear");
		displayTasks(tasks);
		displayMenu();
		std::cout << std::endl << "Enter your choice: ";
		std::cin >> choice;

		// check for eof
		if (std::cin.eof()) {
			std::cout << "\nEOF detected. Exiting program..." << std::endl;
			break;
		}

		// verify input
		if (std::cin.fail()) {
			std::cout << "Invalid input. Please enter a number. \n";
			std::cin.clear(); // clear error flags
			std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
			choice = -1;
			continue;
		}
		std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

		// select option
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

			// mark not completed
			case 4:
				handleMarkTaskNotCompleted(tasks);
				break;

			// remove tasks
			case 5:
				handleRemoveTask(tasks);
				break;

			// save tasks
			case 6:
				handleSaveTasks(tasks, FILENAME);
				break;

			// load tasks
			case 7:
				handleLoadTasks(tasks, FILENAME);
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