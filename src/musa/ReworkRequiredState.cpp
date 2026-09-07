#include "ReworkRequiredState.h"
#include "InProgressState.h"
#include "Task.h"
#include <iostream>

ReworkRequiredState& ReworkRequiredState::getInstance() {
    static ReworkRequiredState instance;
    return instance;
}

TaskState* ReworkRequiredState::resume(Task* task) {
    std::cout << "Task \"" << task->getName() << "\" reworked - back in progress." << std::endl;
    return &InProgressState::getInstance();
}
