#pragma once

#include <string>

enum class TaskStatus {
    Todo,
    InProgress,
    Completed
};

enum class TaskPriority {
    Low,
    Medium,
    High
};

struct Task {
    int id;
    std::string title;
    TaskStatus status{TaskStatus::Todo};
    TaskPriority priority{TaskPriority::Medium};
};
