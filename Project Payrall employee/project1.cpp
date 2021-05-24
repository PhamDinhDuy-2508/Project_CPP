#include "pch.h"
#include "project1.h" 
#include<iostream>	  
#include<string>

using namespace std;  
int Employee::count = 0;
Employee::Employee(string Name, string ADreess, string Day, float _Salary, float _Borrow, char _Level , string code )
{					   
	this->name = Name; 
	this->Address = ADreess; 
	this->Day_Join = Day; 
	this->Borrow = _Borrow;  
	this->Level = _Level;   
	this->salary = _Salary; 	 
	this->Code = code; 
	count++; 
}
Employee::~Employee(){  
	count--;  
}
void Employee::SetName(string name)
{					    
	this->name = name;
}
string Employee::GetName()
{
	return this->name; 
}
void Employee::SetAddress(string _Address)
{ 
	this->Address = _Address;  
}
string Employee::getADDress()
{
	return this->Address; 
}

void Employee::SetDay(string Day)
{ 
	this->Day_Join = Day; 
}

string Employee::getDay()
{
	return this->Day_Join; 
}
void Employee::SetSal(float Sal)
{ 
	this->salary = Sal; 
}

float Employee::GetSal()
{
	return this->salary; 
}
void Employee::SetBor(float Bor)
{ 
	this->Borrow = Bor; 
}
float Employee::getBor()
{
	return this->Borrow;
}
void Employee::SetLevel(char Lev)
{ 
	this->Level = Lev; 
}

char Employee::getVal()
{
	return this->Level; 
}
void Employee::Display()
{
	cout << this->name << endl;
	cout << this->Address << endl;
	cout << this->Day_Join << endl;
}
void Employee::SetCode(string code)
{ 
	this->Code = code; 	
}
string Employee::GetCode()
{
	return this->Code;
}
void Employee::MenuMain(){ 
	cout << "MENU" << endl; 
	cout << "1:\t" << "Print List : " << endl;   
	cout << "2:\t" << "Add member : " << endl;    
	cout << "3:\t" << "Delete member : " << endl; 
	cout << "4:\t" << "Print member Information : " << endl;  
	cout << "5:\t" << "Modify member record : " << endl;  
}	 

















