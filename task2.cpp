#include <iostream>
using namespace std;
int cx[8] = {2, 1, -1, -2, -2, -1, 1, 2};
int cy[8] = {1, 2, 2, 1, -1, -2, -2, -1};
bool isValid(int x, int y, int n) {
return (x >= 0 && y >= 0 && x < n && y < n);
}
bool getNext(int x, int y, int board[5][5], int n, int &nx, int &ny) {
int minDeg = 9, idx = -1;
for (int i = 0; i < 8; i++) {
int tx = x + cx[i], ty = y + cy[i];
if (isValid(tx, ty, n) && board[tx][ty] == -1) {
int deg = 0;
for (int j = 0; j < 8; j++) {
if (isValid(tx + cx[j], ty + cy[j], n) && board[tx + cx[j]][ty + cy[j]] == -1) deg++;
}
if (deg < minDeg) {
minDeg = deg; idx = i; nx = tx; ny = ty;
}
}
}
return (idx != -1);
}
bool solve(int n, int board[5][5], int sx, int sy) {
board[sx][sy] = 0;
int cx_pos = sx, cy_pos = sy;
for (int i = 1; i < n * n; i++) {
int nx, ny;
if (!getNext(cx_pos, cy_pos, board, n, nx, ny)) return false;
board[nx][ny] = i;
cx_pos = nx; cy_pos = ny;
}
return true;
}
int main() {
int n = 5;
int board[5][5];
for (int i = 0; i < n; i++)
for (int j = 0; j < n; j++) board[i][j] = -1;
if (solve(n, board, 0, 0)) {
for (int i = 0; i < n; i++) {
for (int j = 0; j < n; j++) cout << board[i][j] << "\t";
cout << endl;
}
}
return 0;
}
