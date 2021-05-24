#pragma once
#include "Person.h"		   
#include<unordered_set> 
#include<memory>			  
#include<vector>	 
#include<unordered_map>		 
#include<map>		  
enum class select {
	Last, First 
};
class Processing :
	public Person	  
{
private : 	   
	vector<shared_ptr<Person>> Per; 
	vector<shared_ptr<Person>> Data; 
	vector<group> group_state; 
	unordered_multimap< string , shared_ptr<Person>> Hash_company ;
	unordered_multimap<string, shared_ptr<Person>> Hash_Group; 	  

public:
	string  Email_id;  
	pair<string, shared_ptr<Person> > Key_ID;		    
	vector<string> key_IID; 
	vector<shared_ptr<Person>> test; 
	Processing(); 
	~Processing(); 			 
	void DisPlayP(shared_ptr<Person> p);
	void Display(vector<shared_ptr<Person>> per);
	void DisplayWithShortF_Name_and_Second(select sel); 
	void DisplayONLYFirstName(); 
	void Display_with_the_Same_Company();  
	void Display_with_the_same_group();   
	 void Create_CompanyHash(  shared_ptr<Person> ptr);
	 void Create_GroupHash(  shared_ptr<Person> ptr) ; 
	//void SetPerson(vector<Perso Per);  		 
	void Search(); 	   
	void Write();  		   
	void Update(); 
	void Read(); 
	vector<shared_ptr<Person>> GetData(); 
	void ADD(int n );  							  
	vector<shared_ptr<Person>> getPerson() {
		return this->Per; 
	}	 
	vector<shared_ptr<Person>> get_data(){}  	   
	void setMap(shared_ptr<Person> ptr) {  
		
		Processing::Create_CompanyHash(ptr);  
		Processing::Create_GroupHash(ptr); 
	}
	// template<typename T , typename T1>  

	void DeleteDub(shared_ptr<Person> ptr) {
		auto it = find(key_IID.begin(), key_IID.end(), ptr->get_Email());
		if (it == key_IID.end()) {	    
			key_IID.push_back(ptr->get_Email());  
			Processing::Create_CompanyHash(ptr);
			Processing::Create_GroupHash(ptr);
		}
		else{}

	}
};						

