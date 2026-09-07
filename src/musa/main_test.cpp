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

    return 0;
}
