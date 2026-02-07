#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

bool searchMatrix(int** matrix, int matrixSize, int* matrixColSize, int target) {
    int colLen = matrixColSize[0];
    int len = matrixSize*colLen;
    int left = 0;
    int right = len -1;

    while(left  <= right){
        //(left + right) / 2：概念對，但可能 overflow
        //寫 binary search，一律用int mid = left + (right - left) / 2;
        int mid = left + (right - left) / 2;
        int val = matrix[mid/colLen][mid%colLen];
        
        if(target== val){
            return true;
        }else if(target > val){
            left = mid+1;
        }else{
            right = mid-1;
        }
    }   

    return false;
}


static int** makeMatrix(int rows, int cols, int data[]) {
    int** m = (int**)malloc(sizeof(int*) * rows);
    for (int r = 0; r < rows; r++) {
        m[r] = (int*)malloc(sizeof(int) * cols);
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
    int data1[] = {1,3,5,7,10,11,16,20,23,30,34,60};
    int rows1 = 3, cols1 = 4;
    int* colSize1 = (int*)malloc(sizeof(int) * rows1);
    for (int i = 0; i < rows1; i++) colSize1[i] = cols1;
    int** mat1 = makeMatrix(rows1, cols1, data1);

    printf("%d (expect 1)\n", searchMatrix(mat1, rows1, colSize1, 3));
    printf("%d (expect 0)\n", searchMatrix(mat1, rows1, colSize1, 13));
    printf("%d (expect 1)\n", searchMatrix(mat1, rows1, colSize1, 60));
    printf("%d (expect 0)\n", searchMatrix(mat1, rows1, colSize1, 0));

    freeMatrix(mat1, rows1);
    free(colSize1);
    return 0;
}
