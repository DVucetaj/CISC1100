/**************************
* DONAT VUCETAJ PROJECT 7 *
* COUNT ZEROES            *
**************************/
#include <iostream>
#include <fstream>

using namespace std;

//readdata takes an int, an array, and an output file stream
int readdata(int, int[], ofstream&);
//readdata takes an int, and an array
int countzeros(int, int[]);
//readdata takes an int, an array, and an output file stream
int append(int, int[], ofstream&);

//this is the maximum size of the user array
const int MAX_ARR_SIZE = 100;

/**************************************************************************
* The main program initializes the array size to 100, and initializes the *
* output file stream. First 'size' the amount of elements is returned by  *
* the readdata function, which takes the number 'n', the array numbers,   *
* and the output file stream. Then, the array is printed up until the user*
* input amount of elements. After, the countzeros takes the amount of     *
* elements in the array 'size', and the array 'numbers', and counts the   *
* amount of zeroes in the array. It returns the number of zeroes in the   *
* array and prints the value. After, the append function is called and it *
* takes the same parameters as the readdata function has. Once finished,  *
* it will print the new array and check the amount of zeroes again for the*
* new array, including the old values. The stream is closed and returns 0 *
**************************************************************************/
int main(){
  int n, size, zeroCount = 0;
  int numbers[MAX_ARR_SIZE];

  ofstream toFile("proj7out.txt");

  size = readdata(n, numbers, toFile);
  for (int i = 0; i < size; i++) {
    toFile << "ARRAY[" << i << "]->" <<numbers[i] << endl;
  }

  toFile << "\nSTARTING FIRST COUNT ZERO\n";
  zeroCount = countzeros(size, numbers);
  toFile << zeroCount << " ZERO(S) FOUND IN ARRAY\n\n";

  size = append(size, numbers,toFile);
  for (int i = 0; i < size; i++) {
    toFile << "ARRAY[" << i << "]->" <<numbers[i] << endl;
  }

  toFile << "\nSTARTING SECOND COUNT ZERO\n";
  zeroCount = countzeros(size, numbers);
  toFile << zeroCount << " ZERO(S) FOUND IN NEW ARRAY\n\n";

  toFile.close();
  return 0;
}
/**************************************************************************
* int n is how many values are in the array, int vals is the array itself *
* toFile is the output file stream used to log the users inputs. The      *
* program asks the user for an input on array length, n, and then asks the*
* user to input n numbers. If the number input is less than 1, or the     *
* number is more than 100, the program prints an eror and asks for another*
* input from the user. If the number n is valid, then the program writes  *
* the input to the file as the user inputs each number until the amount of*
* numbers input is equal to the desired size. The amount of elements in   *
* the array is returned to the main program.                              *
**************************************************************************/
int readdata(int n, int vals[], ofstream &toFile){
  int value;
  int i = 0;
  cout << "Enter size of array->";
  while(!(cin >> n) || n < 1 || n > 100){
    if(n < 1){
      toFile << "SIZE->" << n << endl;
      cin.clear();
      cin.ignore();
      cout << "ERROR: Please pick a number over 0 \n";
      toFile << "ERROR: Please pick a number over 0 \n";
      cout << "Enter size of array->";
    }
    if(n > 100){
      toFile << "SIZE->" << n << endl;
      cin.clear();
      cin.ignore();
      cout << "ERROR: Please pick a number under 100\n";
      toFile << "ERROR: Please pick a number under 100 \n";
      cout << "Enter size of array->";
    }
  }
  toFile << "SIZE->" << n << endl;
  cout << "Please enter " << n << " numbers: \n";
  toFile << "INPUT->";
  do {
    cin >> value;
    toFile << value << " ";
    vals[i] = value;
    i++;
  } while(i < n);
  toFile << endl;
  return n;
}
/**************************************************************************
* int n is how many values are in the array, int vals is the array itself *
* toFile is the output file stream used to log the users inputs. The      *
* program here just counts all the values in the array that are equal to  *
* zero. If they are equal to zero, the count variable increments. Once the*
* last element is reached, the final count value of zeroes is returned.   *
**************************************************************************/
int countzeros(int n, int vals[]){
  int count = 0;

  for(int i=0; i < n; i++){
    if(vals[i] == 0){
      count++;
    }
  }
  return count;
}

/**************************************************************************
* int n is how many values are in the array, int vals is the array itself *
* toFile is the output file stream used to log the users inputs. The      *
* program here asks for input until fail, ie. until there is no int input *
* in the variable 'vavlue', such as a letter or non number, or until the  *
* amount of elements in the array is up to 100. it returns the new n value*
* which is the new amount of elements in the array.                       *
**************************************************************************/
int append(int n, int vals[], ofstream &toFile){
  int value;
  cout << "Enter values to add to the array-> ";
  toFile << "INPUT->";
  while((cin>>value) && (n < MAX_ARR_SIZE)){
    toFile << value << " ";
    vals[n] = value;
    n++;
  }
  toFile << endl;
  cout << endl;
  return n;
}
