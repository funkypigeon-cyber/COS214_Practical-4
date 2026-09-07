#include "PendingInspectionState.h"
#include "ApprovedState.h"
#include "ReworkRequiredState.h"
#include "Task.h"
#include <iostream>

PendingInspectionState& PendingInspectionState::getInstance() {
    static PendingInspectionState instance;
    return instance;
}

TaskState* PendingInspectionState::approve(Task* task) {
    std::cout << "Task \"" << task->getName() << "\" passed inspection and was approved." << std::endl;
    return &ApprovedState::getInstance();
}

TaskState* PendingInspectionState::reject(Task* task) {
    std::cout << "Task \"" << task->getName() << "\" failed inspection - rework required." << std::endl;
    return &ReworkRequiredState::getInstance();
}
