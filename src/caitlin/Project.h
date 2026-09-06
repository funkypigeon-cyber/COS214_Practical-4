#ifndef PROJECT_H
#define PROJECT_H

#include "WorkGroup.h"

#include <string>

class Project : public WorkGroup
{
public:
    explicit Project(const std::string& name);
    virtual void report() const override;
};

#endif
