#include "state.h"
#include "hash_table.h"

#include <iostream>
#include <queue>

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
}

void get_path(state start, state end) {
    if (start == end) {
        return;
    }
    std::cout << print(prev_move(end)) << std::endl;
    // end.print();
    get_path(start, prev(end));
}

int main() {
    state initial_pos;

    initial_pos.read();
    // initial_pos.print();
    
    state final_pos = bfs(initial_pos);
    get_path(initial_pos, final_pos);
}
