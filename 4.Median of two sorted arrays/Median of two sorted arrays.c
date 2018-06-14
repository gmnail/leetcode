//复杂度，也就是log(n+m) 看见log我们所能想到的肯定是用到了分冶法，不然不会出现这个玩意的。
double findMedianSortedArrays(int* nums1, int nums1Size, int* nums2, int nums2Size) {
    int s[nums1Size+nums2Size];
	int i,R,L;
	int j = nums1Size+nums2Size;
	
	for(i = 0; i <= (j/2);)
	{
		if(L == nums1Size)
		{
			while(i < (j/2))
				s[i++] = nums2[R++];
		}
		else if(R == nums2Size)
		{
			while(i < (j/2))
				s[i++] = nums1[L++];
		}
		else
		{
			if(nums1[L] < nums2[R])
			{
				s[i++] = nums1[L++];
			}
			else{
				s[i++] = nums2[R++];
			}
		}
	}
	
	if(j%2 == 1) {
		return s[i-1];			//s[i++] = nums1[L++]; 赋值之后i自加了1
	}
	else {
		return ((s[i-2] + s[i-1])/2.0);
	}
}









