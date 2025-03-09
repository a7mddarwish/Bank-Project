#pragma once
#include<iostream>
using namespace std;

class ClsPerson
{
private :
	string _FirstName;
	string _LastName; 
	string _Email;
	string _Phone;


public:

   // Create Proberties 

	// First Name 

	void SetFirstName(string FirstName)
	{
		_FirstName = FirstName;
	}
	string GetFirstName()
	{
		return _FirstName;
	}
	

	// Last Name 
	void SetLastName(string LastName)
	{
		_LastName = LastName;
	}
	string GetLastName()
	{
		return _LastName;
	}


	// Email
	void SetEmail(string Email)
	{
		_Email = Email;
	}
	string GetEmail()
	{
		return _Email;
	}


	// Phone 
	void SetPhone(string Phone)
	{
		_Phone = Phone;
	}
	string GetPhone()
	{
		return _Phone ;
	}

	string  FullName()
	{
		return (_FirstName +" " + _LastName);
	}

	__declspec (property (put = SetFirstName, get = GetFirstName)) string FirstName;
	__declspec (property (put = SetLastName, get = GetLastName))   string LastName;
	__declspec (property (put = SetEmail, get = GetEmail))         string Email;
	__declspec (property (put = SetPhone, get = GetPhone))         string Phone;

	ClsPerson(string NewFisrtName , string NewLastName ,  string NewEmail , string NewPhone )
	{

		 FirstName = NewFisrtName;
		 LastName =   NewLastName;
		 Email =      NewEmail;
		 Phone =      NewPhone;

	}


	 virtual void Print()
	{
		cout << "\t\t PERSON CARD \n\n";
		cout << "First Name    : " << _FirstName;
		cout << "\nLast Name     : " << _LastName;
		cout << "\nFull Name     : " << FullName();
		cout << "\nEmail         : " << _Email;
		cout << "\nPhone         : " << _Phone;
	}
};

