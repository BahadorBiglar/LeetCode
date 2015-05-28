int uniquePathsWithObstacles(int **obstacleGrid, int m, int n){
    int path[m][n];
    
    if (obstacleGrid[0][0]==0)
        path[0][0]=1;
    else
        path[0][0]=0;
    
    for (int col = 1; col<n; col++)
        if (obstacleGrid[0][col]==0)
            path[0][col]=path[0][col-1];
        else
            path[0][col]=0;
    
    for (int row = 1; row<m; row++)
        if (obstacleGrid[row][0]==0)
            path[row][0]=path[row-1][0];
        else
            path[row][0]=0;
        ;

    for (int row = 1; row<m; row++)
        for (int col = 1; col<n; col++)
            if (obstacleGrid[row][col]==0)
                path[row][col]=path[row-1][col]+path[row][col-1];
            else
                path[row][col]=0;
    
    return path[m-1][n-1];

}