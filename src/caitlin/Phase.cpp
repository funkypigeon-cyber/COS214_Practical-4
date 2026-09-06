#include "Phase.h"

#include <iostream>

Phase::Phase(const std::string& name)
    : WorkGroup(name)
{
}

void Phase::report() const
{
    std::cout << "[Phase] " << getName() << " (" << getChildCount()
              << " direct item(s))" << std::endl;
    reportChildren();
}
