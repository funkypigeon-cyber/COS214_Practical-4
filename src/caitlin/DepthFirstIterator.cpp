#include "DepthFirstIterator.h"

#include "../shared/WorkComponent.h"

DepthFirstIterator::DepthFirstIterator(WorkComponent* root)
    : SnapshotIterator()
{
    buildSnapshot(root);
}

void DepthFirstIterator::buildSnapshot(WorkComponent* component)
{
    if (component == nullptr)
    {
        return;
    }

    //pre-order dfs
    append(component);

    for (std::size_t i = 0; i < component->getChildCount(); ++i)
    {
        buildSnapshot(component->getChild(i));
    }
}
