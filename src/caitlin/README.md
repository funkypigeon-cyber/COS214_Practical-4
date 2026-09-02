# Caitlin — Composite + Iterator

Put your files here:
- Project.h / Project.cpp
- Phase.h / Phase.cpp
- Task.h / Task.cpp   (implements WorkComponent — coordinate with Musa, since Task also carries the State pattern)
- CriticalPathIterator.h / .cpp
- PendingInspectionIterator.h / .cpp

Depends on: src/shared/WorkComponent.h, src/shared/Iterator.h

Note: Task.h is shared ground between you and Musa (Composite leaf + State
context). Agree on that class's interface together early on.
