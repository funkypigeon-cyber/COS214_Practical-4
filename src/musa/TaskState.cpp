#include "TaskState.h"
#include "Task.h"
#include <iostream>

// Base defaults: every action is invalid unless a concrete state
// overrides it. This is what makes "invalid transitions handled
// sensibly" easy — a state only needs to implement the transitions
// that are actually legal from it.

TaskState* TaskState::invalid(Task* task, const std::string& action) const {
    std::cout << "[Invalid] Cannot " << action << " while task \""
              << task->getName() << "\" is in state " << getName() << std::endl;
    return nullptr; // stay in the current state
}

TaskState* TaskState::start(Task* task) { 
    return invalid(task, "start"); 
}
TaskState* TaskState::submitForInspection(Task* task) { return invalid(task, "submit for inspection"); }
TaskState* TaskState::approve(Task* task)             { return invalid(task, "approve"); }
TaskState* TaskState::reject(Task* task)              { return invalid(task, "reject"); }
TaskState* TaskState::resume(Task* task)              { return invalid(task, "resume"); }
