/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* spiralOrder(int** matrix, int matrixSize, int* matrixColSize, int* returnSize) {
    int m = matrixSize;
    int n = matrixColSize[0];
    *returnSize = 0;
    int* ans = malloc(m * n * sizeof(int));
    int top = 0;
    int left = 0;
    int right = n - 1;
    int bottom = m - 1;
   
    while(left <= right && top <= bottom){
        for(int i = left ; i <= right ; i++){
            ans[*returnSize] = matrix[top][i];
            *returnSize += 1;
        }
        top++;
        if(top>bottom){
            break;
        }

        for(int i = top ; i <= bottom ; i++){
            ans[*returnSize] = matrix[i][right];
            *returnSize += 1;
        }
        right--;
        if(left>right){
            break;
        }

        for(int i = right ; i >= left ; i--){
            ans[*returnSize] = matrix[bottom][i];
            *returnSize += 1;
        }
        bottom--;
        if(top>bottom){
            break;
        }

        for(int i = bottom ; i >= top ; i--){
            ans[*returnSize] = matrix[i][left];
            *returnSize += 1;
        }
        left++;
    }

    return ans;
}