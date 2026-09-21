#include <algorithm>
#include <iostream>
#include <ranges>
#include <string>
#include <vector>

enum class TaskStatus {
    Pending,
    Completed
};

struct Task {
    int id{};
    std::string title;
    TaskStatus status{TaskStatus::Pending};
};

std::string statusToString(TaskStatus status) {
    return status == TaskStatus::Completed ? "Completed" : "Pending";
}

void showTasks(const std::vector<Task>& tasks) {
    if (tasks.empty()) {
        std::cout << "\nNo tasks available.\n";
        return;
    }

    std::cout << "\n=== Your Tasks ===\n";

    std::ranges::for_each(tasks, [](const Task& task) {
        std::cout << task.id
                  << ". [" << statusToString(task.status) << "] "
                  << task.title << '\n';
    });
}

int main() {
    std::vector<Task> tasks;
    int nextTaskId{1};
    int choice{0};

    while (choice != 3) {
        std::cout << "\n=== C++20 Task Engine ===\n";
        std::cout << "1. Add task\n";
        std::cout << "2. View tasks\n";
        std::cout << "3. Exit\n";
        std::cout << "Choose an option: ";

        std::cin >> choice;
        std::cin.ignore();

        switch (choice) {
            case 1: {
                std::string title;

                std::cout << "Enter task title: ";
                std::getline(std::cin, title);

                tasks.push_back({
                    .id = nextTaskId++,
                    .title = title,
                    .status = TaskStatus::Pending
                });

                std::cout << "Task added successfully.\n";
                break;
            }

            case 2:
                showTasks(tasks);
                break;

            case 3:
                std::cout << "Goodbye!\n";
                break;

            default:
                std::cout << "Invalid option. Choose 1, 2, or 3.\n";
                break;
        }
    }

    return 0;
}
