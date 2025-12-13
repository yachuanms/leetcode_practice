#include <stdio.h>
#include <stdbool.h>

// 你要自己實作這個函式
bool isValidSudoku(char** board, int boardSize, int* boardColSize){
    //每一列不能有重複數字（1–9）
    //每一行不能有重複數字（1–9）
    //每個 3x3 小方格不能有重複數字

    int len = boardColSize[0]; //9

    //行
    for(int r = 0 ; r < len; r++){
        bool hash1[9] = {false};
        for(int c = 0; c < len; c++){
            if(board[r][c] == '.'){
                continue;
            }else{
                int idx = board[r][c] -'1';  // '1' → 0, '2' → 1, ... '9' → 8
                if(hash1[idx] == true){
                    //printf("1: [%d][%d] idx: %d\n",r, c, idx);
                    return false;
                }else{
                    hash1[idx] = true;
                }
            }
        }
    }

    //列
    for(int c = 0 ; c < len; c++){
        bool hash2[9] = {false};
        for(int r = 0; r < len; r++){
            if(board[r][c] == '.'){
                continue;
            }else{
                int idx = board[r][c] -'1';  // '1' → 0, '2' → 1, ... '9' → 8
                if(hash2[idx] == true){
                    //printf("2: [%d][%d] idx: %d\n",r, c, idx);
                    return false;
                }else{
                    hash2[idx] = true;
                }
            }
        }
    }

    //3*3
    int times = len/3;
    for(int r = 0; r < times; r++){
        for(int c = 0; c < times; c++){
            bool hash3[9] = {false};

            for(int r1 = r*3; r1 < r*3+3; r1++){
                for(int c1 = c *3; c1< c*3+3; c1++){
                    if(board[r1][c1] == '.'){
                        continue;
                    }
                    int idx = board[r1][c1]-'1';
                    if(hash3[idx] == true){
                        return false;
                    }else{
                        hash3[idx] = true;
                    }
                }
            }
        }
    }

    return true;
}

int main() {
    // 測試 1：有效的數獨盤
    char boardData1[9][9] = {
        {'5','3','.','.','7','.','.','.','.'},
        {'6','.','.','1','9','5','.','.','.'},
        {'.','9','8','.','.','.','.','6','.'},
        {'8','.','.','.','6','.','.','.','3'},
        {'4','.','.','8','.','3','.','.','1'},
        {'7','.','.','.','2','.','.','.','6'},
        {'.','6','.','.','.','.','2','8','.'},
        {'.','.','.','4','1','9','.','.','5'},
        {'.','.','.','.','8','.','.','7','9'}
    };

    char* board1[9];
    for (int i = 0; i < 9; i++) {
        board1[i] = boardData1[i];
    }
    int colSizes1[9] = {9,9,9,9,9,9,9,9,9};

    printf("Test 1 (valid): %s\n",
        isValidSudoku(board1, 9, colSizes1) ? "true" : "false");

    // 測試 2：不合法的數獨盤（同一列有重複的 '5'）
    char boardData2[9][9] = {
        {'5','3','.','.','7','.','.','.','5'}, // 這列多了一個 '5'
        {'6','.','.','1','9','5','.','.','.'},
        {'.','9','8','.','.','.','.','6','.'},
        {'8','.','.','.','6','.','.','.','3'},
        {'4','.','.','8','.','3','.','.','1'},
        {'7','.','.','.','2','.','.','.','6'},
        {'.','6','.','.','.','.','2','8','.'},
        {'.','.','.','4','1','9','.','.','5'},
        {'.','.','.','.','8','.','.','7','9'}
    };

    char* board2[9];
    for (int i = 0; i < 9; i++) {
        board2[i] = boardData2[i];
    }
    int colSizes2[9] = {9,9,9,9,9,9,9,9,9};

    printf("Test 2 (invalid): %s\n",
        isValidSudoku(board2, 9, colSizes2) ? "true" : "false");

    return 0;
}
