#ifndef WORKCOMPONENT_H
#define WORKCOMPONENT_H

#include <cstddef>
#include <string>

class WorkComponent
{
public:
    virtual ~WorkComponent() = default;

    virtual std::string getName() const = 0;
    virtual void report() const = 0;

    virtual void execute()
    {
        report();
    }

    virtual double getCost() const
    {
        return 0.0;
    }

    virtual int getDuration() const
    {
        return 0;
    }

    virtual int getPriority() const
    {
        return 0;
    }

    virtual bool isAudited() const
    {
        return false;
    }

    // Composite operations.
    virtual void add(WorkComponent* child)
    {
        (void)child;
    }

    virtual void remove(WorkComponent* child)
    {
        (void)child;
    }

    virtual WorkComponent* getChild(std::size_t index) const
    {
        (void)index;
        return nullptr;
    }

    virtual std::size_t getChildCount() const
    {
        return 0;
    }

    // Iterator/State
    virtual bool isPendingInspection() const
    {
        return false;
    }
};

#endif