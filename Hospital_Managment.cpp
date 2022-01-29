// Hospital_Managment System : 

#include <iostream>
#include<iomanip>
#include "Admin.h" 
#include "Doctor.h"
#include "Receptionlist.h"
#include "Patients.h"

using namespace std;

int main()
{
		int nMainChoice;
		int n_select;
		char chChoice;
		int nSearchDoctorID;
		int nSearchPatientID;
		int nChoice;
		//calling Main Menu List for selecting the user
		Main_Menu: nMainChoice = MainMenu(); 		

		//clear the output Screen
		system("cls");
		switch (nMainChoice)
		{
		case 1:	//admin
			
			//calling Admin Menu List
			Admin_menu: n_select = AdminMenu(); //Admin_menu is a label for GoTo Statment
			switch (n_select)
			{
			case 1: //Doctor entity operations 

				do
				{
					system("cls"); //Clear Screen
					//Sub Menu List Display in Admin Portal for selecting Doctor Option
					cout << right << setw(87) << setfill(' ') << "------------------------------------------------" << endl;
					cout << endl << endl;
					cout << right << setw(85) << setfill(' ') << "WELCOME TO HOSPITAL MANAGEMENT SYSTEM " << endl << endl;
					cout << right << setw(71) << setfill(' ') << "ADMIN PORTAL " << endl;
					cout << endl << endl;
					cout << right << setw(87) << setfill(' ') << "------------------------------------------------" << endl;
					cout << right << setw(68) << setfill(' ') << "DOCTOR " << endl;
					cout << right << setw(87) << setfill(' ') << "------------------------------------------------" << endl;
					cout << endl << endl;
					cout << right << setw(70) << setfill(' ') << "1. Add Doctor " << endl;
					cout << right << setw(71) << setfill(' ') << "2. View Doctors" << endl;
					cout << right << setw(73) << setfill(' ') << "3. Search Doctors" << endl;
					cout << right << setw(71) << setfill(' ') << "4. Edit Doctors" << endl;
					cout << right << setw(66) << setfill(' ') << "5. Go Back" << endl;
					cout << endl << endl;
					cout << right << setw(87) << setfill(' ') << "------------------------------------------------" << endl << endl;
					cout << "Enter your choice :" << endl << endl;
					cin >> nChoice;
					switch (nChoice)
					{
						case DoctorOperations::Add_Doctor: //Add New Doctor Data
							AddDoctor();
							break;

						case DoctorOperations::View_Doctor: //View  Doctor Data
							ViewDoctor();
							break;

						case DoctorOperations::Search_Doctor: //Search Doctor Data
							cout << "Enter the DOctor ID to Search\n";
							cin >> nSearchDoctorID;
							SearchDoctor(nSearchDoctorID);
							break;

						case DoctorOperations::Edit_Doctor: //Edit Doctor Data
							EditDoctor();
							break;

						case DoctorOperations::GoBack: //Go pack to Previous 
							goto Admin_menu;

						default: cout << "!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!! Wrong Choice !!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!" << endl;
							break;
					}
					cout << "\n\n Go Back to previous menu press B \n Continue with this menu press  Y " << endl;
					cin >> chChoice;
				} while (chChoice == 'y' || chChoice == 'Y') ;

				goto Admin_menu ; //Go back to Admin Menu
				break;


			case 2://patient Entites operation;

				do
				{
					system("cls");
					//Sub Menu List Display in Admin Portal for selecting Patient Option
					cout << right << setw(87) << setfill(' ') << "------------------------------------------------" << endl;
					cout << endl << endl;
					cout << right << setw(85) << setfill(' ') << "WELCOME TO HOSPITAL MANAGEMENT SYSTEM " << endl << endl;
					cout << right << setw(71) << setfill(' ') << "ADMIN PORTAL " << endl;
					cout << endl << endl;
					cout << right << setw(87) << setfill(' ') << "------------------------------------------------" << endl;
					cout << right << setw(68) << setfill(' ') << "Patient " << endl;
					cout << right << setw(87) << setfill(' ') << "------------------------------------------------" << endl;
					cout << endl << endl;
					cout << right << setw(67) << setfill(' ') << "1. Add Patient " << endl;
					cout << right << setw(67) << setfill(' ') << "2. View Patient" << endl;
					cout << right << setw(67) << setfill(' ') << "3. Edit Patient" << endl;
					cout << right << setw(69) << setfill(' ') << "4. Search Patient" << endl;
					cout << right << setw(62) << setfill(' ') << "5. Go Back" << endl;
					cout << endl << endl;
					cout << right << setw(85) << setfill(' ') << "------------------------------------------------" << endl << endl;
					cout << "Enter your choice:" << endl << endl;
					cin >> nChoice;
					
					switch (nChoice)
					{
					case PatientOperations::Add_Patient: //Add New Patient Data
						AddPatient();
						break;

					case PatientOperations::View_Patient: //View  Patient Data
						ViewPatient();
						break;

					case PatientOperations::Search_Patient: //Search Patient Data
						cout << "Enter the Patient ID to Search\n";
						cin >> nSearchPatientID;
						SearchPatient(nSearchPatientID);
						break;

					case PatientOperations::Edit_Patient: //Edit Patient Data
						EditPatient();
						break;

					case PatientOperations::PatientOperationsGoBack: //Go pack to Previous 
						goto Admin_menu;

					default: cout << "!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!! Wrong Choice !!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!" << endl;
						break;
					}

					cout << "\n\n Go Back to previous menu press B \n Continue with this menu press  Y " << endl;
					cin >> chChoice;
				} while (chChoice == 'y' || chChoice == 'Y');
				goto Admin_menu; //Go back to Admin Menu
				break;

			case 3:   system("cls");
				goto Main_Menu;			//logout			
				break;

			default: cout << "!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!! Wrong Choice !!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!"<<endl;

			}
			break;

		case 2: //patient portal
			
			do
			{
				system("cls"); //Clear Screen
				n_select = PatientMenu(); //Display Patient Menu List
				switch (n_select)
				{
				case 1: //View Patient Details 
					ViewPatient();
					break;
				case 2:  //AddAppointment
					AddAppointment();
					break;
				
				case 3:  system("cls");
					goto Main_Menu;
					break;
				default: cout << "!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!! Wrong Choice !!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!" << endl;

				}
				cout << "\n Go Back to previous menu press  Y " << endl;
				cin >> chChoice;
			} while (chChoice == 'y' || chChoice == 'Y');
			goto Main_Menu; // Display Main Menu
			break;

		case 3://Doctor portal

			do {
				system("cls"); //Clear Screen
				n_select = DoctorMenuList(); //Display Doctor Portal Menu List
				switch (n_select)
				{
				case 1: //Search Patient id And View Data
					
					cout << "Enter the Patient ID to Search\n";
					cin >> nSearchPatientID;
					SearchPatient(nSearchPatientID);
					break;

				case 2: //Search Doctor id And View Data
					cout << "Enter the DOctor ID to Search\n";
					cin >> nSearchDoctorID;
					SearchDoctor(nSearchDoctorID);
					break;
				case 3: //Edit Doctor Data Using Doctor id
					EditDoctor();
					break;

				case 4: //View Appointments
					ViewAppointments();
					break;

				case 5:  system("cls"); //Logout and go back to Main Menu
					goto Main_Menu;
					break;

				default: cout << "!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!! Wrong Choice !!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!" << endl;

				}
				cout << "\n Go Back to previous menu press  Y " << endl;
				cin >> chChoice;
			} while (chChoice == 'y' || chChoice == 'Y');
			
			goto Main_Menu;
			break;

		case 4: //Reception
			
			do
			{
				system("cls");
				n_select = ReceptionListMenu(); //Display Receptionlist Menu List
				switch (n_select)
				{
				case 1: //View Patient Details 
					
					cout << "Enter the Patient ID to Search\n";
					cin >> nSearchPatientID;
					SearchPatient(nSearchPatientID);
					break;

				case 2:
					//int nSearchDoctorID;
					cout << "Enter the DOctor ID to Search\n";
					cin >> nSearchDoctorID;
					SearchDoctor(nSearchDoctorID);
					break;

				case 3:   //Add New Appointment
					AddAppointment();
					break;

				case 4: //View Appointments
					ViewAppointments();
					break;

				case 5:  //logout 
					system("cls");
					goto Main_Menu;
					break;

				default: cout << "!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!! Wrong Choice !!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!" << endl;

				}
				cout << "\n Do You Want To Continue. Press  Y " << endl;
				cin >> chChoice;
			} while (chChoice == 'y' || chChoice == 'Y');
			
			goto Main_Menu; //go back to Main Menu
			break;

		case 5: //EXIT
			exit(0);
			break;

		default: cout << "!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!! Wrong Choice !!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!" << endl;
			break;
		}
		
		



	
		
	
}
