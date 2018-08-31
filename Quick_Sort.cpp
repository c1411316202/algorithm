#include<bits/stdc++.h>
using namespace std ;

void sort( int *nums , int begin , int end )
{
	int left = begin , right = end - 1 ;
	if( left >= right ) return ;
	int tmp = nums[begin] ;
	while( right > left )
	{
		while( right > left && nums[right] >= tmp )
			--right ;
		nums[left] = nums[right] ;
		nums[right] = tmp ;
		while( right > left && nums[left] <= tmp )
			++left ;
		nums[right] = nums[left] ;
		nums[left] = tmp ;
	}
	sort( nums , begin , left ) ;
	sort( nums , left+1 , end ) ;
	
}

int main()
{
	clock_t timestart = clock() ;
	int len = 100000 ;
	int* nums = new int[len] ;
	for( int i = 0 ; i < len ; i++ )
		nums[i] = rand() % 1000000007 ;
	sort( nums , 0 , len ) ;
	
	clock_t timeend = clock() ;
	cout << "milli_second:" << timeend - timestart << endl ;
	delete[] nums ;
	return 0 ;
}
