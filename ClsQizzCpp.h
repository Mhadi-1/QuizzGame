#pragma once

#include <string>
#include <iostream>
#include <fstream>
#include <vector>
#include <cstdlib>
#include "clsString.h"
#include "ClsPlayer.h"
#include "ClsCppQizzScreen.h"

using namespace std; 



class ClsQizzCpp  : ClsScreen
{


private:

	static char _QizzRightAnswer;
	static short _QizzQuestionNumber;



	static string _CppQizzFileName()
	{
		return"Cpp.txt";
	}

	static vector <string> _GetCppQizzQuestionsFromFile()
	{
		vector<string> vQizzCpp; 

		fstream CppQizzFile; 
		CppQizzFile.open(_CppQizzFileName(), ios::in | ios::app);


		if (CppQizzFile.is_open())
		{
			string DataLine ; 

			while (getline(CppQizzFile, DataLine))
			{
				vQizzCpp.push_back(DataLine);
			}
			CppQizzFile.close();

		}

		return vQizzCpp;

	}

	static void FillArrWithQizzAnswers(string Arra[6][6], short QuestionNumb)
	{
		
		switch (QuestionNumb)
		{

		case 0 : 
			Arra[0][0] = "a) ptr";
			Arra[0][1] = "b) *ptr";
			Arra[0][2] = "c) &ptr";

		break;

		case 1 :
			Arra[1][0] = "a) for (int i = 0; i < 10; i++)";
			Arra[1][1] = "b) while (true)";
			Arra[1][2] = "c) for (int i = 0; i < 1; i--";

		break;

		case 2 :
			Arra[2][0] = "a) #include <array>";
			Arra[2][1] = "b) #include <list>";
			Arra[2][2] = "c) #include <vector>";

		break;

		case 3:
			Arra[3][0] = "a) public";
			Arra[3][1] = "b) private";
			Arra[3][2] = "c) protected";

		break;

		case 4 : 

			Arra[4][0] = "a) public";
			Arra[4][1] = "b) private";
			Arra[4][2] = "c) protected";

	    break;

		case 5:

			Arra[5][0] = "a) To declare a variable";
			Arra[5][1] = "b) To define a constant value";
			Arra[5][2] = "c) To create an abstract class";

		break;

		default:
			break;
		}
	}

	static vector <char> _GetQizzRightAnswerFromFill()
	{
		vector<char> vQizzCppAnswers;

		fstream CppQizzAnswersFile;

		CppQizzAnswersFile.open("CppQizzAnswers.txt" , ios::in | ios::app );

		if (CppQizzAnswersFile.is_open())
		{
			string LineRecord; 
			while (getline(CppQizzAnswersFile, LineRecord))
			{
				vQizzCppAnswers.push_back(LineRecord[0]);
			}
		}
		return vQizzCppAnswers; 
	}

	static void AddPoints()
	{
		if ( ClsPlayer::GetCharactar() == _QizzRightAnswer )
		{
			static short Point; 
			Point += 1; 
			ClsPlayer::SetPoint(Point); 
		}

	}


	static void _ShowQizzQuestionOnScreen(string QizzQuestion  )
	{


		  ClsCppQizzScreen::ShowCppMainScreen();

		cout << "\n\n   " << clsString::st_toupper(QizzQuestion) << endl;

		string NumberOfQizz = clsString::GetFristLetterrOnStr(QizzQuestion);
		_QizzQuestionNumber = stoi(NumberOfQizz);

	};

	static void _ShowQizzAnswerOnScreen(char ArrayCharactarAnswers[])
	{

		string Arra[6][6]; 

		FillArrWithQizzAnswers( Arra , (_QizzQuestionNumber - 1) );

		cout << endl;
		for (short i = 0; i < 3; i++)
		{
			cout << "   " << clsString::st_toupper(Arra[_QizzQuestionNumber - 1][i]) << endl;

		}


		_QizzRightAnswer = ArrayCharactarAnswers[_QizzQuestionNumber - 1];
		_QizzRightAnswer = toupper(_QizzRightAnswer);
		char UserCharactar = ' ';
		cout << setw(45) << right << "\n   PLEASE  ENTER YOUR CURRECT ANSWER FROM [ A to C ] : " << RESET;
		UserCharactar = ClsPlayer::ReadCharactar();
		AddPoints();

	}

	static void _StartQizz(string ArrayQizzQuestions[], short ArrayLength , char ArrayAnswers [] )
	{
		for (short i = 0; i < ArrayLength; i++)
		{
			_ShowQizzQuestionOnScreen(*(ArrayQizzQuestions + i));
			_ShowQizzAnswerOnScreen(ArrayAnswers);
		}
	}
	

public: 


	static void GetCppQizzes()
	{
		

		 vector <string> vQizzQuestions;
		 vector<char> vRightAnswers; 

		 vQizzQuestions  =  _GetCppQizzQuestionsFromFile();
		 short   length = vQizzQuestions.size();
		 string* ptrArrQizz  = new string[vQizzQuestions.size()];
		 clsString::SaveVectorContanstToArray(vQizzQuestions, ptrArrQizz);
		 

		  vRightAnswers = _GetQizzRightAnswerFromFill();

		 char* ArrayAnswers = new char[vRightAnswers.size()];

		 clsString::SaveVectorContanstToArray(vRightAnswers, ArrayAnswers);

		 _StartQizz(ptrArrQizz, length , ArrayAnswers);
		  
		 ClsScreen::ShowScreenHeader("Finnal Result Screen");
		 ClsScreen::ShowFinnalResultScreen();

		 // Show Finnal Result Screen And Show all Ditales Of The Game : 
		 
		 
		
	
	}


};

