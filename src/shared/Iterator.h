#ifndef ITERATOR_H
#define ITERATOR_H

// Shared Iterator interface. Owned by: Caitlin.
// main.cpp and everyone else's code should only ever talk to this
// interface, never to the internal container Caitlin's Composite uses.
class WorkComponent;

class Iterator {
public:
    virtual ~Iterator() = default;
    virtual bool hasNext() const = 0;
    virtual WorkComponent* next() = 0;
};

#endif
