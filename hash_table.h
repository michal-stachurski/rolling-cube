#ifndef HASH_TABLE_H
#define HASH_TABLE_H

#include <unordered_map>
#include "state.h"

std::unordered_map<state, bool, state::hash> __visited;
std::unordered_map<state, state, state::hash> __prev;
std::unordered_map<state, direction, state::hash> __prev_move;

bool& visited(const state& s) {
    return __visited[s];
}

state& prev(const state& s) {
    return __prev[s];
}

direction& prev_move(const state& s) {
    return __prev_move[s];
}

#endif