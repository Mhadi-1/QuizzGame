#pragma once

#include <string>
#include <iostream>
#include "ClsPHPQizzScreen.h"
#include "ClsCppQizzScreen.h"
#include "ClsCSharpQizzScreen.h"
#include "ClsScreen.h"
#include "clsString.h"
#include "ClsPlayer.h"
#include "ClsQuizzGame.h"



class ClsMainScreenGame : private ClsScreen
{

     enum enQizzOpetions {CPP = 1, PHP = 2 , CSHARP = 3 };


	 static void BackToMenu()
	 {

		 cout << "\n\n\t\t Prss Any Key To  Back To Menu "; 
		 system("pause > 0 "); 
		 ShowMainScreenGame(); 
	 }
	

	static void PerFormPlayerOpetion(enQizzOpetions Opetion)
	{
		
		switch (Opetion)
		{

		case CPP : 

			system("cls"); 
			ClsCppQizzScreen::ShowCppMainScreen();
			ClsGame::StartGame(); 
			BackToMenu(); 
			break; 

		case PHP :

			system("cls");
			ClsPHPQizzScreen::ShowPhpMainScreen();
			BackToMenu();
			break; 

		case CSHARP:

			system("cls");
			ClsCSharpQizzScreen::ShowCSharpMainScrreen();
			BackToMenu();
			break;

		default:

			break;
		}
	}


public:

	static void ShowMainScreenGame()
	{
		 
		
		 system("cls");

		 ClsScreen::ShowScreenHeader("QIZZ TYPES MENU SCREEN");
		 ClsScreen::ShowQizzMenuTypesScreen();
		 ClsPlayer Player = ClsPlayer::GetPlayerInfo();
		 PerFormPlayerOpetion((enQizzOpetions)Player.Opetion());
		
	

	}

};

