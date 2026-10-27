#include <iostream>
using namespace std;
void move(int src[], int &tS, int dest[], int &tD, char s, char d) {
if (tS == -1) {
src[++tS] = dest[tD--];
cout << "Move disk from " << d << " to " << s << endl;
} else if (tD == -1) {
dest[++tD] = src[tS--];
cout << "Move disk from " << s << " to " << d << endl;
} else if (src[tS] < dest[tD]) {
dest[++tD] = src[tS--];
cout << "Move disk from " << s << " to " << d << endl;
} else {
src[++tS] = dest[tD--];
cout << "Move disk from " << d << " to " << s << endl;
}
}
int main() {
int n = 3;
int src[10], aux[10], dest[10];
int tS = -1, tA = -1, tD = -1;
for (int i = n; i >= 1; i--) src[++tS] = i;
char s = 'A', a = 'B', d = 'C';
if (n % 2 == 0) { char t = d; d = a; a = t; }
long long total = 1;
for (int i = 0; i < n; i++) total *= 2;
total -= 1;
for (long long i = 1; i <= total; i++) {
if (i % 3 == 1) move(src, tS, dest, tD, s, d);
else if (i % 3 == 2) move(src, tS, aux, tA, s, a);
else if (i % 3 == 0) move(aux, tA, dest, tD, a, d);
}
return 0;
}
