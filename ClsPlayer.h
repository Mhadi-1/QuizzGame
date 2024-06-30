#pragma once

#include<string>
#include<iostream>



using namespace std; 


class ClsPlayer 
{

    #define RED     "\033[31m"    
    #define YELLOW  "\033[33m"  
    #define GREEN   "\033[32m"
    #define RESET   "\033[0m"
    #define BLUE    "\033[34m" 
	
    static string  _Name; 
	static short  _Rounds ; 
	static short  _OpetionType;
	static char   _Charactar; 
	static short  _Points; 

	struct _stPlayerInfo
	{
		string Name; 
		short Round; 
		short OpetionType; 

	};


	
public:


	static ClsPlayer GetEmptyPlayer()
	{
		return ClsPlayer(" ", 0, 0);
	}

	ClsPlayer(string Name, short Rounds, short Opetion) 
	{
		_Name     = Name; 
		_Rounds   = Rounds; 
		_OpetionType = Opetion;
	}

	//get Meythods set _________ 

	static void SetName(string Name)
	{
		_Name = Name; 
		
	
	}
    static string Name()
	{
		return _Name; 
	}

	static short Rounds()
	{
		return _Rounds; 
	}

	static short Opetion()
	{
		return _OpetionType; 
	}

	static short ReadOpetions(short From, short  To)
	{
		short UserChooice = 0;

		cin >> UserChooice;

		while (UserChooice < From || UserChooice > To)
		{
			cout << RED << "\n InValied Please Enter Range [" << From << "To" << To << "]\n" << RESET;
			cin >> UserChooice;

		};
		
		return UserChooice;
	}

	static short GetPoint()
	{
		return _Points; 
	}

	static void SetPoint(short Point)
	{
		_Points = Point; 
	}

	static char ReadCharactar()
	{
		char Character = 65; 

		cin >> Character;
		Character = toupper(Character); 

		while (Character < 65 || Character > 67)
		{
			cout << RED << "\n   InValied Range !! Please Enter Range From [ A To C ] : "<< RESET;
			cin >> Character;
		    Character = toupper(Character);
 
		}
		_Charactar = Character;

		return Character;
	}

	static void SetCharactar(char Charactar)
	{
		_Charactar = Charactar;
	}

	static char GetCharactar()
	{
		return _Charactar;
	}

	static ClsPlayer GetPlayerInfo()
	{
		_stPlayerInfo PlayerInfo;


		cout << endl;
		cout << endl;
		cout << YELLOW << setw(45) << right << "\n\n please Enter Your Opetion : " << RESET;
		PlayerInfo.OpetionType = ClsPlayer::ReadOpetions(1, 3);

		cout << YELLOW << setw(45) << right << "\n please Enter Your Name    : " << RESET;
		getline(cin>>ws , PlayerInfo.Name);

		cout << YELLOW << setw(45) << right << "\n please Qizz Rounds Number : " << RESET;
		cin >> PlayerInfo.Round;

		ClsPlayer Player(PlayerInfo.Name, PlayerInfo.Round, PlayerInfo.OpetionType);

		return Player;
	}

	_declspec(property(get =  Name, put  = SetName)) string PlayerName; 
	_declspec(property(get = ReadCharactar, put = SetCharactar)) char Charactar;
	_declspec(property(get = Point, put = SetPoint)) short Point;

};

