
#ifndef PROGRAM_H
#define PROGRAM_H

// --- Includes ---
#include <iostream>		// console input and output
#include <string>		// string data type
#include <vector>		// dynamic arrays (vectors)
#include <cstdlib>		// system() _WIN32

//#include <chrono>		// time c++11
//#include <thread>		// time c++11
#include <ctime>
#include <limits>

#include <algorithm> // For std::sort

#include "Task.hpp"
#include "menu_handlers.hpp"

// --- Macros ---

// Text color
#define COLOR_BLACK   "\033[30m"
#define COLOR_RED     "\033[31m"
#define COLOR_GREEN   "\033[32m"
#define COLOR_YELLOW  "\033[33m"
#define COLOR_BLUE    "\033[34m"
#define COLOR_MAGENTA "\033[35m"
#define COLOR_CYAN    "\033[36m"
#define COLOR_WHITE   "\033[37m"

// Text style
#define COLOR_BOLD    "\033[1m"
#define COLOR_UNDERLINE "\033[4m"

// Reset style
#define COLOR_RESET   "\033[0m"

// --- Functions ---

// Handler Utils
bool checkTaskListEmpty(std::vector<Task>& tasks, const std::string& operationName);

// Utils
void		delay(int ms);
void		loadingAnimation(int duration_ms);
void		waitForEnter();
int			clearConsole();
void 		displayMenu();
void		displayTasks(const std::vector<Task>& taskList);

#endif
