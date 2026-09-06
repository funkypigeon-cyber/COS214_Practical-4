#ifndef SNAPSHOTITERATOR_H
#define NAPSHOTITERATOR_H

#include "../shared/Iterator.h"

#include <cstddef>
#include <vector>

class WorkComponent;

class SnapshotIterator : public Iterator
{
private:
    std::vector<WorkComponent*> snapshot;
    std::size_t position;

protected:
    SnapshotIterator();
    void append(WorkComponent* component);
    virtual void buildSnapshot(WorkComponent* component) = 0;

public:
    virtual ~SnapshotIterator();
    virtual bool hasNext() const override;
    virtual WorkComponent* next() override;
};

#endif
