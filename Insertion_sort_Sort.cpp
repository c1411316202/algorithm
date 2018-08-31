#include<bits/stdc++.h>
using namespace std ;

void insertion_sort( int *nums , int len )
{
	for( int i = 1 ; i < len ; i++ )
	{
		int k = i-1 ;
		int temp = nums[i] ;
		while( k >= 0 && nums[k] > temp )
			nums[k+1] = nums[k--] ;
		nums[k+1] = temp ;
	}
}

int main()
{
	clock_t timestart = clock() ;
	int len = 100000 ;
	int* nums = new int[len] ;
	for( int i = 0 ; i < len ; i++ )
		nums[i] = rand() % 1000000007 ;
	insertion_sort( nums , len ) ;
	
	clock_t timeend = clock() ;
	cout << "milli_second:" << timeend - timestart << endl ;
	delete[] nums ;
	return 0 ;
}
