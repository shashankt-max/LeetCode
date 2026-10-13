#include <stdbool.h>

void dfs(int room, int** rooms, int* roomsSize, bool* visited) {
    visited[room] = true;

    for (int i = 0; i < roomsSize[room]; i++) {
        int key = rooms[room][i];

        if (!visited[key]) {
            dfs(key, rooms, roomsSize, visited);
        }
    }
}

bool canVisitAllRooms(int** rooms, int roomsSize, int* roomsColSize) {
    bool visited[1000] = {false};

    dfs(0, rooms, roomsColSize, visited);

    for (int i = 0; i < roomsSize; i++) {
        if (!visited[i]) {
            return false;
        }
    }

    return true;
}