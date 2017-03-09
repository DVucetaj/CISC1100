/**************************
* DONAT VUCETAJ PROJECT 5 *
**************************/
#include <iostream>
#include <cmath>
#include <fstream>
#include <algorithm>

using namespace std;

//void function that prints to console instructions for inputs
//called every time function runs
void menu();
//one char to find opperation in switch statement, one ofstream to write to file
void calculate(char, ofstream &);
//two int to find sum, ofstream to print to file
void add(int,int, ofstream &);
//two ints to find difference, ofstream to print file
void subtract(int,int, ofstream &);
//two ints to find product, ofstream to print file
void multiply(int,int, ofstream &);
//two ints to find quotient, ofstream to print file
void divide(int,int, ofstream &);
//two ints to find remainder, ofstreal to print file
void modulo(int,int, ofstream &);
//two ints to find average, ofstream to print file
void avg(int,int, ofstream &);
//two ints to find maximum, ofstream to print file
void max(int,int, ofstream &);
//two ints to find minimum, ofstream to print file
void min(int,int, ofstream &);
//one ints to find square, ofstream to print file
void square(int, ofstream &);
//one ofstream to print exit message
void quit(ofstream &);

int main(){
  char opp;

  //DIRECTED OUTPUT FILE FOR FINAL OUTPUT
  //Comment out for debug
  ofstream toFile("proj5out.txt");
  //cout outfile for testing with prompts
  //ofstream cout("proj5out.txt");

  //EXAMPLE PRINTS ONCE, THEN ONLY OPERATORS PRINT
  cout << "Please enter an operator or a letter to begin calcultion, \n";
  cout << "then enter two or one numbers as prompted. ex:\n";
  cout << "A\n10\n20\nAVERAGE OF 10 AND 20 = 15\n";
  cout << "*\n10\n20\n10 * 20 = 200\n";
   while(true){
    //SETS LOOP TO TRUE, THEN CHECKS INPUT IF USER WANTS TO QUIT
    menu();
    cin >> opp;
    //CHECKS IF USER WANTS TO QUIT PROGRAM
    if(opp == 'Q' || opp == 'q'){
      quit(toFile);
      return 0;
    }else{
      calculate(opp, toFile);
      //CALCULATE FUNCTION FOR PROMPT DEBUG
      //calculate(opp, cout);
    }
  }
  toFile.close(); //close outfile buffer
}
//void function that prints to console instructions for inputs
//called every time function runs
void menu(){

  cout << "Operators: +, -, *, /, or % \n";
  cout << "A: Average of TWO numbers, X: Maximum of TWO numbers\n";
  cout << "M: Minimum of TWO numbers, S: Square of ONE number\n";
  cout << "Q: Quit program\n";

}
//one char to find opperation in switch statement, one ofstream to write to file
void calculate(char opp, ofstream &toFile){
  int num1, num2;
  switch (opp) {
    case '+':
      add(num1,num2,toFile);//calls add function
      break;
    case '-':
      subtract(num1,num2,toFile);//calls subtract function
      break;
    case '*':
      multiply(num1,num2,toFile);//calls multiply function
      break;
    case '/':
      divide(num1,num2,toFile);//calls divide function
      break;
    case '%':
      modulo(num1,num2,toFile);//calls modulo function
      break;
    case 'A':
      avg(num1,num2,toFile);//calls avg function
      break;
    case 'X':
      max(num1,num2,toFile);//calls max function
      break;
    case 'M':
      min(num1,num2,toFile);//calls min function
      break;
    case 'S':
      square(num1,toFile);//calls square function
      break;
    default:
      //input was not valid, asks for appropriate input
      cout << "Please enter an appropriate input operator.\n\n";
  }

}

/************************
*   START OF FUNCTIONS  *
*************************/
//two int to find sum, ofstream to print to file
void add(int num1,int num2, ofstream &toFile){
  cout << "Please enter two numbers to add\n";
  cin >> num1 >> num2;
  toFile << "ADD: " <<   num1 << " + " << num2 << " = " << num1 + num2 << endl;
}
//two ints to find difference, ofstream to print file
void subtract(int num1,int num2, ofstream &toFile){
  cout << "Please enter two numbers to subtract\n";
  cin >> num1 >> num2;
  toFile << "SUBTRACT: " <<   num1 << " - " << num2 << " = " << num1 - num2 << endl;
}
//two ints to find product, ofstream to print file
void multiply(int num1,int num2, ofstream &toFile){
  cout << "Please enter two numbers to multiply\n";
  cin >> num1 >> num2;
  toFile << "MULTIPLY: " <<   num1 << " * " << num2 << " = " << num1 * num2 << endl;
}
//two ints to find quotient, ofstream to print file
void divide(int num1,int num2, ofstream &toFile){
  cout << "Please enter two numbers to divide\n";
  cin >> num1 >> num2;
  toFile << "DIVISION: " <<  num1 << " / " << num2 << " = " << num1 / num2 << endl;
}
//two ints to find remainder, ofstreal to print file
void modulo(int num1,int num2, ofstream &toFile){
  cout << "Please enter two numbers for modulo\n";
  cin >> num1 >> num2;
  toFile << "MODULO: " << num1 << " % " << num2 << " = " << num1 % num2 << endl;
}
//two ints to find average, ofstream to print file
void avg(int num1,int num2, ofstream &toFile){
  cout << "Please enter two numbers to find their average\n";
  cin >> num1 >> num2;
  toFile << "AVERAGE: " << num1 << " & " << num2 << " = " <<(num1 + num2)/2 << endl;
}
//two ints to find maximum, ofstream to print file
void max(int num1,int num2, ofstream &toFile){
  cout << "Please enter two numbers to find the max\n";
  cin >> num1 >> num2;
  if(num1 >> num2){
    toFile << "MAX: " << num1 << " & " << num2 << " = " << num1 << endl;
  }else{
    toFile << "MAX: " << num1 << " & " << num2 << " = " << num2 << endl;
  }
}
//two ints to find minimum, ofstream to print file
void min(int num1,int num2, ofstream &toFile){
  cout << "Please enter two numbers to find the min\n";
  cin >> num1 >> num2;
  if(num1 << num2){
    toFile << "MIN: " << num1 << " & " << num2 << " = " << num1 << endl;
  }else{
    toFile << "MIN: " << num1 << " & " << num2 << " = " << num2 << endl;
  }
}
//one ints to find square, ofstream to print file
void square(int num1, ofstream &toFile){
  cout << "Please enter a number to find it's square\n";
  cin >> num1;
  toFile << "SQUARE: " << num1 << " = " << num1 * num1 << endl;
}
//one ofstream to print exit message
void quit(ofstream &toFile){
  toFile << "Program is closing.\n";
}

/************************
*   END OF FUNCTIONS    *
*************************/
