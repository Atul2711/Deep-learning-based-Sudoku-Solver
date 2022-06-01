#include <iostream>
using namespace std;

bool isValid(int &grid[9][9],int i,int j, int k){

    for(int x=1;x<=9;x++){
        if(grid[i][x]==k) return false;
        if(grid[x][j]==k) return false;
    }

    int sbi=i-i%3;
    int sbj=j-j%3;

    for(int m=0;m<3;m++){
        for(int n=0;n<3;n++){
            if(grid[m+sbi][n+sbj]==k) return false;
        }
    }

    return true;
}

bool solveSudoku(int &grid[9][9],int row,int col){

    if(row==9 and col==9){
        return true;
    }

    if(col==9){
        row+=1;
        col=0;
    }

    if(grid[row][col]>0){
        return solveSudoku(grid,row,col+1);
    }

    for(int i=1;i<=9;i++){
        if(isValid(grid,row,col,i)){
            grid[row][col]=i;
            if(solveSudoku(grid,row,col+1)) return true;
        }
        grid[row][col]=0;

    }
    return false;
}
int main()
{
    int grid[9][9] = {{0, 0, 0, 2, 6, 0, 7, 0, 1},
                      {6, 8, 0, 0, 7, 0, 0, 9, 0},
                      {1, 9, 0, 0, 0, 4, 5, 0, 0},
                      {8, 2, 0, 1, 0, 0, 0, 4, 0},
                      {0, 0, 4, 6, 0, 2, 9, 0, 0},
                      {0, 5, 0, 0, 0, 3, 0, 2, 8},
                      {0, 0, 9, 3, 0, 0, 0, 7, 4},
                      {0, 4, 0, 0, 5, 0, 0, 3, 6},
                      {7, 0, 3, 0, 1, 8, 0, 0, 0}};

if ((solveSudoku(grid,0,0)){
        sudoku_Display(grid);
}
    
else{
        cout << "Solution not possible";
}
    return 0;
}