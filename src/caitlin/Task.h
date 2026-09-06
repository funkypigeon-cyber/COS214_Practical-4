#ifndef TASK_H
#define TASK_H

#include "../shared/WorkComponent.h"
#include "TaskState.h"

#include <string>

class Task : public WorkComponent
{
private:
    std::string name;
    int plannedDurationDays;
    TaskState* state;

public:
    Task(const std::string& name, int plannedDurationDays);
    virtual ~Task();

    virtual std::string getName() const override;
    virtual void report() const override;
    virtual bool isPendingInspection() const override;

    int getPlannedDurationDays() const;

    // Added state parts to Task.cpp:
    void start();
    void submitForInspection();
    void approve();
    void reject();
    void resume();

    std::string getStateName() const;
};

#endif
