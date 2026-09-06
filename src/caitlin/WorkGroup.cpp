#include "WorkGroup.h"

#include "DepthFirstIterator.h"
#include "PendingInspectionIterator.h"

#include <algorithm>
#include <iostream>
#include <utility>

static bool subtreeContains(const WorkComponent* root, const WorkComponent* wanted)
{
    if (root == nullptr || wanted == nullptr)
    {
        return false;
    }

    if (root == wanted)
    {
        return true;
    }

    for (std::size_t i = 0; i < root->getChildCount(); ++i)
    {
        if (subtreeContains(root->getChild(i), wanted))
        {
            return true;
        }
    }

    return false;
}

WorkGroup::WorkGroup(const std::string& name)
    : name(name)
{
}

WorkGroup::~WorkGroup() = default;

std::string WorkGroup::getName() const
{
    return name;
}

bool WorkGroup::canAccept(const WorkComponent* child) const
{
    if (child == nullptr || child == this)
    {
        return false;
    }

    return !subtreeContains(this, child) && !subtreeContains(child, this);
}

void WorkGroup::add(WorkComponent* child)
{
    if (canAccept(child))
    {
        children.push_back(std::unique_ptr<WorkComponent>(child));
    }
}

bool WorkGroup::addOwned(std::unique_ptr<WorkComponent>&& child)
{
    if (!canAccept(child.get()))
    {
        return false;
    }

    children.push_back(std::move(child));
    return true;
}

std::unique_ptr<WorkComponent> WorkGroup::detach(WorkComponent* child)
{
    for (std::vector<std::unique_ptr<WorkComponent> >::iterator it = children.begin();
         it != children.end(); ++it)
    {
        if (it->get() == child)
        {
            std::unique_ptr<WorkComponent> detached = std::move(*it);
            children.erase(it);
            return detached;
        }
    }

    return std::unique_ptr<WorkComponent>();
}

void WorkGroup::remove(WorkComponent* child)
{
    std::unique_ptr<WorkComponent> detached = detach(child);
    detached.release();
}

bool WorkGroup::transferChild(WorkComponent* child, WorkGroup& target)
{
    if (&target == this || !target.canAccept(child))
    {
        return false;
    }

    std::unique_ptr<WorkComponent> detached = detach(child);
    if (!detached)
    {
        return false;
    }

    if (target.addOwned(std::move(detached)))
    {
        return true;
    }

    addOwned(std::move(detached));
    return false;
}

WorkComponent* WorkGroup::getChild(std::size_t index) const
{
    if (index >= children.size())
    {
        return nullptr;
    }

    return children[index].get();
}

std::size_t WorkGroup::getChildCount() const
{
    return children.size();
}

void WorkGroup::reportChildren() const
{
    for (std::size_t i = 0; i < children.size(); ++i)
    {
        children[i]->report();
    }
}

void WorkGroup::report() const
{
    std::cout << "[Work group] " << name << " (" << children.size()
              << " direct item(s))" << std::endl;
    reportChildren();
}

std::unique_ptr<Iterator> WorkGroup::createDepthFirstIterator()
{
    return std::unique_ptr<Iterator>(new DepthFirstIterator(this));
}

std::unique_ptr<Iterator> WorkGroup::createPendingInspectionIterator()
{
    return std::unique_ptr<Iterator>(new PendingInspectionIterator(this));
}
