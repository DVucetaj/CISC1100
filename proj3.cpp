#include <iostream>
#include <fstream>
#include <math.h>
#include <cmath>

using namespace std;

int main(){

  int studentID, rightAns, wrongAns, qOmitted, grade, qAnswered;
  int numOfStudents = 0;
  float rightPercent;

  cout << "Enter student ID, followed by correct answers, and then incorrect answers\n";
  cout << "Enter student ID 00 to exit\n";

  ofstream cout("proj3out.txt");
  while(true){      //SETS LOOP

    cout.setf(ios::fixed,ios::floatfield);
    cout.precision(3);


    cin >> studentID;
    if(studentID == 00){return 0;}      //EXIT PROGRAM IF STUDENT ID 00
    else{                               //ELSE RUN PROGRAM
        cin >> rightAns;
        cin >> wrongAns;
        qOmitted = 50 - (rightAns + wrongAns);
        if(qOmitted == 50) {
            cout << "NO QUESTIONS ANSWERED, NO RECORD FOR STUDENT ID " << studentID << "\n\n";
            continue;
        }
        else{
            qAnswered = rightAns + wrongAns;
            rightPercent = (float)rightAns / qAnswered;
            grade = rightAns * 2;


            cout << "STUDENT ID: " << studentID << endl;
            cout << rightAns << " RIGHT ANSWERS\t" << wrongAns << " WRONG ANSWERS \n";
            cout << "TOTAL ANSWERED " << qAnswered << endl;
            cout << "TOTAL OMITTED " << qOmitted << endl;
            cout << "GRADE IS " << grade << endl;

            if(rightAns > wrongAns)
              cout << "MORE RIGHT ANSWERS THAN WRONG\n";
            else if (rightAns == wrongAns)
              cout << "SAME AMOUNT WRONG AND RIGHT\n";
            else
             cout << "MORE WRONG ANSWERS THAN RIGHT\n";

            cout << "CORRECT PERCCENT " << rightPercent << endl;


            if(qOmitted >= 10)
              cout << "10 OR MORE OMITTED\n\n";
            else
              cout << "LESS THAN 10 OMITTED\n\n";

            numOfStudents++;
        }                               //END OF Div/0 CHECK
    }                                   //END OF EXIT ID LOOP
  }                                     //END OF WHILE LOOP
  cout << "NUMBER OF STUDENTS " << numOfStudents << endl;

  cout.close();

}
