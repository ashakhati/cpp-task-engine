# Task Engine

A small command-line task-management application written in modern C++20.

This project is being developed incrementally to practise modern C++ concepts, clean project structure, CMake builds, Git, and testable software design.

## Current Features

- Create tasks with automatically generated IDs
- Assign task priorities: Low, Medium, or High
- Track task status: Todo, In Progress, or Completed
- Store tasks in memory using `std::vector`
- List all tasks in the terminal
- Mark a task as completed
- Build the project with CMake

## Project Structure

```text
task-engine/
├── CMakeLists.txt
├── README.md
├── include/
│   ├── task.hpp
│   └── task_manager.hpp
└── src/
    ├── main.cpp
    └── task_manager.cpp
```

## Requirements

- C++20-compatible compiler
  - GCC 10 or newer
  - Clang 12 or newer
- CMake 3.20 or newer
- Git, optional but recommended

## Build and Run

From the project root directory, run:

```bash
cmake -S . -B build
cmake --build build
./build/task_engine
```

On Windows, the executable may be:

```powershell
.\build\task_engine.exe
```

## Example Output

```text
Tasks before completion:
[1] Create CMake project structure | Status: Todo | Priority: High
[2] Implement TaskManager class | Status: Todo | Priority: High
[3] Read about std::vector and enum class | Status: Todo | Priority: Medium
[4] Push Day 2 changes to GitHub | Status: Todo | Priority: Low

Completing task 1...

Tasks after completion:
[1] Create CMake project structure | Status: Completed | Priority: High
[2] Implement TaskManager class | Status: Todo | Priority: High
[3] Read about std::vector and enum class | Status: Todo | Priority: Medium
[4] Push Day 2 changes to GitHub | Status: Todo | Priority: Low
```

## C++ Concepts Used

- **C++20**
- `struct` for the `Task` data model
- `enum class` for type-safe task status and priority values
- Classes and encapsulation through `TaskManager`
- STL container: `std::vector`
- References and const-correctness
- Range-based `for` loops
- Brace initialization
- C++20 designated initializers
- Header and source file separation
- Internal helper functions with an anonymous namespace

## Design

The project separates responsibilities into three areas:

- `Task` represents task data: ID, title, status, and priority.
- `TaskManager` owns the in-memory task collection and provides operations to add, complete, and list tasks.
- `main.cpp` demonstrates how the application uses `TaskManager`.

This separation keeps the code easier to maintain and provides a foundation for later additions such as an interactive menu, filtering, persistence, tests, and concurrent task processing.

## Future Improvements

- Interactive command-line menu
- Add tasks from user input
- Delete and edit tasks
- Filter tasks by status and priority
- Search tasks by title
- Save and load tasks from a file
- Unit tests with CTest or GoogleTest
- Error handling and input validation
- Thread-safe task queue
- Background task execution using `std::thread`
- CI workflow using GitHub Actions

## Author

Asha Khati

Senior software engineer with experience in C++, Linux, embedded systems, telecommunications, automation, and modern DevOps/cloud technologies.
