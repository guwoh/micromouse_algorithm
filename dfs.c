#include <stdio.h>
#include <stdbool.h>

#define N 16
#define MAXPATH 256

char maze[N][N+1] = {
    "S110000000000000",
    "0011011111111000",
    "0010010000011000",
    "0010010111011000",
    "0010010100011000",
    "0011110101111000",
    "0000010100010000",
    "0000010111010000",
    "0000010000010000",
    "0111110111011110",
    "0100000100010010",
    "0111111101111010",
    "0000000101000010",
    "0111111101111110",
    "0100000000000010",
    "01111111111111C0"
};


bool visited[N][N];
int pathX[MAXPATH], pathY[MAXPATH];
int pathLen = 0;

bool dfs(int x, int y) {
    if (x < 0 || x >= N || y < 0 || y >= N) return false;
    if (maze[x][y] == '0' || visited[x][y]) return false;

    pathX[pathLen] = x;
    pathY[pathLen] = y;
    pathLen++;

    if (maze[x][y] == 'C') {
        printf("Chuột đã tìm thấy phô mai!\nĐường đi:\n");
        for (int i = 0; i < pathLen; i++) {
            printf("(%d,%d) ", pathX[i], pathY[i]);
        }
        printf("\n");
        return true;
    }

    visited[x][y] = true;

    if (dfs(x-1, y)) return true;
    if (dfs(x+1, y)) return true;
    if (dfs(x, y-1)) return true;
    if (dfs(x, y+1)) return true;

    pathLen--; // quay lui nếu sai đường
    return false;
}

int main() {
    int start_x, start_y;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            if (maze[i][j] == 'S') {
                start_x = i;
                start_y = j;
            }
        }
    }

    dfs(start_x, start_y);
    return 0;
}

