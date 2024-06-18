#pragma once
#include<iostream>
#include<string>
#include<fstream>
using namespace std;

class Date
{
private:
	int month, day, year;
	int monList[12] = { 31,29,31,30,31,30,31,31,30,31,30,31 };//took 29 to check for leap year as well
public:
	Date();
	int getDay() const;
	void setDay(int);
	int getMonth()const;
	void setMonth(int);
	int getYear()const;
	void setYear(int);

	Date(int, int, int);
	void setDate(int, int, int);
	friend ostream& operator<<(ostream& dateout, const Date& date)
	{

		dateout << date.day << "-" << date.month << "-" << date.year;
		return dateout;
	}
	friend istream& operator>>(istream& datein, Date& date)
	{
	jump:
		cout << "Enter day:";
		datein >> date.day;
		if (date.day > 31 || date.day <= 0)
		{
			cout << "Invalid Input" << endl;
			cout << "Enter again:" << endl;
			goto jump;
		}
	jump1:
		cout << "Enter the month:";
		datein >> date.month;
		if (date.month > 12 || date.month <= 0)
		{

			cout << "Invalid Input" << endl;
			cout << "Enter again:" << endl;
			goto jump1;
		}
		else if (date.monList[date.month - 1] < date.day)
		{

			cout << "Invalid Input" << endl;
			cout << "Enter again:" << endl;
			goto jump;
		}
	jump2:
		cout << "Enter the year:";
		datein >> date.year;
		if (date.year <= 0)
		{
			cout << "Invalid Input" << endl;
			cout << "Enter again:" << endl;
			goto jump2;
		}
		return datein;
	}
	bool operator ==(const Date&);
	int operator -(Date);
	void operator = (Date);
	bool operator <(const Date& date);
	bool operator >(const Date& date);
	~Date();
};

class Project {
private:
	int duration;
	string title;
	double cost;
	Date str_dt;
	Date end_dt;
	string prj_det;
	int num_emp;
	char prj_type;
public:
	Project();
	Project(Project&);
	void setTitle(string);
	void setCost(double);
	void setStrDate();
	void setStrDate(int, int, int);
	void setEndDate();
	void setEndDate(int, int, int);
	void setPrjDetails(string);
	void setPrjType(char);
	void setNumEmp(int);
	string getTitle()const;
	double getCost()const;
	Date getStrDate()const;
	Date getEndDate()const;
	string getPrjDetails()const;
	int getNumEmp()const;
	void calculateDuration();
	void setDuration(int);
	int getDuration()const;
	char getPrjType()const;
	void equalTo(Project* p);
	void printProjectDetails();
	~Project();
};

class Person
{
protected:
	string emp_name;
	int emp_id;
	double emp_salary;
	string emp_pass;
public:
	Person()
	{
		emp_name = "\0";
		emp_id = 0;
		emp_salary = 0;
	}
	void setEmp_name(string);
	void setEmp_id(int);
	string getEmp_name()const;
	int getEmp_id()const;
	void setEmp_salary(double);
	double getEmp_salary()const;
	void setemp_pass(string p)
	{
		emp_pass = p;
	}
	string getemp_pass()const { return emp_pass; }
};

class Worker : public Person {
private:
	bool assigned;
	char prj_type;
	string dpt_name;
public:
	Project* prj_assigned;
	Worker();
	Worker(int, double, bool);
	string getdep_name()const;
	void setdpt_name(string);
	void setPrjassigned(Project*);
	void setPrjType(char);
	char getPrjType()const;
	bool getassignCheck()const;
	void setassignedCheck(bool);
	void printWorkerData();
	~Worker();
};

class Manager : public Person
{
private:
	string dpt_name;
public:

	string getdep_name()const;
	void setdpt_name(string);
	void addBonus(double sl);
};

class CEO : public Person
{

};

class department {
private:
	int count_projects;
	string dpt_name;
	int total_emp = 0;
	double total_cst;
	Project prjs[20];
	int emp_available;
	int emp_working;
	Manager dptManager;
public:
	Worker* emp[30];
	department();
	void addWorkerDetails();
	void addWorkerDetails(string, int, double, string);
	void addManagerDetails();
	void addManagerDetails(string, double, string, int);
	void recieveProject(Project*);
	void assignProject(string);
	double calculateTotalCost();
	double calculateSalary();
	string getDptName()const;
	void setDptName(string);
	int getProjectCount()const;
	int getTotalEmployee() const { return total_emp; }
	string getManagerName()const { return dptManager.getEmp_name(); }
	string getManagerPass() const { return dptManager.getemp_pass(); }
	int getManagerid() const { return dptManager.getEmp_id(); }
	double getManagerSalary()const { return dptManager.getEmp_salary(); }
	void addManagerBonus(double b);
	void getProjectDetails();
	void printDepartmentData();
	~department();
};

class company
{
private:
	string name;
	int dpt_count = 0;
	CEO cmp_ceo;
public:
	department* dpt[15];
	company() {};
	company(string);
	void addDepartment(string, string, double, string, int);
	void printCompanyData();
	string  getName()const;
	void setName(string);
	char CompanyMenu(int, string[4]);
	void viewDepartment(string);
	int getDpt_count()const;
	string getCeoPass()const { return cmp_ceo.getemp_pass(); }
	int getCeoID() const { return cmp_ceo.getEmp_id(); }
};


//class date
Date::Date()
{
	month = 1;
	day = 1;
	year = 1900;
}
Date::Date(int dd, int mm, int yy)
{
	day = dd;
	month = mm;
	year = yy;
}
int Date::getDay()const
{
	return day;
}
void Date::setDay(int dd)
{
	day = dd;
}
int Date::getMonth()const
{
	return month;
}
void Date::setMonth(int mm)
{
	month = mm;
}
int Date::getYear()const
{
	return year;
}
void Date::setYear(int yy)
{
	year = yy;
}
void Date::setDate(int dd, int mm, int yy)
{
	day = dd;
	month = mm;
	year = yy;
}
bool Date::operator ==(const Date& date)
{
	if (year == date.year && month == date.month && day == date.day)
	{
		return true;
	}
	return false;
}
int Date::operator -(Date obj)
{
	int ted = this->getDay() - obj.getDay();
	if (ted < 0)
	{
		ted = -ted;
	}
	int tem = this->getMonth() - obj.getMonth();
	if (tem < 0)
	{
		tem = -tem;
	}
	int tey = this->getYear() - obj.getYear();
	if (tey < 0)
	{
		tey = -tey;
	}
	int remDays = ted + (tem * 31) + (tey * 12 * 31);
	return remDays;
}
void Date::operator = (Date obj)
{
	this->day = obj.day;
	this->month = obj.month;
	this->year = obj.year;
}
bool Date::operator <(const Date& date)
{
	if (year < date.year)
	{
		return true;
	}
	if (year == date.year && month < date.month)
	{
		return true;
	}
	if (month == date.month && day < date.day)
	{
		return true;
	}
	return false;
}
bool Date::operator >(const Date& date)
{
	if (year > date.year)
	{
		return true;
	}
	if (year == date.year && month > date.month)
	{
		return true;
	}
	if (month == date.month && day > date.day)
	{
		return true;
	}
	return false;
}
Date::~Date()
{
	exit;
}


//class project
Project::Project()
{
	duration = 0;
	cost = 0;
	num_emp = 0;
	prj_type = 'I';
}
Project::Project(Project& p)
{
	this->cost = p.cost;
	this->duration = p.duration;
	this->end_dt = p.end_dt;
	this->num_emp = p.num_emp;
	this->prj_det = p.prj_det;
	this->prj_type = p.prj_type;
	this->str_dt = p.str_dt;
	this->title = p.title;
}
void Project::setTitle(string t)
{
	title = t;
}
void Project::setCost(double d)
{
	if (getPrjType() == 'I')
	{
		cost = d;
	}
	else if (getPrjType() == 'T')
	{
		cost = d;
	}
}
void Project::setStrDate()
{
	cout << "Enter starting date of project as (D M Y)" << endl;
	cin >> str_dt;
}
void Project::setStrDate(int d, int m, int y)
{
	str_dt.setDate(d, m, y);
}
void Project::setEndDate()
{
	cout << "Enter ending date of project as (D M Y)" << endl;
	cin >> end_dt;
}
void Project::setEndDate(int d, int m, int y)
{
	end_dt.setDate(d, m, y);
}
void Project::setPrjDetails(string d)
{
	prj_det = d;
}
void Project::setPrjType(char c)
{
	prj_type = c;
}
void Project::setNumEmp(int e)
{
	num_emp = e;
	if (num_emp == 1)
	{
		prj_type == 'I';
	}
	else
	{
		prj_type == 'T';
	}
}
string Project::getTitle()const
{
	return title;
}
double Project::getCost()const
{
	return cost;
}
Date Project::getStrDate()const
{
	return str_dt;
}
Date Project::getEndDate()const
{
	return end_dt;
}
string Project::getPrjDetails()const
{
	return prj_det;
}
int Project::getNumEmp()const
{
	return num_emp;
}
void Project::calculateDuration()
{
	duration = str_dt - end_dt;
}
void Project::setDuration(int d)
{
	duration = d;
}
int Project::getDuration()const
{
	return duration;
}
char Project::getPrjType()const
{
	if (num_emp == 1)
	{
		return 'I';
	}
	else { return 'T'; }
}
void Project::equalTo(Project* p)
{
	this->cost = p->cost;
	this->duration = p->duration;
	this->end_dt = p->end_dt;
	this->num_emp = p->num_emp;
	this->prj_det = p->prj_det;
	this->prj_type = p->prj_type;
	this->str_dt = p->str_dt;
	this->title = p->title;
}
void Project::printProjectDetails()
{
	cout << " Project Type  : " << prj_type << endl;
	cout << " Project Title : " << title << endl;
	cout << " Project Cost  : " << cost << endl;
	cout << " Start Date    : " << str_dt << endl;
	cout << " End Date      : " << end_dt << endl;
}
Project::~Project()
{
	exit;
}

//class Employee
string Person::getEmp_name()const
{
	return emp_name;
}
void Person::setEmp_name(string n)
{
	emp_name = n;
}
void Person::setEmp_id(int id)
{
	emp_id = id;
}
int Person::getEmp_id()const
{
	return emp_id;
}
double Person::getEmp_salary()const
{
	return emp_salary;
}
void Person::setEmp_salary(double sl)
{
	emp_salary = sl;

}

// class Manager
string Manager::getdep_name()const
{
	return dpt_name;
}
void Manager::setdpt_name(string n)
{
	dpt_name = n;
}
void Manager::addBonus(double sl)
{
	emp_salary = Person::getEmp_salary() + sl;
}

//class worker
Worker::Worker()
{
	emp_id = 0;
	emp_salary = 0;
	assigned = false;

	emp_name = "\0";
	dpt_name = "\0";
}
Worker::Worker(int id, double sl, bool as)
{
	emp_id = id;
	emp_salary = sl;
	assigned = as;
}
string Worker::getdep_name()const
{
	return dpt_name;
}
void Worker::setdpt_name(string n)
{
	dpt_name = n;
}
void Worker::setPrjassigned(Project* obj)
{
	assigned = true;
	this->prj_assigned = obj;
}
void Worker::setPrjType(char t)
{
	prj_type = t;
}
char Worker::getPrjType()const
{
	return prj_type;
}
bool Worker::getassignCheck()const
{
	return assigned;
}
void Worker::setassignedCheck(bool c)
{
	assigned = c;
}
void Worker::printWorkerData()
{
	if (assigned)
	{
		cout << "-------------------------------------------------" << endl;
		cout << " ID            : " << emp_id << endl;
		cout << " Worker Name   : " << emp_name << endl;
		cout << " Worker Salary : " << emp_salary << endl;
		cout << endl;
		cout << "Proejct Details" << endl;
		prj_assigned->printProjectDetails();
		cout << "-------------------------------------------------" << endl;
	}
	else
	{
		cout << "-------------------------------------------------" << endl;
		cout << " ID            : " << emp_id << endl;
		cout << " Worker Name   : " << emp_name << endl;
		cout << " Worker Salary : " << emp_salary << endl;
		cout << "Not working on any project " << endl;
		cout << "-------------------------------------------------" << endl;
	}

}
Worker::~Worker()
{
	delete[]prj_assigned;
}


//class depertment
department::department()
{
	string n;
	total_emp = 0;
	count_projects = 0;
	emp_working = 0;
	total_cst = 0;
	emp_available = total_emp;
}
void department::addWorkerDetails()
{
	int t;
	double sl;
	string n, p;
	bool c = true;
	emp[total_emp] = new Worker;
	cout << "Enter Id of new Employee : " << endl;
jump:
	cin >> t;

	for (int i = 0; i < total_emp; i++)
	{
		if (emp[i]->getEmp_id() == t)
		{
			cout << "This ID has already assigned " << endl;
			cout << "Give another ID " << endl;
			c = false;
			goto jump;
		}
	}
	if (c)
	{
		emp[total_emp]->setEmp_id(t);
		cout << "Set Employee Password : ";
		cin >> p;
		emp[total_emp]->setemp_pass(p);
		cout << endl;
		cout << "Enter name of new Employee : " << endl;
		cin.ignore();
		getline(cin, n);
		emp[total_emp]->setEmp_name(n);
		cout << "Enter Employee Salary : " << endl;
		cin >> sl;
		emp[total_emp]->setEmp_salary(sl);
		emp[total_emp]->setdpt_name(this->dpt_name);
		emp_available++;
		total_emp++;
	}

}
void department::addWorkerDetails(string n, int t, double s, string p)
{
	emp[total_emp] = new Worker;
	emp[total_emp]->setEmp_id(t);
	emp[total_emp]->setEmp_name(n);
	emp[total_emp]->setemp_pass(p);
	emp[total_emp]->setdpt_name(this->dpt_name);
	emp[total_emp]->setEmp_salary(s);
	emp_available++;
	total_emp++;
}
void department::addManagerDetails()
{
	string n;
	string p;
	int tm;
	cout << "Enter name of new Manager : " << endl;
	cin.ignore();
	getline(cin, n);
	dptManager.setEmp_name(n);
	cout << "Enter id of Manager : ";
	cin >> tm;
	dptManager.setEmp_id(tm);
	cout << endl;
	cout << "Set Manager's Password : ";
	cin >> p;
	dptManager.setemp_pass(p);
	cout << endl;
}
void department::addManagerDetails(string n, double s, string p, int id)
{
	dptManager.setEmp_id(id);
	dptManager.setemp_pass(p);
	dptManager.setEmp_name(n);
	dptManager.setEmp_salary(s);
}
void department::recieveProject(Project* p)
{
	if (count_projects < 10)
	{
		if (this->emp_available >= p->getNumEmp())
		{
		jump1:
			prjs[count_projects].equalTo(p);
			count_projects++;
		}
		else if (emp_available == 0)
		{
			cout << "This department don't have enough number of employees available" << endl;
		}
		else
		{
			int emp = 0;
			int idx = 0;
			int loop = 0;
			char choice = '\0';
			cout << "This department don't have enough number of employees available" << endl;
			Date temp, temp1;

		jump:
			temp = prjs[0].getEndDate();
			for (int i = 1; i < count_projects; i++)
			{
				if (prjs[i].getEndDate() < temp)
				{
					if (temp == temp1)
					{
						continue;
					}
					else
					{
						temp = prjs[i].getEndDate();
						idx = i;
						loop++;
					}
				}
			}
			if (this->emp_working == 0)
			{
				goto end;
			}
			else if (prjs[idx].getNumEmp() <= p->getNumEmp())
			{
				cout << "Your project will be in progess from " << temp << endl;
			}
			else if (prjs[idx].getNumEmp() <= p->getNumEmp())
			{
				if (loop < count_projects)
				{
					temp = temp1;
					goto jump;
				}
			}
			cout << "";
			cout << "Do you want to place project in the queue press 'Y' or press any key to move on" << endl;
			cin >> choice;
			if (toupper(choice) == 'Y')
			{
				goto jump1;
			}
		}
	}
	else { cout << "This department can't take more projects" << endl; }
end:
	cout << "";
}
void department::assignProject(string title)
{
	bool check = false;
	int tempi;
	int j;
	for (j = 0; j < count_projects; j++)
	{
		if (prjs[j].getTitle() == title)
		{
			if (prjs[j].getNumEmp() <= emp_available)
			{
				check = true;
				break;
			}
		}
	}
	if (check)
	{
		check = false;

		for (int i = 0; i < prjs[j].getNumEmp(); i++)
		{
		jump:
			cout << "Enter " << i + 1 << " Employee id to assign project" << endl;
			cin >> tempi;
			int k;
			for (k = 0; k < emp_available; k++)
			{
				if (!emp[k]->getassignCheck())
				{
					if (emp[k]->getEmp_id() == tempi)
					{
						check = true;
						break;
					}
				}
			}
			if (!check)
			{
				cout << "No such Employee available" << endl;
				cout << "Enter the correct id" << endl;
				goto jump;
			}
			else
			{
				emp[k]->setPrjassigned(&prjs[j]);
				emp[k]->setPrjType(prjs[j].getPrjType());
				emp[k]->setassignedCheck(true);
				emp_working++;
				emp_available--;
			}
		}
	}
}
double department::calculateTotalCost()
{
	total_cst = 0;
	for (int i = 0; i < count_projects; i++)
	{
		total_cst += prjs[i].getCost();
	}
	return total_cst;
}
double department::calculateSalary()
{
	double salary = 0;
	for (int i = 0; i < total_emp; i++)
	{
		salary += emp[i]->getEmp_salary();
	}
	return salary;
}
string department::getDptName() const { return dpt_name; }
void department::setDptName(string n) { dpt_name = n; }
void department::addManagerBonus(double b)
{
	dptManager.addBonus(b);
}
void department::getProjectDetails()
{
	for (int i = 0; i < this->count_projects; i++)
	{
		cout << "-------------------------------------------------" << endl;
		this->prjs[i].printProjectDetails();
		cout << "-------------------------------------------------" << endl;
	}
}
void department::printDepartmentData()
{
	cout << "-------------------------------------------------" << endl;
	cout << "Department Name                  : " << this->dpt_name << endl;
	cout << "Total Number of Employee         : " << this->total_emp << endl;
	cout << "Number of Employees available    : " << this->emp_available << endl;
	cout << "Number of projects taken         : " << this->count_projects << endl;
	cout << "Total Revenue Generated Till Now : " << calculateTotalCost() << endl;
	cout << "Employees working on projects    : ";
	if (this->emp_working < 0)
	{
		cout << -(this->emp_working);
	}
	else
	{
		cout << this->emp_working;
	}
	cout << endl << endl << "PROJECTS : " << endl;
	int co = 0;
	for (int i = 0; i < this->count_projects; i++)
	{
		this->prjs[i].printProjectDetails();
		co++;
	}
	if (co == 0)
	{
		cout << "This department has no project assigned yet" << endl;
	}
	cout << endl << endl << "EMPLOYEES : " << endl;
	co = 0;
	for (int i = 0; i < this->total_emp; i++)
	{
		if (this->emp[i]->getassignCheck())
		{
			this->emp[i]->printWorkerData();
			co++;
		}
	}
	if (co == 0)
	{
		cout << "No employee has assigned any project yet" << endl;
	}
	cout << "-------------------------------------------------" << endl;
}
int department::getProjectCount() const { return count_projects; }
department::~department()
{
	delete[]emp;
}


//class company 
company::company(string n)
{
	name = n;
	cmp_ceo.setEmp_id(123);
	cmp_ceo.setemp_pass("abc");
}
void company::addDepartment(string temps, string temps1, double sal, string p, int i)
{
	dpt[dpt_count] = new department;
	dpt[dpt_count]->addManagerDetails(temps1, sal, p, i);
	dpt[dpt_count]->setDptName(temps);
	dpt_count++;
}
void company::printCompanyData()
{
	cout << "\t\t" << name << endl << endl;
	cout << "Number of departments : " << dpt_count << endl;
	cout << "---------------------------------------------------------------" << endl;
	for (int i = 0; i < dpt_count; i++)
	{
		viewDepartment(dpt[i]->getDptName());
		cout << "---------------------------------------------------------------" << endl;
	}
}
string company::getName() const { return name; }
void company::setName(string m) { name = m; }
char company::CompanyMenu(int tasks, string arrname[4])
{

	char option;
	char ch = 205, ch1 = 201, ch2 = 200, ch3 = 187, ch4 = 188, ch5 = 204, ch6 = 185, ch7 = 186;

	int rs = (39 - strlen(name.c_str()) + 1) / 2;

	cout << "\t" << string(rs, ' ') << ch1;

	for (int x = 0; x <= strlen(name.c_str()) + 1; x++)
	{
		cout << ch;
	}
	cout << ch3 << endl;

	cout << "\t" << string(rs, ' ') << ch7 << " " << name << " " << ch7 << endl;

	cout << "\t" << string(rs, ' ') << ch2;
	for (int x = 0; x <= strlen(name.c_str()) + 1; x++)
	{
		cout << ch;
	}
	cout << ch4 << endl;


	cout << "\t" << ch1;
	for (int x = 0; x <= 13; x++)
	{
		cout << ch;
	}
	cout << "  MAIN MENU  ";
	for (int x = 0; x <= 13; x++)
	{
		cout << ch;
	}
	cout << ch3 << endl;

	{
		for (int x = 0; x < tasks; x++)
		{
			if (x == 9)
			{
				cout << "\t" << ch7 << "Press [" << 0 << "] to " << arrname[x] << " \t  " << ch7 << endl;
			}
			else
				cout << "\t" << ch7 << "Press [" << x + 1 << "] to " << arrname[x] << " \t  " << ch7 << endl;
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
void company::viewDepartment(string nm)
{
	for (int i = 0; i < dpt_count; i++)
	{
		if (dpt[i]->getDptName() == nm)
		{
			dpt[i]->printDepartmentData();
		}
	}
}
int company::getDpt_count() const { return dpt_count; }
