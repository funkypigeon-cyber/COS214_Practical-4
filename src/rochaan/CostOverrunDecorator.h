#ifndef COSTOVERRUNDECORATOR_H
#define COSTOVERRUNDECORATOR_H

#include "TaskDecorator.h"

class CostOverrunDecorator : public TaskDecorator {
public:
    CostOverrunDecorator(WorkComponent* wrapped, double variance);

    void execute() override;
    std::string getName() const override;
    double getCost() const override;

private:
    double variance;
};

#endif
