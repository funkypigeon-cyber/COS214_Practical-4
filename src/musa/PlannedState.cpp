#include "PlannedState.h"
#include "InProgressState.h"
#include "Task.h"
#include <iostream>

PlannedState& PlannedState::getInstance() {
    static PlannedState instance;
    return instance;
}

TaskState* PlannedState::start(Task* task) {
    std::cout << "Task \"" << task->getName() << "\" started." << std::endl;
    return &InProgressState::getInstance();
}
