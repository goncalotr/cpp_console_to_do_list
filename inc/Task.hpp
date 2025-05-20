// Declaration of Task Class

#ifndef TASK_HPP
#define TASK_HPP

#include <string>

class Task {
	public:
		// Constructor declaration
		Task(const std::string& desc, const std::string& dueDate = "");

		// Method declarations - getters
		// const at end -> this method doesn't modify the object's state
		std::string getDescription() const;
		bool getCompleted() const;
		std::string getDueDate() const;

		// Method declarations - setters
		void setDescription(const std::string& newDescription);
		void setComplete();
		void setIncomplete();
		void setDueDate(const std::string& newDueDate);

	private:
		// Member variables
		std::string description;	// text of the task
		bool completed;				// true if task is done
		std::string dueDate;
};

#endif