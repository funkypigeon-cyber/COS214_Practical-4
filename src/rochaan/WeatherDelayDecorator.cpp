#include "WeatherDelayDecorator.h"
#include <iostream>

WeatherDelayDecorator::WeatherDelayDecorator(WorkComponent* wrapped, int delayDays)
    : TaskDecorator(wrapped), delayDays(delayDays) {}

void WeatherDelayDecorator::execute() {
    std::cout << "[Weather Delay] " << wrapped->getName()
              << " pushed back " << delayDays << " day(s)\n";
    TaskDecorator::execute();
}

std::string WeatherDelayDecorator::getName() const {
    return wrapped->getName() + " [Weather-Delayed]";
}

int WeatherDelayDecorator::getDuration() const {
    return wrapped->getDuration() + delayDays;
}
