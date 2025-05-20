// menu_handlers.hpp

#ifndef MENU_HANDLERS_HPP
#define MENU_HANDLERS_HPP

#include "program.hpp"
#include "Task.hpp"

void handleAddTask(std::vector<Task>& tasks);
void handleViewTasks(const std::vector<Task>& tasks);
void handleMarkTaskCompleted(std::vector<Task>& tasks);
void handleRemoveTask(std::vector<Task>& tasks);
// void handleSaveTasks(const std::vector<Task>& tasks);
// void handleLoadTasks(std::vector<Task>& tasks);

#endif
