#include "task_manager.hpp"

#include <iostream>

namespace {

std::string toString(TaskStatus status) {
    switch (status) {
        case TaskStatus::Todo:
            return "Todo";
        case TaskStatus::InProgress:
            return "In Progress";
        case TaskStatus::Completed:
            return "Completed";
    }

    return "Unknown";
}

std::string toString(TaskPriority priority) {
    switch (priority) {
        case TaskPriority::Low:
            return "Low";
        case TaskPriority::Medium:
            return "Medium";
        case TaskPriority::High:
            return "High";
    }

    return "Unknown";
}

} // namespace

int TaskManager::addTask(const std::string& title, TaskPriority priority) {
    Task task{
        .id = nextTaskId_++,
        .title = title,
        .status = TaskStatus::Todo,
        .priority = priority
    };

    tasks_.push_back(task);

    return task.id;
}

bool TaskManager::completeTask(int id) {
    for (Task& task : tasks_) {
        if (task.id == id) {
            task.status = TaskStatus::Completed;
            return true;
        }
    }

    return false;
}

void TaskManager::listTasks() const {
    if (tasks_.empty()) {
        std::cout << "No tasks available.\n";
        return;
    }

    for (const Task& task : tasks_) {
        std::cout
            << "[" << task.id << "] "
            << task.title
            << " | Status: " << toString(task.status)
            << " | Priority: " << toString(task.priority)
            << '\n';
    }
}
