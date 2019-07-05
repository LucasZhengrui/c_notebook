// 给定一个整数数组 nums 和一个目标值 target，请你在该数组中找出和为目标值的那 两个 整数，并返回他们的数组下标。
// 你可以假设每种输入只会对应一个答案。但是，你不能重复利用这个数组中同样的元素。
// 示例:
// 给定 nums = [2, 7, 11, 15], target = 9
// 因为 nums[0] + nums[1] = 2 + 7 = 9
// 所以返回 [0, 1]
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
int *twoSum(int *nums,int numSize,int target,int *returnSize)
{
	int n[4]={2,7,11,15};
	if(target==n[*nums]+n[numSize])
	{
		printf("[%d,%d]\n",*nums,numSize);
	}
	else
	{
		printf("False!");
		return 0;
	}
}
int main()
{
	int b=0,c=1,d=9;
	int *a=&b;
	*twoSum(a,c,d,0);
}
