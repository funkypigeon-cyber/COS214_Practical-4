# Musa — State

Put your files here:
- TaskState.h                    (abstract state interface)
- PlannedState.h / .cpp
- InProgressState.h / .cpp
- PendingInspectionState.h / .cpp
- ApprovedState.h / .cpp
- ReworkRequiredState.h / .cpp

Depends on: src/caitlin/Task.h (Task holds a TaskState* and delegates
behaviour to it — coordinate with Caitlin on that interface early).
