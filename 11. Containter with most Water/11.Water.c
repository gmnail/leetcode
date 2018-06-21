
//超出时间限制
int maxArea(int* height, int heightSize) {
    int i, j;
	int sum, tmp = 0;
	for(i = 1; i < heightSize; i++) {
		for(j = heightSize-1; j > i; j--)
		{
			if(height[j] < height[i])
				sum = height[j] * (j - i);
			else
				sum = height[i] * (j - i);
			if(sum > tmp)
				tmp = sum;
		}
	}
	return tmp;
}



//双指针方式——速度更快
int maxArea(int* height, int heightSize) {
    int i = 0, j = heightSize-1;
	int sum = 0,tmp =0;

	while(i < j)
	{
		if(height[i] < height[j]) {
			sum = height[i] * (j - i);
			i++;
		}
		else {
			sum = height[j] * (j - i);
			j--;
		}
        if(sum > tmp)
            tmp = sum;
	}

	return tmp;
}






