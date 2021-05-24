#pragma once 		  
#include"pch.h"
#include<iostream>
using namespace std;  
class Employee {
private:
	string name;
	string Address;
	string Day_Join;
	float salary;
	float Borrow;
	char Level;	 
	string Code; 	    
	static int count; 
public:
	Employee() = default;
	Employee(string Name, string ADreess, string Day, float _Salary, float _Borrow, char _Level , string code );
	~Employee();
	void SetName(string name);
	string GetName();
	void SetAddress(string Address);
	string getADDress();
	void SetDay(string Day);
	string getDay();
	void  SetSal(float Sal);
	float GetSal();
	void SetBor(float Bor);
	float getBor();
	void SetLevel(char Lev);
	char getVal();
	virtual void Display(); 
	void SetCode(string code); 
	string  GetCode(); 			  
	void MenuMain(); 
	
};
