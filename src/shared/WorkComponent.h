#ifndef WORKCOMPONENT_H
#define WORKCOMPONENT_H

#include <string>

// Shared base interface for the Composite hierarchy (Project/Phase/Task).
// Owned by: Caitlin (Composite + Iterator)
// Everyone else's code interacts with WorkComponent, not with concrete
// Project/Phase/Task classes directly, so agree on this interface FIRST
// before splitting off into folders.
class WorkComponent {
public:
    virtual ~WorkComponent() = default;

    virtual std::string getName() const = 0;
    virtual void report() const = 0; // print/describe this node (and children, if a composite)

    // Composite-management operations. Leaves can provide a default
    // no-op/throw implementation; only composites need real behaviour.
    virtual void add(WorkComponent* child) { (void)child; }
    virtual void remove(WorkComponent* child) { (void)child; }

    virtual WorkComponent* getChild(std::size_t index) const
    {
        (void)index;
        return nullptr;
    }

    virtual std::size_t getChildCount() const { return 0; }

    //Task will later ask its current TaskState for this information.
    virtual bool isPendingInspection() const { return false; }
};

#endif
