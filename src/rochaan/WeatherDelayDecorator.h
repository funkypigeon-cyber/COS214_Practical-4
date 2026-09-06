#ifndef WEATHERDELAYDECORATOR_H
#define WEATHERDELAYDECORATOR_H

#include "TaskDecorator.h"

class WeatherDelayDecorator : public TaskDecorator {
public:
    WeatherDelayDecorator(WorkComponent* wrapped, int delayDays);

    void execute() override;
    std::string getName() const override;
    int getDuration() const override;

private:
    int delayDays;
};

#endif
