
#include <program.hpp>

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
		displayMenu();
		std::cin >> choice;
	}
}