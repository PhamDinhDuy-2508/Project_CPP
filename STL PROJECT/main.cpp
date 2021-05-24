#pragma once
#include"pch.h" 
#include"Processing.h" 
#include"Person.h"  
#include<memory>	
#include<Windows.h>
void Menu() {
	cout << "************** MENU **************** \n"; 
	cout << "1. ADD Person \n"; 
	cout << "2. Display all contacts sorted by first or last name \n";  
	cout << "3. Display only first name with primary number \n";  
	cout << "4. Display contacts from the same company only \n"; 
	cout << "5. Display contacts based on group type\n"; 
	cout << "6. Allow contact search by first or last name \n"; 
	cout << "7. Display count of contacts by company and group \n";  
}								    
void clearScreen() {
	HANDLE   hStdOut;
	CONSOLE_SCREEN_BUFFER_INFO csbi;
	DWORD   count;
	DWORD   cellCount;
	COORD   homeCoords = { 0, 0 };
	hStdOut = GetStdHandle(STD_OUTPUT_HANDLE);
	if (hStdOut == INVALID_HANDLE_VALUE) return;
	if (!GetConsoleScreenBufferInfo(hStdOut, &csbi)) return;
	cellCount = csbi.dwSize.X *csbi.dwSize.Y;

	if (!FillConsoleOutputCharacter(hStdOut, (TCHAR) ' ', cellCount, homeCoords, &count)) return;
	if (!FillConsoleOutputAttribute(hStdOut, csbi.wAttributes, cellCount, homeCoords, &count)) return;

	SetConsoleCursorPosition(hStdOut, homeCoords);
}							 
int main() {	 

	shared_ptr<Processing> T = make_shared<Processing>();
tryagain:
	Menu();
	int choice{};
	cin >> choice;
	switch (choice) {
		
	case 1:
	{
		int amount;
		cout << "Input amount of Person : \n";
		cin >> amount;
		T->ADD(amount);
		char x{};
		cout << "Do you want to back to main menu(y/n) : \n";
		cin >> x;
		if (x == 'y') {
			clearScreen();
			goto tryagain;
		}
		else if (x == 'n') {
			return  0;
		}
		break;
	}
	case 2: {		  
		clearScreen();
		int code;	   
		T->Read(); 
		cout << "1.First | 2.Last \n";
		cin >> code;
		if (code == 1) {
			T->DisplayWithShortF_Name_and_Second(select::First);
		}
		else if (code == 2) {
			T->DisplayWithShortF_Name_and_Second(select::Last);
		}
		else {
			return 0;
		}
		char x{};
		cout << "Do you want to back to main menu(y/n) : \n";
		cin >> x;
		if (x == 'y') {
			clearScreen();
			goto tryagain;
		}
		else if (x == 'n') {
			return  0;
		}
		break;
	}
	case 3: {
		clearScreen();
		T->Read(); 
		T->DisplayONLYFirstName();
		char x{};
		cout << "Do you want to back to main menu(y/n) : \n";
		cin >> x;
		if (x == 'y') {
			clearScreen();
			goto tryagain;
		}
		else if (x == 'n') {
			return  0;
		}
		break;

	}
	case 4: {			  
		clearScreen();	   
		T->Display_with_the_Same_Company();
		char x{};
		cout << "Do you want to back to main menu(y/n) : \n";
		cin >> x;
		if (x == 'y') {
			clearScreen();
			goto tryagain;
		}
		else if (x == 'n') {
			return  0;
		}
		break;
	}
	case 5: {
		clearScreen(); 
		T->Display_with_the_same_group();
		char x{};
		cout << "Do you want to back to main menu(y/n) : \n";
		cin >> x;
		if (x == 'y') {
			clearScreen();
			goto tryagain;
		}
		else if (x == 'n') {
			return  0;
		}
		break;
	}
	case 6: {
		clearScreen();
		int code{};
		T->Search(); 
		char x{};
		cout << "Do you want to back to main menu(y/n) : \n";
		cin >> x;
		if (x == 'y') {
			clearScreen();
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
	return  0; 	    
	system("pause"); 	
}