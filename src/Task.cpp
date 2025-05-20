// task.cpp

// Definition (implementation) of task class

#include "./../inc/Task.hpp"

Task::Task(const std::string& desc, const std::string& dueDateStr)
	: description(desc), completed(false), dueDate(dueDateStr) {
	// empty 
}

// getters
std::string Task::getDescription() const {
	return description;
}

bool Task::getCompleted() const {
	return completed;
}

std::string Task::getDueDate() const {
	return dueDate;
}

// setters
void Task::setDescription(const std::string& newDescription) {
	description = newDescription;
}

void Task::setComplete() {
	completed = true;
}

void Task::setIncomplete() {
	completed = false;
}

void Task::setDueDate(const std::string& newDueDate) {
	this->dueDate = newDueDate;
}
