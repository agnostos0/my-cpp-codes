
#include<iostream>
#include<string>
using namespace std;
class bankaccount{
    private:
    int accountnumber;
    double balance;
    string accountname;
    public:
      bankaccount(string name, int accNumber) {
        accountname = name;
        accountnumber = accNumber;
        balance = 0.0;
    }
    void checkBalance()  {
        cout << "Account Balance: Rs." << balance << std::endl;
    }
    void deposit(double amount) {
        if(amount>0){
            balance += amount;
            cout << "Deposited: Rs." << amount << std::endl;
        }
        else{
            cout<<"Invalid amount"<<endl;
        }

        }
        void withdraw(double amount) {
            if(amount<=balance && amount>0){
             balance-=amount;
             cout<<"withdrawed : Rs."<< amount<<endl;
             }
             else if(balance<amount)
             {
                cout<<"Insufficient balance"<<endl;
             }
             else{
                cout<<"Invalid amount"<<endl;
                }
        }
        void displayAccDetails()
            
        {   cout<<"Account Name: "<<accountname<<endl;
        cout<<"Account Number: "<<accountnumber<<endl;
        cout<<"Account Balance: Rs."<<balance<<endl;

        }
};
   
    int main()
    {
        bankaccount account("xyz", 9999);
        account.checkBalance();
        account.deposit(1000);
        account.checkBalance();
        account.withdraw(500);
        account.checkBalance();
        account.displayAccDetails();
    }