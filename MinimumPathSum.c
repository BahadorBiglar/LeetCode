int minPathSum(int** grid, int gridRowSize, int gridColSize) {
    
    int myGrid[gridRowSize][gridColSize]; // To not to change the original grid values
    int row, col, path1, path2;
    
    myGrid[gridRowSize-1][gridColSize-1] = grid[gridRowSize-1][gridColSize-1];
    
    for (col = gridColSize-2; col >= 0; col--)
        myGrid[gridRowSize-1][col] = myGrid[gridRowSize-1][col+1] + grid[gridRowSize-1][col];
    
    for (row = gridRowSize-2; row >= 0; row--)
        myGrid[row][gridColSize-1] = myGrid[row+1][gridColSize-1] + grid[row][gridColSize-1];
    
    for (row = gridRowSize-2; row >= 0; row--)
        for (col = gridColSize-2; col >= 0; col--){
            path1 = myGrid[row+1][col];
            path2 = myGrid[row][col+1];
            myGrid[row][col] = grid[row][col] + ((path1<path2)?path1:path2);
        }
    
    return myGrid[0][0];
}