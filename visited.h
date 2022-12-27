#pragma once

#include <unordered_map>
#include "state.h"

std::unordered_map<state,bool,state::hash> M;
std::unordered_map<state,state,state::hash> prev;

void visit(const state& s) {
    M[s] = true;
}
bool visited(const state& s) {
    return M[s];
}
