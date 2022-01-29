// Doctor Related all the functions and attributes are mentioned here.

#include <iostream>
#include<iomanip>
#include<string>
using namespace std;

int i; //iteration
int Doctor_id = 0;

//Doctor Menu list 
int DoctorMenuList()
{
	int nChoice;
	system("cls");
	cout << right << setw(85) << setfill(' ') << "------------------------------------------------" << endl;
	cout << right << setw(82) << setfill(' ') << "   WELCOME TO HOSPITAL MANAGEMENT SYSTEM  " << endl;
	cout << right << setw(85) << setfill(' ') << "------------------------------------------------" << endl;
	cout << right << setw(68) << setfill(' ') << "DOCTOR PORTAL " << endl;
	cout << right << setw(85) << setfill(' ') << "------------------------------------------------" << endl;
	cout << endl << endl;
	cout << right << setw(73) << setfill(' ') << "1. View Patient Details" << endl;
	cout << right << setw(72) << setfill(' ') << "2. View Doctor Details" << endl;
	cout << right << setw(72) << setfill(' ') << "3. Edit Doctor Details" << endl;
	cout << right << setw(68) << setfill(' ') << "4. Appointments" << endl;
	cout << right << setw(63) << setfill(' ') << "5. Logout" << endl;
	cout << right << setw(85) << setfill(' ') << "------------------------------------------------" << endl << endl;
	cout << "Enter your choice:" << endl << endl;
	cin >> nChoice;
	return nChoice;
}

//struct  of Doctors
struct stdoctor {
	
	//string Doctor_name;
	//string Doctor_Specialization;
	char Doctor_name[40];
	char Doctor_Specialization[40];
	long long int Doctor_mobile;
	//string Doctor_Gender;
	//string email;
	//string Address_Line1;
	char Doctor_Gender[40];
	char email[40];
	char Address_Line1[40];
	int house_no, Pincode;
	int nAvailableSlot;
}Doctor[50];


//Function for Adding Doctor Data.
void AddDoctor()
{
	int nCount, nTotalId;
	cout << "Already data inputed on the database : " << Doctor_id;
	cout << "\nHow many entry do you want to add : ";
	cin >> nCount;
	nTotalId = nCount + Doctor_id; //number of data entering + number of total doctor id

	//Enter the Data of doctor
	for (i = Doctor_id; i < nTotalId; ++i)
	{
		cout <<endl<< "Enter  Name : ";
		//cin.getline( Doctor[i].Doctor_name);
		cin >> Doctor[i].Doctor_name;
		cout << "Enter Specialization : ";
		//getline(cin, Doctor[i].Doctor_Specialization);
		cin >> Doctor[i].Doctor_Specialization;

		cout << "Enter Gender : ";
		//getline(cin, Doctor[i].Doctor_Gender);
		cin >> Doctor[i].Doctor_Gender;

		cout << "Enter email : ";
		//getline(cin, Doctor[i].email);
		cin >> Doctor[i].email;

		cout << "Enter Mobile : ";
		cin >> Doctor[i].Doctor_mobile;

		cout << "Enter Address ";
		//getline(cin, Doctor[i].Address_Line1);
		cin >> Doctor[i].Address_Line1;

		cout << "Pincode:";
		cin >> Doctor[i].Pincode;

		cout << "Enter The Number of slots available per day : ";
		cin >> Doctor[i].nAvailableSlot;

		++Doctor_id; //Doctor id increment by 1
	}
	//cout << "Already data inputed on the database : " << Doctor_id;

}

//View All Doctors Details in Database
void ViewDoctor()
{
	
	//Check Doctor data is stored
	if (Doctor_id != 0)
	{
		//Display the Heading
		cout << "\n" << "Doctor Id" << "\t" << "Name" << "\t" << "Specialization" << "\t\t" << "Gender" << "\t\t" << "email" << "\t\t\t" << "Mobile" << endl;

		//Display Each Doctor details line by line
		for (i = 0; i < Doctor_id; ++i)
		{
			cout << "\n" << i + 1;
			cout << "\t\t" << Doctor[i].Doctor_name;
			cout << "\t\t" << Doctor[i].Doctor_Specialization;
			cout << "\t\t" << Doctor[i].Doctor_Gender;
			cout << "\t\t" << Doctor[i].email;
			cout << "\t\t" << Doctor[i].Doctor_mobile << endl;
		}
		cout << endl << endl;
	}
	else
	{
		cout << "!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!		Empty DataBase		 !!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!";
	}
}

enum EditDoctorOperations
{
	Name = 1,Specialization, Gender, email, Mobile, Available_Slots
};

//Editing the Doctor Data
void EditDoctor()
{
	int id, nChoice;
	cout << "Enter the Doctor Id  : ";
	cin >> id;
	if (id <= Doctor_id)
	{
		cout << "\n What do you want to edit ? \n Enter your option\n";
		cout << "1.Name\n2.Specialization\n3.Gender\n4.email\n5.Mobile\n6.Available Slots";
		cout << "Enter your choice:" << endl << endl;
		cin >> nChoice;
		--id;// decrement id by 1 beacuse array index is started from zero and doctor id start from 1 

		switch (nChoice)
		{
		case EditDoctorOperations::Name: //used Enum named EditDoctorOperations ->  Name assigned value is 1
			//Editing Name
			cout << "\nEnter  Name : ";
			//getline(cin, Doctor[id].Doctor_name);
			cin >> Doctor[id].Doctor_name;
			break;

		case EditDoctorOperations::Specialization:
			//Editing Specialization
			cout << "\nEnter Specialization : ";
			//getline(cin, Doctor[id].Doctor_Specialization);
			cin >> Doctor[id].Doctor_Specialization;
			break;

		case EditDoctorOperations::Gender:
			//Editing Gender
			cout << "\nEnter Gender : ";
			//getline(cin, Doctor[id].Doctor_Gender);
			cin >> Doctor[id].Doctor_Gender;
			break;

		case EditDoctorOperations::email:
			//Editing Email
			cout << "\nEnter email : ";
			//getline(cin, Doctor[id].email);
			cin >> Doctor[id].email;
			break;

		case EditDoctorOperations::Mobile:
			//Editing Mobile
			cout << "\nEnter Mobile : ";
			cin >> Doctor[id].Doctor_mobile;
			break;

		case EditDoctorOperations::Available_Slots:
			//Editing Available Slot
			cout << "\nEnter the Available Sloat : ";
			cin >> Doctor[id].nAvailableSlot;
			break;

		default: cout << "\nCome on! Enter a valid option." << endl;
		}
	}
	else if(Doctor_id==0)
	{
		cout << "!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!		Empty DataBase		 !!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!"<<endl<<endl;
	}
	else
	{
		cout << "!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!		No Doctor With This Doctor Id 		 !!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!" << endl << endl;
	}
}

//Function For Search Doctor using Doctor id
void SearchDoctor(int i)
{
	system("cls");
	--i; //decrement i by 1 beacuse array index is started from zero and doctor id start from 1
	if (i < Doctor_id)     //check given id is already entered.
	{
		cout << "DOCTOR DETAILS\n";
		cout << "\n Name : " << Doctor[i].Doctor_name;
		cout << "\n Specialization : " << Doctor[i].Doctor_Specialization;
		cout << "\nGender : " << Doctor[i].Doctor_Gender;
		cout << "\n email : " << Doctor[i].email;
		cout << "\n Mobile : " << Doctor[i].Doctor_mobile;
	}
	else
	{
		char ch;
		cout << "ID doesn't exist\n" << "Do you want to continue to Add a Doctor press Y\n" << "press N to exit\n";
		cin >> ch;
		if (ch == 'Y')
		{
			AddDoctor();
		}
			
	}
}