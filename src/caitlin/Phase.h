#ifndef PHASE_H
#define PHASE_H

#include "WorkGroup.h"

#include <string>

class Phase : public WorkGroup
{
public:
    explicit Phase(const std::string& name);
    virtual void report() const override;
};

#endif
