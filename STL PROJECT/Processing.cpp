#include "pch.h"
#include "Processing.h" 
#include<algorithm> 
#include<unordered_set> 
#include<unordered_map>		  
#include<map>			 
#include<fstream>			    
#include<set>
#include<iomanip>
Processing::Processing(){}
Processing::~Processing()
{}
void Processing::DisPlayP(shared_ptr<Person> x)
{									 
	cout << "->First Name :" << "\t\t" << x->getF_Name() << endl;
	cout << "->Second Name :" << "\t\t" << x->getS_name() << endl;
	cout << "->Primary Phonenumber :" << "\t" << x->getP_phone() << "|" << endl;
	cout << "->Second Phonenumber :" << "\t" << x->getS_phone() << "|" << endl;
	cout << "->Address :" << "\t\t" << x->get_Address() << endl;
	cout << "->Email_id:" << "\t\t" << x->get_Email() << endl;
	cout << "->Company: " << "\t\t" << x->get_nameOfCompany() << endl;
	cout << "***************** \n";
}
void Processing::Display(vector<shared_ptr<Person>> Per){ 					   
	for (auto x : Per) {
		cout << "->First Name :" << "\t\t"<< x->getF_Name() << endl;
		cout << "->Second Name :" << "\t\t" << x->getS_name() << endl;
		cout << "->Primary Phonenumber :" << "\t" << x->getP_phone() << endl;
		cout << "->Second Phonenumber :" << "\t" << x->getS_phone() << endl;
		cout << "->Address :" << "\t\t" << x->get_Address() << endl;
		cout << "->Email_id:" << "\t\t" << x->get_Email() << endl;
		cout << "->Company:" << "\t\t" << x->get_nameOfCompany() << endl;
		cout << "***************** \n";  
	}
}
void Processing::DisplayWithShortF_Name_and_Second(select s_sele){ 	 
	vector<shared_ptr<Person>>  vectorPerson;	   
	vectorPerson = Processing::GetData(); 
	if (select::First == s_sele) {			    
		sort(vectorPerson.begin(), vectorPerson.end(), []( auto &e1,  auto &e2) {
			return e1->getF_Name() < e2->getF_Name();
		});
	}							   
	else if (select::Last == s_sele) { 
		sort(vectorPerson.begin(), vectorPerson.end(), []( auto &e1,  auto &e2) {
			return e1->getS_name() < e2->getS_name();
		});
	}
	Display(vectorPerson);
}
void Processing::DisplayONLYFirstName()
{						 
	Processing::Read(); 
	for (auto x : Data) {
		cout << x->getF_Name() << endl;    		
	}								     
} 	  
typedef std::unordered_multimap < std::string, shared_ptr<Person>> HashTB; 
void Processing::Display_with_the_Same_Company() {   	
	Processing::Read(); 	
	set<string> Name_of_company; 
	for (auto x : Hash_company) {
		Name_of_company.insert(x.first); 	   
		cout << x.first << endl; 
	}	 					     
	for (auto i : Name_of_company) {	  
		cout << "_____________Company : " << i <<"_________________" << endl;
		auto range = Hash_company.equal_range(i);  
		for_each(range.first, range.second, [this](HashTB::value_type& x) {  
			DisPlayP(x.second);
			cout << "\n";				   
		}); 					 
		cout << endl; 
		cout << "************************ \n"; 
	}		
}				    
typedef unordered_multimap<string, shared_ptr<Person>> HashG; 
void Processing::Display_with_the_same_group(){	 
	Processing::Read();
	set<string> Group_name; 
	for (auto x : Hash_Group) {  
		Group_name.insert(x.first);	  
		//cout << x;
	}								   
	for (auto i : Group_name) {
		cout << "_____________________Group : " << i <<"_____________________" << endl;  
		auto range = Hash_Group.equal_range(i);  
		for_each(range.first, range.second, [this](HashG::value_type &x) {  
			DisPlayP(x.second);
		}); 
	}
}
 void Processing::Create_CompanyHash(shared_ptr<Person> ptr)  {					 
	 Hash_company.insert({ ptr->get_nameOfCompany(), ptr }); 				  	
}
 void Processing::Create_GroupHash(shared_ptr<Person> ptr){ 
	 Hash_Group.insert({ ptr->get_codeGroup(), ptr });
}
class SearchF_S{ 	  						 
private : 
	string _OBJ;		   
	select choice; 
public : 			 
	vector<shared_ptr<Person>>  vectorPersonF;  
	vector<shared_ptr<Person>>  vectorPersonS;
	SearchF_S() {} ;
	SearchF_S(string obj , select _selection ) :_OBJ(obj) , choice(_selection){}
	void operator()(shared_ptr<Person> per1) {
		if (choice == select::First) {
			if (per1->getF_Name() == _OBJ) {
				vectorPersonF.push_back(per1);
			}			
		}									   
		else if (choice == select::Last) {
			if (per1->getS_name() == _OBJ) {
				vectorPersonS.push_back(per1); 
			}
		}
	}	
};
void Processing::Search( )
{
	string obj;   
	int choice; 								 
	Processing::Read(); 
	cout << "1 . First Name | 2. Last Name \n";  
	cin >> choice; 
	if (choice == 1 )  {   
		cout << "Input First_name do you want to find : ";   
		cin.ignore(); 
		getline(cin, obj); 
		fflush(stdin);
		auto searchFName = for_each(Data.begin(), Data.end() , SearchF_S(obj , select::First)); 				   
		Display(searchFName.vectorPersonF); 
	}										 
	else if (choice == 2 ) {		   
		cout << "Input Second Name  do you want to find : ";
		cin.ignore();
		getline(cin, obj);
		fflush(stdin);
		auto searchFName = for_each(Data.begin(), Data.end(), SearchF_S(obj, select::Last));	 
		Display(searchFName.vectorPersonS);
	}
}
void Processing::Write()    {							 			 
		ofstream out{ "ProjectData.txt",ios::app };
		int _count = 0;
		for (auto x : Per) {			
			_count += 1;					    
			out << x->getF_Name() << endl; 
			out << x->getS_name() << endl; 
			out << x->getP_phone() << endl;  
			out << x->getS_phone() << endl;  
			out << x->get_Address() << endl;  
			out << x->get_Email() << endl;  
			out << x->get_nameOfCompany() << endl;  
			out << x->get_codeGroup() << endl;  
		}			  
		Processing::Update();  
		out.close(); 
}
void Processing::Update(){ 
	for (auto x : Per) {
		this->Data.push_back(x); 
	}
}
void Processing::Read()
{		 
	ifstream input{ "ProjectData.txt" };
	if (input.fail()) {
		cout << "Failed \n" << endl;
		return;
	}
	shared_ptr<Person> t1 = make_shared<Person>();
	string message;
	static int count = 0;
	int i = 0;
	Data.resize(0);
	while (getline(input, message)) {
		count++;			  
		//cout << message << endl; 
		if (count == 1) {
			t1->SetF_Name(message);
		}
		else if (count == 2) {
			t1->setS_name(message);
		}
		else if (count == 3) {
			t1->SetP_phone(message);
		}
		else if (count == 4) {
			t1->setS_Phone(message);
		}
		else if (count == 5) {
			t1->set_Address(message);
		}				 
		else if (count == 6) { 
			t1->Set_Email(message); 
		}							 
		else if (count == 7) {
			t1->set_NameOfCompany(message); 
		}
		else  if (count == 8) {
			if (message == "Friend") {
				t1->set_code(1); } 
			else if (message == "Family") { t1->set_code(2);  }
			else if (message == "Acquaintance") { t1->set_code(3);  } 
			else if (message == "CoWorker") { t1->set_code(4);  }
			Data.push_back(t1);	    
			DeleteDub(t1);
			t1.reset(new Person());
			count = 0;
		}
	}
	input.close();
}
vector<shared_ptr<Person>> Processing::GetData()
{
	return this->Data ;
}
void Processing::ADD(int n ) 
{							  
	shared_ptr<Person> T = make_shared<Person>();
	for (int i = 0; i < n; i++) {
		string S_name;
		string name;
		string P_num;
		string S_num;
		string Email_id;
		string Company;
		string Address;			 
		int code; 												  
		cin.ignore(); 
		cout << "Input First Name : "; getline(cin , name); 	   		

		cout << "Input Second Name : "; getline(cin, S_name);
		cout << "Input Primary Phone Number : ";  cin>> P_num ;
		cout << "Input Secondary Phone Number ";  cin >> S_num; 
		cout << "Input Address : "; cin >> Address; ;
		cout << "Input Email_id "; cin >> Email_id; 
		cout << "Input Company : ";	cin >> Company; 
		cout << "1. Friend |  2. Family | 3.Acquaintance | 4 . CoWorker \n";  
		cout << "Input Group  ";   
		cin >> code; 
		fflush(stdin); 
		T->SetF_Name(name);
		T->setS_name(S_name);
		T->SetP_phone(P_num);
		T->setS_Phone(S_num);
		T->set_Address(Address);
		T->Set_Email(Email_id);
		T->set_NameOfCompany(Company); 	     
		T->set_code(code);
		Per.push_back(T); 		     
		//Create_CompanyHash(T);	 
		//Create_GroupHash(T); 
		T.reset(new Person()); 
	}	 
	Processing::Write();  
}
