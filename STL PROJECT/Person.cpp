#include "pch.h"
#include "Person.h" 
#include<map>
Person::Person(string F_name, string S_name, string P_p, string S_p, string Email, string Address, string company)
{
	this->First_name = F_name;
	this->Last_name = S_name;
	this->primary_phoneNumber = P_p;
	this->Secondary_phoneNumber = S_p;
	this->Email_Id = Email;
	this->Address = Address;
	this->Name_Company = company;
}
 string Person::getF_Name() 
{
	return this->First_name;
}
void Person::SetF_Name(string name)
{
	this->First_name = name;
}
string Person::getS_name()
{
	return this->Last_name;
}
void Person::setS_name(string name)
{
	this->Last_name = name;
}
string Person::getP_phone()
{
	return this->primary_phoneNumber;
}
void Person::SetP_phone(string phone)
{
	this->primary_phoneNumber = phone;
}
string Person::getS_phone()
{
	return this->Secondary_phoneNumber;
}
void Person::setS_Phone(string phone)
{
	this->Secondary_phoneNumber = phone;
}
 string Person::get_Email()
{
	return this->Email_Id;
}

void Person::Set_Email(string email)
{
	this->Email_Id = email;
}
string Person::get_Address()
{
	return this->Address;
}
void Person::set_Address(string Add)
{
	this->Address = Add;
}
string Person::get_nameOfCompany()
{
	return this->Name_Company;
}
void Person::set_NameOfCompany(string company)
{
	this->Name_Company = company;
}
void Person::Display() {}
void Person::_group(group _groupState) {  
	if (group::Acquaintance == _groupState) {} 

}
string Person::getGroup_stage()
{
	return string(); 
}
string  Person::get_codeGroup()
{
	return this->code_group; 
}
void Person::set_code(int code)	  
{			  						 
	if (code == 1) { this->code_group  = "Friend";  } 
	if (code == 2) { this->code_group = "Family"; } 
	if (code == 3) { this->code_group = "Acquaintance"; }
	if (code == 4) { this->code_group = "Coworker"; }
}
Person::~Person() {}
