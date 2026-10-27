#include <iostream>
using namespace std;
//MaxRow finding
int findMaxRow(int a[][3], int r, int c) {
int m = 0;
for (int i = 0; i < r; i++) {
if (a[i][c] > a[m][c]) m = i;
}
return m;
}
//Peakness
void findPeak(int a[][3], int r, int c, int mid, int &pr, int &pc) {
int m = findMaxRow(a, r, mid);
bool left = (mid > 0 && a[m][mid - 1] > a[m][mid]);
bool right = (mid < c - 1 && a[m][mid + 1] > a[m][mid]);
if (!left && !right) {
pr = m; pc = mid;
return;
}
if (left) findPeak(a, r, c, mid / 2, pr, pc);
else findPeak(a, r, c, mid + (c - mid) / 2, pr, pc);
}
//Main
int main() {
int a[3][3] = {{1, 4, 3}, {2, 5, 6}, {1, 3, 2}};
int pr = -1, pc = -1;
findPeak(a, 3, 3, 1, pr, pc);
cout << "Peak: " << pr << ", " << pc << endl;
return 0;
}
