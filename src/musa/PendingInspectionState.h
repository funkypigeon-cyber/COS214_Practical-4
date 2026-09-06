#ifndef PENDINGINSPECTIONSTATE_H
#define PENDINGINSPECTIONSTATE_H

#include "TaskState.h"

class PendingInspectionState : public TaskState {
public:
    static PendingInspectionState& getInstance();

    std::string getName() const override { return "PendingInspection"; }
    TaskState* approve(Task* task) override;
    TaskState* reject(Task* task) override;
    bool isPendingInspection() const override { return true; }

private:
    PendingInspectionState() = default;
};

#endif
