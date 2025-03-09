
#pragma once
#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include<iomanip>
#include "ClsPerson.h"
#include "ClsString.h"


class ClsBankClient : public ClsPerson
{
private :
	//Defintion
	enum enMode;

	string _AccoutNumber;
	string _Pincode;
	enMode _Mode;
	double  _Balance;
	bool _MarkForDeleted = false;

	// proprties


	static ClsBankClient _ConvertLineToOBJ(string Line, string Separator = "#//#")
	{
		//asd4as44#//#asdas#//#asd#//#sad#//#A501#//#asd#//#5454.000000
		vector <string> VClientData;

		VClientData = ClsString::Split(Line, Separator);

		return (ClsBankClient(enMode::updateObj, VClientData[0], VClientData[1], VClientData[2], VClientData[3]
			, VClientData[4], ClsUtil::Decrypt(VClientData[5]), stod(VClientData[6])));
		
	}
	static string _ConvertObjToLine(ClsBankClient Client , string Separator = "#//#")
	{
		string DataLine = "";

		DataLine += Client.FirstName + Separator;
		DataLine += Client.LastName + Separator;
		DataLine += Client.Email + Separator;
		DataLine += Client.Phone + Separator;
		DataLine += Client.GetAccountNumber() + Separator;
		DataLine += ClsUtil::Encrypt(Client.Pincode) + Separator;
		DataLine += to_string(Client.Balance);

		return DataLine;
	}
	static vector <ClsBankClient> _LoadDataFromFile()
	{
		vector <ClsBankClient> VClients;

		fstream Myfile;
		Myfile.open("Clients.txt", ios::in); // Read Mode
		if (Myfile.is_open())
		{
			string DataLine;
			while (getline(Myfile, DataLine))
			{
				ClsBankClient Client = _ConvertLineToOBJ(DataLine);
				VClients.push_back(Client);
			}
			Myfile.close();
		}


		return VClients;

	}



	static ClsBankClient _GetEmptyOBJ()
	{
		return (ClsBankClient(enMode::emptyObj , "", "", "", "", "", "", 0000));
	}
	bool _IsEmpty()
	{
		return (_Mode == enMode::emptyObj ? 1 : 0);
	}

	// 
	void _SaveClientsDataToFile(vector <ClsBankClient> VClients)
	{
		fstream Myfile;
		Myfile.open("Clients.txt", ios::out ); // write mode only

		if(Myfile.is_open())
		{ 
		     string DataLine;
		    for (ClsBankClient C : VClients)
		    {
				if (C._MarkForDeleted == false)
				{ 
		    	DataLine = _ConvertObjToLine(C);
				Myfile << DataLine << endl;
				}
		    }
			Myfile.close();
		}

	}

	void SaveClienttoFile(string Line)
	{
		fstream Myfile;

		Myfile.open("Clients.txt", ios::out | ios::app); // Append mode

		if (Myfile.is_open())
		{
			Myfile << Line << "\n";
			Myfile.close();
		}


	}
 
	void _Update()
	{
		vector <ClsBankClient> Vclients;

		Vclients = _LoadDataFromFile();

		for (ClsBankClient & C : Vclients)
		{
			if (C.GetAccountNumber() == this->GetAccountNumber())
			{
				C = *this;
				break;
			}
		}

		_SaveClientsDataToFile(Vclients);
	}
	void _NewClient()
	{
		SaveClienttoFile(_ConvertObjToLine(*this));
	}
	string _PrpRegstrLine(string S, float Amount, ClsBankClient ToClient)
	{
		string Line = "";
		Line += ClsDate::GetDateTimeString();

		Line += S + this->_AccoutNumber;
		Line += S + ToClient.GetAccountNumber();
		Line += S + to_string(Amount);
		Line += S + to_string(this->Balance);
		Line += S + to_string(ToClient.Balance);
		Line += S + CurrentUser.Username;

		return Line;

	}

	 
	

public :
	/*bool WhitDraw(double NwBalance);
	void Deposite(double NwBalance);*/

	
	enum enMode { emptyObj = 1, updateObj = 2, newObj = 3 };

	ClsBankClient( enMode NewMode ,string NewFirstName, string NewLastName, string NewEmail, string NewPhone, string NewAccountNumber
		, string NewPincode, double NewBalance) : ClsPerson(NewFirstName , NewLastName , NewEmail , NewPhone )
	{
		 _AccoutNumber = NewAccountNumber;
		_Pincode =NewPincode;
		_Mode = NewMode ;
		_Balance = NewBalance;
	}

	struct stTransfeerElements
	{
		string DateTime;
		string SaccountNom;
		string DaccountNom;
		double Amount;
		double NewSBalance;
		double NewDBalance;
		string Username;
	};

	// Get Account Number ** Read Only
	string GetAccountNumber()
	{
		return (_AccoutNumber);
	}

	//Password 
	string GetPincode()
	{
		return (_Pincode);
	}
	void SetPincode(string NewPincode)
	{
		_Pincode = NewPincode;
	}
	__declspec(property (get = GetPincode, put = SetPincode)) string Pincode;

	// Balance 
	float GetBalance()
	{
		return (_Balance);
	}
	void SetBalance(double NewBalnce)
	{
		_Balance = NewBalnce;
	}
	__declspec(property (get = GetBalance, put = SetBalance)) float Balance;

	// Mode 
	enMode GetMode()
	{
		return (_Mode);
	}
	void SetMode(enMode Newmode)
	{
		Newmode = _Mode;
	}
	__declspec(property (get = GetMode, put = SetMode)) enMode Mode;

	//Transfer
	void SaveRegTransfer(float Amount, ClsBankClient ToClient)
	{
		
		
			fstream Myfile;

			Myfile.open("TransferProcFile.txt", ios::out | ios::app);

			if (Myfile.is_open())
			{

				string DataLine = _PrpRegstrLine("#//#" , Amount , ToClient);

				Myfile << DataLine << endl;


				Myfile.close();
			
		    }

	}
	bool Transfeer(float Amount , ClsBankClient& ToClient)
	{

		if (Amount > _Balance)
			return false;


		

		WhitDraw(Amount);
		ToClient.Deposite(Amount);
		SaveRegTransfer(Amount, ToClient);
		
		return true;

	}
	// don't forget apply abstraction
    static 	stTransfeerElements _ConvertLineToStruct(string DataLine , string Separator = "#//#")
	{
		stTransfeerElements St;
		vector <string> VData = ClsString::Split(DataLine, Separator);

		St.DateTime = VData[0];
		St.SaccountNom = VData[1];
		St.DaccountNom = VData[2];
		St.Amount = stod(VData[3]);
		St.NewSBalance = stod(VData[4]);
		St.NewDBalance = stod(VData[5]);
		St.Username = VData[6];

		return St;


	}
	static vector <stTransfeerElements> _LoadProcessFromFile()
	{
		vector <stTransfeerElements> VProcess;

		fstream Myfile;
		Myfile.open("TransferProcFile.txt", ios::in); // Read Mode
		if (Myfile.is_open())
		{
			string DataLine;
			while (getline(Myfile, DataLine))
			{
				stTransfeerElements Process = _ConvertLineToStruct(DataLine);
				VProcess.push_back(Process);
			}
			Myfile.close();
		}

		return VProcess;
	}


	// Find Metodes
	static ClsBankClient Find(string AccountNumber)
	{
		//vector < ClsBankClient> VClients;

		fstream Myfile; 
		Myfile.open("Clients.txt", ios::in); // Read Only 

		if (Myfile.is_open())
		{
			string DataLine;

			while (getline(Myfile, DataLine))
			{
				ClsBankClient Client = _ConvertLineToOBJ(DataLine);
				if (Client.GetAccountNumber() == AccountNumber)
				{
					Myfile.close();
					return Client;
				}

			}
			Myfile.close();
			return _GetEmptyOBJ();

		}

	}
	static ClsBankClient Find(string AccountNumber , string Password)
	{
		//vector < ClsBankClient> VClients;

		fstream Myfile; 
		Myfile.open("Clients.txt", ios::in); // Read Only 

		if (Myfile.is_open())
		{
			string DataLine;

			while (getline(Myfile, DataLine))
			{
				ClsBankClient Client = _ConvertLineToOBJ(DataLine);
				if (Client.GetAccountNumber() == AccountNumber && Client.Pincode == Password)
				{
					Myfile.close();
					return Client;
				}

			}
			Myfile.close();
			return _GetEmptyOBJ();

		}

	}

	
	// Add CLients Methods
	static ClsBankClient AddClient(string AccountNumber)
	{
		return (ClsBankClient(enMode::newObj, "", "", "", "", AccountNumber, "", 0));
	}
	
	// Delete Client form file
	bool DeleteClient()
	{
		vector <ClsBankClient> _Vclients;
		_Vclients = _LoadDataFromFile();

		for (ClsBankClient &C : _Vclients)
		{
			if (C.GetAccountNumber() == _AccoutNumber)
			{
				C._MarkForDeleted = true;
				break;
			}
		}
		*this = _GetEmptyOBJ();
		_SaveClientsDataToFile(_Vclients);
		
		return true;

	}
	
	// Print Client Card
	//Print Client Record in one Line
	void PrintClientforBalancesList(ClsBankClient Client)
	{
		cout << "| " << left << setw(15) << Client._AccoutNumber;
		cout << "| " << left << setw(40) <<Client.FullName();
		cout << "| " << left << setw(12) << Client.Balance;
	}

	// Check if client exist in the file 
	static bool IsCLientExist(string AccNumber)
	{
		ClsBankClient Client = ClsBankClient::Find(AccNumber);

		return (!Client._IsEmpty());
	}


	// Get list of all clients in file
	static vector <ClsBankClient> GetClientsList()
	{
		return (_LoadDataFromFile());
	}


	// Get total balances 
	static double GetTotalBalances()
	{
		vector <ClsBankClient> VClients = _LoadDataFromFile();

		double TotalBalances = 0;

		for (ClsBankClient Client : VClients)
		{
			TotalBalances += Client.Balance;
		}

		return TotalBalances;
	}

	enum enAcsessToSave {SaveSucsseded =1 , SaveFailedClientEmpty =2  , SaveFailedClientExist =3 };

        enAcsessToSave Save()
	    {
		switch (_Mode)
		{
		case enMode::updateObj:
		{
			_Update();
			return enAcsessToSave::SaveSucsseded;
			
		}
		case enMode::newObj:
		{
			if (ClsBankClient::IsCLientExist(_AccoutNumber))
			{
				return SaveFailedClientExist;
			}
			else 
			{

			_NewClient();
			_Mode = updateObj;
			return SaveSucsseded;
			}
		}
		
		case enMode::emptyObj:
		{
			return enAcsessToSave::SaveFailedClientEmpty;
			
		}
		}
	    }

		void Deposite(double NwBalance)
		{
			Balance += NwBalance;
			Save();
		}
		bool WhitDraw(double NwBalance)
		{
			if (NwBalance > Balance)
				return 0;
			else 
			{
			Balance -= NwBalance;
			Save();
			}
			return 1;
		}

};