#include "Task.h"
#include "PlannedState.h"

#include <iostream>

Task::Task(const std::string& name, int plannedDurationDays)
    : name(name),
      plannedDurationDays(plannedDurationDays < 0 ? 0 : plannedDurationDays),
      state(&PlannedState::getInstance())
{
}

Task::~Task() = default;

std::string Task::getName() const
{
    return name;
}

void Task::report() const
{
    std::cout << "  [Task] " << name << " - " << plannedDurationDays
              << " day(s) - " << state->getName() << std::endl;
}

bool Task::isPendingInspection() const
{
    return state->isPendingInspection();
}

int Task::getPlannedDurationDays() const
{
    return plannedDurationDays;
}

std::string Task::getStateName() const
{
    return state->getName();
}

void Task::start()
{
    if (TaskState* next = state->start(this)) state = next;
}

void Task::submitForInspection()
{
    if (TaskState* next = state->submitForInspection(this)) state = next;
}

void Task::approve()
{
    if (TaskState* next = state->approve(this)) state = next;
}

void Task::reject()
{
    if (TaskState* next = state->reject(this)) state = next;
}

void Task::resume()
{
    if (TaskState* next = state->resume(this)) state = next;
}
