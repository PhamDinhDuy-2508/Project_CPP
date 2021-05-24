#include"pch.h"
#include<iostream> 	  
#include<vector>	
#include<string> 	 
using namespace std;
template<typename T, typename...values>
T binarySearch(T&&a, values&&...args) {
	return 1;
}
template<typename T1, typename...value>
int binarySearch(vector<T1> arr, string x, int n) {
	auto it = find(arr.begin(), arr.end(), x);

	if (it != arr.end())
	{
		int index = it - arr.begin();
		return index; 
	}
	else {
		return -1; 
	}		   
}


