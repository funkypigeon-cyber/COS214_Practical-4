#include "TaskDecorator.h"

TaskDecorator::TaskDecorator(WorkComponent* wrapped) : wrapped(wrapped) {}

TaskDecorator::~TaskDecorator() {
    delete wrapped;
}

void TaskDecorator::add(WorkComponent* child) { wrapped->add(child); }
void TaskDecorator::remove(WorkComponent* child) { wrapped->remove(child); }
WorkComponent* TaskDecorator::getChild(int index) const { return wrapped->getChild(index); }

void TaskDecorator::execute() { wrapped->execute(); }
std::string TaskDecorator::getName() const { return wrapped->getName(); }
double TaskDecorator::getCost() const { return wrapped->getCost(); }
int TaskDecorator::getDuration() const { return wrapped->getDuration(); }
int TaskDecorator::getPriority() const { return wrapped->getPriority(); }
bool TaskDecorator::isAudited() const { return wrapped->isAudited(); }
