/**
 * Return an array of arrays of size *returnSize.
 * The sizes of the arrays are returned as *returnColumnSizes array.
 * Note: Both returned array and *columnSizes array must be malloced, assume caller calls free().
 */
int** fourSum(int* nums, int numsSize, int target, int* returnSize, int** returnColumnSizes) {
    int **ans = malloc(sizeof(int *));
    *returnColumnSizes = malloc(sizeof(int));
    *returnSize = 0;
    int k , l , temp;
    long long sum;

    for (int i = 0; i < numsSize - 1; i++) {
        for (int j = 0; j < numsSize - i - 1; j++) {
            if (nums[j] > nums[j + 1]) {
                temp = nums[j];
                nums[j] = nums[j + 1];
                nums[j + 1] = temp;
            }
        }
    }

    for(int i = 0 ; i < (numsSize - 3); i++){

        if(i != 0 && nums[i] == nums[i-1]){
            continue;
        }
        
        for(int j = i + 1 ; j < (numsSize-2) ; j++){

            if(j != i + 1 && nums[j] == nums[j-1]){
                continue;
            }

            k = j + 1;
            l = numsSize - 1;

            while(k < l){
                sum = (long long)nums[i] + (long long)nums[j] + (long long)nums[k] + (long long)nums[l];
                if(sum == target){
                    ans = realloc(ans,(*returnSize + 1)*sizeof(int *));

                    ans[*returnSize] = malloc(4 * sizeof(int));

                    ans[*returnSize][0] = nums[i];
                    ans[*returnSize][1] = nums[j];
                    ans[*returnSize][2] = nums[k];
                    ans[*returnSize][3] = nums[l];

                    *returnColumnSizes = realloc(*returnColumnSizes,(*returnSize + 1)*sizeof(int));
                    (*returnColumnSizes)[*returnSize] = 4;

                    (*returnSize)++;
                    k++;
                    l--;

                    while(k < l && nums[k] == nums[k-1])
                        k++;

                    while(k < l && nums[l] == nums[l+1])
                        l--;
                }
                else if(sum > target){
                    l--;
                }
                else{
                    k++;
                }
            }
        }

    }

    return ans;

}