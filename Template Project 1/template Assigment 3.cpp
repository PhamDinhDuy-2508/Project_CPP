#include"pch.h"
#include<iostream> 
using namespace std;
enum class Connection {
	Employee,
	Contact
};    
template <typename T >   

string CreatObject() {		 
	return " "; 
} 
template<typename T , typename...values> 
T CreatObject(T&&a, values&&...args) { 
	cout << a << endl;  
	return 1; 	  
	//CreatObject(forward<values>(args)...); 
}	   
class Employee {
protected  :  
	string name;  
	int ID;  
	long int Salary;  
public :  	   
	Employee() = default; 
	void SetName(string Name) { 
		this->name = Name; 
	}					    
	void SetID(int Id) {this->ID = Id; }				    
	void setSalary(long int sal) {this->Salary = sal; }
};			 
template<typename T, typename...values>
Employee *CreatObject(string  NAME, int Id, long int sala) {    
	Employee *k = new Employee(); 
	k->SetID(Id); 
	k->SetName(NAME); 
	k->setSalary(sala); 
	return  k; 
}							  
class  Contact {  
private : 
	string name;  
	string phonenumber; 
	string Address;  
	string email;  
public:  
	Contact() = default;  
	void SetName(string _name) { this->name = _name;  } 
	void setPhone(string Phone) { this->phonenumber = Phone;  } 
	void setAddress(string Address) { this->Address = Address;  } 
	void setEmail(string email) { this->email = email;  } 	
};					 
template<typename T1 , typename...values>
Contact *CreatObject(string  NAME,  string Phone, string add, string email) { 
	Contact*contact = new Contact();  
	contact->setAddress(add);  
	contact->SetName(NAME);  
	contact->setEmail(email); 
	contact->setPhone(Phone); 
	return contact; 
}
int main() {
	int  p = CreatObject<int>(6); 
	string k = CreatObject<string>();   
	Employee*em = CreatObject<Employee>("p", 123, 12323);  
	Contact*con = CreatObject<Contact>("Pham", "0702949892", "@QWEQWE", "123123123"); 
	return 0; 
}
