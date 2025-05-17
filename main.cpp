
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

	int choice;

	do {
		std::system("clear");
		displayMenu();
		std::cin >> choice;
		std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

		switch (choice) {
			case 1:
				std::cout  << "Adding a new task..." << std::endl;
				delay(3000);
				break;

			case 2:
				std::cout  << "Viewing tasks" << std::endl;
				loadingAnimation(3000);
				waitForEnter();
				break;

			case 3:
				std::cout  << "Marking tasks as completed" << std::endl;
				break;

			case 4:
				std::cout  << "Removing task..." << std::endl;
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