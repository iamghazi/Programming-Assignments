#include<iostream>
#include<string>
using namespace std;

int OK=1,insufficientFunds=0;

class BankAccount                                           //Simple Bank Account class
{
	protected:
		string name;                                        //store name of Customer
		double balance;                                     //store balance in Account
	public:
		BankAccount()
		{
			name="NA";
			balance=0.0;
		}
		BankAccount(string accname,double accbalance)
		{
			name=accname;
			balance=accbalance;
		}
		void deposit(double amount)                         //Deposit function
		{
			balance+=amount;
		}
		virtual int withdraw(double amount)                 //withdraw function
		{
			if(amount<=balance)
			{
				balance-=amount;
				return OK;
			}
			else
			{
				cout<<"Insufficient Funds, Withdraw Denied"<<endl;
				return insufficientFunds;
			}
		}
		string getName()                                       //function to display name
		{
			return name;
		}
		double getBalance()                                     //function to display balance
		{
			return balance;
		}
};
class MoneyMarketAccount: public BankAccount                    //Money Market Account class
{
	private:
		int count=0;                                            //to store amount of withdraw
	public:
		MoneyMarketAccount()
		{
			name="NA";
			balance=0.0;
		}
		MoneyMarketAccount(string accname,double accbalance)
		{
			name=accname;
			balance=accbalance;
		}
		virtual int withdraw(double amount)                     //withdraw function
		{
			if(amount<=balance)
			{
				count++;
				if(count<=2)                                    //if count is less than 2 no charges deducted
					balance-=amount;
				else
				balance-=(amount+1.50);                         //for mor than two withdraws penalty
				return OK;
			}
			else
			{
				cout<<"Insufficient Funds, Withdraw Denied"<<endl;
				return insufficientFunds;
			}
			
		}
};
class CDAccount: public BankAccount                             //Credit of deposit account class
{
	private:
		double interestRate;                                    //to store rate of Interest
	public:
		CDAccount()
		{
			name="NA";
			balance=0.0;
			interestRate=0.0;
		}
		CDAccount(string accname,double accbalance,double rate)
		{
			name=accname;
			balance=accbalance;
			interestRate=rate;
		}
		double getInterestRate()                                //to access interest rate
		{
			return interestRate;
		}
		virtual int withdraw(double amount)                     //withdraw function
		{
			double penalty=0.25*(balance*interestRate/100);
			if((penalty+amount)<=balance)
			{
				balance-=(amount+penalty);
				return OK;
			}
			else
			{
				cout<<"Insufficient Funds, Withdraw Denied"<<endl;
				return insufficientFunds;
			}
		}
};
int transfer(double amount, BankAccount& acc1, BankAccount& acc2)       //function to transfer money from one account to another
{
	if(acc1.withdraw(amount)==OK)
	{
		acc2.deposit(amount);
		return OK;
	}
	else
	{
		cout<<"Insufficient Funds, Withdraw Denied"<<endl;
		return insufficientFunds;
	}
}
int main()                                                              //main function
{
	string str;
	int choice;
	double amt,i,tra;
	//take inputs for account
	cout<<"Lets set up three Different Bank Accounts (Basic Account, Money Market Account and Credit Deposit Account"<<endl;
	cout<<"Enter Name of Customer"<<endl;
	cin>>str;
	cout<<"Enter Balance for Basic Account"<<endl;
	cin>>amt;
	BankAccount acc1(str,amt);
	cout<<"Enter Balance for Money Market Account"<<endl;
	cin>>amt;
	MoneyMarketAccount acc2(str,amt);
	cout<<"Enter Balance and Interest Rate for Certificate of Deposit Account"<<endl;
	cin>>amt>>i;
	CDAccount acc3(str,amt,i);
	bool check=true;
	while(check)
	{
	    //show options
		cout<<endl<<"Press 1: To Check Account Details"<<endl;
		cout<<"Press 2: To Transfer Money from Basic Account to Money Market Account"<<endl;
		cout<<"Press 3: To Transfer Money from Basic Account to Certificate of Deposit Account"<<endl;
		cout<<"Press 4: To Transfer Money from Money Market Account to Basic Account"<<endl;
		cout<<"Press 5: To Transfer Money from Money Market Account to Certificate of Deposit Account"<<endl;
		cout<<"Press 6: To Transfer Money from Certificate of Deposit Account to Basic Account"<<endl;
		cout<<"Press 7: To Transfer Money from Certificate of Deposit Account to Money Market Account"<<endl;
		cout<<"Press 8: To Quit"<<endl;
		cin>>choice;
		switch(choice)
		{
			case 1:
				cout<<endl<<"			Account Holder Name: "<<acc1.getName()<<endl;
				cout<<"			Basic Account Balance: "<<acc1.getBalance()<<endl;
				cout<<"			Money Market Account Balance: "<<acc2.getBalance()<<endl;
				cout<<"			Certificate of Deposit Account Balance: "<<acc3.getBalance()<<endl;
				break;
			case 2:
				cout<<"Enter Amount to Transfer"<<endl;
				cin>>tra;
				transfer(tra,acc1,acc2);
				break;
			case 3:
				cout<<"Enter Amount to Transfer"<<endl;
				cin>>tra;
				transfer(tra,acc1,acc3);
				break;
			case 4:
				cout<<"Enter Amount to Transfer"<<endl;
				cin>>tra;
				transfer(tra,acc2,acc1);
				break;
			case 5:
				cout<<"Enter Amount to Transfer"<<endl;
				cin>>tra;
				transfer(tra,acc2,acc3);
				break;
			case 6:
				cout<<"Enter Amount to Transfer"<<endl;
				cin>>tra;
				transfer(tra,acc3,acc1);
				break;
			case 7:
				cout<<"Enter Amount to Transfer"<<endl;
				cin>>tra;
				transfer(tra,acc3,acc2);
				break;
			case 8:
				cout<<"Thank You"<<endl;
				check=false;
				break;
			default:
				cout<<"Invalid Input. Enter Again"<<endl;
		}
	}	
}
