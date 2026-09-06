#include "SnapshotIterator.h"

SnapshotIterator::SnapshotIterator(): position(0)
{
}

SnapshotIterator::~SnapshotIterator() = default;

void SnapshotIterator::append(WorkComponent* component)
{
    if (component != nullptr)
    {
        snapshot.push_back(component);
    }
}

bool SnapshotIterator::hasNext() const
{
    return position < snapshot.size();
}

WorkComponent* SnapshotIterator::next()
{
    if (!hasNext())
    {
        return nullptr;
    }

    return snapshot[position++];
}
