
#pragma once
#include <iostream>
#include <string>
#include "clsString.h"
//#include "clsDate.h"

class ClsInputValidate
{


public:

	 	// Optimization code with Template methodes 

	template <typename T >
	 static bool IsNumberBetween(T Number, T From, T To)
	{
		if (Number >= From && Number <= To)
			return true;
		else
			return false;
	}


	 template <typename T1> 
	static T1 ReadRecord(string ErrorMessage = "Invalid Number, Enter again\n")
	{
		T1 Number;
		while (!(cin >> Number)) {
			cin.clear();
			cin.ignore(numeric_limits<streamsize>::max(), '\n');
			cout << ErrorMessage;
		}
		return Number;
	}

	template <typename T2>
	static T2 ReadNumberBetween(T2 From, T2 To, string ErrorMessage = "Number is not within range, Enter again:\n")
	{
		T2 Number  = ReadRecord <T2> ();

		while (!IsNumberBetween(Number, From, To))
		{
			cout << ErrorMessage <<" : ";
			Number = ReadRecord<T2>();
		}
		return Number;
	}

	static string ReadString()
	{
		string str = "";

		cin >> str;

		if (str.length() == 0)
			return "";

		return str;
	}
};


