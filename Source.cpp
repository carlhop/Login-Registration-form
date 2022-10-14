#include<iostream>
#include<fstream>
#include<string.h>
using namespace std;

void login();
void registration();
void forgot();

int main()
{

	int choice;
	cout << "\t\t\t                        \n\n\n";
	cout << "\t\t\t                      Welcome to Icon World           \n\n\n";
	cout << "\t\t\t                             Menu           \n\n\n";
	cout << "\t Press 1 to Login \n\n\n";
	cout << "\t Press 2 to Register \n\n\n";
	cout << "\t Press 3 if you have forgotten your password \n\n\n";
	cout << "\t Press 4 to Exit \n\n\n";
	cin >> choice;
	cout << endl;

	switch (choice)
	{
	case 1:
		login();
		break;

	case 2:
		registration();
		break;

	case 3:
			forgot();
			break;

	case 4: 
		cout << "\t\t\t Thank You! \n\n";
		break;

	default:
		system("cls");
		cout << "\t\t\t     Please select from options above \n" <<endl;
		main();

	}
	
	
}

void login()
{
	int count;
	string userId, password, id, pass;
	system("cls");
	cout << "\t\t\t  please enter you username and password: " << endl;
	cout << "\t\t\t Username: ";
	cin >> userId;
	cout << "\t\t\t Password: ";
	cin >> password;

	ifstream input("records.txt");

	while (input>>id>> pass)
	{
		if (id==userId && pass==password)
		{
			count=1;
			system("cls");
		}
	}
	input.close();

	if (count==1)
	{
		cout << userId << "\n Your login is successful.";
		main();
	}
	else {
		cout << "\n Login Error";
		main();
	}
}
void registration()
{
	string ruserId, rpassword, rid, rpass;
	system("cls");
	cout << "\t\t\t Enter Username: ";
	cin >> ruserId;
	cout << "\t\t\t Enter password: ";
	cin >> rpassword;

	ofstream f1("records.txt,", ios::app);
	f1 << ruserId << ' ' << rpassword << endl;
	system("cls");
	cout << "\n\t\t\t Registration is successful \n"; \
		main();

}

void forgot()
{
	int option;
	system("cls");
	cout << "\t\t\t It seems you have forgotten your password \n ";
	cout << "Press 1 to search your username" << endl;;
	cout << "Pres 2 to go back to main menu"<<endl;
	cout << "\t\t\t Enter your choice: ";
	cin >> option;
	switch (option)
	{

	case 1:
		{
		int count = 0;
				string suserId, sId, spass;
			cout << "\n\t\t Enter the username which you remembered:";
			cin >> suserId;

			ifstream f2("records.txt");
			while (f2 >> sId >> spass)
			{
				if (sId == suserId)
				{
					count = 1;
				}
			}

			f2.close();
			if (count == 1)
			{
				cout << "\n\n Your account is found \n";
				cout << "\n\n Your password is: " << spass;
				main();

			}
			else {
				cout << "\n\t Your account was not found.";
				main();

			}
			break;


		}

	case 2:
	{
		main();
	}

	default:
		cout << "\t\t\t Wrong choice please try again." << endl;
		forgot();
	}
}
