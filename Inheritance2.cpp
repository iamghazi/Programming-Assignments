/* INPUT/OUTPUT:


Enter your choice:
1)HourlyEmployee
2)SalariedEmployee
3)TemporaryEmployee
4)AdministrativeEmployee
5)PermanentEmployee
4

_____________________________________________
Pay to the order of Mr. Drake Shot
The sum of 10500.5 Dollars
_____________________________________________
Check Stub: NOT NEGOTIABLE
Employee Number: 987-65-4321
Administrative Employee. 
Salary: 10500.5 Pay: 10500.5
_____________________________________________
Perform operation again?Enter: 1 or 0 to exit
1
Enter your choice:
1)HourlyEmployee
2)SalariedEmployee
3)TemporaryEmployee
4)AdministrativeEmployee
5)PermanentEmployee
2

_____________________________________________
Pay to the order of Mr. Big Shot
The sum of 10500.5 Dollars
_____________________________________________
Check Stub: NOT NEGOTIABLE
Employee Number: 987-65-4321
Salaried Employee. 
Salary: 10500.5 Pay: 10500.5
_____________________________________________
Perform operation again?Enter: 1 or 0 to exit
0
 */

#include<iostream>
#include<string>
using namespace std;
class Employee
{
  public:
    Employee( );
    Employee(string the_name, string the_ssn);
    string get_name( ) const;
    string get_ssn( ) const;
    double get_net_pay( ) const;
    void set_name(string new_name);
    void set_ssn(string new_ssn);
    void set_net_pay(double new_net_pay);
    void print_check( ) const;
  private:
    string name;
    string ssn;
    double net_pay;
};
Employee::Employee( ) : name("No name yet"), ssn("No number yet"), net_pay(0)
{
    //deliberately empty
}
Employee::Employee(string the_name, string the_number): name(the_name), ssn(the_number), net_pay(0)
{
    //deliberately empty
}
string Employee::get_name( ) const
{
  return name;
}
string Employee::get_ssn( ) const
{
  return ssn;
}
double Employee::get_net_pay( ) const
{
  return net_pay;
}
void Employee::set_name(string new_name)
{
  name = new_name;
}
void Employee::set_ssn(string new_ssn)
{
  ssn = new_ssn;
}
void Employee::set_net_pay (double new_net_pay)
{
  net_pay = new_net_pay;
}
void Employee::print_check( ) const
{
  cout << "\nERROR: print_check FUNCTION CALLED FOR AN \n"<< "UNDIFFERENTIATED EMPLOYEE. Aborting the program.\n"<<"Check with the author of the program about this bug.\n";
  exit(1);
}

//-------------HourlyEmployee---------------//

class HourlyEmployee : public Employee
{
  public:
    HourlyEmployee( );
    HourlyEmployee(string the_name, string the_ssn,double the_wage_rate, double the_hours);
    void set_rate(double new_wage_rate);
    double get_rate( ) const;
    void set_hours(double hours_worked);
    double get_hours( ) const;
    void print_check( );
  private:
    double wage_rate;
    double hours;
};
HourlyEmployee::HourlyEmployee( ) : Employee( ), wage_rate(0), hours(0)
{
    //deliberately empty
}
HourlyEmployee::HourlyEmployee(string the_name, string the_number,double the_wage_rate, double the_hours): Employee(the_name, the_number), wage_rate(the_wage_rate), hours(the_hours)
{
    //deliberately empty
}

void HourlyEmployee::set_rate(double new_wage_rate)
{
  wage_rate = new_wage_rate;
}
double HourlyEmployee::get_rate( ) const
{
  return wage_rate;
}
void HourlyEmployee::set_hours(double hours_worked)
{
  hours = hours_worked;
}
double HourlyEmployee::get_hours( ) const
{
  return hours;
}

void HourlyEmployee::print_check( )
{
  set_net_pay (hours * wage_rate);
  cout << "\n_____________________________________________\n";
  cout << "Pay to the order of "<< get_name( ) << endl;
  cout << "The sum of " << get_net_pay( ) << " Dollars\n";
  cout << "_____________________________________________\n";
  cout << "Check Stub: NOT NEGOTIABLE\n";
  cout << "Employee Number: " << get_ssn( ) << endl;
  cout << "Hourly Employee. \nHours worked: " << hours<< " Rate: " << wage_rate << " Pay: " << get_net_pay( ) << endl;
  cout << "_____________________________________________\n";
}

//------------------SalariedEmployee----------------//

class SalariedEmployee : public Employee
{
  public:
    SalariedEmployee( );
    SalariedEmployee (string the_name, string the_ssn,double the_weekly_salary);
    double get_salary( ) const;
    void set_salary(double new_salary);
    void print_check( );
  private:
    double salary;//weekly
};
SalariedEmployee::SalariedEmployee( ) : Employee( ), salary(0)
{
    //deliberately empty
}
SalariedEmployee::SalariedEmployee(string the_name, string the_number,double the_weekly_salary): Employee(the_name, the_number), salary(the_weekly_salary)
{
    //deliberately empty
}
void SalariedEmployee::set_salary(double new_salary)
{
  salary = new_salary;
}
double SalariedEmployee::get_salary( ) const
{
  return salary;
}
void SalariedEmployee::print_check( )
{
  set_net_pay (salary);
  cout << "\n_____________________________________________\n";
  cout << "Pay to the order of "<< get_name( ) << endl;
  cout << "The sum of " << get_net_pay( ) << " Dollars\n";
  cout << "_____________________________________________\n";
  cout << "Check Stub: NOT NEGOTIABLE\n";
  cout << "Employee Number: " << get_ssn( ) << endl;
  cout << "Salaried Employee. \nSalary: " << salary << " Pay: " << get_net_pay( ) << endl;
  cout << "_____________________________________________\n";
}


//------------------TemporaryEmployee----------------//

class TemporaryEmployee : public Employee
{
  public:
    TemporaryEmployee( );
    TemporaryEmployee (string the_name, string the_ssn,double the_weekly_salary);
    double get_salary( ) const;
    void set_salary(double new_salary);
    void print_check( );
  private:
    double salary;//weekly
};
TemporaryEmployee::TemporaryEmployee( ) : Employee( ), salary(0)
{
    //deliberately empty
}
TemporaryEmployee::TemporaryEmployee(string the_name, string the_number,double the_weekly_salary): Employee(the_name, the_number), salary(the_weekly_salary)
{
    //deliberately empty
}
void TemporaryEmployee::set_salary(double new_salary)
{
  salary = new_salary;
}
double TemporaryEmployee::get_salary( ) const
{
  return salary;
}
void TemporaryEmployee::print_check( )
{
  set_net_pay (salary);
  cout << "\n_____________________________________________\n";
  cout << "Pay to the order of "<< get_name( ) << endl;
  cout << "The sum of " << get_net_pay( ) << " Dollars\n";
  cout << "_____________________________________________\n";
  cout << "Check Stub: NOT NEGOTIABLE\n";
  cout << "Employee Number: " << get_ssn( ) << endl;
  cout << "Temporary Employee. \nSalary: " << salary << " Pay: " << get_net_pay( ) << endl;
  cout << "_____________________________________________\n";
}


//------------------AdministrativeEmployee----------------//

class AdministrativeEmployee : public Employee
{
  public:
    AdministrativeEmployee( );
    AdministrativeEmployee (string the_name, string the_ssn,double the_weekly_salary);
    double get_salary( ) const;
    void set_salary(double new_salary);
    void print_check( );
  private:
    double salary;//weekly
};
AdministrativeEmployee::AdministrativeEmployee( ) : Employee( ), salary(0)
{
    //deliberately empty
}
AdministrativeEmployee::AdministrativeEmployee(string the_name, string the_number,double the_weekly_salary): Employee(the_name, the_number), salary(the_weekly_salary)
{
    //deliberately empty
}
void AdministrativeEmployee::set_salary(double new_salary)
{
  salary = new_salary;
}
double AdministrativeEmployee::get_salary( ) const
{
  return salary;
}
void AdministrativeEmployee::print_check( )
{
  set_net_pay (salary);
  cout << "\n_____________________________________________\n";
  cout << "Pay to the order of "<< get_name( ) << endl;
  cout << "The sum of " << get_net_pay( ) << " Dollars\n";
  cout << "_____________________________________________\n";
  cout << "Check Stub: NOT NEGOTIABLE\n";
  cout << "Employee Number: " << get_ssn( ) << endl;
  cout << "Administrative Employee. \nSalary: " << salary << " Pay: " << get_net_pay( ) << endl;
  cout << "_____________________________________________\n";
}

//------------------PermanentEmployee----------------//

class PermanentEmployee : public Employee
{
  public:
    PermanentEmployee( );
    PermanentEmployee (string the_name, string the_ssn,double the_weekly_salary);
    double get_salary( ) const;
    void set_salary(double new_salary);
    void print_check( );
  private:
    double salary;//weekly
};
PermanentEmployee::PermanentEmployee( ) : Employee( ), salary(0)
{
    //deliberately empty
}
PermanentEmployee::PermanentEmployee(string the_name, string the_number,double the_weekly_salary): Employee(the_name, the_number), salary(the_weekly_salary)
{
    //deliberately empty
}
void PermanentEmployee::set_salary(double new_salary)
{
  salary = new_salary;
}
double PermanentEmployee::get_salary( ) const
{
  return salary;
}
void PermanentEmployee::print_check( )
{
  set_net_pay (salary);
  cout << "\n_____________________________________________\n";
  cout << "Pay to the order of "<< get_name( ) << endl;
  cout << "The sum of " << get_net_pay( ) << " Dollars\n";
  cout << "_____________________________________________\n";
  cout << "Check Stub: NOT NEGOTIABLE\n";
  cout << "Employee Number: " << get_ssn( ) << endl;
  cout << "Permanent Employee. \nSalary: " << salary << " Pay: " << get_net_pay( ) << endl;
  cout << "_____________________________________________\n";
}


int main( )
{
  int choice,op=1;
  HourlyEmployee joe("Mighty Joe","123-45-6789", 20.50, 40);
  SalariedEmployee boss("Mr. Big Shot","987-65-4321", 10500.50);
  TemporaryEmployee clay("Mr. Clay Soe","987-65-4321", 10500.50);
  AdministrativeEmployee drake("Mr. Drake Shot","987-65-4321", 10500.50);
  PermanentEmployee elf("Mr. elf steel","987-65-4321", 10500.50);
 
  
  while(op==1)
  {
    cout<<"Enter your choice:\n1)HourlyEmployee\n2)SalariedEmployee\n3)TemporaryEmployee\n4)AdministrativeEmployee\n5)PermanentEmployee\n";
    cin>>choice;
    if(choice==1)
    {
      joe.print_check();
    }
    else if(choice==2)
    {
      boss.print_check();
    }
    else if(choice==3)
    {
      clay.print_check();
    }
    else if(choice==4)
    {
      drake.print_check();
    }
    else if(choice==5)
    {
      elf.print_check();
    }
    else
    {
      cout<<"Enter valid choice\n";
    }
    cout<<"Perform operation again?Enter: 1 or 0 to exit\n";
    cin>>op;
}
 
 return 0;
}