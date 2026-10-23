#include <stdio.h>
void troca_vizinhos(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}
int main(void) {
    int v[] = {10, 20, 30, 40, 50, 60};
    const int n = (int)(sizeof(v) / sizeof(v[0]));
    for (int i = 0; i < n; i += 2) troca_vizinhos(&v[i], &v[i + 1]);
    for (int i = 0; i < n; i++) printf("%d%c", v[i], i == n - 1 ? '\n' : ' ');
    return 0;
}
