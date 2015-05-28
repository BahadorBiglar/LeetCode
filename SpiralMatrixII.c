/**
 * Return an array of arrays.
 * Note: The returned array must be malloced, assume caller calls free().
 */
int** generateMatrix(int n) {
    if (n<=0)
        return NULL;
    
    int **answer;
    int row, col, count, direction, rub, cub, rlb, clb;
    bool is_row;
    
    answer = (int **)malloc(n * sizeof(int *));

    for (col = 0; col < n; col++)
    {
        answer[col] = (int *)malloc(n * sizeof(int));
    }
    
    is_row = true;
    rub = n-1;
    cub = n-1;
    rlb = 1;
    clb = 0;
    direction = +1;
    row=0;
    col=0;
    count = 1;
    
    while (count <= (n*n)){
        answer[row][col] = count;
        count++;
        
        if (is_row){
            if (direction==+1){
                if (col!=cub){
                    col=col+direction;
                }
                else{
                    is_row    = false;
                    direction = +1;
                    cub--;
                    row=row+direction;
                }
            }
            else{
                if (col!=clb){
                    col=col+direction;
                }
                else{
                    is_row    = false;
                    direction = -1;
                    clb++;
                    row=row+direction;
                }
            }
        }
        else{
            if (direction==+1){
                if (row!=rub){
                    row=row+direction;
                }
                else{
                    is_row    = true;
                    direction = -1;
                    rub--;
                    col=col+direction;
                }
            }
            else{
                if (row!=rlb){
                    row=row+direction;
                }
                else{
                    is_row    = true;
                    direction = +1;
                    rlb++;
                    col=col+direction;
                }
            }
        }
    }

    return answer;

}