#include "dynamic_m.h"
#include <malloc.h>

void Create(int **x, int n) {
    *x = (int *)malloc(n * sizeof(int));
    return;
}

void Vvod(FILE *in, int *x, int n) {
    for (int i = 0; i < n; i++) {
        fscanf(in, "%i", &x[i]);
    }
    return;
}

int sum(int *x, int n) {
    int sum = 0;
    for (int i = 0; i < n; i++) {
        if (x[i] >= 0) {
            sum += x[i];
        }
    }
    return sum;
}


int first_pos(int *x, int n) {
    int i = 0;
    int fl = 1;
    while (i < n && fl) {
        if (x[i] > 0) fl = 0;
        else i += 1;
    }
    return i;
}


int min_pos(int *x, int n) {
    int start = first_pos(x, n);
    int min = x[start];

    for (int j = start + 1; j < n; j++) {
        if (x[j] > 0 && x[j] < min) {
            min = x[j];
        }
    }
    return min;
}

void Ochistka(int **x) {
    free((*x));
    return;
}
