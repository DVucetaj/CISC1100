#include <iostream>
#include <fstream>
#include <cmath>
#include <cstdlib>

using namespace std;
double fRand();

int main(){
  int count = 1;
  double balance;
  string line;

  ofstream toFile("accountList.txt");
  cout.setf(ios::fixed,ios::floatfield);
  cout.precision(2);

  for(int i=1; i<=20 ;i++){
    balance = ((double)rand()/100000) * 1000;
    toFile << count << " " << balance << endl;
    count++;
  }
  toFile.close(); //close outfile buffer
}
