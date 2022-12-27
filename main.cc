#include "state.h"
#include "visited.h"
#include <queue>

void bfs(state start, int depth = 0) {
    
    std::queue<state> Q;
    Q.push(start);

    state game = Q.front();
    while (!Q.empty()) {
        game = Q.front();
        Q.pop();

        if (game.solved()) {
            game.print();
            break;
        }
        visit(game);
        for (state next : game.possible()) {
            if (!visited(next)) {
                prev[next] = game;
                Q.push(next);
            }
        }
    }
    while (!(game == start)) {
        game.print();
        game = prev[game];
    }

}

int main() {
    state s = state();
    // s.print();
    bfs(s);
}
