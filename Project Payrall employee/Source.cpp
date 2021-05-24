#include"pch.h"
#include"processing.h" 
#include"project1.h" 
#include"Algro.h"
#include<iostream>   
#include <Windows.h> 
#include<fstream>
using namespace std; 	  
void  MenuMain() {
	cout << "MENU" << endl;
	cout << "1:\t" << "Print List : " << endl;
	cout << "2:\t" << "Add member : " << endl;
	cout << "3:\t" << "Delete member : " << endl;
	cout << "4:\t" << "Print member Information : " << endl;
	cout << "5:\t" << "Modify member record : " << endl;
}   				    
void Clear() {	
		HANDLE   hStdOut;
		CONSOLE_SCREEN_BUFFER_INFO csbi;
		DWORD   count;
		DWORD   cellCount;
		COORD   homeCoords = { 0, 0 };
		hStdOut = GetStdHandle(STD_OUTPUT_HANDLE);
		if (hStdOut == INVALID_HANDLE_VALUE) return;
		if (!GetConsoleScreenBufferInfo(hStdOut, &csbi)) return;
		cellCount = csbi.dwSize.X *csbi.dwSize.Y;

		if (!FillConsoleOutputCharacter(hStdOut,(TCHAR) ' ',cellCount,homeCoords,&count)) return;
		if (!FillConsoleOutputAttribute(hStdOut,csbi.wAttributes,cellCount,homeCoords,&count)) return;

		SetConsoleCursorPosition(hStdOut, homeCoords);
}
int main() {	    
	shared_ptr<processing> T = make_shared<processing>();  

	tryagain :     
	MenuMain();  
	int choice{};  	
	cin >> choice; 
	switch (choice) 
	{				 
	case 1: {	 			 
		T->Read(); 
		T->Printdetail();		
		char x{}; 
		cout << "Do you want to back to main menu(y/n) : \n";
		cin >> x;
		if (x == 'y') {
			Clear();
			goto tryagain;
		}
		else if (x == 'n') {
			return  0;
		}
		break; 
	}		    
	case 2 : {    
		Clear(); 
		int n; 
		cout << "INPUT amount of member : "; cin >> n;  
		T->Add(n); 	 

		char x{};
		cout << "Do you want to back to main menu(y/n) : \n";   
		cin >> x; 
		if (x == 'y') {
				Clear(); 
				goto tryagain; 
		} 
		else if(x =='n') {
				return  0; 
	}   
		break;
	}		
	case 3 : { 	 			 
		Clear(); 
		string _string{};  
		cout << "Input Member's Code : \t";  
		cin >> _string; 
		cin.ignore(256, '\n');  
		fflush(stdin);
		T->Delete(_string);   
		char x{};
		cout << "Do you want to back to main menu(y/n) : \n";
		cin >> x;
		if (x == 'y') {
			Clear(); 
			
			goto tryagain;
		}
		else if (x == 'n') {
			return  0;
		}
		break; 				   
	}
	case 4 : 
	{				 
		Clear();
		string _string{};
		cout << "Input Member's Code : \t";
		cin >> _string;
		T->PrintPayrall(_string); 		 
		char x{};
		cout << "Do you want to back to main menu(y/n) : \n";
		cin >> x;
		if (x == 'y') {
			Clear();

			goto tryagain;
		}
		else if (x == 'n') {
			return  0;
		}
		break;
	} 
	case 5 :  
	{					    
		Clear();
		string _string{};
		cout << "Input Member's Code : \t";
		cin >> _string;
		T->ModifyInfor(_string);
		char x{};
		cout << "Do you want to back to main menu(y/n) : \n";
		cin >> x;
		if (x == 'y') {
			Clear();
			goto tryagain;
		}
		else if (x == 'n') {
			return  0;
		}
		break;
	}

	default:
		break;
	} 			   
	
	return 0 ;  
			    


}	