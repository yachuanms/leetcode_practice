#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

//每一列由左到右遞增
//每一行由上到下遞增

bool searchMatrix(int** matrix, int matrixSize, int* matrixColSize, int target) {
    int colSize = matrixColSize[0];
    int rowSize = matrixSize;
    //從右上角開始
    //比他大代表當前col太小 c--;
    //比她小代表當前row太大 r++;
    int r = 0;
    int c = colSize-1;
    //c--所以是要檢查下界 不是檢查c < colSize!!
    while(r< rowSize && c >=0 ){
        if(matrix[r][c]== target){
            return true;
        }else if(matrix[r][c] > target){
            c--;
        }else{
            r++;
        }
    }

    return false;
}


static int** makeMatrix(int rows, int cols, int data[]) {
    int** m = malloc(sizeof(int*) * rows);
    for (int r = 0; r < rows; r++) {
        m[r] = malloc(sizeof(int) * cols);
        for (int c = 0; c < cols; c++) {
            m[r][c] = data[r * cols + c];
        }
    }
    return m;
}

static void freeMatrix(int** m, int rows) {
    for (int r = 0; r < rows; r++) free(m[r]);
    free(m);
}

int main() {
    int data[] = {
        1,  4,  7, 11, 15,
        2,  5,  8, 12, 19,
        3,  6,  9, 16, 22,
        10,13, 14,17, 24,
        18,21, 23,26, 30
    };

    int rows = 5, cols = 5;
    int* colSize = malloc(sizeof(int) * rows);
    for (int i = 0; i < rows; i++) colSize[i] = cols;

    int** mat = makeMatrix(rows, cols, data);

    printf("%d (expect 1)\n", searchMatrix(mat, rows, colSize, 5));
    printf("%d (expect 0)\n", searchMatrix(mat, rows, colSize, 20));
    printf("%d (expect 1)\n", searchMatrix(mat, rows, colSize, 30));

    freeMatrix(mat, rows);
    free(colSize);
    return 0;
}
