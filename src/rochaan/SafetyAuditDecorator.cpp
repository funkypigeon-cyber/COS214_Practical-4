#include "SafetyAuditDecorator.h"
#include <iostream>

SafetyAuditDecorator::SafetyAuditDecorator(WorkComponent* wrapped)
    : TaskDecorator(wrapped), auditPassed(false) {}

void SafetyAuditDecorator::runAuditCheck() {

    auditPassed = true;
    std::cout << "[Safety Audit] Checked " << wrapped->getName() << " -- PASSED\n";
}

void SafetyAuditDecorator::execute() {
    runAuditCheck();
    TaskDecorator::execute();
}

std::string SafetyAuditDecorator::getName() const {
    return wrapped->getName() + " [Audited]";
}

bool SafetyAuditDecorator::isAudited() const {
    return auditPassed;
}
