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

namespace MyFunctionsLib
{
	struct stEmployee {
		string FirstName;
		string LastName;
		int Salary = 0;
	};

	void ReadNumber(vector <stEmployee>& vNumber)
	{
		stEmployee Employee;

		char ReadMore = 'Y';
		do
		{
			cout << "Please Enter Fist Name Employee = ";
			cin >> Employee.FirstName;
			cout << endl;
			cout << "Please Enter Last Name Employee = ";
			cin >> Employee.LastName;
			cout << endl;
			cout << "Please Enter Salary Employee = ";
			cin >> Employee.Salary;
			vNumber.push_back(Employee);

			cout << endl;
			cout << "Do you want more Employee? Y/N? ";
			cin >> ReadMore;
		} while (ReadMore == 'y' || ReadMore == 'Y');

	}

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
		getline(cin >> ws, Name); // ws : ???? ??? leading whitespace ?? ??? input stream? ????? ??? \n ??????? ??? ReadPositiveNumber.

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

	void PrintVector(vector <stEmployee>& vNumber)
	{
		stEmployee Employee;
		for (stEmployee& Employee : vNumber)
		{
			cout << endl;
			cout << "First Name = " << Employee.FirstName << endl;
			cout << "Last Name = " << Employee.LastName << endl;
			cout << "Salary = " << Employee.Salary << endl;
			cout << endl << endl;
		}
	}

	void PointerWithArray()
	{
		int arr[4] = { 1,2,3,4 };
		int* ptr;
		ptr = arr;

		for (int i = 0; i < 4; i++)
		{
			cout << ptr + i << endl;
		}

		cout << endl << endl;

		for (int i = 0; i < 4; i++)
		{
			cout << *(ptr + i) << endl;
		}
	}

	void PointerWithStruct()
	{
		stEmployee Employee, * ptr;

		Employee.FirstName = "Sadeq";
		Employee.LastName = "Othman";
		Employee.Salary = 2000;

		cout << "First Name : " << Employee.FirstName << endl;
		cout << "Last Name : " << Employee.LastName << endl;
		cout << "Salary : " << Employee.Salary << endl;

		cout << endl << endl;

		ptr = &Employee;

		cout << "First Name : " << ptr->FirstName << endl;
		cout << "Last Name : " << ptr->LastName << endl;
		cout << "Salary : " << ptr->Salary << endl;
	}

	void PointerwithVoid()
	{
		void* ptr;

		int a = 10;
		float b = 11.2;

		ptr = &a;

		cout << ptr << endl;
		cout << *(static_cast<int*>(ptr)) << endl;


		cout << endl << endl;

		ptr = &b;
		cout << ptr << endl;
		cout << *(static_cast<float*>(ptr)) << endl;

		//    ??? ???? ???? ?????? ???? ??? ?? ???? ???? ???? ?? ???? ???? ?????? ?????? ?? ???? ????
	}

	void PointerMemoryMangment()
	{
		int* Xptr;
		float* Yptr;

		Xptr = new int;
		Yptr = new float;

		*Xptr = 45;
		*Yptr = 58.35f;

		cout << *Xptr << endl;
		cout << *Yptr << endl;


		delete Xptr;
		delete Yptr;

		//??? ??? ???? ?????? ??? ?????? ?? ???? ?? ?? ???? ???? ???????? ?????? ????? ?? ???????? ??? ????? ????? ???????? ??? ???? ?? ??? ???? ??? ???? ?? ?????? ???? ??? ???? ????? ???????
	}

	void PointerDynamicArrays()
	{
		float* ptr;

		int Number;
		cout << "Please Enter Mark Numbers : ";
		cin >> Number;


		ptr = new float[Number];

		for (int i = 0; i < Number; i++)
		{
			cout << "Student" << i + 1 << " : ";
			cin >> *(ptr + i);
		}

		cout << endl << endl;

		cout << "Print Mark :" << endl;

		for (int i = 0; i < Number; i++)
		{
			cout << "Student" << i + 1 << " : " << *(ptr + i) << endl;
		}

		delete[] ptr;
	}

	void VectorEccesElement()
	{
		vector <int> Number = { 1,2,3,4,5 };

		cout << "Element at Index 0 :" << Number.at(0) << endl;
		cout << "Element at Index 2 :" << Number.at(2) << endl;
		cout << "Element at Index 4 :" << Number.at(4) << endl;

		cout << endl << endl;

		cout << "Element at Index 0 :" << Number[0] << endl;
		cout << "Element at Index 2 :" << Number[2] << endl;
		cout << "Element at Index 4 :" << Number[4] << endl;

		cout << endl << endl;
	}

	void PrintVectorIterator()
	{
		vector <int> Number = { 1,2,3,4,5 };

		vector <int> ::iterator iter;// ???? ???? ??? ??? ??????? 

		for (iter = Number.begin(); iter != Number.end(); iter++)
		{
			cout << *iter << "  ";
		}

	}

	void TryAndCatch()
	{
		vector<int> Number = { 1,2,3,4,5 };

		try
		{
			cout << Number.at(15);
		}
		catch (...)
		{
			cout << "out of bound\n";
		}

		//	?????? ????? ?????? ??????? ????? ???????? ???? ?????????? ?? ??? ????? ?????? ????
	}

	void CCTYPEFunction()
	{
		char x;
		char w;
		x = toupper('a');
		w = tolower('A');
		cout << "converting a to A: " << x << endl;
		cout << "converting A to a: " << w << endl;
		// Digits (A to Z)
		// returns zero if not, and non zero of yes
		cout << "isupper('A') " << isupper('A') << endl;
		// lower case (a to z)
		// returns zero if not, and non zero of yes
		cout << "islower('A') " << islower('A') << endl;
		// Digits (0 to 9)
		// returns zero if not, and non zero of yes
		cout << "isdigit('A') " << isdigit('A') << endl;
		// punctuation characters are !"#$%&'()*+,-./:;<=>?@[\]^_`{|}~
		// returns zero if not, and non zero of yes
		cout << "ispunct('A') " << ispunct('A') << endl;
	}

	void WriteModeFile()
	{
		fstream MyFile;

		MyFile.open("MyFile.txt", ios::out);// write mode

		if (MyFile.is_open())
		{
			MyFile << "Hi, this is the first line\n";
			MyFile << "Sadeq\n";
			MyFile << "Hi, this is the third line\n";

			MyFile.close();

			//	??????? ??? ?? ?? ???? ???????? ???? ???? ???? ???? ???? 
		}
	}

	void AppendModeFile()
	{
		fstream MyFile;
		MyFile.open("MyFile.txt", ios::out | ios::app);


		if (MyFile.is_open())
		{
			MyFile << "I Love Programming" << endl;
			MyFile << "I Love Mama" << endl;
			MyFile.close();
		}
	}

	void PrintFileContenet(string FileName)
	{
		fstream MyFile;
		MyFile.open("MyFile.txt", ios::in);


		if (MyFile.is_open())
		{
			string line;

			while (getline(MyFile, line))
			{
				cout << line << endl;
			}

			MyFile.close();
		}

	}

	void LoadDataFromFileToVector(string FileName, vector <string>& vFile)
	{
		fstream MyFile;
		MyFile.open("MyFile.txt", ios::in);


		if (MyFile.is_open())
		{
			string line;

			while (getline(MyFile, line))
			{
				vFile.push_back(line);
			}

			MyFile.close();
		}

	}

	int ReadValidationNumberOnly()
	{
		int Number;

		cout << "Please Enter Your Number\n";

		cin >> Number;

		while (cin.fail())
		{
			cin.clear();
			cin.ignore(std::numeric_limits < std::streamsize > ::max(), '\n');
			cout << "Inalid Number, Enter a Valid one" << endl;

			cin >> Number;
		}
		return Number;
	}

	int BitWiseAndOperator(int Num1, int Num2)
	{
		int Result = 0;

		Result = (Num1 & Num2);

		return Result;
	}

	int BitWiseOrOperator(int Num1, int Num2)
	{
		int Result = 0;

		Result = (Num1 | Num2);

		return Result;
	}

	int DefultParameter(int a, int b, int c = 0, int d = 0)
	{
		// c And d , Defult Parameter

		return (a + b + c + d);
	}

	int RecursionPrintNumber(int Base, int Power)
	{
		if (Power == 0)
		{
			return 1;
		}
		else
		{
			return  (Base * RecursionPrintNumber(Base, Power - 1));
		}





		/*MyPower(2, 4)
			= 2 * MyPower(2, 3)
			= 2 * 2 * MyPower(2, 2)
			= 2 * 2 * 2 * MyPower(2, 1)
			= 2 * 2 * 2 * 2 * MyPower(2, 0)*/
	}

	void IntegerFormatPrintf()
	{
		int Page = 1, TotalPages = 10;

		// print string and int variable
		printf("The page number = %d \n", Page);
		printf("You are in Page %d of %d \n", Page, TotalPages);
		//Width specification
		printf("The page number = %0*d \n", 2, Page);
		printf("The page number = %0*d \n", 3, Page);
		printf("The page number = %0*d \n", 4, Page);
		printf("The page number = %0*d \n", 5, Page);
		int Number1 = 20, Number2 = 30;
		printf("The Result of %d + %d = %d \n", Number1, Number2,
			Number1 + Number2);
	}

	void FloatFormatPrintf()
	{
		float PI = 3.14159265;

		//Precision specification
		printf("Precision specification of %.*f\n", 1, PI);
		printf("Precision specification of %.*f\n", 2, PI);
		printf("Precision specification of %.*f\n", 3, PI);
		printf("Precision specification of %.*f\n", 4, PI);

		float x = 7.0, y = 9.0;

		printf("\nThe float division is : %.3f / %.3f = %.3f \n\n", x,
			y, x / y);

		double d = 12.45;
		printf("The double value is : %.3f \n", d);
		printf("The double value is : %.4f \n", d);
	}

	void StringFormatPrintf()
	{
		char Name[] = "Mohammed Abu-Hadhoud";
		char SchoolName[] = "Programming Advices";

		// print string and String
		printf("Dear %s, How are you?\n\n", Name);
		printf("Welcome to %s School!\n\n", SchoolName);
		char c = 'S';
		printf("Setting the width of c :%*c \n", 1, c);
		printf("Setting the width of c :%*c \n", 2, c);
		printf("Setting the width of c :%*c \n", 3, c);
		printf("Setting the width of c :%*c \n", 4, c);
		printf("Setting the width of c :%*c \n", 5, c);
	}

	void StringObject()
	{
		string S1 = "My Name is Mohammed Abu-Hadhoud, I LoveProgramming.";
		//Prints the length of the string
		cout << S1.length() << endl;

		//Returns the letter at position 3
		cout << S1.at(3) << endl;

		//Adds @ProgrammingAdvices to the end of string
		S1.append(" @ProgrammingAdvices");
		cout << S1 << endl;

		//inserts Ali at position 7
		S1.insert(7, " Ali ");
		cout << S1 << endl;

		//Prints all the next 8 letters from position 16.
		cout << S1.substr(16, 8) << endl;

		//Adds one character to the end of the string
		S1.push_back('X');
		cout << S1 << endl;

		//Removes one character from the end of the string
		S1.pop_back();
		cout << S1 << endl;

		//Finds Ali in the string
		cout << S1.find("Ali") << endl;

		//Finds ali in the string
		cout << S1.find("ali") << endl;
		if (S1.find("ali") == S1.npos)
		{
			cout << "ali is not found";
		}

		//clears all string letters.
		S1.clear();
		cout << S1 << endl;
	}

	char InvertLetterCase(char ch)
	{
		return islower(ch) ? toupper(ch) : tolower(ch);
	}

	string InvertAllStringLettersCase(string word)
	{

		for (int i = 0; i < word.length(); i++)
		{
			word[i] = InvertLetterCase(word[i]);
		}

		return word;
	}

	string UpperFirstLetterOfEachWord(string Name)
	{

		for (int i = 0; i < Name.length(); i++)
		{
			if (Name[i] != ' ')
			{
				Name[i] = toupper(Name[i]);
			}
		}
		return Name;

	}

	string LowerFirstLetterOfEachWord(string Name)
	{

		for (int i = 0; i < Name.length(); i++)
		{
			if (Name[i] != ' ')
			{
				Name[i] = tolower(Name[i]);
			}
		}
		return Name;

	}

	int CountCapitalLettersInString(string word)
	{
		int Count = 0;

		for (int i = 0; i < word.length(); i++)
		{
			if (isupper(word[i]))
			{
				Count++;
			}
		}
		return Count;
	}

	int CountSmallLettersInString(string word)
	{
		int Count = 0;

		for (int i = 0; i < word.length(); i++)
		{
			if (islower(word[i]))
			{
				Count++;
			}
		}
		return Count;
	}

	int IsLetterCount(string word, char Letter)
	{
		int Counter = 0;

		for (int i = 0; i < word.length(); i++)
		{
			if (word[i] == Letter)
			{
				Counter++;
			}
		}
		return Counter++;
	}

	int IsLetterCountMatchOrNotCase(string word, char Letter, bool MatchCase = true)
	{
		int Counter = 0;

		for (int i = 0; i < word.length(); i++)
		{
			if (MatchCase)
			{
				if (word[i] == Letter)
				{
					Counter++;
				}

			}

			else
			{
				if (toupper(word[i]) == toupper(Letter))
				{
					Counter++;
				}
			}
		}
		return Counter++;
	}

	bool IsVowel(char Letter)
	{
		Letter = tolower(Letter);

		return ((Letter == 'a') || (Letter == 'e') || (Letter == 'i') || (Letter == 'o') || (Letter == 'u'));
	}

	int CountVowelInString(string word)
	{
		int Counter = 0;

		for (int i = 0; i < word.length(); i++)
		{
			if (IsVowel(word[i]))
			{
				Counter++;
			}
		}

		return Counter;
	}

	void PrintVowelInString(string word)
	{

		for (int i = 0; i < word.length(); i++)
		{
			if (IsVowel(word[i]))
			{
				cout << word[i] << "  ";
			}
		}


	}

	void PrintWordsInString(string S1) // Sadeq Khater Gamil 
	{
		string delim = " ";

		cout << "Your string wrords are: \n";

		int pos = 0;
		string sWord;

		while ((pos = S1.find(delim)) != std::string::npos)
		{
			sWord = S1.substr(0, pos);

			if (sWord != "")
			{
				cout << sWord << endl;
			}

			S1.erase(0, pos + delim.length());
		}

		if (S1 != "")
		{
			cout << S1 << endl;
		}


	}

	int CountWords(string S1) // Sadeq Khater Gamil 
	{
		int Count = 0;

		string delim = " ";

		cout << "\nThe Number of words int Your string is: ";

		int pos = 0;
		string sWord;

		while ((pos = S1.find(delim)) != std::string::npos)
		{
			sWord = S1.substr(0, pos);

			if (sWord != "")
			{
				Count++;
			}

			S1.erase(0, pos + delim.length());
		}

		if (S1 != "")
		{
			Count++;
		}

		return Count;

	}

	vector <string> SplitString(string S1, string Delim)
	{
		vector <string> Tokens;

		int pos = 0;
		string sWord;

		while ((pos = S1.find(Delim)) != std::string::npos)
		{
			sWord = S1.substr(0, pos);

			if (sWord != "")
			{
				Tokens.push_back(sWord);
			}

			S1.erase(0, pos + Delim.length());
		}

		if (S1 != "")
		{
			Tokens.push_back(S1);
		}

		return Tokens;
	}

	string ReveseWord(string S1)
	{
		vector <string> Tokens = SplitString(S1, " ");

		string S2 = "";

		vector<string>::iterator iter = Tokens.end();

		while (iter != Tokens.begin())
		{
			--iter;
			S2 += *iter + " ";
		}
		S1 = S2.substr(0, S2.length() - 1);

		return S1;

	}

	string TrimLeft(string S1)
	{
		for (int i = 0; i < S1.length(); i++)
		{
			if (S1[i] != ' ')
			{
				return S1.substr(i, S1.length() - i);
			}
		}

		return "";
	}

	string TrimRight(string S1)
	{
		for (int i = (int)S1.length() - 1; i >= 0; i--)
		{
			if (S1[i] != ' ')
			{
				return S1.substr(0, i + 1);
			}
		}

		return "";
	}

	string Trim(string S1)
	{
		return TrimLeft(TrimRight(S1));
	}
	string JoinString(vector<string> Vjoin, string Delim)
	{
		string S1 = "";

		for (string& s : Vjoin)
		{
			S1 = S1 + s + Delim;
		}

		return S1.substr(0, S1.length() - Delim.length());
	}

	string ReplaceWordInStringUsingBuiltInFunction(string S1, string StringToReplace, string ReplaceTo)
	{
		int pos = S1.find(StringToReplace);

		while (pos != std::string::npos)
		{
			S1 = S1.replace(pos, StringToReplace.length(), ReplaceTo);
			pos = S1.find(StringToReplace);
		}

		return S1;
	}

	string ReplaceWordInStringUsingSplit(string S1, string StringToReplace, string ReplaceTo, bool Matches = true)
	{
		vector <string> Tokens = SplitString(S1, " ");

		for (string& s : Tokens)
		{
			if (Matches)
			{
				if (s == StringToReplace)
				{
					s = ReplaceTo;
				}

			}
			else
			{
				if (LowerFirstLetterOfEachWord(s) == LowerFirstLetterOfEachWord(StringToReplace))
				{
					s = ReplaceTo;
				}
			}
		}
		return JoinString(Tokens, " ");

	}

	string RemovePunctuationsFromString(string S1)
	{

		string S2 = "";
		for (int i = 0; i < S1.length(); i++)
		{
			if (!ispunct(S1[i]))
			{
				S2 += S1[i];
			}

		}

		return S2;

	}







	bool ISLeapYear(int Year)
	{
		return (Year % 400 == 0) || (Year % 4 == 0 && Year % 100 != 0);
	}

	int NumberOfDayInYear(int Year)
	{
		return ISLeapYear(Year) ? 366 : 365;
	}

	int NumberOfHourInYear(int Year)
	{
		return NumberOfDayInYear(Year) * 24;
	}

	int NumberOfMinutesInYear(int Year)
	{
		return NumberOfHourInYear(Year) * 60;
	}

	int NumberOfSecondsInYear(int Year)
	{
		return NumberOfMinutesInYear(Year) * 60;
	}


	int GetDaysInMonth(int Month, int Year)
	{
		int DaysInMonth[] = { 31, ISLeapYear(Year) ? 29 : 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };

		return DaysInMonth[Month - 1];
	}

	int NumberOfHourInMonth(int Month, int Year)
	{
		return GetDaysInMonth(Month, Year) * 24;
	}

	int NumberOfMinutesInMonth(int Month, int Year)
	{
		return NumberOfHourInMonth(Month, Year) * 60;
	}

	int NumberOfSecondsInMonth(int Month, int Year)
	{
		return NumberOfMinutesInMonth(Month, Year) * 60;
	}



	int DayOfWeekOrder(int Year, int Month, int Day)
	{
		int  a = (14 - Month) / 12;
		int  y = Year - a;
		int  m = Month + (12 * a) - 2;

		int d = (Day + y + (y / 4) - (y / 100) + (y / 400) + ((31 * m) / 12)) % 7;

		return d;
	}

	void PrintDate(short Year, short Month, short Day)
	{
		cout << "\n\nDate           :" << Day << "/" << Month << "/" << Year << endl;
	}


	// 8

	string GetMonthName(int Month)
	{
		string MonthsNames[] =
		{
			"Jan",
			"Feb",
			"Mar",
			"Apr",
			"May",
			"Jun",
			"Jul",
			"Aug",
			"Sep",
			"Oct",
			"Nov",
			"Dec"
		};

		return MonthsNames[Month - 1];
	}

	void PrintMonthCalendar(int Month, int Year)
	{
		int NumberOfDays;

		int Current = DayOfWeekOrder(Year, Month, 1);

		NumberOfDays = GetDaysInMonth(Month, Year);

		cout << "\n  _______________" << GetMonthName(Month) << "_______________\n\n";

		printf("  Sun  Mon  Tue  Wed  Thu  Fri  Sat\n");

		int i;

		for (i = 0; i < Current; i++)
		{
			printf("     ");
		}

		for (int j = 1; j <= NumberOfDays; j++)
		{
			printf("%5d", j);

			if (++i == 7)
			{
				i = 0;
				printf("\n");
			}
		}

		cout << "\n  _________________________________\n\n";

	}


	//9

	void PrintYearCalendar(int Year)
	{
		cout << "\n\n  ---------------------------------\n\n";
		cout << "           Calendar - " << Year << endl;
		cout << "\n  ---------------------------------\n";

		for (int i = 1; i <= 12; i++)
		{
			PrintMonthCalendar(i, Year);
		}
	}

	//10

	int NumberOfDaysFromTheBeginingOfTheYear(int Year, int Month, int Day)
	{
		int TotalDays = 0;

		for (int i = 1; i <= Month - 1; i++)
		{
			TotalDays += GetDaysInMonth(i, Year);
		}

		TotalDays += Day;

		return TotalDays;

	}


	// 11

	struct sDate
	{
		int Year;
		int Month;
		int Day;
	};

	sDate GetDateFromDayOrderInYear(int TotalDays, int Year)
	{
		sDate Date;

		int RemainingDays = TotalDays;
		Date.Year = Year;
		Date.Month = 1;

		int MonthDays = 0;


		while (true)
		{

			MonthDays = GetDaysInMonth(Date.Month, Year);

			if (RemainingDays > MonthDays)
			{
				RemainingDays -= MonthDays;
				Date.Month++;
			}
			else
			{
				Date.Day = RemainingDays;
				break;
			}
		}

		return Date;
	}


	// 12

	sDate DateAddDays(int Days, sDate Date)
	{
		short RemainingDays = Days +
			NumberOfDaysFromTheBeginingOfTheYear(Date.Year, Date.Month,
				Date.Day);
		short MonthDays = 0;
		Date.Month = 1;
		while (true)
		{
			MonthDays = GetDaysInMonth(Date.Month, Date.Year);
			if (RemainingDays > MonthDays)
			{
				RemainingDays -= MonthDays;
				Date.Month++;
				if (Date.Month > 12)
				{
					Date.Month = 1;
					Date.Year++;
				}
			}
			else
			{
				Date.Day = RemainingDays;
				break;
			}
		}
		return Date;
	}


	// 13

	bool IsDate1BeforeDate2(sDate Date1, sDate Date2)
	{
		return (Date1.Year < Date2.Year) ? true : ((Date1.Year ==
			Date2.Year) ? (Date1.Month < Date2.Month ? true : (Date1.Month ==
				Date2.Month ? Date1.Day < Date2.Day : false)) : false);
	}

	// 14

	bool IsDate1EqualDate2(sDate Date1, sDate Date2)
	{
		return ((Date1.Year == Date2.Year ? (Date1.Month == Date2.Month ? (Date1.Day == Date2.Day ? true : false) : false) : false));
	}

	// 15

	bool IsLastDayInMonth(sDate Date)
	{
		return GetDaysInMonth(Date.Month, Date.Year) == Date.Day ? true : false;
	}

	bool IsLastMonthInYear(sDate Date)
	{
		return Date.Month == 12;
	}


	//16

	sDate IncreaseDateByOneDay(sDate Date)
	{

		if (IsLastDayInMonth(Date))
		{
			if (IsLastMonthInYear(Date))
			{
				Date.Day = 1;
				Date.Month = 1;
				Date.Year++;
			}
			else
			{
				Date.Day = 1;
				Date.Month++;
			}
		}
		else
		{
			Date.Day++;
		}

		return Date;
	}


	//17 && 19

	void SwapDates(sDate& Date1, sDate& Date2)
	{
		sDate SwapDate;

		SwapDate.Day = Date1.Day;
		SwapDate.Month = Date1.Month;
		SwapDate.Year = Date1.Year;

		Date1.Day = Date2.Day;
		Date1.Month = Date2.Month;
		Date1.Year = Date2.Year;

		Date2.Day = SwapDate.Day;
		Date2.Month = SwapDate.Month;
		Date2.Year = SwapDate.Year;

	}

	int GetDifferenceInDays(sDate Date1, sDate Date2, bool	IncludeEndDay = false)
	{
		int Days = 0;

		int SwapFlagValue = 1;

		if (!IsDate1BeforeDate2(Date1, Date2))
		{
			SwapDates(Date1, Date2);
			SwapFlagValue = -1;
		}

		while (IsDate1BeforeDate2(Date1, Date2))
		{
			Days++;
			Date1 = IncreaseDateByOneDay(Date1);
		}
		return IncludeEndDay ? ++Days * SwapFlagValue : Days * SwapFlagValue;
	}


	// 18

	sDate GetSystemDate()
	{
		sDate Date;

		time_t t = time(0);

		tm now;
#ifdef _WIN32
		localtime_s(&now, &t);
#else
		localtime_r(&t, &now);
#endif

		Date.Year = now.tm_year + 1900;
		Date.Month = now.tm_mon + 1;
		Date.Day = now.tm_mday;

		return Date;
	}

	// 20

	sDate IncreaseDateByOneWeek(sDate Date)
	{
		int Count = 0;

		while (Count != 7)
		{
			Date = IncreaseDateByOneDay(Date);
			Count++;
		}
		return Date;
	}

	sDate IncreaseDateByXDays(int Days, sDate Date)
	{
		for (int i = 0; i < Days; i++)
		{
			Date = IncreaseDateByOneDay(Date);
		}
		return Date;
	}

	sDate IncreaseDateByXWeek(int Weeks, sDate Date)
	{

		for (int i = 0; i < Weeks; i++)
		{
			Date = IncreaseDateByOneWeek(Date);
		}

		return Date;
	}

	sDate IncreaseDateByOneMonth(sDate Date)
	{
		if (Date.Month != 12)
		{
			Date.Month++;
		}
		else
		{
			Date.Month = 1;
			Date.Year++;
		}

		int Number = GetDaysInMonth(Date.Month, Date.Year);

		if (Date.Day > Number)
		{
			Date.Day = Number;
		}

		return Date;
	}

	sDate IncreaseDateByXMonth(int NumberTheMonths, sDate Date)
	{
		int Count = 0;

		while (Count != NumberTheMonths)
		{
			Date = IncreaseDateByOneMonth(Date);

			Count++;
		}

		return Date;
	}

	sDate IncreaseDateByOneYear(sDate Date)
	{

		Date.Year++;

		if (!ISLeapYear(Date.Year) && Date.Month == 2 && Date.Day == 29)
		{
			Date.Day = 28;
		}

		return Date;
	}

	sDate IncreaseDateByXYear(int NumberTheYear, sDate Date)
	{
		int Count = 0;

		while (Count != NumberTheYear)
		{
			Date = IncreaseDateByOneYear(Date);
			Count++;
		}

		return Date;
	}

	sDate IncreaseDateByXYearFaster(int NumberTheYear, sDate Date)
	{
		Date.Year += NumberTheYear;

		return Date;
	}

	sDate IncreaseDateByOneDecade(sDate Date)
	{

		int Count = 0;

		while (Count != 10)
		{
			Date = IncreaseDateByOneYear(Date);
			Count++;
		}

		return Date;

	}

	sDate IncreaseDateByXDecade(int NumberTheDecade, sDate Date)
	{
		int Count = 0;

		while (Count != NumberTheDecade)
		{
			Date = IncreaseDateByOneDecade(Date);
			Count++;
		}

		return Date;
	}

	sDate IncreaseDateByXDecadeFaster(int NumberTheDecade, sDate Date)
	{
		Date.Year += (10 * NumberTheDecade);

		return Date;

	}

	sDate IncreaseDateByOneCentury(sDate Date)
	{
		Date = IncreaseDateByXDecade(10, Date);

		return Date;
	}

	sDate IncreaseDateByOneMillennium(sDate Date)
	{
		Date.Year += 1000;
		return Date;
	}



	sDate DecreaseDateByOneDay(sDate Date)
	{
		if (Date.Day == 1)
		{
			if (Date.Month == 1)
			{
				Date.Month = 12;
				Date.Day = 31;
				Date.Year--;
			}
			else
			{
				Date.Month--;
				Date.Day = GetDaysInMonth(Date.Month, Date.Year);
			}
		}
		else
		{
			Date.Day--;
		}

		return Date;
	}

	sDate DecreaseDateByXDays(short Days, sDate Date)
	{
		for (short i = 1; i <= Days; i++)
			Date = DecreaseDateByOneDay(Date);

		return Date;
	}

	sDate DecreaseDateByOneWeek(sDate Date)
	{
		for (short i = 1; i <= 7; i++)
			Date = DecreaseDateByOneDay(Date);

		return Date;
	}

	sDate DecreaseDateByXWeeks(short Weeks, sDate Date)
	{
		for (short i = 1; i <= Weeks; i++)
			Date = DecreaseDateByOneWeek(Date);

		return Date;
	}

	sDate DecreaseDateByOneMonth(sDate Date)
	{
		if (Date.Month == 1)
		{
			Date.Month = 12;
			Date.Year--;
		}
		else
		{
			Date.Month--;
		}

		int DaysInCurrentMonth =
			GetDaysInMonth(Date.Month, Date.Year);

		if (Date.Day > DaysInCurrentMonth)
			Date.Day = DaysInCurrentMonth;

		return Date;
	}

	sDate DecreaseDateByXMonths(short Months, sDate Date)
	{
		for (short i = 1; i <= Months; i++)
			Date = DecreaseDateByOneMonth(Date);

		return Date;
	}

	sDate DecreaseDateByOneYear(sDate Date)
	{
		Date.Year--;
		return Date;
	}

	sDate DecreaseDateByXYears(short Years, sDate Date)
	{
		for (short i = 1; i <= Years; i++)
			Date = DecreaseDateByOneYear(Date);

		return Date;
	}

	sDate DecreaseDateByXYearsFaster(short Years, sDate Date)
	{
		Date.Year -= Years;
		return Date;
	}

	sDate DecreaseDateByOneDecade(sDate Date)
	{
		Date.Year -= 10;
		return Date;
	}

	sDate DecreaseDateByXDecades(short Decades, sDate Date)
	{
		for (short i = 1; i <= Decades * 10; i++)
			Date = DecreaseDateByOneYear(Date);

		return Date;
	}

	sDate DecreaseDateByXDecadesFaster(short Decades, sDate Date)
	{
		Date.Year -= Decades * 10;
		return Date;
	}

	sDate DecreaseDateByOneCentury(sDate Date)
	{
		Date.Year -= 100;
		return Date;
	}

	sDate DecreaseDateByOneMillennium(sDate Date)
	{
		Date.Year -= 1000;
		return Date;
	}


	// 47 - 53

	string GetDayName(int Day)
	{
		string MonthsNames[] =
		{
		  "Sun", "Mon", "Tue", "Wed", "Thu", "Fri", "Sat"
		};

		return MonthsNames[Day];
	}


	//Overloading
	int DayOfWeekOrder(sDate Date)
	{
		return DayOfWeekOrder(Date.Year, Date.Month, Date.Day);
	}


	short IsEndOfWeek(sDate Date)
	{
		return DayOfWeekOrder(Date) == 6;
	}

	bool IsWeekEnd(sDate Date)
	{
		//Weekends are Fri and Sat
		short DayIndex = DayOfWeekOrder(Date);
		return (DayIndex == 5 || DayIndex == 6);
	}

	bool IsBusinessDay(sDate Date)
	{

		return !IsWeekEnd(Date);
	}

	int DaysUntilTheEndOfWeek(sDate Date)
	{
		return 6 - DayOfWeekOrder(Date);
	}

	int DaysUntilTheEndOfMonth(sDate Date)
	{
		return GetDaysInMonth(Date.Month, Date.Year) - Date.Day + 1;
	}

	int DaysUntilTheEndOfYear(sDate Date)
	{
		sDate EndOfYearDate;

		EndOfYearDate.Day = 31;
		EndOfYearDate.Month = 12;
		EndOfYearDate.Year = Date.Year;

		return GetDifferenceInDays(Date, EndOfYearDate, true);

	}


	// 54

	int CalculateVacationDays(sDate Date1, sDate Date2)
	{
		int DaysCount = 0;

		while (IsDate1BeforeDate2(Date1, Date2))
		{
			if (IsBusinessDay(Date1))
			{
				DaysCount++;
			}
			Date1 = IncreaseDateByOneDay(Date1);

		}

		return DaysCount--;
	}


	// 55

	sDate CCalculateVacationDays(sDate Date, int Days)
	{
		while (Days > 0)
		{
			if (IsBusinessDay(Date))
			{
				Days--;
			}

			Date = IncreaseDateByOneDay(Date);
		}

		return Date;
	}


	// 56

	bool IsDate1AfterDate2(sDate Date1, sDate Date2)
	{
		return (!IsDate1BeforeDate2(Date1, Date2) && !IsDate1EqualDate2(Date1, Date2));
	}

	// 57


	enum enCompere { Befor = -1, Equale = 0, After = 1 };

	enCompere CompereDates(sDate Date1, sDate Date2)
	{
		if (IsDate1AfterDate2(Date1, Date2))
		{
			return enCompere::After;
		}
		else if (IsDate1BeforeDate2(Date1, Date2))
		{
			return enCompere::Befor;
		}
		else
		{
			return enCompere::Equale;
		}
	}


	// 58

	struct Period
	{
		sDate StartDate;
		sDate EndDate;
	};


	bool Overlap(Period period1, Period period2)
	{


		if (CompereDates(period2.EndDate, period1.StartDate) == enCompere::Befor || CompereDates(period2.StartDate, period1.EndDate) == enCompere::After)
		{
			return false;
		}

		return true;


	}


	// 60

	bool isDateInPeriod(Period period1, sDate Date)
	{
		if (IsDate1AfterDate2(Date, period1.StartDate) && IsDate1BeforeDate2(Date, period1.EndDate))
		{
			return true;
		}
		return false;
	}


	// 61

	int OverlapDays(Period period1, Period period2)
	{
		if (!Overlap(period1, period2))
		{
			return 0;
		}


		//???? ????? 
		/*sDate OverlapStart;
		sDate OverlapEnd;


		if (IsDate1AfterDate2(period1.StartDate, period2.StartDate))
		{
			OverlapStart = period1.StartDate;
		}
		else
		{
			OverlapStart = period2.StartDate;
		}


		if (IsDate1BeforeDate2(period1.EndDate, period2.EndDate))
		{
			OverlapEnd = period1.EndDate;
		}
		else
		{
			OverlapEnd = period2.EndDate;
		}

		return GetDifferenceInDays(OverlapStart, OverlapEnd);*/


		// ???? ??????


		/*int Period1Length = GetDifferenceInDays(period1.StartDate, period1.EndDate , true);
		int Period2Length = GetDifferenceInDays(period2.StartDate, period2.EndDate, true);
		int NumDay = 0;

		if (Period1Length < Period2Length)
		{
			while (IsDate1BeforeDate2(period1.StartDate, period1.EndDate))
			{
				if (isDateInPeriod(period2, period1.StartDate))
				{
					NumDay++;
				}

				period1.StartDate = IncreaseDateByOneDay(period1.StartDate);
			}
		}

		else
		{
			if (IsDate1BeforeDate2(period2.StartDate, period2.EndDate))
			{
				if (isDateInPeriod(period1, period2.StartDate))
				{
					NumDay++;
				}

				period2.StartDate = IncreaseDateByOneDay(period2.StartDate);
			}
		}

		return NumDay++;*/

	}


	//62

	bool IsValidDate(sDate Date)
	{
		if (Date.Month > 12 || Date.Month < 1)
		{
			return false;
		}

		if (Date.Day > GetDaysInMonth(Date.Month, Date.Year) || Date.Day < 1)
		{
			return false;
		}

		return true;
	}

	// 63 & 64

	sDate StringToDate(string date)
	{

		sDate Date;

		vector<string> vDate;

		vDate = SplitString(date, "/");
		Date.Day = stoi(vDate[0]);
		Date.Month = stoi(vDate[1]);
		Date.Year = stoi(vDate[2]);

		return Date;
	}

	string DateToString(sDate Date)
	{
		string S1 = "";

		S1 = S1 + to_string(Date.Day) + "/"
			+ to_string(Date.Month) + "/"
			+ to_string(Date.Year);

		return S1;
	}


	// 65

	string Formating(sDate Date, string FormatDate = "dd/mm/yyyy")

	{
		string S1 = "";

		S1 = ReplaceWordInStringUsingBuiltInFunction(FormatDate, "dd", to_string(Date.Day));
		S1 = ReplaceWordInStringUsingBuiltInFunction(S1, "mm", to_string(Date.Month));
		S1 = ReplaceWordInStringUsingBuiltInFunction(S1, "yyyy", to_string(Date.Year));

		return S1;
	}

}
