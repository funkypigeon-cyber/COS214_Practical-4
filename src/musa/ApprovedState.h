#ifndef APPROVEDSTATE_H
#define APPROVEDSTATE_H

#include "TaskState.h"

// Terminal state — every action is invalid from here (inherits the
// base class's default "invalid" behaviour for everything), which is
// exactly correct: an approved task shouldn't be able to restart,
// resubmit, etc.
class ApprovedState : public TaskState {
public:
    static ApprovedState& getInstance();

    std::string getName() const override { return "Approved"; }

private:
    ApprovedState() = default;
};

#endif
