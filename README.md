# C++ Console To-Do List Manager

A simple, console-based To-Do List application written in C++ as a learning project.
This application allows users to manage their tasks directly from the command line.

<p align="center">
	<src=https://github.com/goncalotr/cpp_console_to_do_list/blob/main/Screenshot.png>
</p>

## Features
- **Add Tasks:** Create new tasks with a description and an optional due date.
- **View Tasks:** Display all current tasks, including their status (completed/incomplete), description, and due date.
- **Mark Tasks as Completed:** Toggle the completion status of tasks.
- **Edit Task Descriptions:** Modify the text of existing tasks.
- **Remove Tasks:** Delete tasks from the list.
- **Sort Tasks:**
	- By description (A-Z or Z-A).
	- By completion status (incomplete tasks first).
- **Persistent Storage:**
	- Save the current list of tasks to a file (`tasks.txt` by default).
	- Load tasks from the file when the application starts or via a menu option.

## Getting Started

### Build

1. Clone the repository

	``` bash
	git clone git@github.com:goncalotr/cpp_console_to_do_list.git
	```

2. Navigate to the project's root directory in your terminal.

	```bash
	cd cpp_console_to_do_list
	```

3. Run the `make` command:

	```bash
	make
	```

4. To clean the build files:
	```bash
	make clean  # Removes object files
	make fclean # Removes object files and the executable
	```


### Running

5. After building, run the executable:

	```bash
	./todo_list
	```
