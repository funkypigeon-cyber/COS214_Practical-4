#ifndef SAFETYAUDITDECORATOR_H
#define SAFETYAUDITDECORATOR_H

#include "TaskDecorator.h"

class SafetyAuditDecorator : public TaskDecorator {
public:
    explicit SafetyAuditDecorator(WorkComponent* wrapped);

    void execute() override;
    std::string getName() const override;
    bool isAudited() const override;

private:
    bool auditPassed;
    void runAuditCheck();
};

#endif
