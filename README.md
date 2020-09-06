# Programming-Assignments
#include <iostream>
#include <string>
using namespace std;
class person
{
	private:
		string name;
	public:
		void set_names(string s)
	{
		name=s;
	}
		string 	get_names();
		person(string );
		person(person& );
		friend istream& operator>>(istream& , person&);
		friend ostream& operator<<(ostream&, person&);
};
person::person(string s)
{
	name=s;
}
person::person(person& p)
{
	name=p.name;
}

string person::get_names()
{
	return name;
}
istream& operator>>(istream &i, person &p)
	{
		getline(i,p.name);
		return i;
	}
ostream& operator<<(ostream &o, person &p)
{
	o<<p.name;
	return o;
}





class employees
{
	private:
		string name;
		string ssn;
		double net_pay;
	public:
		void set_name(string);
		string get_name();
		void set_ssn(string);
		string get_ssn();
		void set_netpay(double);
		double get_netpay();
		employees(string, string, double);
		
};
string employees::get_name()
		{
			return name;
		}
void employees::set_name(string s)
		{
			name=s;
		}
void employees::set_ssn(string s)
		{
			ssn=s;
		}
string employees::get_ssn()
		{
			return ssn;
		}
void employees::set_netpay(double x)
 	{
 		net_pay=x;
	 }
double employees::get_netpay()
	{
		return net_pay;
	}
employees::employees(string s1, string s2,double x=0)
{
	name=s1;
	ssn=s2;
	x=net_pay;
}




class salaried_employee: public employees
{
	private:
		double salary;
	public:
		salaried_employee(string s="N/A", string a="N/A", double x=0):employees(s,a,x)
		{
			salary=x;
		}
		void set_salary(double);
		double get_salary();
};
double salaried_employee::get_salary()
{
	return salary;
}
void salaried_employee::set_salary(double x)
{
	salary=x;
}




class doctor: public salaried_employee
{	
	private:
		string specialty;
		double visit_fee;
	public:
		void set_fee(double);
		double get_fee();
		void set_specialty(string);
		string get_specialty();
		doctor(string s="general practitioner",string s1="doctor",double x=100):salaried_employee(s1)
		{
			specialty=s;
			visit_fee=x;
		}
};
void doctor::set_fee(double x=0)
{
	visit_fee=x;
}
double doctor::get_fee()
{
	return visit_fee;
}
void doctor::set_specialty(string s="general practitioner")
{
	specialty=s;
}
string doctor::get_specialty()
{
	return specialty;
}
class patient: public person
{
	private:
		doctor physician;
	public:
		void set_docname(string s)
		{
			physician.set_name(s);
		}
		string get_docname()
		{
			return physician.get_name();
		}
		patient(string s,string s1="doctor", string s2="general practitioner"):person(s)
		{
			
			physician.set_name(s1);
			physician.set_specialty(s2);
		}
		patient(patient &p):person(p.get_names())
		{
			physician=p.physician;
			
		}
};
class billing
{
	private:
		doctor physician;
		patient p;
		double amount;
	public:
		void set_amount(double x)
		{
			amount=x;
		}
		double get_amount()
		{
			return amount;
		}
		void set_doc(string s, string s1="general practitioner", double x=100)
		{
			physician.set_name(s);
			physician.set_specialty(s1);
			physician.set_fee(x);
		}
		string get_doc()
		{
			return physician.get_name();
		}
		void set_patient(string s)
		{
			p.set_names(s);
		}
		string get_patient()
		{
			return p.get_names();
		}
		billing(string s1, string a, double x=100)
		{	p.set_names(s1);
			physician.set_name(a);
			amount=x;
		}
		billing(patient p,doctor d, double x=100)
		{
			this->p=p;
			physician=d;
			amount=x;
		}
		friend ostream& operator <<(ostream &o,billing &b)
		{
			o<<b.get_patient()<<endl<<b.get_doc()<<endl<<b.get_amount();
			return o;
		}
};

int main()
{
	doctor d1("pediatrician","name",250), d2("heart specialist","name",1000);
	patient p1("name","doctor","specialty"), p2("name", "doctor", "specialty");
	billing b1(d1,p1,300),b2(d2,p2,2000);
	cin>>n; //no. of billing records
	double amount[n],total;
	for(int i<n;i<0;i++)
	{
		cin<<amount[i];
		total=total+amount[i];
	}
	cout<<total;
}
