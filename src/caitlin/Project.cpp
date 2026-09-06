#include "Project.h"

#include <iostream>

Project::Project(const std::string& name)
    : WorkGroup(name)
{
}

void Project::report() const
{
    std::cout << "\n========== CONSTRUCTION PROJECT ==========\n";
    std::cout << "[Project] " << getName() << std::endl;
    reportChildren();
    std::cout << "==============================================" << std::endl;
}
