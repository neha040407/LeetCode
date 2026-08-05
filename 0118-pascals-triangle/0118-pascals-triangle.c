/**
 * Return an array of arrays of size *returnSize.
 * The sizes of the arrays are returned as *returnColumnSizes array.
 * Note: Both returned array and *columnSizes array must be malloced, assume caller calls free().
 */
int** generate(int numRows, int* returnSize, int** returnColumnSizes) {
    int **arr = malloc(numRows*sizeof(int*));
    *returnColumnSizes = malloc(numRows * sizeof(int));   //allocating this cuz its an array of the lengths of each row. so we gotta giv it the size of no of rows
    *returnSize = numRows;

    int *subarr = malloc(sizeof(int));
    subarr[0] = 1;

    arr[0] = subarr;
    (*returnColumnSizes)[0] = 1;

    for(int i = 1 ; i < numRows ; i++){
        subarr = malloc((i+1)*sizeof(int));
        subarr[0] = 1;
        subarr[i] = 1;
        for(int j = 1 ; j < i ; j++){
            subarr[j] = arr[i-1][j-1] + arr[i-1][j];
        }
        arr[i]=subarr;
        (*returnColumnSizes)[i] = i + 1;
    }

    return arr;
}