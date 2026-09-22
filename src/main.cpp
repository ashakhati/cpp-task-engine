#include "task_manager.hpp"

#include <iostream>

int main() {
    TaskManager taskManager;

    const int firstTaskId =
        taskManager.addTask("Create CMake project structure", TaskPriority::High);

    taskManager.addTask("Implement TaskManager class", TaskPriority::High);
    taskManager.addTask("Read about std::vector and enum class", TaskPriority::Medium);
    taskManager.addTask("Push Day 2 changes to GitHub", TaskPriority::Low);

    std::cout << "Tasks before completion:\n";
    taskManager.listTasks();

    std::cout << "\nCompleting task " << firstTaskId << "...\n";

    if (!taskManager.completeTask(firstTaskId)) {
        std::cerr << "Task was not found.\n";
        return 1;
    }

    std::cout << "\nTasks after completion:\n";
    taskManager.listTasks();

    return 0;
}
