/**************************
* DONAT VUCETAJ PROJECT 6 *
* BANK ACCOUNTS           *
**************************/
#include <iostream>
#include <fstream>
#include <cmath>

using namespace std;
/*****************
*PROTOTYPES START*
*****************/
//void prints menu. called every time program runs
void menu();
//
int read_accts(int acctnum_array[], double balance_array[], int max_accts);
//
int findacct(int acctnum_array[], int num_accts, int account);
//
void withdrawal(int acctnum_array[], double balance_array[], int num_accts);
//
void deposit(int acctnum_array[], double balance_array[], int num_accts);
//
int new_acct(int acctnum_array[], double balance_array[], int num_accts);
//
void balance(int acctnum_array[], double balance_array[], int num_accts);
//
void print_accts(int acctnum_array[], double balance_array[], int num_accts);
/***************
*PROTOTYPES END*
***************/

const int MAX_NUM = 20;
int main(){

  int acctnum_array[MAX_NUM];
  int num_accts, account;
  double balance_array[MAX_NUM];
  char action;

  //set float to 2 decimal places for account balances
  cout.setf(ios::fixed,ios::floatfield);
  cout.precision(2);

  num_accts = read_accts(acctnum_array, balance_array, MAX_NUM);
  print_accts(acctnum_array, balance_array, num_accts);
  do {
    menu();
    cin >> action;
    cout << endl;
    switch (action) {
      case 'W':
      case 'w':
        withdrawal(acctnum_array, balance_array, num_accts);
        break;
      case 'D':
      case 'd':
        deposit(acctnum_array, balance_array, num_accts);
        break;
      case 'N':
      case 'n':
        new_acct(acctnum_array, balance_array, num_accts);
        break;
      case 'B':
      case 'b':
        balance(acctnum_array, balance_array, num_accts);
        break;
      case 'Q':
      case 'q':
        print_accts(acctnum_array, balance_array, num_accts);
        return 0;
        break;
      default:
        cout << "\n INVALID INPUT. PLEASE CHOOSE SOMETHING FROM MENU \n\n";
    }
  } while(action!='Q');

  toFile.close(); //close outfile buffer
}//END MAIN

//Main Menu function that has no parameters, prints menu.
//called after every successful transaction.
void menu(){
  cout << "\t\tSelect one of the following\n";
  cout << "\t\tW - Withdrawl\n";
  cout << "\t\tD - Deposit\n";
  cout << "\t\tN - New account\n";
  cout << "\t\tB - Balance\n";
  cout << "\t\tQ - Quit\n";
  //cout << "X - Delete Account\n";
}
//passes account number array, balance array, and MAXIMUM allowed accounts
int read_accts(int acctnum_array[], double balance_array[], int max_accts){
  int num_accts = 0;
  int aNum;
  double bNum;

  ifstream inFile;
  inFile.open("accountList.txt");

  inFile >> aNum >> bNum;
  do{
    acctnum_array[num_accts] = aNum;
    balance_array[num_accts] = bNum;
    num_accts++;
    inFile >> aNum >> bNum;
  }while(!inFile.eof());
  return num_accts;
}
//passes account number array, balance array, and the requested account #
int findacct(int acctnum_array[], int num_accts, int account){
  int count=0;
  for(int i=0;i<num_accts;i++){
    if(account == acctnum_array[i])
      return i;
    }
    return -1;
}
//passes account number array, balance array, and the number of available accounts
void withdrawal(int acctnum_array[], double balance_array[], int num_accts){
  int accountNumer;
  double withdrawAmount;
  cout << "Please enter requested account number-> ";
  while(!(cin>>accountNumer)){
     cin.clear();
     cin.ignore();
     cout << "Not a number. Please try again\n";
     cout << "Please enter requested account number-> ";
  }
  int acctReturn = findacct(acctnum_array, num_accts, accountNumer);
  if(acctReturn == -1){
    cout << "Account does not exist. Please try again\n\n";
    return;
  }else{
    cout << "Please enter the amount you would like to withdraw->";
    while(!(cin>>withdrawAmount) || withdrawAmount < 0){
       cin.clear();
       cin.ignore();
       cout << "Not a valid input. Please try again\n";
       cout << "Please enter requested withdraw amount-> ";
    }
    if(withdrawAmount > balance_array[acctReturn]){
      cout << "INSUFFICIENT FUNDS. Transaction cancelled \n";
    }else{
      balance_array[acctReturn] = balance_array[acctReturn] - withdrawAmount;
      cout << "Remaining Balance: " << balance_array[acctReturn] << "\n";
    }
  }
}
//passes account number array, balance array, and the number of available accounts
void deposit(int acctnum_array[], double balance_array[], int num_accts){
  int accountNumer;
  double depositAmount;
  cout << "Please enter requested account number-> ";
  while(!(cin>>accountNumer)){
     cin.clear();
     cin.ignore();
     cout << "Not a number. Please try again\n";
     cout << "Please enter requested account number-> ";
  }
  int acctReturn = findacct(acctnum_array, num_accts, accountNumer);
  if(acctReturn == -1){
    cout << "Account does not exist. Please try again\n\n";
    return;
  }else{
    cout << "Please enter the amount you would like to Deposit->";
    while(!(cin>>depositAmount) || depositAmount < 0){
       cin.clear();
       cin.ignore();
       cout << "Not a valid input. Please try again\n";
       cout << "Please enter requested deposit amount-> ";
    }
    balance_array[acctReturn] = balance_array[acctReturn] + depositAmount;
    cout << "Account Balance: " << balance_array[acctReturn] << "\n";
  }
}
//passes account number array, balance array, and the number of  accounts
int new_acct(int acctnum_array[], double balance_array[], int num_accts){
  int newAccNum;
  cout << "Please enter requested account number->";
  while(!(cin>>newAccNum)){
     cin.clear();
     cin.ignore();
     cout << "Not a number. Please try again\n";
     cout << "Please enter requested account number-> ";
  }
  int acctReturn = findacct(acctnum_array, num_accts, newAccNum);
  if(acctReturn >=0){
      cout << "ERROR: Account number already exists.\n";
      return num_accts;
  }
  acctnum_array[num_accts - 1] = newAccNum;
  balance_array[num_accts - 1] = 0.00;
  num_accts++;
  return num_accts;
}
//passes account number array, balance array, and the number of accounts
void balance(int acctnum_array[], double balance_array[], int num_accts){
  int accountNumer;
  cout << "Please enter requested account number-> ";
  while(!(cin>>accountNumer)){
     cin.clear();
     cin.ignore();
     cout << "Not a number. Please try again\n";
     cout << "Please enter requested account number-> ";
  }
  int acctReturn = findacct(acctnum_array, num_accts, accountNumer);
  if(acctReturn == -1){
    cout << "Account does not exist. Please try again\n\n";
    return;
  }else{
    cout << "Accont# " << accountNumer << " Balance: $" << balance_array[acctReturn] << "\n\n";
  }
}
////passes account number array, balance array, and the number of  accounts
void print_accts(int acctnum_array[], double balance_array[], int num_accts){
  for(int i=0; i < num_accts; i++){
    cout.width(10);
    cout << "ACCOUNT#: ";
    cout.width(6);
    cout << acctnum_array[i] << "\t\t";
    cout.width(10);
    cout << "ACCOUNT#: ";
    cout.width(6);
    cout <<  acctnum_array[i+1] << "\n";
    cout.width(10);
    cout << "BALANCE: $";
    cout.width(6);
    cout << balance_array[i] << "\t\t";
    cout.width(10);
    cout << "BALANCE: $";
    cout.width(6);
    cout << balance_array[i+1] << "\n\n";
    i++;
  }
}
