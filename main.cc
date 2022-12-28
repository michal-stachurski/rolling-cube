#include "state.h"
#include "hash_table.h"

#include <iostream>
#include <queue>

const char* verbose(direction d) {
    switch (d) {
        case up: return "up";
        case right: return "right";
        case down: return "down";
        case left: return "left";
        default: return "none";
    }
}

state bfs(state start) {
    std::queue<state> Q;
    Q.push(start);

    while (!Q.empty()) {
        state game = Q.front();
        Q.pop();
        if (game.solved()) {
            return game;
        }
        visited(game) = true;
        for (direction d : {up, right, down, left}) {
            state next = game.move(d);
            if (!visited(next)) {
                Q.push(next);
                prev(next) = game;
                prev_move(next) = d;
            }
        }
    }
    return state();
}

void backtrace(state start, state end, std::deque<direction>& moves) {
    if (start == end) {
        return;
    }
    moves.push_front(prev_move(end));
    backtrace(start, prev(end), moves);
}

int main() {
    state initial_pos;
    initial_pos.read();
    
    std::cout << "Searching for solution..." << std::endl;
    state final_pos = bfs(initial_pos);

    std::deque<direction> moves;
    backtrace(initial_pos, final_pos, moves);

    std::cout << "Found " << moves.size() << " moves solution:" << std::endl;
    for (direction move : moves) {
        std::cout << verbose(move) << std::endl;
    }
}
