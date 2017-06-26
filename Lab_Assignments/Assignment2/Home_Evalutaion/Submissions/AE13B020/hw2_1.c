#include <stdio.h>

static int N;

void getTemp(int mat[N][N], int temp[N][N], int p, int q, int n) {
    int i = 0, j = 0, row, col;
    for (row = 0; row < n; row++) {
        for (col = 0; col < n; col++) {
            if (row != p && col != q) {
                temp[i][j++] = mat[row][col];
                if (j == n - 1) {
                    j = 0;
                    i++;
                }
            }
        }
    }
}

int determinant(int mat[N][N], int n) {
    int i, Det = 0, temp[N][N], sign = 1;
    if (n == 1)
        return mat[0][0];
    for (i = 0; i < n; i++) {
        getTemp(mat, temp, 0, i, n);
        Det += sign * mat[0][i] * determinant(temp, n - 1);
        sign = -sign;
    }
    return Det;
}

void main() {
    int n, i, j;
    scanf("%d", &n);
    int matrix[n][n];
    for (i = 0; i < n; i++) {
        for (j = 0; j < n; j++) {
            scanf("%d", &matrix[i][j]);
        }
    }
    N = n;
    printf("%d\n", determinant(matrix, N));
}