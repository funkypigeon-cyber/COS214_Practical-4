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

    Task* distributionBoard = new Task("Install Main Distribution Board", 2);
    services->add(distributionBoard);
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

    // ==================== STATE ====================
    std::cout << std::endl;
    std::cout << "Running 'Install Main Distribution Board' through its lifecycle:"
              << std::endl;

    distributionBoard->report();

    std::cout << std::endl
              << "Attempting to approve before work has started (invalid):"
              << std::endl;
    distributionBoard->approve();
    distributionBoard->report();

    std::cout << std::endl << "Starting the task:" << std::endl;
    distributionBoard->start();
    distributionBoard->report();

    std::cout << std::endl << "Submitting for inspection:" << std::endl;
    distributionBoard->submitForInspection();
    distributionBoard->report();

    std::unique_ptr<Iterator> pendingAfterSubmit =
        project.createPendingInspectionIterator();

    printTraversal(
        "Pending-inspection iterator, re-created after the state change:",
        *pendingAfterSubmit
    );

    std::cout << std::endl
              << "Inspection fails; task is sent for rework:" << std::endl;
    distributionBoard->reject();
    distributionBoard->report();

    std::cout << std::endl << "Rework complete, back in progress:" << std::endl;
    distributionBoard->resume();
    distributionBoard->report();

    std::cout << std::endl << "Resubmitted and approved:" << std::endl;
    distributionBoard->submitForInspection();
    distributionBoard->approve();
    distributionBoard->report();

    std::cout << std::endl
              << "Attempting to restart an approved (terminal) task (invalid):"
              << std::endl;
    distributionBoard->start();
    distributionBoard->report();

    // TODO: wrap a Task in one or more decorators (Rochaan)

    return 0;
}
