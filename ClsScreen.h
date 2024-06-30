#pragma once

#include <iomanip>
#include <string>
#include <iostream>
#include "ClsPlayer.h"
#include "clsDate.h"
using namespace std; 

class ClsScreen
{



private: 

	static void _SceenColors()
	{
        #define RED     "\033[31m"    
        #define YELLOW  "\033[33m"  
        #define GREEN   "\033[32m"
        #define RESET   "\033[0m"
        #define BLUE    "\033[34m" 
    }
	static void _ShowDateHeader()
	{
	
		clsDate Date; 
		cout << endl;
		cout << YELLOW << setw(30) << right << "" << Date.DateToString() << endl << RESET;
		cout << RED << setw(40) <<"\t__________________\n" << RESET;
	}

public:



	static void ShowScreenHeader(string Title)
	{
		 system("cls"); 
		_ShowDateHeader();
		cout << endl;;
		cout << setw(40)<< YELLOW "\t\t  -------------------------------  \n ";
		cout << setw(45)<< Title << endl;;
		cout << setw(40)<< "\t\t  ------------------------------- \n " << RESET ;
		cout << endl;;


	}

	static void ShowQizzMenuTypesScreen()
	{
		cout << endl;
		cout << endl;
		cout << RED   << setw(20) << "[1] CPP " << RESET;
		cout << GREEN << setw(20) << "[2] PHP " << RESET;
		cout << BLUE  << setw(20) << "[3] C#  " << RESET;
		cout << endl;
		cout << endl;

	}

	static void ShowFinnalResultScreen()
	{

		    cout << BLUE << setw(10) << "\t "<< " Player Name : "     << RESET << ClsPlayer::Name() << endl;;
			cout << GREEN << setw(10) << "\t " << " Player Opetion : " << RESET << ClsPlayer::Opetion() << endl;
			cout << RED << setw(10) << "\t "<< " Player Round : "    << RESET << ClsPlayer::Rounds() << endl; ;
			cout << YELLOW << setw(10) << "\t "<< " Player Right Answer/(s) : " << RESET << ClsPlayer::GetPoint() << endl;;

			cout <<RED << setw(40) << "\n\t\t  -------------------------------- \n " << RESET;

	};

	
	

};

