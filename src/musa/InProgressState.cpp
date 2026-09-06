#include "InProgressState.h"
#include "PendingInspectionState.h"
#include "Task.h"
#include <iostream>

InProgressState& InProgressState::getInstance() {
    static InProgressState instance;
    return instance;
}

TaskState* InProgressState::submitForInspection(Task* task) {
    std::cout << "Task \"" << task->getName() << "\" submitted for inspection." << std::endl;
    return &PendingInspectionState::getInstance();
}
