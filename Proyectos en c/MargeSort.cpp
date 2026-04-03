#include <stdio.h>
#define N 10

void mergesort(int a[], int low, int high);
void merge(int a[], int low, int mid, int high);

int main() {
    int i;
    int a[N] = {9, 7, 10, 8, 2, 4, 6, 5, 1, 3};

    mergesort(a, 0, N - 1);

    printf("Arreglo ordenado:\n");
    for (i = 0; i < N; i++)
        printf("%d ", a[i]);
    printf("\n");

    return 0;
}

void mergesort(int a[], int low, int high) {
    int mid;
    if (low < high) {
        mid = (low + high) / 2;
        mergesort(a, low, mid);
        mergesort(a, mid + 1, high);
        merge(a, low, mid, high);
    }
}

void merge(int a[], int low, int mid, int high) {
    int b[N];
    int h = low, i = low, j = mid + 1, k;

    while (h <= mid && j <= high) {
        if (a[h] <= a[j]) {
            b[i] = a[h];
            h++;
        } else {
            b[i] = a[j];
            j++;
        }
        i++;
    }

    if (h > mid) {
        for (k = j; k <= high; k++) {
            b[i] = a[k];
            i++;
        }
    } else {
        for (k = h; k <= mid; k++) {
            b[i] = a[k];
            i++;
        }
    }

    for (k = low; k <= high; k++)
        a[k] = b[k];
}

