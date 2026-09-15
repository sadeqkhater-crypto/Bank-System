#pragma once


#include <iomanip>
#include <iostream>
#include <cstdio>
#include<vector>
#include<string.h>
#include<cctype>
#include<string>
#include<fstream>
#include<ctime>

using namespace std;

namespace BankingSystemLib
{
	const string FileName = "Clients.txt";

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

	void ShowMainMenu();
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
	void ShowTransactionsMenu(vector<sClient>& vClient);
	void ShowDepositScreen();
	string IsAccountNumber(vector<sClient>& vClients);
	void PerformDeposit(vector<sClient>& vClient, int Deposit, string AccounNumber, enTransactionsMenuOption TransactionsMenuOption);
	void SaveTransactionToFile(enTransactionsMenuOption TransactionsMenuOption, vector<sClient>& vClient, string AccountNumber, sClient Client);
	void ShowTotalBalance(vector<sClient>& vClients);
	void ShowWithDrowScreen();



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

	void ExecuteMainMenuOption(int ChooseNumber)
	{
		sClient Client;
		vector<sClient> vClients = LoadClientsDataFromFile(FileName);

		switch (ChooseNumber)
		{
		case 1:
		{
			ShowClientsList(vClients);
			break;
		}


		case 2:
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


		case 3:
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

		case 4:
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

		case 5:

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

		case 6:
			ShowTransactionsMenu(vClients);
			break;

		case 7:
			ShowExistScreen();
			break;
		}

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

	sClient ConvertLineToRecord(string Line)
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
				Client = ConvertLineToRecord(Line);
				vClients.push_back(Client);
			}

			MyFile.close();
		}

		return vClients;
	}

	void PrintClientsListHeader()
	{
		cout << "-----------------------------------------------------------------------------------------\n\n";
		cout << "| Account Number  | Pin Code  | Client Name                     | Phone       |Balance\n\n";
		cout << "-----------------------------------------------------------------------------------------\n\n";
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

	void PrintClientRecord(sClient Client)
	{

		cout << "| " << setw(15) << left << Client.AccountNumber
			<< " | " << setw(10) << left << Client.PinCode
			<< "| " << setw(20) << left << Client.Name
			<< "            | " << setw(11) << left << Client.Phone
			<< " | " << setw(10) << left << Client.AccountBalance << "\n";
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

	bool AskForDeleteOrUpdateConfirmation(int Number)
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
			return AskForDeleteOrUpdateConfirmation(Number);

		}
		else
		{
			cout << "\nClient with Account Number (" << AccountNumber << ") is Not Found\n\n";
			return false;
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

	void PerformTransactionsMenuOption(int Number, vector<sClient>& vClient)
	{
		switch (Number)
		{
		case 1:
			system("cls");
			ExecuteTransactionsMenuOption(Number, vClient);
			system("pause");
			system("cls");
			ShowTransactionsMenu(vClient);
			break;

		case 2:

			system("cls");
			ExecuteTransactionsMenuOption(Number, vClient);
			system("pause");
			system("cls");
			ShowTransactionsMenu(vClient);
			break;

		case 3:

			system("cls");
			ExecuteTransactionsMenuOption(Number, vClient);
			system("pause");
			system("cls");
			ShowTransactionsMenu(vClient);
			break;

		case 4:

			system("cls");
			ShowMainMenu();
			break;

		}


	}

	void ShowTransactionsMenu(vector<sClient>& vClient)
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

		PerformTransactionsMenuOption(ChoiseNumber, vClient);
	}

	void PerformMainMenuOption(int Number)
	{
		switch (Number)
		{
		case 1:

		case 2:

		case 3:

		case 4:

		case 5:
			system("cls");
			ExecuteMainMenuOption(Number);
			system("pause");
			system("cls");
			ShowMainMenu();
			break;

		case 6:
			system("cls");
			ExecuteMainMenuOption(Number);
			break;

		case 7:
			system("cls");
			ExecuteMainMenuOption(Number);
			break;
		}


	}

	void ShowMainMenu()
	{
		cout << "=============================================\n";
		cout << "                  Main Menue Screen\n";
		cout << "=============================================\n";
		cout << "           [1] Show Client List.\n";
		cout << "           [2] Add New Client.\n";
		cout << "           [3] Delete Client.\n";
		cout << "           [4] Update Client Info.\n";
		cout << "           [5] Find Client.\n";
		cout << "           [6] Transactions.\n";
		cout << "           [7] Exit.\n";
		cout << "=============================================\n";

		int ChoiseNumber = ReadNumberPositive("Choose what do you Wand to do? [1 to 7]? ");

		PerformMainMenuOption(ChoiseNumber);



	}


}