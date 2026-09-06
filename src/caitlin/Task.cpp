#include "Task.h"

#include <iostream>

Task::Task(const std::string& name, int plannedDurationDays)
    : name(name),
      plannedDurationDays(plannedDurationDays < 0 ? 0 : plannedDurationDays)
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
              << " day(s)" << std::endl;
}

bool Task::isPendingInspection() const
{
    return false; //state should replace this
}

int Task::getPlannedDurationDays() const
{
    return plannedDurationDays;
}
