#include <stdio.h>
int soma(int *v, int n) {
    int total = 0;
    for (int *p = v; p < v + n; p++) total += *p;
    return total;
}
int main(void) {
    int v[] = {1, 2, 3, 4, 5};
    printf("Soma: %d\n", soma(v, 5));
    return 0;
}
