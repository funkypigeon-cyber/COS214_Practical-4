#ifndef TASK_H
#define TASK_H

#include "../shared/WorkComponent.h"

#include <string>

class Task : public WorkComponent
{
private:
    std::string name;
    int plannedDurationDays;

public:
    Task(const std::string& name, int plannedDurationDays);
    virtual ~Task();

    virtual std::string getName() const override;
    virtual void report() const override;
    virtual bool isPendingInspection() const override;

    int getPlannedDurationDays() const;
};

#endif
