#include "ApprovedState.h"

ApprovedState& ApprovedState::getInstance() {
    static ApprovedState instance;
    return instance;
}
