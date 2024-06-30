#pragma once


#include <string>
#include <iostream>
#include "ClsPlayer.h"

#include "ClsShowCppQizz.h"

using namespace std; 





class ClsGame 
{


private:



	
     short _GameRound;
	 static short _GameOpetion; 
	 
	enum _enGameOpetion { CPP = 1 , CSHARP = 2 , PHP = 3};


	static void _GetGameOpetionType()
	{
		_enGameOpetion Opetion = (_enGameOpetion) _GameOpetion;

		switch (Opetion)
		{

		case  CPP:
		
			ClsShowCppQizz::ShowCppQizzeGame();

			break;

		case  CSHARP:

			break;

		case  PHP:

			break;

		default:
			break;
		}
	}


public:

	enum enGameMode {Start = 1 , Stop = 2 };
    static enGameMode enMode;

	ClsGame(enGameMode GameMode ,  short Round , short Option)
	{
		_GameRound   = Round;
		 enMode      = GameMode;
		_GameOpetion = Option; 

	};

	short Round()
	{
		return _GameRound; 
	}

	enGameMode GameMode()
	{
		return enMode;
	}

	short Opetion()
	{
		return _GameOpetion; 
	}

	static ClsGame GetStartGame()
	{
		return ClsGame(Start, ClsPlayer::Rounds(), ClsPlayer::Opetion());
	}

	static void StartGame()
	{
		
		ClsGame::GetStartGame();

		if (IsGameStart())
		{
			_GetGameOpetionType();

		}
		

	}
   

    static bool IsGameStart()
	{
		return (enMode == enGameMode::Start) ;
    }



};

