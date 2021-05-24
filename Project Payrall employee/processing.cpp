#include "pch.h"
#include "processing.h"	    
#include"Algro.h"							  
#include<memory>	 
#include<string>
#include<fstream> 		    
#include<fcntl.h>	   
int processing::count = 0; 	    
processing::processing()
{	   
	count++; 
}				    
void processing::Add(int n )
{					 
	shared_ptr<Employee> T = make_shared<Employee>();
	for (int i = 0; i < n; i++) {
		string code;
		string name;
		string Day;
		float Salary;
		float Borrow;
		string Address;	
		fflush(stdin); 	  
		cin.ignore(); 
		cout << "Input Code of Employee : "; getline(cin ,  code );
		cout << "INput Name : "; getline(cin , name);
		cout << "Day Joint : "; getline(cin , Day );
		cout << "Input Salary : "; cin >> Salary;
		cout << "Input Borrow :  "; cin >> Borrow;	    						  
		cout << "Input Address : "; cin >> Address; 
		T->SetAddress(Address);
		cin.ignore(256,'\n'); 
		T->SetCode(code);
		T->SetName(name);
		T->SetDay(Day);
		T->SetSal(Salary);
		T->SetBor(Borrow);		
		lis.push_back(*T);
		cout << endl; 		 
		T.reset(new Employee());
	}	 
	processing::UPdate(); 
	processing::Wirte(Selection::_update); 
}	    
void processing::totalCount()
{				  
	cout << count; 
}
void processing::ModifyInfor(string code) 
{		 						  
	processing::Read(); 
	vector<string> CODEINFOR{};
	for (auto x : Data) { 	
		 string k = x.GetCode();
		CODEINFOR.push_back(k); 
	} 							  
	cout << "Info of Member :  " << code << " : " << endl; 
	processing::PrintPayrall(code);
	string _code = code; 
    if(binarySearch<string>(CODEINFOR, _code, CODEINFOR.size()) != -1 ) {	
		int  k = binarySearch<string>(CODEINFOR, code, Data.size()); 
		string code;
		string name;
		string Day;
		float Salary;
		float Borrow;
		string Address;	     	 
		fflush(stdin);
		cin.ignore();
		cout << "INput Name : "; getline(cin, name );
		cout << "Day Joint : "; getline(cin, Day);
		cout << "Input Salary : "; cin >> Salary;
		cout << "Input Borrow :  "; cin >> Borrow; 
		cout << "Input Address : "; cin >> Address;  
		Data[k].SetName(name);
		Data[k].SetDay(Day);
		Data[k].SetSal(Salary);
		Data[k].SetBor(Borrow);
		Data[k].SetAddress(Address);	 
		lis.resize(0); 
		for (auto x : Data) {
			lis.push_back(x);
		}					  
		processing::Wirte(Selection::del); 
	}				
	else { 
		cout << "CANOT FIND Employee \n"; 
	}	   
}
void processing::Delete(string code )
{		 				  
	processing::Read();

	vector<string> CODEINFOR{};
	for (auto x : Data) {
		string k = x.GetCode();		  
		CODEINFOR.push_back(k);  
	}	 
	if (binarySearch<string>(CODEINFOR, code, CODEINFOR.size()) != -1) {  
		int k = binarySearch<string>(CODEINFOR, code, CODEINFOR.size());     
		if (Data.size() == 0) { 
			return; 
		}			    
		else {
			Data.erase(Data.begin() + k, Data.begin() + k + 1);
		}		 
		this->lis.erase(lis.begin(), lis.end());  
		for (auto x : Data) {
			lis.push_back(x); 
		}		
		processing::Wirte(Selection::del); 
	}		 					    
	else {
		cout << "Cannot Find "; 
	}								 
	cout << "DELETE complete \n ";  
}
void processing::Printdetail() {
	int _count = 1; 		 
	if (Data.size() != 0) { 	 
		for (auto x : Data) { 											    
			cout << "************************************************ \n"; 
			cout << _count <<"\t\t"<< "  IO Address : \t" << x.GetCode() << endl; 
			cout << "\t\t" << "  Name       : \t" << x.GetName() << endl;   
			cout << "\t\t" << "  Day_Joint  : \t" << x.getDay()  <<  endl; 
			cout << "\t\t" << "  Address    : \t" << x.getADDress() << endl; 
			cout << "\t\t" << "  Salary     : \t" << x.GetSal() << endl; 
			cout << "\t\t" << "  Borrow     : \t" << x.getBor() << endl;   
			cout << "************************************************ \n"; 
			_count++; 
		}
	}	
}
void processing::PrintPayrall(string code)  
{			
	processing::Read();

	vector<string> CODEINFOR{};		 
	for (auto x : Data) {
		string k1 = x.GetCode();
		CODEINFOR.push_back(k1);
	} 	 	
	if ((binarySearch<string>(CODEINFOR, code,CODEINFOR.size()) != -1)) {	
		int k = binarySearch<string>(CODEINFOR, code, CODEINFOR.size()); 
		auto x = Data[k]; 
		cout << "************************************************ \n";
		cout << "\t\t" << ": ID Address : \t" << x.GetCode() << endl;
		cout << "\t\t" << "  Name       : \t" << x.GetName() << endl;
		cout << "\t\t" << "  Day_Joint  : \t" << x.getDay() << endl;
		cout << "\t\t" << "  Address    : \t" << x.getADDress() << endl;
		cout << "\t\t" << "  Salary     : \t" << x.GetSal() << endl;
		cout << "\t\t" << "  Borrow     : \t" << x.getBor() << endl;
		cout << "************************************************ \n";
	}
	else {
		cout << "CANNOT FIND \n"; 
	}	 
}
void processing::setList(vector<Employee> temp)
{				  
	this->lis = temp; 
}
vector<Employee> processing::AgetLis()
{
	return this->lis; 
}
void processing::Wirte(Selection _select) {
	if (_select == Selection::_update) {
		ofstream out{ "data.txt"  , ios::app };
		int _count = 0;
		for (auto x : lis) {
			out << x.GetCode() << endl;
			out << x.GetName() << endl;
			out << x.getDay() << endl;
			out << x.getADDress() << endl;
			out << x.GetSal() << endl;
			out << x.getBor() << endl;
			_count += 1;
		}
		processing::UPdate();  
		out.close();
	} 
	if (_select == Selection::del) {		    
		ofstream out{ "data.txt" };
		int _count = 0;
		for (auto x : lis) {
			out << x.GetCode() << endl;
			out << x.GetName() << endl;
			out << x.getDay() << endl;
			out << x.getADDress() << endl;
			out << x.GetSal() << endl;
			out << x.getBor() << endl;
			_count += 1;
		}
		processing::UPdate();	 
		out.close();
	} 
}
int processing::getLis(){ 
	return this->lis.size(); 
}
void processing::UPdate()
{					 
	for (auto x : lis) {
		(this->Data).push_back(x); 
	}					    
}
void processing::Read() {    
	ifstream input{ "data.txt" };   
	if (input.fail()) { 
		cout << "Failed \n" << endl; 
		return  ;
	}				 
	shared_ptr<Employee> t1 = make_shared<Employee>(); 
	string message;  				  
	static int count = 0 ; 
 	int i = 0; 			   
	Data.resize(0); 
	while (getline(input, message))  {    
		count++;
			if (count == 1 ) { 
				t1->SetCode(message); 
			}						  				 
			 else if (count == 2){ 
				t1->SetName(message); 	 
			}						  
			 else if (count == 3) {
				t1->SetDay(message); 	  
			}						 
			 else if (count == 4) {
				t1->SetAddress(message); 	    
			}							 
			 else if (count == 5) {	   
				float number = stod(message); 
				t1->SetSal(number); 			  
			}						  
			 else  if (count == 6) {
				float number = stod(message);
				t1->SetBor(number);	 
				Data.push_back(*t1); 	  
				t1.reset(new Employee()); 	    
				count = 0; 
			}	 
		}			
	input.close(); 
	}		 		
processing::~processing()	 
{							  
	count--;    
}				  
