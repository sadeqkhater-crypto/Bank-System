#pragma once

#include"MyFunctionLib.h"


#include <iomanip>
#include <iostream>
#include <cstdio>
#include<vector>
#include<string.h>
#include<cctype>
#include<string>
#include<fstream>
#include<ctime>


/*
*  1
*  2
*  4 
*  8
*  16
*  32 
*  64
*/


using namespace std;
using namespace MyFunctionsLib;
namespace BankingSystemLib
{

	
	const string FileName = "Clients.txt";
	const string FileName2 = "Users.txt";

	struct sLogin
	{
		string UserName;
		string PassWord;
		int Permissions = 0;
	};

	struct sClient {
		string AccountNumber;
		string PinCode;
		string Name;
		string Phone;
		int AccountBalance = 0;
	};

	enum enTransactionsMenuOption
	{
		Deposit = 1,
		Withdraw = 2,
		TotalBalance = 3,
		MainMenue = 4
	};

	enum enBinaryNumber
	{
		ShowClientList = 1,
		AddNewClient = 2,
		DeleteClient = 3,
		UpdateClientInfo = 4,
		FindClient = 5,
		Transactions = 6,
		ManageUsers = 7

	};

	char ReadCharacter(string massage)
	{
		char ch;

		cout << massage;
		cin >> ch;

		return ch;

	}

	string ReadString(string massage)
	{
		string Name = "";

		cout << massage;
		getline(cin >> ws, Name); 

		return Name;

	}

	int ReadNumberPositive(string massage)
	{
		int Number;
		do {
			cout << massage;
			cin >> Number;
		} while (Number <= 0);

		return Number;
	}


	void ShowFindUserScreen();
	sLogin ReadNewUser();
	void ShowUpdateUserScreen();
	sClient ReadNewClient();
	void PrintUserCard(sLogin Login);
	bool AskForDeleteOrUpdateUser(int Number);
	sLogin ResearchLoginByUsername(vector<sLogin>& vLogin, string username);
	void ShowDeleteUserScreen();
	void ShowAccessDeniedScreen();
	sLogin ConvertLineToRecordLogin(string Line);
	void SaveUserToFile(vector<sLogin>& vLogin, int Number, string Line, sLogin Login1);
	string ConvertLoginToLine(sLogin Login, string Spemeter = "#//#");
	int ReadUserPermissions();
	vector<int> AskForUserPermissions();
	sLogin AddUser(vector<sLogin>& vLogin);
	bool IsUserNameFound(vector<sLogin>& vLogin, string UserName);
	void ShowAddUserScreen();
	void ShowUsersList(vector<sLogin>& vLogin);
	vector<sLogin> LoadLoginDataFromFile(string FileName);
	void ShowManagerUserMenu(vector<sLogin>& vLogin, string username = " ");
	void Login();
	void ShowMainMenu(string username = "");
	vector<sClient> LoadClientsDataFromFile(string FileName);
	bool CheckClientActionMainMenue(vector<sClient> vClients, string AccountNumber, int Number);
	void PrintClientCard(vector<sClient>& vClients, sClient Client);
	void ShowClientsList(vector<sClient>& vClients);
	void ShowAddNewClientScreen();
	void ShowDeleteClientScreen();
	void SaveClientToFile(vector<sClient> vClients, int Number, string Line, sClient Client);
	sClient ResearchClintByAccountNumber(vector<sClient>& vClients, string AccountNumber);
	string ConvertClientToLine(sClient Client, string Spemeter = "#//#");
	sClient InilizationClient(vector<sClient>& vClients);
	void ShowUpdateClientScreen();
	void ShowFindClientScreen();
	bool IsClientExistAccountNumber(vector<sClient>& vClients, string AccountNumber);
	void ShowExistScreen();
	void ShowTransactionsMenu(vector<sClient>& vClient, string username = "");
	void ShowDepositScreen();
	string IsAccountNumber(vector<sClient>& vClients);
	void PerformDeposit(vector<sClient>& vClient, int Deposit, string AccounNumber, enTransactionsMenuOption TransactionsMenuOption);
	void SaveTransactionToFile(enTransactionsMenuOption TransactionsMenuOption, vector<sClient>& vClient, string AccountNumber, sClient Client);
	void ShowTotalBalance(vector<sClient>& vClients);
	void ShowWithDrowScreen();


	bool ReturnPermission(int Number, string username , vector<sLogin>& vLogin)
	{
		for (sLogin& L : vLogin)
		{
			if (L.UserName == username)
			{
				if (MyFunctionsLib::BitWiseAndOperator(L.Permissions, pow(2, Number - 1)) != 0)
				{
					return true;
				}
			}
		}

		return false;
	}

	void ExecuteManageUserMenuOption(int Number, vector<sLogin>& vLogin)
	{
		sLogin Login;

		switch (Number)
		{

		case 1:
			ShowUsersList(vLogin);
			break;




		case 2:
			ShowAddUserScreen();

			char Answer;
			do
			{
				sLogin Login1 = AddUser(vLogin);
				vLogin.push_back(Login1);
				SaveUserToFile(vLogin , Number , " ", Login1);

				Answer = ReadCharacter("User Added Successfully, do you want to add more users? y/n? ");
			} while (toupper(Answer) == 'Y');
			break;








		case 3:
			ShowDeleteUserScreen();

				Login.UserName = ReadString("Please enter Username? ");

				if (IsUserNameFound(vLogin, Login.UserName))
				{
					PrintUserCard(ResearchLoginByUsername(vLogin, Login.UserName));
					if (AskForDeleteOrUpdateUser(Number))
					{
						sLogin Login1 = ResearchLoginByUsername(vLogin, Login.UserName);
						SaveUserToFile(vLogin, Number, " ", Login1);
					}
				}
				else
				{
					cout << "User with Username (" << Login.UserName << ") is Not Found\n\n";
				}
				break;


		case 4:
		{
			ShowUpdateUserScreen();
			Login.UserName = ReadString("Please enter Username? ");

			if (IsUserNameFound(vLogin, Login.UserName))
			{
				PrintUserCard(ResearchLoginByUsername(vLogin, Login.UserName));
				if (AskForDeleteOrUpdateUser(Number))
				{
					sLogin Login1 = ResearchLoginByUsername(vLogin, Login.UserName);
					SaveUserToFile(vLogin, Number, Login.UserName , Login1);
				}
			}
			else
			{
				cout << "User with Username (" << Login.UserName << ") is Not Found\n\n";
			}
			break;
		}

		case 5:

			ShowFindUserScreen();
			Login.UserName = ReadString("Please enter Username? ");

			if (IsUserNameFound(vLogin, Login.UserName))
			{
				PrintUserCard(ResearchLoginByUsername(vLogin, Login.UserName));
			}
			else
			{
				cout << "User with Username (" << Login.UserName << ") is Not Found\n\n";
			}
			break;



		}

	}

	void ExecuteTransactionsMenuOption(int Number, vector<sClient>& vClients)
	{
		enTransactionsMenuOption TransactionsMenuOption;
		sClient Client;

		switch (Number)
		{
		case 1:
			ShowDepositScreen();
			Client.AccountNumber = IsAccountNumber(vClients);
			PrintClientCard(vClients, ResearchClintByAccountNumber(vClients, Client.AccountNumber));
			PerformDeposit(vClients, ReadNumberPositive("Please enter deposit amount? "), Client.AccountNumber, (enTransactionsMenuOption)Number);
			break;

		case 2:
			ShowWithDrowScreen();
			Client.AccountNumber = IsAccountNumber(vClients);
			PrintClientCard(vClients, ResearchClintByAccountNumber(vClients, Client.AccountNumber));
			PerformDeposit(vClients, ReadNumberPositive("Please enter Withdraw amount? "), Client.AccountNumber, (enTransactionsMenuOption)Number);
			break;

		case 3:

			ShowTotalBalance(vClients);
			break;
		}
	}

	void ExecuteMainMenuOption(int ChooseNumber , string username = "")
	{
		sClient Client;
		vector<sClient> vClients = LoadClientsDataFromFile(FileName);
		vector<sLogin> vLogin = LoadLoginDataFromFile(FileName2);


		switch (ChooseNumber)
		{

		case 1:
		{
			if (ReturnPermission(ChooseNumber, username, vLogin))
			{
				ShowClientsList(vClients);
				break;
			}
			ShowAccessDeniedScreen();
			break;
	        
		}

		case 2:
		{
			if (ReturnPermission(ChooseNumber, username, vLogin))
			{
				ShowAddNewClientScreen();
				char AddClient = 'y';
				do
				{
					SaveClientToFile(vClients, ChooseNumber, ConvertClientToLine(InilizationClient(vClients)), Client);
					cout << "\nClient Added Successfuly, do you want to add more clients? Y/N? ";
					cin >> AddClient;
				} while (AddClient == 'y' || AddClient == 'Y');
				break;
			}
			ShowAccessDeniedScreen();
			break;
		}


		case 3:
		{
			if (ReturnPermission(ChooseNumber, username, vLogin))
			{
				ShowDeleteClientScreen();
				Client.AccountNumber = ReadString("Please Enter AccountNumber? ");
				if (CheckClientActionMainMenue(vClients, Client.AccountNumber, ChooseNumber))
				{
					sClient Client1 = ResearchClintByAccountNumber(vClients, Client.AccountNumber);
					SaveClientToFile(vClients, ChooseNumber, " ", Client1);
				}
				break;
			}
			ShowAccessDeniedScreen();
			break;
		}

		case 4:
		{
			if (ReturnPermission(ChooseNumber, username, vLogin))
			{
				ShowUpdateClientScreen();
				Client.AccountNumber = ReadString("Please enter AccountNumber? ");
				if (CheckClientActionMainMenue(vClients, Client.AccountNumber, ChooseNumber))
				{
					sClient Client1 = ResearchClintByAccountNumber(vClients, Client.AccountNumber);
					SaveClientToFile(vClients, ChooseNumber, Client.AccountNumber, Client1);
				}
				break;
			}
			ShowAccessDeniedScreen();
			break;
		}

		case 5:
		{
			if (ReturnPermission(ChooseNumber, username, vLogin))
			{
				ShowFindClientScreen();
				Client.AccountNumber = ReadString("Please enter AccountNumber? ");
				if (IsClientExistAccountNumber(vClients, Client.AccountNumber))
				{
					sClient IsClient = ResearchClintByAccountNumber(vClients, Client.AccountNumber);
					PrintClientCard(vClients, IsClient);
				}
				else
				{
					cout << "\n\nClient with Account Number (" << Client.AccountNumber << ") is Not Found\n\n";
				}
				break;
			}
			ShowAccessDeniedScreen();
			break;
		}

		case 6:
		{
			if (ReturnPermission(ChooseNumber, username, vLogin))
			{
				ShowTransactionsMenu(vClients , username);
				break;
			}
			ShowAccessDeniedScreen();
			break;
		}

		case 7:
		{
			if (ReturnPermission(ChooseNumber, username, vLogin))
			{
				ShowManagerUserMenu(vLogin  , username);
				break;
			}
			ShowAccessDeniedScreen();
			break;
		}
			
		case 8:
			Login();
			break;
		}



	}

	sLogin AddUser( vector<sLogin> &vLogin)
	{
		sLogin Login;

		bool Result = false;

		Login.UserName = ReadString("Enter UserName? ");

		do
		{
			if (Result == true)
			{
				cout << "User With [" << Login.UserName << "] already exists, ";
				Login.UserName = ReadString("Enter another UserName? ");
			}

			if (IsUserNameFound(vLogin, Login.UserName))
			{
				Result = true;
			}
			else
			{
				Result = false;
			}
			
		} while (Result == true);

		Login.PassWord = ReadString("Enter Password? ");

		Login.Permissions = ReadUserPermissions();

		return Login;
	}

	int ReadUserPermissions()
	{
		sLogin Login;

		char Answer = ReadCharacter("Do you want to give full access? y/n? ");

		vector<int> vNumber ;

		int Number = 0;

		if (toupper(Answer) == 'N')
		{
			 vNumber = AskForUserPermissions();

			for (int i = 0; i < vNumber.size(); i++)
			{
				Number = MyFunctionsLib::BitWiseOrOperator(Number, vNumber[i]);
			}

			return Number;
		}
		else
		{
			return Number = -1;
		}
	}

	vector<int> AskForUserPermissions()
	{
		enBinaryNumber Binary;
		vector<int> Number;
		int Answer; 

		for (int i = 1; i <= 7; i++)
		{
			switch (i)
			{

		     case enBinaryNumber::ShowClientList :
				 Answer = ReadCharacter(" Show Client List? ");
				 if (toupper(Answer) == 'Y')
				 {
					 Number.push_back(1);
				 }
				break;


			 case enBinaryNumber::AddNewClient:
				 Answer = ReadCharacter(" Add New Client? ");
				 if (toupper(Answer) == 'Y')
				 {
					 Number.push_back(2);
				 }
				 break;


			 case enBinaryNumber::DeleteClient:

				 Answer = ReadCharacter(" Delete Client? ");
				 if (toupper(Answer) == 'Y')
				 {
					 Number.push_back(4);
				 }
				 break;


			 case enBinaryNumber::UpdateClientInfo:
				 Answer = ReadCharacter(" Update Client List? ");
				 if (toupper(Answer) == 'Y')
				 {
					 Number.push_back(8);
				 }
				 break;

			 case enBinaryNumber::FindClient:
				 Answer = ReadCharacter(" Find Client ? ");
				 if (toupper(Answer) == 'Y')
				 {
					 Number.push_back(16);
				 }
				 break;

			 case enBinaryNumber::Transactions:
				 Answer = ReadCharacter(" Transactions? ");
				 if (toupper(Answer) == 'Y')
				 {
					 Number.push_back(32);
				 }
				 break;

			 case enBinaryNumber::ManageUsers:
				 Answer = ReadCharacter(" Manager Users? ");
				 if (toupper(Answer) == 'Y')
				 {
					 Number.push_back(64);
				 }
				 break;

			}
		}

		return Number;
	}

	void SaveUserToFile(vector<sLogin> &vLogin , int Number , string Line , sLogin Login1)
	{
		
		
		switch (Number)
		{
		   case 2:
		   {
			   ofstream MyFile;

			   MyFile.open(FileName2, ios::out);

			   if (MyFile.is_open())
			   {
				   for (sLogin& L : vLogin)
				   {
					   Line = ConvertLoginToLine(L);
					   MyFile << Line << endl;
				   }

				   MyFile.close();
			   }
			   break;
		   }

		   case 3:
		   {
			   int Index = -1;
			   fstream MyFile;

			   MyFile.open(FileName2, ios::out);

			   if (MyFile.is_open())
			   {
				   for (int i = 0; i < vLogin.size(); i++)
				   {
					   if (vLogin[i].UserName == Login1.UserName)
					   {
						   Index = i;
					   }
					   else
					   {
						   Line = ConvertLoginToLine(vLogin[i]);
						   MyFile << Line << endl;
					   }
				   }

				   MyFile.close();
			   }

			   if (Index != -1)
			   {
				   vLogin.erase(vLogin.begin() + Index);
			   }

			   break;
		   }


		   case 4:
		   {
			   fstream MyFile;

			   MyFile.open(FileName2, ios::out);

			   if (MyFile.is_open())
			   {
				   string Data;
				   for (sLogin& L : vLogin)
				   {
					   if (L.UserName != Login1.UserName)
					   {
						   Data = ConvertLoginToLine(L);
						   MyFile << Data << endl;
					   }
					   else
					   {
						   L = ReadNewUser();
						   L.UserName = Line;
						   Data = ConvertLoginToLine(L);
						   MyFile << Data << endl;
					   }

				   }
			   }

			   MyFile.close();

			   break;
		   }




		}

		  

	}

	void SaveClientToFile(vector<sClient> vClients, int Number, string Line, sClient Client)
	{
		switch (Number)
		{
		case 2:
		{
			fstream MyFile;

			MyFile.open(FileName, ios::out | ios::app);

			if (MyFile.is_open())
			{
				MyFile << Line << endl;
			}

			MyFile.close();

			break;
		}

		case 3:
		{
			fstream MyFile;

			MyFile.open(FileName, ios::out);

			if (MyFile.is_open())
			{
				for (sClient& c : vClients)
				{
					if (c.AccountNumber != Client.AccountNumber)
					{
						Line = ConvertClientToLine(c);
						MyFile << Line << endl;
					}

				}
			}

			MyFile.close();

			break;
		}

		case 4:
		{
			fstream MyFile;

			MyFile.open(FileName, ios::out);

			if (MyFile.is_open())
			{
				string Data;
				for (sClient& c : vClients)
				{
					if (c.AccountNumber != Client.AccountNumber)
					{
						Data = ConvertClientToLine(c);
						MyFile << Data << endl;
					}
					else
					{
						c = ReadNewClient();
						c.AccountNumber = Line;
						Data = ConvertClientToLine(c);
						MyFile << Data << endl;
					}

				}
			}

			MyFile.close();

			break;
		}


		}

	}

	bool IsUserNameFound(vector<sLogin>& vLogin, string UserName)
	{
		for (sLogin& L : vLogin)
		{
			if (L.UserName == UserName)
			{
				return true;
			}
		}
		return false;
	}

	bool IsClientExistAccountNumber(vector<sClient>& vClients, string AccountNumber)
	{
		for (sClient& c : vClients)
		{
			if (c.AccountNumber == AccountNumber)
			{
				return true;
			}
		}
		return false;
	}

	sClient ResearchClintByAccountNumber(vector<sClient>& vClients, string AccountNumber)
	{
		for (sClient& c : vClients)
		{
			if (c.AccountNumber == AccountNumber)
			{
				return c;
			}
		}
	}

	sLogin ResearchLoginByUsername(vector<sLogin>& vLogin, string username)
	{
		for (sLogin& L : vLogin)
		{
			if (L.UserName == username)
			{
				return L;
			}
		}
	}

	vector<string> splitLine(string Line, string Spemeter = "#//#")
	{
		vector<string> Members;

		int pos = 0;

		while ((pos = Line.find(Spemeter)) != std::string::npos)
		{
			Members.push_back(Line.substr(0, pos));
			Line.erase(0, pos + Spemeter.length());
		}
		if (Line != "")
		{
			Members.push_back(Line);
		}
		return Members;
	}

	sClient ConvertLineToRecordClient(string Line)
	{
		sClient Client;

		vector<string> Members = splitLine(Line);

		Client.AccountNumber = Members[0];
		Client.PinCode = Members[1];
		Client.Name = Members[2];
		Client.Phone = Members[3];
		Client.AccountBalance = stoi(Members[4]);

		return Client;
	}
	
	sLogin ConvertLineToRecordLogin(string Line)
	{
		sLogin Login;

		vector<string> Members = splitLine(Line);

		Login.UserName = Members[0];
		Login.PassWord = Members[1];
		Login.Permissions = stoi(Members[2]);

		return Login;
	}


	string ConvertClientToLine(sClient Client, string Spemeter)
	{
		string S1 = "";
		S1 += Client.AccountNumber + Spemeter;
		S1 += Client.PinCode + Spemeter;
		S1 += Client.Name + Spemeter;
		S1 += Client.Phone + Spemeter;
		S1 += to_string(Client.AccountBalance);

		return S1;
	}

	string ConvertLoginToLine(sLogin Login, string Spemeter)
	{
		string S1 = "";
		S1 += Login.UserName + Spemeter;
		S1 += Login.PassWord + Spemeter;
		S1 += to_string(Login.Permissions);

		return S1;
	}

	vector<sClient> LoadClientsDataFromFile(string FileName)
	{
		vector<sClient> vClients;
		sClient Client;

		ifstream MyFile;

		MyFile.open(FileName, ios::in);

		if (MyFile.is_open())
		{
			string Line;

			while (getline(MyFile, Line))
			{
				Client = ConvertLineToRecordClient(Line);
				vClients.push_back(Client);
			}

			MyFile.close();
		}

		return vClients;
	}

	vector<sLogin> LoadLoginDataFromFile(string FileName)
	{
		vector<sLogin> vLogin;
		sLogin Login;

		ifstream MyFile;

		MyFile.open(FileName2, ios::in);

		if (MyFile.is_open())
		{
			string Line;

			while (getline(MyFile, Line))
			{
				Login = ConvertLineToRecordLogin(Line);
				vLogin.push_back(Login);
			}

			MyFile.close();
		}

		return vLogin;
	}

	void PrintClientsListHeader()
	{
		cout << "-----------------------------------------------------------------------------------------\n\n";
		cout << "| Account Number  | Pin Code  | Client Name                     | Phone       |Balance\n\n";
		cout << "-----------------------------------------------------------------------------------------\n\n";
	}

	void PrintUsersListHeader()
	{
		cout << "------------------------------------------------\n\n";
		cout << "| User Name       | PassWord  | Permissions         \n\n";
		cout << "------------------------------------------------\n\n";
	}

	void ShowAddNewClientScreen()
	{

		cout << "---------------------------------------------\n";
		cout << "              Add New Client Screen\n";
		cout << "---------------------------------------------\n";
		cout << "Adding New Client: \n\n";
	}

	void ShowDeleteClientScreen()
	{
		cout << "---------------------------------------------\n";
		cout << "              Delete Client Screen\n";
		cout << "---------------------------------------------\n\n";
	}

	void ShowUpdateClientScreen()
	{
		cout << "---------------------------------------------\n";
		cout << "              Update Client Screen\n";
		cout << "---------------------------------------------\n\n";
	}

	void ShowFindClientScreen()
	{
		cout << "---------------------------------------------\n";
		cout << "              Find Client Screen\n";
		cout << "---------------------------------------------\n\n";
	}

	void ShowExistScreen()
	{
		cout << "---------------------------------------------\n";
		cout << "              Program Ends :-)\n";
		cout << "---------------------------------------------\n\n";
	}

	void ShowDepositScreen()
	{
		cout << "---------------------------------------------\n";
		cout << "              Deposit Screen \n";
		cout << "---------------------------------------------\n\n";
	}

	void ShowWithDrowScreen()
	{
		cout << "---------------------------------------------\n";
		cout << "              Withdraw Screen \n";
		cout << "---------------------------------------------\n\n";
	}
    
	void ShowLoginScreen()
	{
		cout << "---------------------------------------------\n";
		cout << "              Login Screen \n";
		cout << "---------------------------------------------\n\n";
	}

	void ShowAddUserScreen()
	{
		cout << "---------------------------------------------\n";
		cout << "              Add New User Screen \n";
		cout << "---------------------------------------------\n\n";

		cout << "Adding User Screen: \n\n";
	}

	void ShowDeleteUserScreen()
	{
		cout << "---------------------------------------------\n";
		cout << "             Delete User's Screen \n";
		cout << "---------------------------------------------\n\n";

	}

	void ShowUpdateUserScreen()
	{
		cout << "---------------------------------------------\n";
		cout << "             Update User Screen \n";
		cout << "---------------------------------------------\n\n";

	}

	void ShowFindUserScreen()
	{
		cout << "---------------------------------------------\n";
		cout << "             Find User Screen \n";
		cout << "---------------------------------------------\n\n";

	}

	void ShowAccessDeniedScreen()
	{
		cout << "---------------------------------------------\n";
		cout << " Access Denied, \n ";
		cout << "You Don't Have Permission To Do this, \n ";
		cout << "Please Contact Your Admin. \n";
		cout << "---------------------------------------------\n\n";

	}

	void PrintClientRecord(sClient Client)
	{

		cout << "| " << setw(15) << left << Client.AccountNumber
			<< " | " << setw(10) << left << Client.PinCode
			<< "| " << setw(20) << left << Client.Name
			<< "            | " << setw(11) << left << Client.Phone
			<< " | " << setw(10) << left << Client.AccountBalance << "\n";
	}

	void PrintUsersRecord(sLogin Login)
	{

		cout << "| " << setw(15) << left << Login.UserName
			<< " | " << setw(10) << left << Login.PassWord
			<< "| " << setw(20) << left << Login.Permissions << endl;
			
	}

	void PrintClientCard(vector<sClient>& vClients, sClient Client)
	{

		cout << "\nThe following are the client details:\n";
		cout << "- - - - - - - - - - - - - - - - - - - \n";
		cout << "Account Number: " << Client.AccountNumber << endl;
		cout << "Pin Code: " << Client.PinCode << endl;
		cout << "Name: " << Client.Name << endl;
		cout << "Phone: " << Client.Phone << endl;
		cout << "Account Balance: " << Client.AccountBalance << endl;
		cout << "- - - - - - - - - - - - - - - - - - - \n\n\n";



	}

	void PrintUserCard(sLogin Login)
	{
		cout << "\nThe following are the User details:\n";
		cout << "- - - - - - - - - - - - - - - - - - - \n";
		cout << "Account Number: " << Login.UserName << endl;
		cout << "Pin Code: " << Login.PassWord << endl;
		cout << "Name: " << Login.Permissions << endl;
		cout << "- - - - - - - - - - - - - - - - - - - \n\n\n";
	}

	bool AskForDeleteOrUpdateClient(int Number)
	{
		switch (Number)
		{
		case 3:
		{
			char SureDelete = ReadCharacter("Are you sure you want delete this client? y/n? ");

			if (SureDelete == 'y' || SureDelete == 'Y')
			{
				return true;
			}
			else
			{
				cout << "Client was not deleted\n";
				return false;
			}
		}

		case 4:
		{
			char SureUpdate = ReadCharacter("Are you sure you want Update this client? y/n? ");

			if (SureUpdate == 'y' || SureUpdate == 'Y')
			{
				return true;
			}
			else
			{
				cout << "Client was not updated\n";
				return false;
			}
		}
		}


	}

	bool AskForDeleteOrUpdateUser(int Number)
	{
		switch (Number)
		{
		case 3:
		{
			char SureDelete = ReadCharacter("Are you sure you want delete this User? y/n? ");

			if (SureDelete == 'y' || SureDelete == 'Y')
			{
				return true;
			}
			else
			{
				cout << "User was not deleted\n";
				return false;
			}
		}

		case 4:
		{
			char SureUpdate = ReadCharacter("Are you sure you want Update this User? y/n? ");

			if (SureUpdate == 'y' || SureUpdate == 'Y')
			{
				return true;
			}
			else
			{
				cout << "User was not updated\n";
				return false;
			}
		}

		
		}
	}

	void ShowClientsList(vector<sClient>& vClients)
	{
		cout << "                                        Client List (" << vClients.size() << ") Client (s)\n\n";

		PrintClientsListHeader();

		for (sClient& c : vClients)
		{
			PrintClientRecord(c);
		}

		cout << "\n\n-----------------------------------------------------------------------------------------\n\n\n";
	}

	void ShowUsersList(vector<sLogin>& vLogin)
	{
		cout << "                                        Users List (" << vLogin.size() << ") Users (s)\n\n";

		PrintUsersListHeader();

		for (sLogin& c : vLogin)
		{
			PrintUsersRecord(c);
		}

		cout << "\n\n------------------------------------------------\n\n\n";
	}

	void ShowTotalBalance(vector<sClient>& vClients)
	{
		int sum = 0;

		cout << "                                        Client List (" << vClients.size() << ") Client (s)\n\n";

		cout << "-----------------------------------------------------------------------------------------\n\n";
		cout << "| Account Number        |    Client Name                         |Balance\n\n";
		cout << "-----------------------------------------------------------------------------------------\n\n";

		for (sClient& c : vClients)
		{
			cout << "| " << setw(15) << left << c.AccountNumber
				<< "       | " << setw(20) << left << c.Name
				<< "                   | " << setw(10) << left << c.AccountBalance << "\n";

			sum += c.AccountBalance;
		}

		cout << "\n\n-----------------------------------------------------------------------------------------\n\n\n";

		cout << "                                                            Totale Balance = " << sum << "\n\n";
	}

	sClient ReadNewClient()
	{
		sClient Client;

		Client.PinCode = ReadString("\nEnter PinCode? ");
		Client.Name = ReadString("\nEnter Name? ");
		Client.Phone = ReadString("\nEnter Phone? ");
		Client.AccountBalance = ReadNumberPositive("\nEnter AccountBalance? ");

		return Client;
	}

	sLogin ReadNewUser()
	{
		sLogin Login;
		Login.PassWord = ReadString("Enter Password? ");

		Login.Permissions = ReadUserPermissions();
		
		return Login;
	}

	void SaveTransactionToFile(enTransactionsMenuOption TransactionsMenuOption, vector<sClient>& vClient, string AccountNumber, sClient Client)

	{

		string Line = "";
		fstream MyFile;

		MyFile.open(FileName, ios::out);

		if (MyFile.is_open())
		{
			for (sClient& c : vClient)
			{
				if (c.AccountNumber == Client.AccountNumber)
				{
					c = Client;
					Line = ConvertClientToLine(c);
					MyFile << Line << endl;
				}
				else
				{
					Line = ConvertClientToLine(c);
					MyFile << Line << endl;
				}


			}
		}

		MyFile.close();

	}

	void PerformDeposit(vector<sClient>& vClient, int Amount, string AccounNumber, enTransactionsMenuOption TransactionsMenuOption)
	{
		sClient Client;

		char Perform = 'y';
		Client = ResearchClintByAccountNumber(vClient, AccounNumber);

		if (TransactionsMenuOption == enTransactionsMenuOption::Withdraw)
		{
			if (Client.AccountBalance >= Amount)
			{
				Client.AccountBalance -= Amount;
			}
			else
			{
				cout << "\nInsufficient balance!\n";
				return;
			}
		}
		else
		{
			Client.AccountBalance += Amount;
		}

		if (toupper(ReadCharacter("\nAre you sure you  perform this transaction? y/n?")) == 'Y')
		{
			SaveTransactionToFile(TransactionsMenuOption, vClient, AccounNumber, Client);
			cout << "\n\nDone successfully. New balance = " << Client.AccountBalance << "\n\n";
		}



	}

	string IsAccountNumber(vector<sClient>& vClients)
	{
		sClient Client;

		bool Result = true;

		do
		{
			if (!Result)
			{
				cout << "Client with [" << Client.AccountNumber << "] Not Found. ";
			}

			Client.AccountNumber = ReadString("Enter Account Number? ");
			Result = IsClientExistAccountNumber(vClients, Client.AccountNumber);

		} while (Result == false);

		return Client.AccountNumber;
	}

	sClient InilizationClient(vector<sClient>& vClients)
	{
		sClient Client;

		bool Result = false;

		do
		{
			if (Result)
			{
				cout << "Client with [" << Client.AccountNumber << "] already exists. ";
			}

			Client.AccountNumber = ReadString("Enter Account Number? ");
			Result = IsClientExistAccountNumber(vClients, Client.AccountNumber);

		} while (Result == true);


		Client.PinCode = ReadString("\nEnter PinCode? ");
		Client.Name = ReadString("\nEnter Name? ");
		Client.Phone = ReadString("\nEnter Phone? ");
		Client.AccountBalance = ReadNumberPositive("\nEnter AccountBalance? ");

		vClients.push_back(Client);

		return Client;
	}

	bool CheckClientActionMainMenue(vector<sClient> vClients, string AccountNumber, int Number)
	{
		sClient Client;


		if (IsClientExistAccountNumber(vClients, AccountNumber))
		{
			PrintClientCard(vClients, ResearchClintByAccountNumber(vClients, AccountNumber));
			return AskForDeleteOrUpdateClient(Number);

		}
		else
		{
			cout << "\nClient with Account Number (" << AccountNumber << ") is Not Found\n\n";
			return false;
		}

	}

	void PerformTransactionsMenuOption(int Number, vector<sClient>& vClient , string username ="")
	{
		switch (Number)
		{
		case 1:
			system("cls");
			ExecuteTransactionsMenuOption(Number, vClient);
			system("pause");
			system("cls");
			ShowTransactionsMenu(vClient , username);
			break;

		case 2:

			system("cls");
			ExecuteTransactionsMenuOption(Number, vClient);
			system("pause");
			system("cls");
			ShowTransactionsMenu(vClient , username);
			break;

		case 3:

			system("cls");
			ExecuteTransactionsMenuOption(Number, vClient);
			system("pause");
			system("cls");
			ShowTransactionsMenu(vClient , username);
			break;

		case 4:

			system("cls");
			ShowMainMenu(username);
			break;

		}


	}

	void PerformManageUserMenuOption(int Number, vector<sLogin>& vLogin , string username = " ")
	{
		switch (Number)
		{
		case 1:
			system("cls");
			ExecuteManageUserMenuOption(Number, vLogin);
			system("pause");
			system("cls");
			ShowManagerUserMenu(vLogin);
			break;

		case 2:
			system("cls");
			ExecuteManageUserMenuOption(Number, vLogin);
			system("pause");
			system("cls");
			ShowManagerUserMenu(vLogin);
			break;

		case 3:
			system("cls");
			ExecuteManageUserMenuOption(Number, vLogin);
			system("pause");
			system("cls");
			ShowManagerUserMenu(vLogin);
			break;

		case 4:
			system("cls");
			ExecuteManageUserMenuOption(Number, vLogin);
			system("pause");
			system("cls");
			ShowManagerUserMenu(vLogin);
			break;

		case 5:
			system("cls");
			ExecuteManageUserMenuOption(Number, vLogin);
			system("pause");
			system("cls");
			ShowManagerUserMenu(vLogin);
			break;

		case 6:

			system("cls");
			ShowMainMenu(username);
		}
	}

	void ShowTransactionsMenu(vector<sClient>& vClient , string username )
	{
		cout << "=============================================\n";
		cout << "             Transactions Menue Screen\n";
		cout << "=============================================\n";
		cout << "           [1] Deposit.\n";
		cout << "           [2] Withdraw.\n";
		cout << "           [3] Total Balance.\n";
		cout << "           [4] Main Menue.\n";
		cout << "=============================================\n";

		int ChoiseNumber = ReadNumberPositive("Choose what do you Wand to do? [1 to 4]? ");

		PerformTransactionsMenuOption(ChoiseNumber, vClient , username);
	}

	void ShowManagerUserMenu(vector<sLogin>& vLogin , string username)
	{
		cout << "=============================================\n";
		cout << "             Manage Users Menu Screen\n";
		cout << "=============================================\n";
		cout << "           [1] List Users.\n";
		cout << "           [2] Add New User.\n";
		cout << "           [3] Delete User.\n";
		cout << "           [4] Update User.\n";
		cout << "           [5] Find User.\n";
		cout << "           [6] Main Menu.\n";
		cout << "=============================================\n";

		int ChoiseNumber = ReadNumberPositive("Choose what do you Wand to do? [1 to 6]? ");

		PerformManageUserMenuOption(ChoiseNumber, vLogin , username);
	}

	void PerformMainMenuOption(int Number , string username)
	{
		switch (Number)
		{
		case 1:
		case 2:

		case 3:

		case 4:

		case 5:
			system("cls");
			ExecuteMainMenuOption(Number , username );
			system("pause");
			system("cls");
			ShowMainMenu(username);
			break;

		case 6:
			system("cls");
			ExecuteMainMenuOption(Number, username);
			break;

		case 7:
			system("cls");
			ExecuteMainMenuOption(Number, username);
			break;

		case 8:
			system("cls");
			ExecuteMainMenuOption(Number, username);
			break;
		}



	}

	void ShowMainMenu(string username )
	{
		cout << "=============================================\n";
		cout << "                  Main Menu Screen\n";
		cout << "=============================================\n";
		cout << "           [1] Show Client List.\n";
		cout << "           [2] Add New Client.\n";
		cout << "           [3] Delete Client.\n";
		cout << "           [4] Update Client Info.\n";
		cout << "           [5] Find Client.\n";
		cout << "           [6] Transactions.\n";
		cout << "           [7] Manage Users.\n";
		cout << "           [8] Logout.\n";
		cout << "=============================================\n";

		int ChoiseNumber = ReadNumberPositive("Choose what do you Wand to do? [1 to 8]? ");

		PerformMainMenuOption(ChoiseNumber , username);

	}

	bool CheckValidUserName(const vector<sLogin>& vLogin, string username, string password)
	{
		for (const sLogin& L : vLogin)
		{
			if (L.UserName == MyFunctionsLib::Trim(username) && L.PassWord == MyFunctionsLib::Trim(password))
			{
				return true;
			}
		}



		return false;
	}

	void Login()
	{
		bool Result = false;

		vector<sLogin> vLogin = LoadLoginDataFromFile(FileName2);
		ShowLoginScreen();

		do {

			string username = ReadString("Enter UserName: ");
			string password = ReadString("Enter PassWord: ");


			

			if (CheckValidUserName( vLogin, username, password))
			{
				 
				Result = true;
			}
			else
			{
				system("cls");
				ShowLoginScreen();
				cout << "Invalid UserName/PassWord!\n";
			}
		} while (Result == false);



	}


}