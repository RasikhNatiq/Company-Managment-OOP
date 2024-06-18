#include<iostream>
#include<string>
#include<Windows.h>
#include"Header.h"
#include<sstream>

using namespace std;
void gotoXY(int x, int y)
{
	COORD coord = { x, y };
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
	return;
}
void getID_PasswordCeo(int* id, string* pass, int i)
{
	if (i == 0)
	{
		cout << "Enter Your ID\t\tEnter Your password ";
		gotoXY(14, 11);
		cout << "----------";
		gotoXY(45, 11);
		cout << "-------------";
	jump:
		gotoXY(14, 10);
		cin >> *id;
		gotoXY(45, 10);
		cin >> *pass;
		cout << endl;
	}
	else
	{
		gotoXY(14, 10);
		cout << "          ";
		gotoXY(45, 10);
		cout << "             ";
		goto jump;
	}
}
void getID_PasswordEmployee(int* id, string* pass, int i)
{
	if (i == 0)
	{
		cout << "Enter Your ID\t\tEnter Your password ";
		gotoXY(14, 17);
		cout << "----------";
		gotoXY(45, 17);
		cout << "-------------";
	jump:
		gotoXY(14, 16);
		cin >> *id;
		gotoXY(45, 16);
		cin >> *pass;
		cout << endl;
	}
	else
	{
		gotoXY(14, 16);
		cout << "          ";
		gotoXY(45, 16);
		cout << "             ";
		goto jump;
	}
}
void getID_PasswordManager(int* id, string* pass, int i)
{
	if (i == 0)
	{
		cout << "Enter Your ID\t\tEnter Your password ";
		gotoXY(14, 17);
		cout << "----------";
		gotoXY(45, 17);
		cout << "-------------";
	jump:
		gotoXY(14, 16);
		cin >> *id;
		gotoXY(45, 16);
		cin >> *pass;
		cout << endl;
	}
	else
	{
		gotoXY(14, 16);
		cout << "          ";
		gotoXY(45, 16);
		cout << "             ";
		goto jump;
	}
}
void setProject(Project* pr)
{
	string temps;
	int tempi;
	double tempd;
	cout << "Enter project Title" << endl;
	cin.ignore();
	getline(cin, temps);
	pr->setTitle(temps);
	pr->setStrDate();
	pr->setEndDate();
	cout << "Enter number of employee needed" << endl;
jump:
	cin >> tempi;
	pr->setNumEmp(tempi);
	if (tempi > 1)
	{
		pr->setPrjType('T');
	}
	else if (tempi == 1)
	{
		pr->setPrjType('I');

	}
	else if (tempi < 0)
	{
		cout << "Employees can not be less than 0 " << endl;
		cout << "Enter again" << endl;
		goto jump;
	}
	cout << "Enter total project cost" << endl;
jump1:
	cin >> tempd;
	if (tempd < 0)
	{
		cout << "Cost can not be less than 0 " << endl;
		cout << "Enter again" << endl;
		goto jump1;
	}
	else { pr->setCost(tempd); }
	cout << "Enter project details" << endl;
	cin.ignore();
	getline(cin, temps);
	pr->setPrjDetails(temps);

	pr->calculateDuration();
}
char departmentMenu(int tasks, string name[4], string dpname)
{

	char option;
	char ch = 205, ch1 = 201, ch2 = 200, ch3 = 187, ch4 = 188, ch5 = 204, ch6 = 185, ch7 = 186; ;
	int rs = (39 - strlen(dpname.c_str()) + 1) / 2;

	cout << "\t" << string(rs, ' ') << ch1;

	for (int x = 0; x <= strlen(dpname.c_str()) + 1; x++)
	{
		cout << ch;
	}
	cout << ch3 << endl;

	cout << "\t" << string(rs, ' ') << ch7 << " " << dpname << " " << ch7 << endl;

	cout << "\t" << string(rs, ' ') << ch2;
	for (int x = 0; x <= strlen(dpname.c_str()) + 1; x++)
	{
		cout << ch;
	}
	cout << ch4 << endl;
	{
		cout << "\t" << ch1;
		for (int x = 0; x <= 40; x++)
		{
			cout << ch;
		}
		cout << ch3 << endl;

	}
	{
		for (int x = 0; x < tasks; x++)
		{
			if (x == 9)
			{
				cout << "\t" << ch7 << "Press [" << 0 << "] to " << name[x] << " \t  " << ch7 << endl;
			}
			else
				cout << "\t" << ch7 << "Press [" << x + 1 << "] to " << name[x] << " \t  " << ch7 << endl;
		}
	}
	{
		cout << "\t" << ch2;
		for (int x = 0; x <= 40; x++)
		{
			cout << ch;
		}
		cout << ch4 << endl;
	}

	cin >> option;

	return option;
}
int dpartmentDriver(department* dp1, string temps)
{
	int tempi;
	dp1->setDptName(temps);
	Project prj1;
	int numberOfTasks = 10;
	string taskName[10] = { "Add Employee         ","Add project          ","Assign project       ","View Employee Data   ","View Projects Taken  ","See department data  ","Total Salaries       ","Total Projects Cost  ","Logout               ","Exit                 " };
	char choice = ' ';
	do
	{
	jump:
		choice = departmentMenu(numberOfTasks, taskName, dp1->getDptName());
		switch (choice)
		{
		case '1':
			dp1->addWorkerDetails();
			break;
		case'2':
			setProject(&prj1);
			dp1->recieveProject(&prj1);
			break;
		case'3':
			cout << "Enter Project Title to assign " << endl;
			cin.ignore();
			getline(cin, temps);
			dp1->assignProject(temps);
			break;
		case'4':
			for (int i = 0; i < dp1->getTotalEmployee(); i++)
			{
				dp1->emp[i]->printWorkerData();
			}
			break;
		case'5':
			dp1->getProjectDetails();
			break;
		case '6':
			dp1->printDepartmentData();
			break;
		case '7':
			cout << "-------------------------------------------------" << endl;
			cout << "Total Employee salaries : " << dp1->calculateSalary() << endl;
			cout << "-------------------------------------------------" << endl;
			break;
		case '8':
			cout << "-------------------------------------------------" << endl;
			cout << "Total Revenue generated : " << dp1->calculateTotalCost() << endl;
			cout << "-------------------------------------------------" << endl;
			break;
		case'9':
			return 1;
		case'0':
			goto end;
		default:
			cout << "You have entered invalid input." << endl;
			cout << "Enter again" << endl;
			goto jump;
		}

		cout << "\nDo you want to use Department Menu again? (Y/N)" << endl;
	jump2:
		cin >> choice;
		switch (choice)
		{
		case 'y':
		case 'Y':
			system("cls");
			goto jump;
		case 'n':
		case 'N':
			goto end;
		default:
			cout << "You have entered invalid input" << endl;
			cout << "Enter again" << endl;
			goto jump2;
		}
	} while (choice != 'n' && choice != 'N');
end:
	return 0;

}
int companyOwnerDriver(company* cp)
{
	string temps, temps1, pass;
	int tempi;
	double tempd;
	bool as = true;
	Project temporaryProject;
	int numberOfTasks = 10;
	string taskName[10] = { "Add Department       ","Add Employee         ","Recieve Project      ","View company data    ","view department Data ","Handle a department  ","Get Managers Details ","Give Manager a Bonus ","Logout               ","Exit                 " };
	char choice = ' ';
	do
	{
	jump:
		choice = cp->CompanyMenu(numberOfTasks, taskName);
		switch (choice)
		{
		case '1':
			cout << "Enter Department Name" << endl;
			cin.ignore();
			getline(cin, temps);
			for (int i = 0; i < cp->getDpt_count(); i++)
			{
				if (cp->dpt[i]->getDptName() == temps)
				{
					cout << "Department with such name already exists " << endl;
					as = false;
				}
			}
			if (as)
			{
				cout << "Add Departments Manager" << endl;
				cout << "Enter Manager's Name : " << endl;
				cin >> temps1;
				cout << "Enter Manager's Salary : " << endl;
				cin >> tempd;
				cout << "Set Manager ID : ";
				cin >> tempi;
				cout << endl;
				cout << "Set Manager Password : ";
				cin >> pass;
				cout << endl;
				cp->addDepartment(temps, temps1, tempd, pass, tempi);
			}
			break;
		case'2':
			as = true;
			cout << endl << "Departments in Company" << endl;
			cout << "-------------------------------------------------" << endl;
			for (int i = 0; i < cp->getDpt_count(); i++)
			{
				cout << cp->dpt[i]->getDptName() << "  ";
			}
			cout << endl << "-------------------------------------------------" << endl;
			cout << "Enter the name of department in which you want to add employee " << endl;
			cin.ignore();
			getline(cin, temps);
			for (int i = 0; i < cp->getDpt_count(); i++)
			{
				if (cp->dpt[i]->getDptName() == temps)
				{
					cp->dpt[i]->addWorkerDetails();
					as = false;
				}
			}
			if (as)
			{
				cout << "No department with such name exists" << endl;
			}

			break;
		case '3':
			setProject(&temporaryProject);
			cout << endl << "Departments in Company" << endl;
			cout << "-------------------------------------------------" << endl;
			for (int i = 0; i < cp->getDpt_count(); i++)
			{
				cout << cp->dpt[i]->getDptName() << "  ";
			}
			cout << endl << "-------------------------------------------------" << endl;
			cout << endl << "Enter name of department to assign project" << endl;
			fflush;
			getline(cin, temps);
			for (int i = 0; i < cp->getDpt_count(); i++)
			{
				if (cp->dpt[i]->getDptName() == temps)
				{
					cp->dpt[i]->recieveProject(&temporaryProject);
					as = false;
				}
			}
			if (as)
			{
				cout << "No department with such name exists" << endl;
			}
			break;
		case'4':
			cp->printCompanyData();
			break;
		case '5':
			cout << "Departments in Company" << endl;
			cout << "-------------------------------------------------" << endl;
			for (int i = 0; i < cp->getDpt_count(); i++)
			{
				cout << cp->dpt[i]->getDptName() << "  ";
			}
			cout << endl << "-------------------------------------------------" << endl;
			cout << "Enter name of departmnet to view" << endl;
			cin.ignore();
			getline(cin, temps);
			cp->viewDepartment(temps);
			break;
		case '6':
			cout << "Departments in Company" << endl;
			cout << "-------------------------------------------------" << endl;
			for (int i = 0; i < cp->getDpt_count(); i++)
			{
				cout << cp->dpt[i]->getDptName() << "  ";
			}
			cout << endl << "-------------------------------------------------" << endl;
			cout << "Enter name of departmnet to handle" << endl;
			cin.ignore();
			getline(cin, temps);
			for (int i = 0; i < cp->getDpt_count(); i++)
			{
				if (cp->dpt[i]->getDptName() == temps)
				{
					dpartmentDriver(cp->dpt[i], temps);
					as = false;
				}
			}
			if (as)
			{
				cout << "No department with such name exists" << endl;
			}
			break;
		case '7':
			for (int i = 0; i < cp->getDpt_count(); i++)
			{
				cout << "-------------------------------------------------" << endl;
				cout << endl << "Department Name : " << cp->dpt[i]->getDptName() << endl;
				if (cp->dpt[i]->getManagerSalary() == NULL)
				{
					cout << "This department has not assigned any Manager yet" << endl;
				}
				cout << "Manager Name    : " << cp->dpt[i]->getManagerName() << endl;
				cout << "Manager Salary  : " << cp->dpt[i]->getManagerSalary() << endl;
				cout << "-------------------------------------------------" << endl;
			}
			break;
		case '8':
			cout << "Managers in Company" << endl;
			cout << "-------------------------------------------------" << endl;
			for (int i = 0; i < cp->getDpt_count(); i++)
			{
				cout << cp->dpt[i]->getDptName() << " : " << cp->dpt[i]->getManagerName() << "  " << endl;
			}
			cout << endl << "-------------------------------------------------" << endl;
			cout << "Enter manager Name ";
			cin.ignore();
			getline(cin, temps);
			cout << endl;
			for (int i = 0; i < cp->getDpt_count(); i++)
			{
				if (cp->dpt[i]->getManagerName() == temps)
				{
					cout << "Enter Bonus : ";
					cin >> tempd;
					cp->dpt[i]->addManagerBonus(tempd);
					cout << "Bonus given successfully" << endl;
					as = false;
				}
			}
			if (as)
			{
				cout << "No Manager with such name " << endl;
			}
			break;
		case'9':
			return 1;
		case '0':
			goto end;
		default:
			cout << "You have entered invalid input." << endl;
			cout << "Enter again" << endl;
			goto jump;
		}

		cout << "\nDo you want to use Main Menu again? (Y/N)" << endl;
	jump2:
		cin >> choice;
		switch (choice)
		{
		case 'y':
		case 'Y':
			system("cls");
			goto jump;
		case 'n':
		case 'N':
			goto end;
		default:
			cout << "You have entered invalid input" << endl;
			cout << "Enter again" << endl;
			goto jump2;
		}
	} while (choice != 'n' && choice != 'N');
end:
	return 0;
}
void accessMenu(company* cp)
{
	string temps, pass;
	int tempi;
	bool tempb = true;
	bool tempb2 = true;
	string designations[3] = { "CEO","Manager","Employee" };
jump3:
	system("cls");
	cout << "\tLOGIN TO THE SYSTEM " << endl << endl;
	cout << "Designations in Company" << endl;
	cout << "-------------------------------------------------" << endl;
	for (int i = 0; i < 3; i++)
	{
		cout << designations[i] << "  ";
	}
	cout << endl << "-------------------------------------------------" << endl;
	cout << endl;
	cout << "Enter your designation " << endl;
	cin >> temps;
	cout << endl;
	if (temps == designations[0])
	{
		int chec = 0;
	againpass:
		getID_PasswordCeo(&tempi, &pass, chec);
		if (cp->getCeoID() == tempi)
		{
			if (cp->getCeoPass() == pass)
			{
				system("cls");
				tempi = companyOwnerDriver(cp);
				if (tempi == 1)
				{
					goto jump3;
				}
			}
			else
			{
				cout << " Wrong credentials" << endl;
				cout << " Enter Again" << endl;
				chec++;
				goto againpass;
			}
		}
		else
		{
			cout << " Wrong credentials" << endl;
			cout << " Enter Again" << endl;
			chec++;
			goto againpass;
		}
	}
	else if (temps == designations[1])
	{
		cout << "Departments in Company" << endl;
		cout << "-------------------------------------------------" << endl;
		for (int i = 0; i < cp->getDpt_count(); i++)
		{
			cout << cp->dpt[i]->getDptName() << "  ";
		}
		cout << endl << "-------------------------------------------------" << endl;
		cout << "Enter your department Name ";
		cin.ignore();
		getline(cin, temps);
		cout << endl;
		int chec = 0;
	againpass1:
		for (int i = 0; i < cp->getDpt_count(); i++)
		{
			if (cp->dpt[i]->getDptName() == temps)
			{
				tempb = false;
				getID_PasswordManager(&tempi, &pass, chec);
				if (cp->dpt[i]->getManagerid() == tempi)
				{
					if (cp->dpt[i]->getManagerPass() == pass)
					{
						system("cls");
						tempi = dpartmentDriver(cp->dpt[i], temps);
						if (tempi == 1)
						{
							goto jump3;
						}
						tempb2 = false;
					}
				}
			}
		}
		if (tempb2)
		{
			cout << " Wrong credentials" << endl;
			cout << " Enter Again" << endl;
			chec++;
			goto againpass1;
		}
		if (tempb)
		{
			cout << "No such department exists " << endl;
		}
	}
	else if (temps == designations[2])
	{
		int chec = 0;
		cout << "Departments in Company" << endl;
		cout << "-------------------------------------------------" << endl;
		for (int i = 0; i < cp->getDpt_count(); i++)
		{
			cout << cp->dpt[i]->getDptName() << "  ";
		}
		cout << endl << "-------------------------------------------------" << endl;
		cout << "Enter your department Name ";
		cin.ignore();
		getline(cin, temps);
		cout << endl;
	againpass2:
		for (int i = 0; i < cp->getDpt_count(); i++)
		{
			if (cp->dpt[i]->getDptName() == temps)
			{
				getID_PasswordEmployee(&tempi, &pass, chec);
				tempb = false;
				for (int j = 0; j < cp->dpt[i]->getTotalEmployee(); j++)
				{
					if (cp->dpt[i]->emp[j]->getEmp_id() == tempi)
					{
						if (cp->dpt[i]->emp[j]->getemp_pass() == pass)
						{
						jump2:
							cp->dpt[i]->emp[j]->printWorkerData();
							tempb2 = false;
						}
					}
				}
			}
		}
		if (tempb2)
		{
			cout << " Wrong credentials" << endl;
			cout << " Enter Again" << endl;
			chec++;
			goto againpass2;
		}
		if (tempb)
		{
			cout << "No department with such name" << endl;
		}
	}
	else
	{
		cout << "No Such designation in the company" << endl;
		cout << "Enter again" << endl << endl;
		Sleep(1000);
		system("cls");
		goto jump3;
	}
}

void addDummyData(company* cmp)
{

	cmp->addDepartment("Creative", "Rasikh", 100000, "abc", 123);
	cmp->addDepartment("Technologies", "Anas", 100000, "abc", 456);
	cmp->addDepartment("BSAI", "Rehmak", 100000, "abc", 789);
	cmp->dpt[0]->addWorkerDetails("Basit", 1, 12000, "abc");
	cmp->dpt[0]->addWorkerDetails("Ahmad", 2, 13000, "abc");
	cmp->dpt[0]->addWorkerDetails("Touseef", 3, 14000, "abc");
	cmp->dpt[1]->addWorkerDetails("Khurram", 4, 15000, "abc");
	cmp->dpt[1]->addWorkerDetails("Abdullah", 5, 16000, "abc");
	cmp->dpt[1]->addWorkerDetails("Sarim", 6, 17000, "abc");
	cmp->dpt[2]->addWorkerDetails("Amjad", 7, 18000, "abc");
	cmp->dpt[2]->addWorkerDetails("Iqbal", 8, 12000, "abc");

	Project pr1, pr2, pr3;
	pr1.setTitle("project1");
	pr1.setStrDate(1, 1, 2020);
	pr1.setEndDate(1, 2, 2020);
	pr1.setNumEmp(1);
	pr1.setPrjType('I');
	pr1.setCost(10000);
	pr1.setPrjDetails("First project");
	pr1.calculateDuration();

	//second project

	pr2.setTitle("project2");
	pr2.setStrDate(1, 3, 2020);
	pr2.setEndDate(1, 4, 2020);
	pr2.setNumEmp(2);
	pr2.setPrjType('T');
	pr2.setCost(20000);
	pr2.setPrjDetails("Second project");
	pr2.calculateDuration();

	//third project

	pr3.setTitle("project3");
	pr3.setStrDate(1, 5, 2020);
	pr3.setEndDate(1, 6, 2020);
	pr3.setNumEmp(1);
	pr3.setPrjType('I');
	pr3.setCost(30000);
	pr3.setPrjDetails("Third project");
	pr3.calculateDuration();

	cmp->dpt[0]->recieveProject(&pr1);
	cmp->dpt[1]->recieveProject(&pr2);
	cmp->dpt[2]->recieveProject(&pr3);

}

int main()
{
	company cp("Pauspan Private Limited");
	addDummyData(&cp);
	accessMenu(&cp);
}