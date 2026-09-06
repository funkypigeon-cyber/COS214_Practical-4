#ifndef TASKSTATE_H
#define TASKSTATE_H

#include <string>

class Task; // forward declaration — avoids circular include with Task.h

// Abstract State. Each concrete state decides what happens on each
// action, and either returns the next state or rejects the transition.
class TaskState {
public:
    virtual ~TaskState() = default;

    virtual std::string getName() const = 0;

    // Each of these is called by Task, which then swaps its state
    // pointer based on what's returned. Returning nullptr signals
    // "no transition" — Task should log/print why and stay put.
    virtual TaskState* start(Task* task);        // Planned -> InProgress
    virtual TaskState* submitForInspection(Task* task); // InProgress -> PendingInspection
    virtual TaskState* approve(Task* task);      // PendingInspection -> Approved
    virtual TaskState* reject(Task* task);       // PendingInspection -> ReworkRequired
    virtual TaskState* resume(Task* task);       // ReworkRequired -> InProgress

    // Matches WorkComponent::isPendingInspection() — Task delegates to
    // this so the pending-inspection iterator can filter without
    // knowing about TaskState at all. Only PendingInspectionState
    // overrides it to return true.
    virtual bool isPendingInspection() const { return false; }

protected:
    // Shared helper so every invalid-transition message looks the same.
    TaskState* invalid(Task* task, const std::string& action) const;
};

#endif
