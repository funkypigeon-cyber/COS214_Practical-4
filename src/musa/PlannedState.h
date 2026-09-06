#ifndef PLANNEDSTATE_H
#define PLANNEDSTATE_H

#include "TaskState.h"

// States are implemented as singletons (Meyer's singleton — a static
// local instance). They're stateless and shared across every Task in
// that state, so Task holds a non-owning TaskState* and never deletes
// it. This keeps the destruction policy simple and avoids leaks.
class PlannedState : public TaskState {
public:
    static PlannedState& getInstance();

    std::string getName() const override { return "Planned"; }
    TaskState* start(Task* task) override;

private:
    PlannedState() = default;
};

#endif
