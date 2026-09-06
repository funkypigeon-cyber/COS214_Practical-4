#ifndef RUSHPRIORITYDECORATOR_H
#define RUSHPRIORITYDECORATOR_H

#include "TaskDecorator.h"

class RushPriorityDecorator : public TaskDecorator {
public:
    RushPriorityDecorator(WorkComponent* wrapped, int boost);

    void execute() override;
    std::string getName() const override;
    int getPriority() const override;

private:
    int boost;
};

#endif
