int* twoSum(int* nums, int numsSize, int target) {
    int i,j;
    int *dst = (int *)malloc(2*sizeof(int));
    for(i = 0; i<=numsSize; i++)
    {
        for(j = i+1;j<=numsSize;j++)
        {
            if(nums[i]+nums[j] == target)
            {
                dst[0] = i;
                dst[1] = j;
            }  
        }
    }
    return dst; 
}
