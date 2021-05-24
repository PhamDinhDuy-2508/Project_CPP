#include"pch.h" 
#include<iostream> 			   
#include<utility>
#include<vector> 
#include<algorithm>
using namespace std; 
template<typename T>
T Max(T a, T b) {	 
	//a = 4; 
	auto  check = [](int d , int c )->T {	 
		if (c > d)return c;  
		else return d; 
	}(a,b); 
	return check; 
} 								 
template<typename T> 
bool Greater(T a, T b) {
	auto check = [](int d, int c) ->bool { 
		if (c > d)return true;  
		else return false; 
	}(a,b);  		   
	return check; 
}		 
template<typename T>  
bool Less(T a, T b) {
	auto check = [](int d, int c)->bool {
		if (c > d) return false;   
		else return true; 
	}(a,b);  
	return check;
}				
template<typename T , typename callBack , int size>  
void Foreach(T(&arr)[size] , callBack call) { 
	for (auto x : arr) {
		call(x); 
	}
}	  
template<typename T , int size> 
pair<T, T > MinMax(int begin, int  end ,  T (&arr)[size]) {    
	T x1;  
	T x2; 		 
	pair<T, T> i; 	  
	int k = arr[0]; 
	Foreach(arr, [&k](auto x) {   
		if (k < x) { k = x;  }
	});		 				   
	i.first = k;    
	int y = arr[0];
	Foreach(arr, [&y](auto x) {
		if (y > x) { y = x;  }
	});		 
	i.second = y; 
	return  i; 
}
int main() {
	cout <<  Max(3, 2);   	 
	cout << Greater(2, 3);  
	cout << Less(3, 2); 
	int k[]{ 1,2,3,4 };  	 
	int n = sizeof(k) / sizeof(k[0]);  
	pair<int, int> test1; 
	test1 = MinMax<int>(0, n, k );    
	cout << "Max Element is : " << test1.first << endl;  
	cout << "Min Element is : " << test1.second << endl; 
	return  0; 					  						   
	system("pause"); 

	
}