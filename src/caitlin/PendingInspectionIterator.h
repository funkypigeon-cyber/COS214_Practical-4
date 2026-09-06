#ifndef PENDINGINSPECTIONITERATOR_H
#define PENDINGINSPECTIONITERATOR_H

#include "SnapshotIterator.h"

// State reports that they are waiting for inspection.
class PendingInspectionIterator : public SnapshotIterator
{
protected:
    virtual void buildSnapshot(WorkComponent* component) override;

public:
    explicit PendingInspectionIterator(WorkComponent* root);
};

#endif
