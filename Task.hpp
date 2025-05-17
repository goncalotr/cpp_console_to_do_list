// Declaration of Task Class

#ifndef TASK_HPP
#define TASK_HPP

#include <string>

class Task {
	public:
		// constructor
		Task(const std::string& desc) : description(desc), completed(false);
		
		// getters
		// const at end -> this method doesn't modify the object's state
		std::string getDescription() const {
			return description;
		} 

		bool isCompletedd() const {
			return completed;
		}

		void markComplete() {
			completed = true;
		}

		void markIncomplete() {
			completed = false;
		}

	private:
		std::string description;	// text of the task
		bool completed;				// true if task is done
};

#endif