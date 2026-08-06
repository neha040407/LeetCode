/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* majorityElement(int* nums, int numsSize, int* returnSize) {
    int* ans = malloc(2*(sizeof(int)));
    int count1 = 0 , count2 = 0;
    int candidate1 , candidate2;
    *returnSize = 0;

    for(int i = 0 ; i < numsSize ; i++){
        if(nums[i] == candidate1){
            count1++;
        }
        else if(nums[i] == candidate2){
            count2++;
        }
        else if(count1 == 0){
            candidate1 = nums[i];
            count1++;
        }
        else if(count2 == 0){
            candidate2 = nums[i];
            count2++;
        }
        else{
            count1--;
            count2--;
        }
    }

    count1 = 0 ; 
    count2 = 0;

    for(int i = 0 ; i < numsSize ; i++){
        if(nums[i] == candidate1){
            count1++;
        }
        else if(nums[i] == candidate2){
            count2++;
        }
    }

    if(count1 > numsSize/3){
        ans[*returnSize] = candidate1;
        *returnSize +=1 ;
    }
    
    if(count2 > numsSize/3){
        ans[*returnSize] = candidate2;
        *returnSize += 1;
    }

    return ans;
}