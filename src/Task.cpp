// task.cpp

// Definition (implementation) of task class

#include "./../inc/Task.hpp"

Task::Task(const std::string& desc) : description(desc), completed(false) {
	// empty 
}

std::string Task::getDescription() const {
	return description;
}

bool Task::getCompleted() const {
	return completed;
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

