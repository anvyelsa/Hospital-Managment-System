//Receptionlist Related all the functions and attributes are mentioned here.

#include <iostream>
#include<iomanip>
using namespace std;

int nChoice;
int AppointmentCount = 0;
int ReceptionListMenu()
{
	
	system("cls");
	cout << right << setw(81) << setfill(' ') << "WELCOME TO HOSPITAL MANAGEMENT SYSTEM  " << endl;
	cout << right << setw(68) << setfill(' ') << "RECEPITIONLIST " << endl;
	cout << endl << endl;
	cout << right << setw(85) << setfill(' ') << "------------------------------------------------" << endl;

	cout << right << setw(71) << setfill(' ') << "1. Patient Details" << endl;
	cout << right << setw(71) << setfill(' ') << "2. Doctor Details" << endl;
	cout << right << setw(70) << setfill(' ') << "3. Appointment Booking" << endl;
	cout << right << setw(70) << setfill(' ') << "4. View Appointment " << endl;
	cout << right << setw(67) << setfill(' ') << "5. Logout" << endl;
	cout << right << setw(85) << setfill(' ') << "------------------------------------------------" << endl << endl;
	cout << "Enter your choice:" << endl << endl;
	cin >> nChoice;
	return nChoice;
}

struct stAppointment
{
	int nAppointmentId;
	string PatientName;
	long long Appointment_PhoneNumber;
	char date[30];
	char time[10];
	int slot;
	int AppointmentDoctorId;
}AppointmentList[50];


void AddAppointment()
{
	
	
	int nSlot;
	int nIterator1;
	int nIterator2;
	int nTotal=0;
	ViewDoctor();

	cout << "\nSELECT DOCTOR Id TO TAKE APPOINMENT: " << endl;
	cin >> nChoice;
	for (nIterator1 = 0; nIterator1 < Doctor_id; ++nIterator1)
	{
		if (nChoice  == nIterator1)
		{
			cout << "current available slot for the doctor :" << Doctor[nIterator1].nAvailableSlot << endl;
			cout << "Enter the number of slots to book :\t";
			cin >> nSlot;
			//cout << "Enter the details if u wanna book :" << endl;
			nTotal = nSlot + AppointmentCount;
			for (nIterator2 = AppointmentCount; nIterator2 < nTotal; ++nIterator2)
			{			
				cout << "Enter Name : ";
				cin  >> AppointmentList[nIterator2].PatientName;
				cout << "Enter the Date : ";
				cin >> AppointmentList[nIterator2].date;
				cout << "Enter Phone Number : ";
				cin >> AppointmentList[nIterator2].Appointment_PhoneNumber;
				cout << "Enter Time : ";
				cin >> AppointmentList[nIterator2].time;
				++AppointmentCount;
				AppointmentList[nIterator2].nAppointmentId = AppointmentCount;
				AppointmentList[nIterator2].AppointmentDoctorId = nIterator1+1;
			}
			Doctor[nIterator1].nAvailableSlot = Doctor[nIterator1].nAvailableSlot - AppointmentCount;
		}
		
	}
	while (nTotal==0)
	{
		cout << "Enter valid Doctor id" << endl;
	}
	
}

void ViewAppointments()
{
	//int id; //stori
	// Appointmentslist is available then it shows
	if (AppointmentCount != 0)
	{
		cout << "Appointment ID\t\tDate\t\tPatient_Name\t\t\tPhone Number\t\tTime\t\tDoctor\t\t";
		//displaying Each list one by one
		for (i = 0; i < AppointmentCount; ++i)
		{
			//id = AppointmentList[i].AppointmentDoctorId;
			cout << "\n" << AppointmentList[i].nAppointmentId << "\t\t" << AppointmentList[i].date << "\t\t";
			cout << AppointmentList[i].PatientName << "\t\t" << AppointmentList[i].Appointment_PhoneNumber;
			cout << "\t" << AppointmentList[i].time << "\t\t" << Doctor[AppointmentList[i].AppointmentDoctorId - 1].Doctor_name;
		}
	} //appointment list is not available this part will work
	else
	{
		cout << "Appointment Booking is not Done" << endl;
	}
	
}

