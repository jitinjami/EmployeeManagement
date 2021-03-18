#include <iostream>
#include <ctime>

using namespace std;
bool date_check(int date[3]) //Date checking (Born after 1900)
{
    if (date[2] > 1900)
    {
        if (date[1]==1 || date[1]==3 || date[1]==5 || date[1]==7 || date[1]==8 || date[1]==10 || date[1]==12)
        {
            if (date[0] <= 31)
            {
                return 1;
            }
            else
            {
                return 0;
            }
        }
        else if (date[1]==4 || date[1] == 6 || date[1] == 9 || date[1] == 11)
        {
            if (date[0] <=30)
            {
                return 1;
            }
            else
            {
                return 0;
            }
        }
        else if (date[1] == 2)
        {
            if (date[0] <=28)
            {
                return 1;
            }
            else
            {
                return 0;
            }
        }
        else
        {
            return 0;
        }
    }
    else
    {
        return 0;
    }
}
class Employee //Employee class
{
private:
    string forename; //First name
    string surname; //Last name
protected:
    int type; //Type of employee
    int no_of_holidays; //No of holidays given
    int holidays_taken; //No. of holidays taken
public:
    int dob[3]; //Birthday
    Employee() {}; //Constructor 1
    Employee(string f, string s) : forename(f), surname(s) //Constructor 2
    {
        type = 0;
    };
    string get_forename() //Getter for forename
    {
        return forename;
    }
    string get_surname() //Getter for surname
    {
        return surname;
    }
    int get_no_of_holidays() //Getter for no. of holidays
    {
        return no_of_holidays;
    }
    int get_holidays_taken() //Getter for holidays taken
    {
        return holidays_taken;
    }
    int get_type() //Getter for type of employee
    {
        return type;
    }
    void display_details() //Display details
    {
        cout << "First name:" << forename << endl;
        cout << "Last name:" << surname << endl;
        int rem = no_of_holidays - holidays_taken;
        cout << "Remaining Holidays:" << rem << endl;
        cout << "Date of birth: " << dob[0] << "/" << dob[1] << "/" << dob[2] << endl;
    }
    void take_a_holiday() //For employee to take a holiday
    {
        int holiday;
        int rem = no_of_holidays - holidays_taken;
        cout << "Please enter no. of days the employee wants to avail leave" << endl;
        cin >> holiday;
        if (holiday <= rem)
        {
            holidays_taken+=holiday;
            cout << "Leave approved" << endl;
        }
        else
        {
            cout << "Not enough remaining leaves. Please try again." << endl;
        }
    }
    void set_no_of_holidays(int no) // setting number of holidays
    {
        no_of_holidays = no;
    }
};
class HourlyEmployee: public Employee //Hourly employee
{
private:
    float hourly_wage; //Hourly wage
    int hours_worked; //No. of hours worked
public:
    HourlyEmployee(string f, string s, int w) : Employee(f,s),hourly_wage(w) //Contructor
    {
        type = 3;
        no_of_holidays = 30;
        holidays_taken = 0;
        hours_worked = 0;
    };
    float get_hourly_wage()
    {
        return hourly_wage;
    }
    int get_hours_worked()
    {
        return hours_worked;
    }
    void display_details()
    {
        cout << "First name:" << get_forename() << endl;
        cout << "Last name:" << get_surname() << endl;
        int rem = no_of_holidays - holidays_taken;
        cout << "Remaining Holidays:" << rem << endl;
        cout << "Date of birth: " << dob[0] << "/" << dob[1] << "/" << dob[2] << endl;

        cout << "Hourly wage:" << hourly_wage << endl;
        cout << "Hours worked:" << hours_worked << endl;
    }
};
class SalariedEmployee: public Employee //Salaried Employee
{
private:
    float annual_salary; //Annual Salary
public:
    SalariedEmployee(string f, string s, float as) : Employee(f,s),annual_salary(as)
    {
        type=2;
        no_of_holidays = 30;
        holidays_taken = 0;
    };
    float get_annual_salary()
    {
        return annual_salary;
    }
    void display_details()
    {
        cout << "First name:" << get_forename() << endl;
        cout << "Last name:" << get_surname() << endl;
        int rem = no_of_holidays - holidays_taken;
        cout << "Remaining Holidays:" << rem << endl;
        cout << "Date of birth: " << dob[0] << "/" << dob[1] << "/" << dob[2] << endl;

        cout << "Annual Salary:" << annual_salary << endl;
    }
};
class Manager: public Employee //Manager
{
private:
    float profit_sharing; // Profit sharing

public:
    Manager(string f, string s, float ps) : Employee(f,s),profit_sharing(ps)
    {
        type=1;
        holidays_taken = 0;
        no_of_holidays = 30;
    };
    float get_profit_sharing()
    {
        return profit_sharing;
    }
    void display_details()
    {
        cout << "First name:" << get_forename() << endl;
        cout << "Last name:" << get_surname() << endl;
        int rem = no_of_holidays - holidays_taken;
        cout << "Remaining Holidays:" << rem << endl;
        cout << "Date of birth: " << dob[0] << "/" << dob[1] << "/" << dob[2] << endl;

        cout << "Profit Sharing:" << profit_sharing << endl;
    }
};

Employee employees[500]; //Initiating object list for 500 employees
int today[3]; //array for storing current date

int search_empty(Employee em[500]) //Seatch for an employee
{
    int i=0;
    while (i<501)
    {
        if (em[i].get_forename() == "")
        {
            break;
        }
        i++;
    }
    return i;
}
int search_emp(Employee em[500]) //Search for an empty spot on the employee list
{
    int i=0;
    string fname, sname;
    cout << "Please enter the forename of the employee you would like to search for: ";
    cin >> fname;
    cout << "Now enter the surname: ";
    cin >> sname;
    while (i<501)
    {
        if (em[i].get_forename() == fname && em[i].get_surname() == sname)
        {
            em[i].display_details();
            break;
        }
        i++;
    }
    return i;
}
void create(Employee em[500]) //Create any kind of employee
{
    int employee_id = search_empty(em);
    cout << "The new employee will be added to the next available employee index: " << employee_id << endl;
    int index;
    string fname,sname;
    float prof, ann_sar, h_wage;
    bool datecheck2 = 0, index_check = 0;

    cout << "To create an employee we need to know if its a Manager [1], Salaried Employee [2], Hourly Employee [3]" << endl;
    do
    {
        cout << "Please enter the appropriate number: ";
        cin >> index;
        if (index != 1 && index !=2 && index !=3)
        {
            cout << "Please enter either 1 or 2 or 3."<<endl;
            index_check = 0;
        }
        else
        {
            index_check = 1;
        }
    }
    while (index_check == 0);
    switch(index)
    {
    case 1:
        cout << "You have chosen Manager." << endl;
        cout << "Please enter forename: ";
        cin >> fname;
        cout << "Please enter surname: ";
        cin >> sname;
        cout << "Please enter profit sharing percentage: ";
        cin >> prof;
        em[employee_id] = Manager(fname,sname,prof);
        cout << "Please enter date of birth in DDMMYYYY format." << endl;
        do
        {
            cout << "Date: ";
            cin >> em[employee_id].dob[0];
            cout << "Month: ";
            cin >> em[employee_id].dob[1];
            cout << "Year: ";
            cin >> em[employee_id].dob[2];
            datecheck2 = date_check(em[employee_id].dob);
            if (datecheck2 == 0)
            {
                cout << "Please enter appropriate date." << endl;
            }
        }
        while(datecheck2 == 0);
        if (today[2] - em[employee_id].dob[2] > 50)
        {
            em[employee_id].set_no_of_holidays(32);
        }
        break;
    case 2:
        cout << "You have chosen Salaried Employee." << endl;
        cout << "Please enter forename: ";
        cin >> fname;
        cout << "Please enter surname: ";
        cin >> sname;
        cout << "Please enter annual salary: ";
        cin >> ann_sar;
        em[employee_id] = SalariedEmployee(fname,sname,ann_sar);
        cout << "Please enter date of birth in DDMMYYYY format." << endl;
        do
        {
            cout << "Date: ";
            cin >> em[employee_id].dob[0];
            cout << "Month: ";
            cin >> em[employee_id].dob[1];
            cout << "Year: ";
            cin >> em[employee_id].dob[2];
            datecheck2 = date_check(em[employee_id].dob);
            if (datecheck2 == 0)
            {
                cout << "Please enter appropriate date." << endl;
            }
        }
        while(datecheck2 == 0);
        if (today[2] - em[employee_id].dob[2] > 50)
        {
            em[employee_id].set_no_of_holidays(32);
        }
        break;
    case 3:
        cout << "You have chosen Hourly Employee." << endl;
        cout << "Please enter forename: ";
        cin >> fname;
        cout << "Please enter surname: ";
        cin >> sname;
        cout << "Please enter hourly wage: ";
        cin >> h_wage;
        em[employee_id] = HourlyEmployee(fname,sname,h_wage);
        cout << "Please enter date of birth in DDMMYYYY format." << endl;
        do
        {
            cout << "Date: ";
            cin >> em[employee_id].dob[0];
            cout << "Month: ";
            cin >> em[employee_id].dob[1];
            cout << "Year: ";
            cin >> em[employee_id].dob[2];
            datecheck2 = date_check(em[employee_id].dob);
            if (datecheck2 == 0)
            {
                cout << "Please enter appropriate date." << endl;
            }
        }
        while(datecheck2 == 0);
        if (today[2] - em[employee_id].dob[2] > 50)
        {
            em[employee_id].set_no_of_holidays(32);
        }
        break;
    }
}
void delete_employee(Employee em[500]) //Delete an employee by searhing firstname and lastname
{
    int i=0;
    string fname, sname;
    cout << "Please enter the forename of the employee you would like to delete: ";
    cin >> fname;
    cout << "Now enter the surname of the employee: ";
    cin >> sname;

    while (i<501)
    {
        if (em[i].get_forename() == fname && em[i].get_surname() == sname)
        {
            cout << "Employee (" << fname << ", " << sname << ") will be deleted from index: " << i << endl;
            em[i] = Employee("","");
            break;
        }
        i++;
    }
}
void list_emp(Employee em[500]) //List details of all employees
{
    cout << "Id no.\tType of Employee\tForename\tSurname\tDate of Birth\tNo. of leaves taken" << endl;
    string type;
    for (int i=0; i<500; i++)
    {
        if (em[i].get_type() == 1 && em[i].get_forename() != "")
        {
            cout << i << "\tManager" << "\t" << em[i].get_forename() << "\t" << em[i].get_surname() << "\t" << em[i].dob[0] << "/" << em[i].dob[1] << "/" << em[i].dob[2] << "\t" << em[i].get_holidays_taken() << endl;
        }
        else if (em[i].get_type() == 2 && em[i].get_forename() != "")
        {
            cout << i << "\tSalaried Employee" << "\t" << em[i].get_forename() << "\t" << em[i].get_surname() << "\t" << em[i].dob[0] << "/" << em[i].dob[1] << "/" << em[i].dob[2] << "\t" << em[i].get_holidays_taken() << endl;
        }
        else if (em[i].get_type() == 3 && em[i].get_forename() != "")
        {
            cout << i << "\tHourly Employee" << "\t" << em[i].get_forename() << "\t" << em[i].get_surname() << "\t" << em[i].dob[0] << "/" << em[i].dob[1] << "/" << em[i].dob[2] << "\t" << em[i].get_holidays_taken() << endl;
        }
    }
}
int main()
{
    cout << "Welcome to staff management system. Please enter todays date in DDMMYYYY." << endl;;
    bool datecheck = 0;
    do
    {
        cout << "Date: ";
        cin >> today[0];
        cout << "Month: ";
        cin >> today[1];
        cout << "Year: ";
        cin >> today[2];
        datecheck = date_check(today);
        if (datecheck == 0)
        {
            cout << "Please enter appropriate date." << endl;
        }
    }
    while(datecheck == 0);
    bool done = 0;
    do
    {

        cout << "What would you like to do today?\n1. Create an employee\n2. Delete an employee\n3. Take holiday for an employee.\n4. Search for an employee.\n5. List all employee records." << endl;
        int c,s;
        cin >> c;
        switch(c)
        {
        case 1:
            create(employees);
            break;
        case 2:
            delete_employee(employees);
            break;
        case 3:
            s = search_emp(employees);
            employees[s].take_a_holiday();
            break;
        case 4:
            search_emp(employees);
            break;
        case 5:
            list_emp(employees);
            break;
        }
        cout << "Are you done? Type 1 for yes, 0 for no" << endl;
        cin >> done;
    }
    while(done == 0);
    return 0;
}
