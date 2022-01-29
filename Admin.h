// Admin  Related all the functions and attributes are mentioned here.


#include <iostream>
#include<iomanip>
using namespace std;

//Main Menu List
int MainMenu()
{
	int nChoice1;
	cout << right << setw(81) << setfill(' ') << "WELCOME TO HOSPITAL MANAGEMENT SYSTEM " << endl;
	cout << endl << endl;
	cout << right << setw(85) << setfill(' ') << "------------------------------------------------" << endl;
	cout << right << setw(63) << setfill(' ') << "1. Admin" << endl;
	cout << right << setw(65) << setfill(' ') << "2. Patient" << endl;
	cout << right << setw(64) << setfill(' ') << "3. Doctor" << endl;
	cout << right << setw(71) << setfill(' ') << "4. Receptionlist" << endl;
	cout << right << setw(62) << setfill(' ') << "5. Exit" << endl;
	cout << right << setw(85) << setfill(' ') << "------------------------------------------------" << endl << endl;
	cout << "Enter your choice:" << endl << endl;
	cin >> nChoice1;
	return nChoice1;
}







//Admin Main Menu list 
int AdminMenu()
{
	int nChoice;
	system("cls");
	cout << right << setw(87) << setfill(' ') << "WELCOME TO HOSPITAL MANAGEMENT SYSTEM ADMIN PORTAL " << endl;
	cout << endl << endl;
	cout << right << setw(84) << setfill(' ') << "------------------------------------------------" << endl;
	cout << right << setw(63) << setfill(' ') << "1. Doctor " << endl;
	cout << right << setw(63) << setfill(' ') << "2. Patient" << endl;
	cout << right << setw(62) << setfill(' ') << "3. Logout" << endl;
	cout << right << setw(84) << setfill(' ') << "------------------------------------------------" << endl << endl;
	cout << "Enter your choice:" << endl << endl;
	cin >> nChoice;
	return nChoice;
}

//Enum 
enum DoctorOperations
{
	Add_Doctor=1 , View_Doctor, Search_Doctor,Edit_Doctor,GoBack
};

enum PatientOperations
{
	Add_Patient = 1, View_Patient, Search_Patient, Edit_Patient, PatientOperationsGoBack
};
