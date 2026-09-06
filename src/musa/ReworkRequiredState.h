#ifndef REWORKREQUIREDSTATE_H
#define REWORKREQUIREDSTATE_H

#include "TaskState.h"

class ReworkRequiredState : public TaskState {
public:
    static ReworkRequiredState& getInstance();

    std::string getName() const override { return "ReworkRequired"; }
    TaskState* resume(Task* task) override; // back to InProgress after rework

private:
    ReworkRequiredState() = default;
};

#endif
