int findDuplicate(int* nums, int numsSize) {
    int slow = 0;
    int fast = 0;
    slow = nums[slow];
    fast = nums[nums[fast]];

    while(slow != fast){
        slow = nums[slow];
        fast = nums[nums[fast]];
    }

    slow = 0;

    while(slow != fast){
        slow = nums[slow];
        fast = nums[fast];
    }

    return slow;
}