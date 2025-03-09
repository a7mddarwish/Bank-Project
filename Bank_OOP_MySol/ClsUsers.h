#pragma once
#pragma warning (disable : 4996)
#include<iostream>
#include <vector>
#include<fstream>
#include<string>
#include"ClsPerson.h"
#include"ClsInputValidate.h"
#include"ClsDate.h"
#include"ClsUtil.h"
class ClsUsers : public ClsPerson
{
private :
	struct StRegisterLogin;

	enum enMode;

	enMode _Mode;
	string _UserName;
	string _Pincode;
	int _Permission;

	static ClsUsers _ConvertLineToUserObj(string DataLine, string Delemeter = "#//#")
	{
		//Ola#//#Ahmad#//#Ola@gmail.com#//#838837#//#User8#//#1234#//#7
		vector <string> _VData = ClsString::Split(DataLine, Delemeter);

		return (ClsUsers(enMode::Updated, _VData[0], _VData[1], _VData[2], _VData[3], _VData[4], ClsUtil::Decrypt(_VData[5]), stoi(_VData[6])));
	}

	// Date
	string _PrpRegstrLine(string S)
	{
		string Line = "";
		Line += ClsDate::GetDateTimeString();

		Line += S + this->Username;
		Line += S + ClsUtil::Encrypt(this->_Pincode);
		Line += S + to_string(this->Permission);

		return Line;

	}

	static StRegisterLogin _ConvectLineToRecord(string Line , string Separator = "#//#")
	{
		vector <string > UserData = ClsString::Split(Line, Separator);
		StRegisterLogin StUserData;

		StUserData.DateandTime = UserData[0];
		StUserData.Username = UserData[1];
		StUserData.Passwotd = ClsUtil::Decrypt(UserData[2]);
		StUserData.Permission = stoi(UserData[3]);

		return StUserData;

	}
	static vector <StRegisterLogin> _LoadRegUsersFromFile()
	{
		fstream Myfile;
		vector <StRegisterLogin> _UsersV;

		Myfile.open("RegisterFile.txt", ios::in); // Read only

		if (Myfile.is_open())
		{
			string DataLine;

			while (getline(Myfile, DataLine))
			{
				StRegisterLogin UserSt = _ConvectLineToRecord(DataLine);
				_UsersV.push_back(UserSt);
			}
			Myfile.close();
		}

		return _UsersV;


	}

public:
	
	bool _MsrkForDeleted = false;

	enum enMode { Updated = 0, Empty = 1, AddNew = 2 };
	enum enPermission
	{
		pAll = -1,
		pShowList = 1,
		pAddNew = 2,
		pDelete = 4,
		pUpdate = 8,
		pFind = 16,
		pTransAction = 32,
		pMangeUsers = 64,
		pRegisterScr =128
	};
	enum enDeleteCase
	{
		enDeletedDone = 1,
		enDeletefaild = 2,
		enfaildAdmin = 3
	};

	struct StRegisterLogin
	{
		string DateandTime;
		string Username;
		string Passwotd;
		int Permission;
	};

	//Alia#//#Ali#//#M@gmail.com#//#09388322#//#User6#//#4323#//#-1
	ClsUsers(enMode Mode, string FisrtName, string LastName, string Email, string Phone, string UserName, string PinCode
		, int Permission) : ClsPerson(FisrtName, LastName, Email, Phone)
	{
		_Mode = Mode;
		_UserName = UserName;
		_Pincode = PinCode;
		_Permission = Permission;

	}

	void SetUsername(string UserName)
	{
		_UserName = UserName;
	}
	string GetUserName()
	{
		return _UserName;
	}
	_declspec(property(put = SetUsername, get = GetUserName)) string Username;


	void SetPassword(string Pass)
	{
		_Pincode = Pass;
	}
	string GetPassword()
	{
		return _Pincode;
	}
	_declspec(property(put = SetPassword, get = GetPassword)) string PinCode;


	void SetPermission(int Permission)
	{
		_Permission = Permission;
	}
	int GetPermission()
	{
		return _Permission;
	}
	_declspec(property(put = SetPermission, get = GetPermission)) int Permission;

	void SetMode(enMode Mode)
	{
		_Mode = Mode;
	}
	enMode GetMode()
	{
		return _Mode;
	}
	_declspec(property(put = SetMode, get = GetMode)) enMode Mode;



	void SaveUsersToFile(vector <ClsUsers>& Users)
	{
		fstream Myfile;

		Myfile.open("Users.txt", ios::out);

		if (Myfile.is_open())
		{
			string DataLine = "";
			for (ClsUsers U : Users)
			{
				if (U._MsrkForDeleted == false)
				{
					DataLine = _ConvertObjToDataLine(U);
					Myfile << DataLine << endl;
				}
			}
			Myfile.close();
		}


	}
	enDeleteCase Delete()
	{
		if (_UserName == "Admin")
			return enDeleteCase::enfaildAdmin;

		vector <ClsUsers> Users = _LoadUsersFromFile();

		for (ClsUsers& U : Users)
		{
			if (U.Username == _UserName)
			{
				U._MsrkForDeleted = enDeleteCase::enDeletedDone;
				break;
			}
		}

		SaveUsersToFile(Users);
		*this = GetEmptyObj();

		return enDeleteCase::enDeletedDone;
	}

	static vector <StRegisterLogin> ShowRegUsers()
	{
		return (_LoadRegUsersFromFile());

	}
	// Find User
	static ClsUsers Find(string UserName, string Pincode)
	{
		vector <ClsUsers> _UsersV = _LoadUsersFromFile();

		for (ClsUsers U : _UsersV)
		{
			if (U.Username == UserName && U.PinCode == Pincode)
			{
				return U;
			}
		}

		return GetEmptyObj();
	}
	static ClsUsers Find(string UserName)
	{
		vector <ClsUsers> _UsersV = _LoadUsersFromFile();

		for (ClsUsers U : _UsersV)
		{
			if (U.Username == UserName)
			{
				return U;
			}
		}

		return GetEmptyObj();
	}

	// Get Objects 
	static ClsUsers GetEmptyObj()
	{
		return (ClsUsers(enMode::Empty, "", "", "", "", "", "", 0));
	}
	static ClsUsers GetNewOpj(string UserName)
	{
		return (ClsUsers(ClsUsers::enMode::AddNew, "", "", "", " ", UserName, " ", 0));
	}

	bool IsEmpty()
	{
		return (this->_Mode == enMode::Empty) ? true : false;
	}
	static vector <ClsUsers> _LoadUsersFromFile()
	{
		fstream Myfile;
		vector <ClsUsers> _UsersV ;

		Myfile.open("Users.txt", ios::in); // Read only

		if (Myfile.is_open())
		{
			string DataLine;

			while (getline(Myfile, DataLine))
			{
				ClsUsers User = _ConvertLineToUserObj(DataLine);
				_UsersV.push_back(User);
			}
			Myfile.close();
		}

		return _UsersV;


	}

	void UpdateFile()
	{
		vector <ClsUsers> Users = _LoadUsersFromFile();

		for (ClsUsers& U : Users)
		{
			if (U.Username == _UserName)
			{
				U = *this;
				break;
			}
		}
		SaveUsersToFile(Users);

	}


	static bool IsUserExist(string UserName)
	{
		ClsUsers user = ClsUsers::Find(UserName);

		return (user._Mode == Empty) ? 0 : 1;
	}
	enum EnSaveResults {
		enSaveSuccsefully = 1,
		enSaveFailed = 2,
		enSavefaildUserexist = 3
	};

	string _ConvertObjToDataLine(ClsUsers User, string Delemeter = "#//#")
	{
		//Alia#//#Ali#//#M@gmail.com#//#09388322#//#User6#//#4323#//#-1

		string DataLine = "";

		DataLine += User.FirstName + Delemeter;
		DataLine += User.LastName + Delemeter;
		DataLine += User.Email + Delemeter;
		DataLine += User.Phone + Delemeter;
		DataLine += User.Username + Delemeter;
		DataLine += ClsUtil::Encrypt(User.PinCode) + Delemeter;
		DataLine += to_string(User._Permission);

		return DataLine;
	}
	void SaveInfoToFile()
	{

		fstream Myfile;

		Myfile.open("Users.txt", ios::out | ios::app);
		if (Myfile.is_open())
		{
			string Dataline = _ConvertObjToDataLine(*this);
			Myfile << Dataline << endl;
			Myfile.close();
		}
	}
	bool Acsess(enPermission Permission)
	{
		if (Permission == enPermission::pAll)
			return true;
		if ((this->Permission & Permission) == Permission)
			return true;

		return false;


	}

	

	 void SaveLogUserinReg()
	{
		fstream Myfile;

		Myfile.open("RegisterFile.txt", ios::out | ios::app);

		if (Myfile.is_open())
		{

			string DataLine = _PrpRegstrLine("#//#");

			Myfile << DataLine << endl;


			Myfile.close();
		}
	}


	EnSaveResults Save()
	{
		switch (_Mode)
		{
		case (enMode::Empty):
		{
			return EnSaveResults::enSaveFailed;
		}

		case (enMode::AddNew):

		{
			if (ClsUsers::IsUserExist(_UserName))
				return EnSaveResults::enSavefaildUserexist;
			else
			{
				SaveInfoToFile();
				_Mode = enMode::Updated;

				return EnSaveResults::enSaveSuccsefully;
			}
		}
		case (enMode::Updated):
		{
			UpdateFile();

			return EnSaveResults::enSaveSuccsefully;
		}

		}
	}

};

