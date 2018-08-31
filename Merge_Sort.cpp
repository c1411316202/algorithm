#include<bits/stdc++.h>
using namespace std ;

void sort( int *nums , int *buf , int begin , int end )
{
	if( begin >= end-1 ) return ;
	int mid = ( begin + end ) / 2 ;
	sort( nums , buf , begin , mid ) ;
	sort( nums , buf , mid , end ) ;
	int index1 , index2 ;
	index1 = begin , index2 = mid ;
	int index = begin ;
	while( index1 < mid && index2 < end )
	{
		while( index1 < mid && index2 < end && nums[index1] <= nums[index2] )
			buf[index++] = nums[index1++] ;
		while( index1 < mid && index2 < end && nums[index1] >= nums[index2] )
			buf[index++] = nums[index2++] ;
	}
	while( index1 < mid )
		buf[index++] = nums[index1++] ;
	while( index2 < end )
		buf[index++] = nums[index2++] ;
	for( int i = begin ; i < end ; i++ )
		nums[i] = buf[i] ;
}

void merge_sort( int *nums , int len )
{
	int* buf = new int[len] ;
	sort( nums , buf , 0 , len ) ;
	delete[] buf ;
}

int main()
{
	clock_t timestart = clock() ;
	int len = 100000 ;
	int* nums = new int[len] ;
	for( int i = 0 ; i < len ; i++ )
		nums[i] = rand() % 1000000007 ;
	merge_sort( nums , len ) ;
	clock_t timeend = clock() ;
	cout << "milli_second:" << timeend - timestart << endl ;
	delete[] nums ;
	return 0 ;
}
