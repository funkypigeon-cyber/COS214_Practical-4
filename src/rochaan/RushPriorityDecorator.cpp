#include "RushPriorityDecorator.h"
#include <iostream>

RushPriorityDecorator::RushPriorityDecorator(WorkComponent* wrapped, int boost)
    : TaskDecorator(wrapped), boost(boost) {}

void RushPriorityDecorator::execute() {
    std::cout << "[Rush Priority] " << wrapped->getName()
              << " bumped by " << boost << "\n";
    TaskDecorator::execute();
}

std::string RushPriorityDecorator::getName() const {
    return wrapped->getName() + " [Rushed]";
}

int RushPriorityDecorator::getPriority() const {
    return wrapped->getPriority() + boost;
}
