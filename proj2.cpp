#include <iostream>
#include <math.h>
#include <cmath>
#include <stdio.h>
#include <fstream>
using namespace std;

int main(){

	float y, x;
	x = -3.0;
	int pos=0;
	int neg=0;
	int zero=0;

    ofstream cout("proj2out.txt");

	cout << left;
    cout << "THIS IS THE OUTPUT OF MY FIRST PROGRAM \n";
    cout << "X-Value\tY-Value\tPositive/Negative\n";
	for(x;x <= 4;x+=0.5){
        //Y FUNCTION SEPARATED IN SOURCE CODE TO PREVENT WARPING
		y = ((9.0 * pow(x,3.0)) - (27.0 * pow(x,2.0)) - (4.0 * x) + 12.0)
		/
		(pow((3.0 * pow(x,2.0)) + 1.0,0.5) + abs(5.0 - pow(x,4.0)));
        //END OF FUNCTION CODE
		if(y<0){
            cout.width(7);
            cout << x;
            cout.width(10);
            cout <<y;
            cout << "Y IS NEGATIVE \n";
			neg++;      //increment negative result counter
		}else if(y < 0.01 && y > -0.01){
            cout.width(7);
            cout << x;
            cout.width(10);
            cout <<y;
            cout << "Y IS ZERO \n";
			zero++;     //increment zero result counter
		}else{
            cout.width(7);
            cout << x;
            cout.width(10);
            cout <<y;
            cout << "Y IS POSITIVE \n";
			pos++;      //increment positive result counter
		}
	}
	//COUNTERS FORMATTED TO PREVENT WARPING OF SOURCE CODE
	cout << pos <<" positive Y values, " 
	cout << zero << " zero Y values, and "
	cout << neg << " negative Y values \n";
	cout << "LAST LINE OF CODE REACHED, PROGRAM IS HALTING" << endl;
    cout.close();
}
