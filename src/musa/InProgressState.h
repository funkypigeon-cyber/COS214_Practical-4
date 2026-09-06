#ifndef INPROGRESSSTATE_H
#define INPROGRESSSTATE_H

#include "TaskState.h"

class InProgressState : public TaskState {
public:
    static InProgressState& getInstance();

    std::string getName() const override { return "InProgress"; }
    TaskState* submitForInspection(Task* task) override;

private:
    InProgressState() = default;
};

#endif
