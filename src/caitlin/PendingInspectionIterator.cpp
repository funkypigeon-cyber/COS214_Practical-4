#include "PendingInspectionIterator.h"

#include "../shared/WorkComponent.h"

PendingInspectionIterator::PendingInspectionIterator(WorkComponent* root)
    : SnapshotIterator()
{
    buildSnapshot(root);
}

void PendingInspectionIterator::buildSnapshot(WorkComponent* component)
{
    if (component == nullptr)
    {
        return;
    }

    if (component->isPendingInspection())
    {
        append(component);
    }

    for (std::size_t i = 0; i < component->getChildCount(); ++i)
    {
        buildSnapshot(component->getChild(i));
    }
}
