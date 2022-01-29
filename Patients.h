// Patient Related all the functions and attributes are mentioned here.
#include <iostream>
#include<iomanip>
using namespace std;

int  nPatient_id=0;

//Patient Menu list 
int PatientMenu()
{
	int nChoice;
	system("cls");
	cout << right << setw(80) << setfill(' ') << "WELCOME TO HOSPITAL MANAGEMENT SYSTEM  " << endl;
	cout << right << setw(70) << setfill(' ') << "PATIENT PORTAL " << endl;
	cout << endl << endl;
	cout << right << setw(85) << setfill(' ') << "------------------------------------------------" << endl;
	cout << right << setw(72) << setfill(' ') << "1. View your Details" << endl;
	cout << right << setw(73) << setfill(' ') << "2. Appointment Booking" << endl;
	cout << right << setw(66) << setfill(' ') << "3. Logout" << endl;
	cout << right << setw(85) << setfill(' ') << "------------------------------------------------" << endl << endl;
	cout << "Enter your choice:" << endl << endl;
	cin >> nChoice;
	return nChoice;
}

//struct  of Patient
struct stPatient {
	char szPatientName[50];
	char szPatientAge[20];
	char szPatientBlood[30];
	long long int llnPatientMobile;
	char szPatientGender[10];
	char szPatientEmail[20];
	char szPAddressLine[30];
	int  nPatientPincode;

}Patient_t[50];

//Function for Adding Patient Data.
void AddPatient()
{
	int ncount;
	int nTotalCount;
	cout << "Already data inputed on the database : " << nPatient_id << endl;
	cout << "How many entry do you want to add : " << endl;
	cin >> ncount;
	nTotalCount = ncount + nPatient_id; //number of data entering + number of total Patients id
	//Enter the Data of Patients
	for (i = nPatient_id; i < nTotalCount; ++i)
	{
		cout << "Enter  Name : ";
		cin >> Patient_t[i].szPatientName;
		cout << "Enter Age : ";
		cin >> Patient_t[i].szPatientAge;
		cout << "Enter Gender : ";
		cin >> Patient_t[i].szPatientGender;
		cout << "Enter Blood Group : ";
		cin >> Patient_t[i].szPatientBlood;
		cout << "Enter Mobile : ";
		cin >> Patient_t[i].llnPatientMobile;
		cout << "Enter email : ";
		cin >> Patient_t[i].szPatientEmail;
		cout << "Enter Address : ";
		cin >> Patient_t[i].szPAddressLine;
		cout << "House Pincode:";
		cin >> Patient_t[i].nPatientPincode;
		++nPatient_id; //patient id increment by 1 after entering each  patient Data
	}
	cout << "\nAlready data inputed on the database : " << nPatient_id << endl;
}

//Function for view All Patient Data
void ViewPatient()
{

	if (nPatient_id != 0)
	{
		for (i = 0; i < nPatient_id; ++i)
		{
			cout << "\nName			: " << Patient_t[i].szPatientName;
			cout << "\nAge			: " << Patient_t[i].szPatientAge;
			cout << "\nGender		: " << Patient_t[i].szPatientGender;
			cout << "\nBloood Group : " << Patient_t[i].szPatientBlood;
			cout << "\nMobile		: " << Patient_t[i].llnPatientMobile;
		}
	}
	else if(nPatient_id==0)
	{
		cout << "!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!		Empty DataBase		 !!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!";
	}
	else
	{
		cout << "!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!		No Patient With This Patient Id 		 !!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!" << endl << endl;
	}
}

//Function for Edit Patients Data
void EditPatient()
{
	int  nId, nChoice;
	cout << "\nAlready data inputed on the database : " << nPatient_id << endl;
	cout << "Enter the Patient Id  : ";
	cin >> nId;
	if (nId <= nPatient_id)
	{
		cout << "What do you want to edit ? \nEnter your option\n";
		cout << "1.Name\n2.Age\n3.Gender\n4.Blood Group \n5.Mobile";
		cout << "Enter your choice:" << endl << endl;
		cin >> nChoice;
		--nId; // decrement id by 1 beacuse array index is started from zero and doctor id start from 1 
		cout << nId << endl;
		if (nChoice == 1)
		{
			cout << "\nEnter  Name : ";
			cin >> Patient_t[nId].szPatientName;
		}
		else if (nChoice == 2)
		{
			cout << "\nEnter Age : ";
			cin >> Patient_t[nId].szPatientAge;
		}
		else if (nChoice == 3)
		{
			cout << "\nEnter Gender : ";
			cin >> Patient_t[nId].szPatientGender;
		}
		else if (nChoice == 4)
		{
			cout << "\nEnter Blood Group : ";
			cin >> Patient_t[nId].szPatientBlood;

		}
		else if (nChoice == 5)
		{
			cout << "\nEnter Mobile : ";
			cin >> Patient_t[nId].llnPatientMobile;
		}
		else
		{
			cout << "\nPlease enter valid option." << endl;
		}
	}
	else if (nPatient_id == 0)
	{
		cout << "!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!		Empty DataBase		 !!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!" << endl << endl;
	}
	else
	{
		cout << "!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!		No Patient With This Patient Id 		 !!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!" << endl << endl;
	}
}

//Function for display pationn details using patient id
void SearchPatient(int i)
{
	system("cls");
	--i; //decrement i by 1 beacuse array index is started from zero and doctor id start from 1
	if (i < nPatient_id)
	{
		cout << "\nName			: " << Patient_t[i].szPatientName;
		cout << "\nAge			: " << Patient_t[i].szPatientAge;
		cout << "\nGender		: " << Patient_t[i].szPatientGender;
		cout << "\nBloood Group : " << Patient_t[i].szPatientBlood;
		cout << "\nMobile		: " << Patient_t[i].llnPatientMobile;
	}
	else
	{
		char ch;
		cout << "ID doesn't exist\n" << "Do you want to continue to Add a Patient press Y\n" << "press any key to exit\n";
		cin >> ch;
		if (ch == 'Y')
		{
			AddPatient();
		}
			
	}
}