#ifndef DEPTHFIRSTITERATOR_H
#define DEPTHFIRSTITERATOR_H

#include "SnapshotIterator.h"

class DepthFirstIterator : public SnapshotIterator
{
protected:
    virtual void buildSnapshot(WorkComponent* component) override;

public:
    explicit DepthFirstIterator(WorkComponent* root);
};

#endif
