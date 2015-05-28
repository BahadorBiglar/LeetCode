int minimumTotal(int **triangle, int numRows) {
    int row, col;
    
    for(row = numRows-2; row>=0; row--)
        for(col = 0; col<=row; col++)
            triangle[row][col] += ((triangle[row+1][col] < triangle[row+1][col+1]) ? (triangle[row+1][col]):(triangle[row+1][col+1]));
    return triangle[0][0];
}