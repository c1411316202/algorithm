#include<bits/stdc++.h>
using namespace std ;

void sort( int *nums , int len )
{
	for( int i = 0 ; i < len ; i++ )
		for( int j = 1 ; j < len - i ; j++ )
		{
			if( nums[j] > nums[j-1] )
				continue ;
			nums[j] += nums[j-1] ;
			nums[j-1] = nums[j] - nums[j-1] ;
			nums[j] = nums[j] - nums[j-1] ;
		}
}

int main()
{
	clock_t timestart = clock() ;
	int len = 100000 ;
	int* nums = new int[len] ;
	for( int i = 0 ; i < len ; i++ )
		nums[i] = rand() % 1000000007 ;
	sort( nums , len ) ;
	clock_t timeend = clock() ;
	cout << "milli_second:" << timeend - timestart << endl ;
	delete[] nums ;
	return 0 ;
}
