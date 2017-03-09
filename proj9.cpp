/**************************
* DONAT VUCETAJ PROJECT 9 *
* DONATIONS               *
**************************/
#include <iostream>
#include <fstream>

using namespace std;

//function descriptions at bottom
int readIn(int[],int[]);
void sortID(int[],int[],int);
void sortDonations(int[],int[],int);
void printTable(int[],int[],int);

ofstream toFile("proj9out.txt");

int main(){

  int idnumbers[50];
  int donations[50];
  int n = 0;

  n = readIn(idnumbers,donations);
  toFile << "\t\t ORIGINAL INPUT TABLE\n";
  toFile << "\t-----------------------------------------\n";
  printTable(idnumbers,donations,n);


  sortID(idnumbers,donations,n);
  toFile << "\t\tSORTED ID TABLE\n";
  toFile << "\t-----------------------------------------\n";
  printTable(idnumbers,donations,n);


  sortDonations(idnumbers,donations,n);
  toFile << "\t\t SORTED DONATION TABLE\n";
  toFile << "\t-----------------------------------------\n";
  printTable(idnumbers,donations,n);


  return 0;
}
//readIn returns the number of elements in the array. it takes in the arrays for ID
//and for the donations. It makes sure that the user enters at least 2 data sets
//and less than 50. It will read 'count' amount of sets even if the user inputs more than
//count, and will presist until all sets are entered.
int readIn(int id[], int donate[]){
  int count= 0;
  cout << "How many sets of data will you enter? ";
  cin >> count;
  while (count < 2 || count > 50) {
    cout << "ERROR: Enter at least 2 sets and less than 50 sets of data\n";
    cin >> count;
  }
  cout << "Enter a 3-digit ID number, followed by a space and donation amount " << count << " times:\n";
  for(int i=0; i < count; i++){
    cin >> id[i] >> donate[i];
  }

  return count;
}
//sortID returns nothing, takes in both ID and donation arrays, and the size of the arrays
//The Bubble sort is used here to sort the two arrays. Temporary ID and donation ints are used
//to hold the values while they are being swapped out. The loop for both sorts are the same
//the only thing that changes is the if conditional for ID or donations
void sortID(int id[], int donate[], int n){
  int i, j, k;
  int tempID, tempDonate;

    for(i=1; i<=n-1; i++){
      for(j=0; j<i; j++){
        //if the ID in id[i] is larger than id[j], put the value of id[i] into
        //id[j] and store id[j] into temp. do the same for the respective
        //donation amount associated with that ID
        if(id[j] > id[i]){
          tempID = id[j];
          id[j] = id[i];
          tempDonate = donate[j];
          donate[j] = donate[i];

          //stores the value of the trailing iterator, the smaller value,
          //to the location of the leading iterator for both the ID
          //and the donation values
          for(k=i; k>j; k--){
            id[k] = id[k-1];
            donate[k] = donate[k-1];
          }

          //since the value of K is positioned at the trailing iterator because
          //of the loop, id[k+1] is equal to the value stored in temp,which was
          //the larger value.
          id[k+1] = tempID;
          donate[k+1] = tempDonate;

        }//end if conditional

      }//end j iterator loop(trailing)

    }//end i iterator loop(leading)

}//end sortID
//sortDonations returns nothing, takes in both ID and donation arrays, and the size of the arrays
//The Bubble sort is used here to sort the two arrays. Temporary ID and donation ints are used
//to hold the values while they are being swapped out. The loop for both sorts are the same
//the only thing that changes is the if conditional for ID or donations
void sortDonations(int id[], int donate[], int n){
  int i, j, k;
  int tempID, tempDonate;

    for(i=1; i<=n-1; i++){
      for(j=0; j<i; j++){
        //if the donation in donate[i] is larger than donate[j],
        //put the value of donate[i] into donate[j] and store donate[j] into temp.
        //do the same for the respective ID
        if(donate[j] > donate[i]){
          tempID = id[j];
          id[j] = id[i];
          tempDonate = donate[j];
          donate[j] = donate[i];

          //stores the value of the trailing iterator, the smaller value,
          //to the location of the leading iterator for both the ID
          //and the donation values
          for(k=i; k>j; k--){
            id[k] = id[k-1];
            donate[k] = donate[k-1];
          }

          //since the value of K is positioned at the trailing iterator because
          //of the loop, id[k+1] is equal to the value stored in temp,which was
          //the larger value.
          id[k+1] = tempID;
          donate[k+1] = tempDonate;

        }//end if conditional

      }//end j iterator loop(trailing)

    }//end i iterator loop(leading)
}
//printTable returns nothing, but takes in the id array, the donation array, and the amount of
//elements in the array and prints them out into a neat little table. the title of the table
//is printed out by the main program so the function can be used universally.
//once the loop is complete and all items are printed, the table closes of the end with another line
void printTable(int id[], int donate[], int n){
  toFile << "\t|\tID\t|\tDonation\t|\n";
  toFile << "\t|---------------|-----------------------|\n";
  for(int i=0; i < n; i++){
    toFile <<"\t|\t" <<  id[i] << "\t|\t" << donate[i] << "\t\t|\n";
  }
  toFile << "\t-----------------------------------------\n\n";
}//end printTable
