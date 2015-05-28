int uniquePaths(int m, int n) {
    int path[m][n];
    
    path[0][0]=1;
    for (int col = 1; col<n; col++)
        path[0][col]=1;
    
    for (int row = 1; row<m; row++)
        path[row][0]=1;

    for (int row = 1; row<m; row++)
        for (int col = 1; col<n; col++)
            path[row][col]=path[row-1][col]+path[row][col-1];
    
    return path[m-1][n-1];
}