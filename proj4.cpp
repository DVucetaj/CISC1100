/**************************
* DONAT VUCETAJ PROJECT 4 *
**************************/

#include <iostream>
#include <fstream>

using namespace std;

const int MIN_SCORE = 0;
const int MAX_SCORE = 300;
//rating strings
const string PROFESSIONAL = "YOU BOWLED A PROFESSIONAL GAME! SCORE:";
const string EXCELLENT = "YOU BOWLED AN EXCELLENT GAME! SCORE:";
const string VERY_GOOD = "YOU BOWLED A VERY GOOD GAME! SCORE:";
const string GOOD = "YOU BOWLED A GOOD GAME! SCORE:";
const string POOR = "YOU BOWLED A POOR GAME! SCORE:";
const string HORRIBLE = "YOU BOWLED A HORRIBLE GAME! SCORE:";



int validgroup(int ,int ,int ,ofstream&);
void onegamescore(int, ofstream&);
int avg3scores(int,int,int);
bool isValid(int);

int main(){

  int score1, score2, score3;
  int isGroupValid = 0; //flag to check if group is valid. 0 is invalid, 1 is valid
  int finalAvg = 0;     //final average score var used in main
  int groupsProcessed = 0;
  int groupsValid = 0;
  int groupsInvalid = 0;

  //DIRECTED OUTPUT FILE FOR FINAL OUTPUT
  ofstream toFile("proj4out.txt");

  //cout outfile for testing with prompts
  //ofstream cout("proj4out.txt");


  while(score1 != 999){
    cout << "ENTER THE 3 FINAL BOWLING SCORES\n";
    cout << "ENTER 999 FORE SCORE 1 TO EXIT PROGRAM\n";
    cin >> score1;
    if(score1 == 999){      //input sentinel, game is over, output counters
      toFile << "GROUPS PROCESSED: " << groupsProcessed << endl;
      toFile << "VALID GROUPS: " << groupsValid << endl;
      toFile << "INVALID GROUPS: " << groupsInvalid << endl;
      toFile.close();
      return 0;
    }                         //exit program check. breaks loop and exits PROGRAM
    else{
      groupsProcessed++;
      cin >> score2 >> score3;
      toFile << "SCORE1: " << score1 << " SCORE2: " << score2 << " SCORE3: " << score3 <<endl;
      isGroupValid = validgroup(score1,score2,score3,toFile);
      if(isGroupValid == 0){  //if group is invalid, reset loop for next group
        groupsInvalid++;
        continue;
      }else{
        groupsValid++;
        toFile << "SCORE1 RATING ->";
        onegamescore(score1, toFile);
        toFile << "SCORE2 RATING ->";
        onegamescore(score2, toFile);
        toFile << "SCORE3 RATING ->";
        onegamescore(score3, toFile);

        finalAvg = avg3scores(score1,score2,score3);
                              //indicate group average rating
        toFile << "GROUP AVERAGE ->";
        onegamescore(finalAvg, toFile);

        toFile << "\n\n"; //prints 3 blank lines
      }
    }
  }
}
//one int input to check if the score is valid
bool isValid(int score){//checks if a score is valid
  if(score >= MIN_SCORE && score <= MAX_SCORE){
    return true;
  }
  else
    return false;
}//end isValid
//three int inputs to check if the group is valid, one ofstream to output to file
int validgroup(int s1,int s2,int s3,ofstream &toFile){
  if(isValid(s1) && isValid(s2) && isValid(s3)){
    toFile << "THIS GROUP IS VALID\n";
    return 1;
  }
  else{
    toFile << "THIS GROUP IS INVALID\n";
    if (isValid(s1) == false){
      if(s1 < MIN_SCORE){
        toFile << "SCORE 1: " << s1 << " INVALID: LESS THAN 0 \n";
      }
      else if(s1 > MAX_SCORE){
        toFile << "SCORE 1: " << s1 << " INVALID: GREATER THAN 300 \n";
      }
    }
    if (isValid(s2) == false){
      if(s2 < MIN_SCORE){
        toFile << "SCORE 2: " << s2 << " INVALID: LESS THAN 0 \n";
      }
      else if(s2 > MAX_SCORE){
        toFile << "SCORE 2: " << s2 << " INVALID: GREATER THAN 300 \n";
      }
    }
    if (isValid(s3) == false){
      if(s3 < MIN_SCORE){
        toFile << "SCORE 3: " << s3 << " INVALID: LESS THAN 0 \n\n";
      }
      else if(s3 > MAX_SCORE){
        toFile << "SCORE 3: " << s3 << " INVALID: GREATER THAN 300 \n\n";
      }
    }
    toFile << "\n";
    return 0;
  }

}//end validgroup
//one int input to check the score rating, one ofstream to output to file
void onegamescore(int score, ofstream &toFile){
  if(score >= 250 && score <= 300)
    toFile << PROFESSIONAL << score << "\n";
  else if(score >= 200 && score <= 249)
    toFile << EXCELLENT << score << "\n";
  else if(score >= 140 && score <= 199)
    toFile << VERY_GOOD << score << "\n";
  else if(score >= 100 && score <= 139)
    toFile << GOOD << score << "\n";
  else if(score >= 50 && score <= 99)
    toFile << POOR << score << "\n";
  else
    toFile << HORRIBLE << score << "\n";
}//end onegamescore
//three int inputs to find the average of the group.
//is only called if group is valid
int avg3scores(int s1,int s2,int s3){
  int avg = (s1 + s2 + s3) / 3;
  return avg;
}//end avg3scores
