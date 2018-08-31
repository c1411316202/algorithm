#include<bits/stdc++.h>
using namespace std ;

void heap_adjust( int *nums , int i , int len )
{
	if( i >= len ) return ;
	int temp = i ;
	if( 2 * i + 1 < len && nums[2*i+1] > nums[temp] ) temp = 2*i + 1 ;
	if( 2 * i + 2 < len && nums[2*i+2] > nums[temp] ) temp = 2*i + 2 ;
	if( temp == i ) return ;
	nums[i] += nums[temp] ;
	nums[temp] = nums[i] - nums[temp] ;
	nums[i] = nums[i] - nums[temp] ;
	heap_adjust( nums , temp , len ) ;
}

void make_heap( int *nums , int len )
{
	int i = len / 2 ;
	while( i >= 0 )
	{
		heap_adjust( nums , i , len ) ;
		i-- ;
	}
}

void heap_sort( int *nums , int len )
{
	make_heap( nums , len ) ;
	while( len-- )
	{
		int temp = nums[len] ;
		nums[len] = nums[0] ;
		nums[0] = temp ;
		heap_adjust( nums , 0 , len ) ;
	}
}

int main()
{
	clock_t timestart = clock() ;
	int len = 100000 ;
	int* nums = new int[len] ;
	for( int i = 0 ; i < len ; i++ )
		nums[i] = rand() % 1000000007 ;
	heap_sort( nums , len ) ;
	clock_t timeend = clock() ;
	cout << "milli_second:" << timeend - timestart << endl ;
	delete[] nums ;
	return 0 ;
}
