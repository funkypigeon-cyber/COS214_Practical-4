Put the design write-up here: domain description, ownership rationale,
traversal-modification policy, GDB/Valgrind investigation notes, and
team contribution statement (everything that goes into the submission PDF).

# Composite + Iterator design
## GoF participant mapping

Component -WorkComponent 
Composite - WorkGroup
Concrete composites - Project, Phase
Leaf - Task
Iterator - Iterator
Iterator support -SnapshotIterator
Concrete iterators - DepthFirstIterator, PendingInspectionIterator

## How the classes connect
`Project`, `Phase`, and `Task` all implement `WorkComponent`, so client code can store and process every construction item through the same interface. A `WorkGroup` owns zero or more `WorkComponent` children. `Project` and `Phase` reuse that ownership and child-management implementation, while `Task` remains a leaf whose inherited child operations do nothing.

`WorkGroup` creates either concrete Iterator through the shared `Iterator` interface. `SnapshotIterator` stores the common snapshot vector and cursor. `DepthFirstIterator` recursively includes every Component in pre-order, whereas `PendingInspectionIterator` visits the hierarchy but includes only Components whose `isPendingInspection()` result is true.

## Ownership and movement
Calling `WorkGroup::add()` transfers ownership of an unowned pointer to that group. Children are stored as `std::unique_ptr<WorkComponent>`, so deleting the root Project recursively destroys the complete hierarchy through the virtual `WorkComponent` destructor.

`remove()` detaches a child without destroying it; the caller then owns the raw pointer.
`transferChild()` is safer for ordinary moves because it moves the internal `unique_ptr` directly from one group to another.

## Traversal-modification policy
Each Iterator captures its own traversal sequence and position at construction time. Therefore:

- two Iterators over the same Project advance independently;
- adding or moving a node does not reorder an Iterator already in progress;
- a new Iterator sees the modified hierarchy; and
- a detached node must not be destroyed while an older snapshot could still reference it.