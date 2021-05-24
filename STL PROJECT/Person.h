#pragma once 
#include<iostream>  
#include<string> 
#include<memory> 
#include<vector>
using namespace std;
enum class group {
	Friend, Family,
	Coworker, Acquaintance
};				 

class Person {
private:
	string	First_name;
	string Last_name;
	string primary_phoneNumber;
	string 	Secondary_phoneNumber;
	string Email_Id;
	string Address;
	string Name_Company; 
	string Group;  
	string  code_group; 
public:
	Person() = default;
	Person(string F_name, string S_name, string P_p, string S_p, string Email, string Address, string company);
	string    getF_Name();
	void      SetF_Name(string name);
	string 	  getS_name();
	void      setS_name(string phone);
	string 	  getP_phone();
	void	  SetP_phone(string phone);
	string	  getS_phone();
	void	  setS_Phone(string phone);
	string    get_Email(); 
	void	  Set_Email(string email);
	string	  get_Address();
	void	  set_Address(string Add);
	string	  get_nameOfCompany();
	void      set_NameOfCompany(string company);
	virtual void  Display();
	void virtual _group(group _groupState);
	virtual string getGroup_stage();   
	string get_codeGroup(); 		  
	void set_code(int code); 				  

	~Person();
};						   			

