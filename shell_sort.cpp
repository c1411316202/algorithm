#include<bits/stdc++.h>
using namespace std ;

void shell_sort( int *nums , int len )
{
	int n = len ;
	for( n /= 2 ; n > 0 ; n /= 2 )
	{
		for( int i = 0 ; i < n ; i++ )
		{
			for( int j = i + n ; j < len ; j += n )
			{
				int temp = nums[j] ;
				int k = j - n ;
				while( k >= 0 && nums[k] > temp )
				{
					nums[k+n] = nums[k] ;
					k -= n ;
				}
				nums[k+n] = temp ;
			}
		}
	}
}

int main()
{
	clock_t timestart = clock() ;
	int len = 100000 ;
	int* nums = new int[len] ;
	for( int i = 0 ; i < len ; i++ )
		nums[i] = rand() % 1000000007 ;
	shell_sort( nums , len ) ;
	clock_t timeend = clock() ;
	cout << "milli_second:" << timeend - timestart << endl ;
	delete[] nums ;
	return 0 ;
}
