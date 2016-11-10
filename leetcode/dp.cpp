Maximum Subarray
Find the contiguous subarray within an array (containing at least one number) which has the largest sum.
For example, given the array [−2,1,−3,4,−1,2,1,−5,4],
the contiguous subarray [4,−1,2,1] has the largest sum = 6.

假设A(0, i)区间存在k，使得[k, i]区间是以i结尾区间的最大值， 定义为Max[i], 在这里，当求取Max[i+1]时，
Max[i+1] = Max[i] + A[i+1],  if (Max[i] + A[i+1] >0)
                = 0, if(Max[i]+A[i+1] <0)，如果和小于零，A[i+1]必为负数，没必要保留，舍弃掉
