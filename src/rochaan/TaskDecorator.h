#ifndef TASKDECORATOR_H
#define TASKDECORATOR_H

#include "../shared/WorkComponent.h"

class TaskDecorator : public WorkComponent {
public:
    explicit TaskDecorator(WorkComponent* wrapped);
    virtual ~TaskDecorator(); 

    void add(WorkComponent* child) override;
    void remove(WorkComponent* child) override;
    WorkComponent* getChild(int index) const override;

    void execute() override;
    std::string getName() const override;
    double getCost() const override;
    int getDuration() const override;
    int getPriority() const override;
    bool isAudited() const override;

protected:
    WorkComponent* wrapped; 
};

#endif
