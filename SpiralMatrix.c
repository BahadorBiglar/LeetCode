/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* spiralOrder(int** matrix, int matrixRowSize, int matrixColSize) {
    int *answer = (int *)malloc(matrixRowSize*matrixColSize*sizeof(int));
    if (matrixRowSize * matrixColSize == 0)
        return answer;
    
    int row, col, count, direction, rub, cub, rlb, clb;
    bool is_row;
    
    is_row = true;
    rub = matrixRowSize-1;
    cub = matrixColSize-1;
    rlb = 1;
    clb = 0;
    direction = +1;
    row=0;
    col=0;
    count = 0;
    
    while (count < (matrixRowSize*matrixColSize)){
        answer[count] = matrix[row][col];
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