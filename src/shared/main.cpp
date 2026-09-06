#include <iostream>

// This is where the demo scenarios (Task 3) get wired together, using
// Project/Phase/Task (Caitlin), Task state transitions (Musa), and
// decorators (Rochaan). Build it incrementally as each piece lands —
// don't leave integration for the last day.
#include "../caitlin/Phase.h"
#include "../caitlin/Project.h"
#include "../caitlin/Task.h"
#include "Iterator.h"

#include <iostream>
#include <memory>
#include <string>

void printTraversal(const std::string& heading, Iterator& iterator)
{
    std::cout << std::endl << heading << std::endl;

    while (iterator.hasNext())
    {
        WorkComponent* component = iterator.next();

        if (component != nullptr)
        {
            std::cout << "- " << component->getName() << std::endl;
        }
    }
}

int main() {
    std::cout << "TaskForge - Construction Project Management" << std::endl;

    // TODO: build a sample Project with Phases and Tasks (Caitlin)

    // ==================== COMPOSITE ====================
    Project project("Riverside Office Build");

    Phase* structuralWork = new Phase("Structural Work");
    Phase* foundation = new Phase("Foundation");
    Phase* framing = new Phase("Framing");
    Phase* services = new Phase("Services");

    foundation->add(new Task("Excavate Site", 4));
    foundation->add(new Task("Install Reinforcement", 3));

    Task* concreteSlab = new Task("Pour Concrete Slab", 2);
    foundation->add(concreteSlab);

    framing->add(new Task("Build Ground Floor Frame", 6));

    services->add(new Task("Install Main Distribution Board", 2));
    services->add(new Task("Install Water Lines", 3));

    structuralWork->add(foundation);
    structuralWork->add(framing);

    project.add(structuralWork);
    project.add(services);

    std::cout << std::endl << "Initial project structure:" << std::endl;
    project.report();

    // ==================== ITERATOR ====================
    std::unique_ptr<Iterator> iteratorOne =
        project.createDepthFirstIterator();

    std::unique_ptr<Iterator> iteratorTwo =
        project.createDepthFirstIterator();

    std::cout << std::endl;
    std::cout << "Two independent iterators:" << std::endl;

    std::cout << "Iterator 1 visits: "
              << iteratorOne->next()->getName() << std::endl;

    std::cout << "Iterator 1 visits: "
              << iteratorOne->next()->getName() << std::endl;

    std::cout << "Iterator 2 still starts at: "
              << iteratorTwo->next()->getName() << std::endl;

    printTraversal(
        "Remaining items from Iterator 1:",
        *iteratorOne
    );

    // TODO: run two independent traversals over the same structure
    // ==================== STRUCTURE CHANGE + TRAVERSAL ====================
    std::cout << std::endl;
    std::cout << "Moving Pour Concrete Slab from Foundation to Framing..."
              << std::endl;

    foundation->transferChild(concreteSlab, *framing);

    std::unique_ptr<Iterator> updatedIterator =
        project.createDepthFirstIterator();

    printTraversal(
        "New traversal after moving the task:",
        *updatedIterator
    );

    std::unique_ptr<Iterator> inspectionIterator =
        project.createPendingInspectionIterator();

    printTraversal(
        "Tasks currently pending inspection:",
        *inspectionIterator
    );

    // TODO: run a Task through its lifecycle (Musa)
    // TODO: wrap a Task in one or more decorators (Rochaan)

    return 0;
}
