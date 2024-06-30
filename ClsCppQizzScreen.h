#pragma once

#include<string>
#include<iostream>
#include"ClsScreen.h"


#include "ClsPlayer.h"

using namespace std;




class ClsCppQizzScreen : protected ClsScreen
{

private:

	


public:


	static void ShowCppMainScreen()
	{

		system("cls");
		cout << setw(40) << RED << "\n\t\t___________________________\n\n";
		cout << setw(40) << "CPP QIZZ SCREEN " << endl;;
		cout << setw(40) << "\t___________________________ \n " << RESET;
		cout << endl;;

	}

};

