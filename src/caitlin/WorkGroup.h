#ifndef TASKFORGE_WORKGROUP_H
#define TASKFORGE_WORKGROUP_H

#include "../shared/Iterator.h"
#include "../shared/WorkComponent.h"

#include <memory>
#include <string>
#include <vector>

//Composite
class WorkGroup : public WorkComponent
{
private:
    std::string name;
    std::vector<std::unique_ptr<WorkComponent> > children;

    bool canAccept(const WorkComponent* child) const;

protected:
    void reportChildren() const;

public:
    explicit WorkGroup(const std::string& name);
    virtual ~WorkGroup();

    virtual std::string getName() const override;
    virtual void report() const override;

  
    virtual void add(WorkComponent* child) override; //transfers ownership

    virtual void remove(WorkComponent* child) override; //removes onwership

    bool addOwned(std::unique_ptr<WorkComponent>&& child);
    std::unique_ptr<WorkComponent> detach(WorkComponent* child);
    bool transferChild(WorkComponent* child, WorkGroup& target);

    virtual WorkComponent* getChild(std::size_t index) const override;
    virtual std::size_t getChildCount() const override;

    std::unique_ptr<Iterator> createDepthFirstIterator();
    std::unique_ptr<Iterator> createPendingInspectionIterator();
};

#endif
