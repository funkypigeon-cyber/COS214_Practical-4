#include "Task.h"
#include <iostream>

int main() {
    Task t("Pour concrete slab", 3);
    t.report();

    t.approve(); // invalid: still Planned
    t.report();

    t.start();
    t.report();
    std::cout << "isPendingInspection: " << t.isPendingInspection() << std::endl;

    t.approve(); // invalid: still InProgress
    t.report();

    t.submitForInspection();
    t.report();
    std::cout << "isPendingInspection: " << t.isPendingInspection() << std::endl;

    t.reject();
    t.report();

    t.approve(); // invalid: ReworkRequired
    t.report();

    t.resume();
    t.report();

    t.submitForInspection();
    t.approve();
    t.report();

    t.start(); // invalid: Approved is terminal
    t.report();

    std::cout << "\n--- Two-task independence test ---" << std::endl;
    Task a("Task A", 1);
    Task b("Task B", 2);

    a.start();              // A: Planned -> InProgress
    a.report();
    b.report();             // B should still be Planned

    b.start();               // B: Planned -> InProgress
    a.submitForInspection(); // A: InProgress -> PendingInspection
    a.report();
    b.report();              // B should still be InProgress, NOT PendingInspection

    b.approve();              // invalid: B is InProgress, not PendingInspection
    b.report();

    return 0;
}
