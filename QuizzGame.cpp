


#include <iostream>
#include <string>
#include <cstdlib>
#include "ClsMainGameScreen.h"
#include "ClsScreen.h"
using namespace std; 

string ClsPlayer::_Name; 
short ClsQizzCpp::_QizzQuestionNumber; 
char ClsQizzCpp::_QizzRightAnswer;
short ClsGame::_GameOpetion;
short ClsPlayer::_OpetionType;
char ClsPlayer::_Charactar;
short ClsPlayer::_Rounds;
short ClsPlayer::_Points; 
ClsGame::enGameMode ClsGame::enMode;



int main()
{

	srand(unsigned(time(NULL)));
	
	ClsMainScreenGame::ShowMainScreenGame();

	

}

