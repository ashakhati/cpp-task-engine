#pragma once

#include "task.hpp"

#include <string>
#include <vector>

class TaskManager {
public:
    int addTask(const std::string& title, TaskPriority priority);
    bool completeTask(int id);
    void listTasks() const;

private:
    std::vector<Task> tasks_;
    int nextTaskId_{1};
};
