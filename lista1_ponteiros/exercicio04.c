#include <stdio.h>
int main(void) {
    int v[5] = {2, 4, 6, 8, 10};
    int *p = v;
    printf("%d\n", *p);
    printf("%d\n", *(p + 2));
    printf("%d\n", p[3]);
    printf("%d\n", *p + 1);
    printf("%d\n", *(v + 4));
    return 0;
}
