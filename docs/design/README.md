## Design Ownership and Rationale

### Recursive Hierarchy

`Project` and `Phase` reuse `WorkGroup`'s child-management behaviour. Because every child is a `WorkComponent`, groups can contain tasks as well as nested groups, giving TaskForge a genuine recursive part-whole structure without client-side type checks.

### Ownership and Destruction

`WorkGroup` owns its children through `std::unique_ptr<WorkComponent>`. Destruction of the root therefore destroys the hierarchy recursively through the virtual `WorkComponent` destructor. `transferChild()` moves an existing `unique_ptr` directly between groups so that a work item is never simultaneously owned by two parents.

### Traversal Encapsulation

Client code receives an `Iterator` and calls `hasNext()` and `next()`; it never obtains the group's internal `std::vector`. `DepthFirstIterator` visits the complete hierarchy in pre-order. `PendingInspectionIterator` applies the meaningful selection rule supplied by `WorkComponent::isPendingInspection()`.

### Snapshot Lifetime Rule

`SnapshotIterator` stores non-owning `WorkComponent*` pointers. The owning hierarchy must therefore outlive all active iterators, and a detached node must not be destroyed while an older snapshot could still refer to it.

### State Lifecycle

`Task` delegates lifecycle actions to its current `TaskState`. The concrete states control valid transitions, while invalid actions leave the task unchanged. Singleton state objects are shared safely between tasks.

### Decorator Extension

`TaskDecorator` wraps a `WorkComponent` and delegates its normal behaviour. Concrete decorators dynamically add safety auditing, weather delays, cost overruns or priority boosts without changing the original task class.

### Traversal-Modification Policy

Each iterator stores a snapshot of non-owning `WorkComponent*` pointers when it is created. Changes to the hierarchy do not affect an active iterator; a new iterator must be created to view the updated structure. Nodes may not be deleted while an older iterator could still reference them.

### Other Important Design Decisions

`WorkGroup` owns its children using `std::unique_ptr`, while `transferChild()` safely moves ownership between groups. `canAccept()` prevents null children, self-containment and recursive cycles. Task states are shared Singleton objects, and decorators may be stacked to add behaviour without modifying `Task`.
