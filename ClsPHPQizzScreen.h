#pragma once

#include<string>
#include<iostream>
#include "ClsScreen.h"
#include "ClsQizzCpp.h"

using namespace std;

class ClsPHPQizzScreen : protected ClsScreen
{

private: 




public:


	static void ShowPhpMainScreen()
	{
		system("cls");

		cout << setw(40) << GREEN << "\n\t\t___________________________\n\n";
		cout << setw(40) << "PHP QIZZ SCREEN " << endl;;
		cout << setw(40) << "\t___________________________ \n " << RESET;
		cout << endl;;

		cout << "\n\t  PHP QIZZ SCREEN WILL BE HERE..\n"; 
	}


};

