#include "CostOverrunDecorator.h"
#include <iostream>

CostOverrunDecorator::CostOverrunDecorator(WorkComponent* wrapped, double variance)
    : TaskDecorator(wrapped), variance(variance) {}

void CostOverrunDecorator::execute() {
    std::cout << "[Cost Overrun] " << wrapped->getName()
              << " variance: " << variance << "\n";
    TaskDecorator::execute();
}

std::string CostOverrunDecorator::getName() const {
    return wrapped->getName() + " [Cost-Flagged]";
}

double CostOverrunDecorator::getCost() const {
    return wrapped->getCost() + variance;
}
