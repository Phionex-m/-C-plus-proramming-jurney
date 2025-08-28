#include <iostream>
using namespace std;
 class Account {
  private :
    int accountNumber ;
    double balance ;
  public :
    Account(int accountNumber , double balance){
        this->accountNumber = accountNumber ;
        this->balance = balance ;

    }
    void deposite(double amount);
    void withdraw(double amount);
    double getBalance();
    friend void display (Account acc );
 };

 void Account ::  deposite(double amount){
        cout << "Enter your deposite amount" << endl ;
        cin >> amount  ;
        balance += amount;
        cout << "Your New Balance Is " << balance << endl  ;

    }

  void Account :: withdraw(double amount){
        cout << "Enter your withdraw amount" << endl ;
        cin >> amount  ;
        if (amount <= balance ){
            balance -= amount ;
            cout << "Your New Balance Is " << balance << endl  ;

        }

        else {

          cout << "There isnot enough balance "<< endl;
        }
       
        
     }
    
  double Account :: getBalance(){
        return balance ;

    }

 void display (Account acc ){

  cout<< "Account Number " << acc.accountNumber << endl <<"Your Balance " <<  acc.balance << endl ;

}


 class SavingsAccount : public Account {
 private :
    double interestRate;
    
  public:
    SavingsAccount(int accountNumber, double balance, double rate) 
        : Account(accountNumber, balance) {
        interestRate = rate;
    } 
    
    void applyInterest() {
        double currentBalance = getBalance();
        double interest = currentBalance * interestRate;
        cout << "Interest applied: " << interest << endl;
        deposite(interest);
    }
    
    double getInterestRate() {
        return interestRate;
    }
};

int main(){
cout << "--Your account information " << endl ;
  Account b (12345678,5000);
  display(b);
  cout << "--Your saving account informations " << endl ; 
  SavingsAccount i (34567774,6000,0.15);
  display(i);

   int o;
    double amount;
    do{
    cout << "\n -Banking Menu " << endl;
    cout << "1. Deposit to Account" << endl;
    cout << "2. Withdraw from Account" << endl;
    cout << "3. Display Account Details" << endl;
    cout << "4. Apply Interest to Savings" << endl;
    cout << "5. Exit" << endl;
  
   cout << "Enter your choice from 1 to 5 " << endl ;
   cin>> o ;
  switch (o){
 case 1 : 
   b.deposite(amount);
   break ;
 case 2 :
   b.withdraw(amount);
   break ;
  case 3:
    display(b);
    display(i);
    break;
  case 4:
    i.applyInterest();
    break;
  case 5:
    cout << "Thank you for using our banking system!" << endl;
     break;
   default :
   cout << "This operation not found "<< endl ;

  }
}while (o != 0);


    cin.get();
    return 0;
}