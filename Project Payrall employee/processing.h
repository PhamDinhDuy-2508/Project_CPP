#pragma once
#include "project1.h" 
#include<iostream> 
#include<vector>	 
#include<string>    
enum class Selection {
	_update, del
};
class processing :
	public Employee
{
private : 
	Employee k;  
	vector<Employee> lis;   
	vector<Employee> Data; 
	static int  count; 
	
public:
	processing();		    
	processing(Employee i, vector<Employee> check, vector<Employee> Data) : k{ i }, lis{ check },Data{Data}{}
	void Add(int n );  	   
	void totalCount();	 
	void ModifyInfor(string code); 
	void Delete(string code ); 		  
	void Printdetail();
	void PrintPayrall(string code);   
	void setList(vector<Employee> temp); 
	vector<Employee> AgetLis(); 	  
	void Wirte(Selection _select);
	void  Read();
	int getLis(); 
	void  UPdate();




	~processing();
};

