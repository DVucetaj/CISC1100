/**************************
* DONAT VUCETAJ PROJECT 8 *
* WORD COUNT              *
**************************/

#include <iostream>
#include <fstream>
#include <string>
#include <iomanip>

using namespace std;


int makearray(string[]);
int diffwords(int, string[],string[]);
int wordcount(string[], int, string);
void printcount(int[], string[], int);
void format(string&);
bool findword(int, string[], string);


const int MAX_WORDS = 120;
ofstream toFile("proj8out.txt");
ifstream readFile("proj8in.txt");

int main(){

  string words[MAX_WORDS];
  string uniqueWords[MAX_WORDS];

  string text, temp;
  int numOfWords = 0, numOfUniqueWords = 0, counter = 0;
  bool lastWord = false;

  //creates an array of the text with uniform formatted words(no punctuation)
  //and all in lower case. this is used to compare the frequency of the words
  //that appear uniquely to the whole text
  readFile >>  text;
  do{
    format(text);
    words[numOfWords] = text;
    numOfWords++;
  }while(readFile >> text);

  /*
  for(int i=0; i<numOfWords; i++)
    cout << "words["<< i << "] ->" << words[i] << endl;
  */
  //from here on, another value containing the amount of elements is added
  //numOfUniqueWords keeps track of how many unique words are in the uniform
  //formatted text.
  numOfUniqueWords = diffwords(numOfWords,words,uniqueWords);

  int frequency[numOfUniqueWords];
  for(int i=0; i <numOfUniqueWords; i++){
    temp = uniqueWords[i];
    counter = wordcount(words,numOfWords,temp);
    frequency[i] = counter;
  }
  printcount(frequency,uniqueWords,numOfUniqueWords);


  //close streams and return 0
  readFile.close();
  toFile.close();
  return 0;
}
void printcount(int frequency[], string uniqueWords[], int numOfUniqueWords){

  toFile << left << setw(12) << "WORD";
  toFile << "||";
  toFile << setw(5) << "COUNT\n";
  toFile << "------------------------------\n";
  for(int i=0; i<numOfUniqueWords; i++){
    toFile << left <<  setw(12) << uniqueWords[i];
    toFile << "||";
    toFile << setw(5) << frequency[i] << "\n";
  }
  toFile << "------------------------------";
}
//wordcount returns the number of times a word appears in the text. it takes in
// an array for total words, an int for total elements in words, and the
//word that is to be found and counted.
int wordcount(string words[], int numOfWords, string countThis){
  int uniqueCount = 0;
  for(int j=0; j < numOfWords; j++){

    if(countThis == words[j]){
      uniqueCount++;
    }

  }
  return uniqueCount;
}//end wordcount

//returns the number of unique words. int num is the number of total words from the text
//words is the array of formatted words from the text, and uniqueWords is the array
//of strings to be filled with unique words. diffwords skips the first word because it is
//the first word and inherently unique. it compares the rest of the elements to everything
//earlier in the array. if it is not the first occurence of the word, it is not added to the
//uniqueWords array.
int diffwords(int num, string words[], string uniqueWords[]){
  int currWord = 0, lastWord = num, count = 0;
  string temp;
  bool uniqueWordFlag;
  for(currWord; currWord < lastWord; currWord++){
    temp = words[currWord];
    if(currWord == 0){
      uniqueWords[count] = temp;
      count++;
    }else{
      uniqueWordFlag = findword(currWord,words,temp);
      if(uniqueWordFlag){
        uniqueWords[count] = temp;
        count++;
      }else{
        //do noting;
      }
    }
  }//end for loop
  return count;
}//END diffwords

//findword returns a bool, false if word is found and true if the word is Unique.
//it takes in the current position of the the currWord counter to see where in
//the array words the diffwords function is. It looks backwards to see if the word
//has occured before. if it has, the word is not unique and it it continues to the
//next element in the words array. toFind is the word the diffwords is seeking
bool findword(int pos, string words[], string toFind){
  for(int i=pos; i>0; i--){
    if(words[i-1] == toFind){
      return false;
    }
  }
  return true;
}//end findword

//format is a void function that takes in a string by reference and changes the string
//if it has any punctuation, periods, commas, or is upper case, it is made lower case
//this is to make sure that all the words read in and compared are the same case and
//can be processed as the same words
void format(string &s){
  for(int i=0; i < s.length(); i++){
    if(isupper(s[i])){
      s[i] = tolower(s[i]);
    }
    if(ispunct(s[i])){
      s.erase(i,1);
    }
    if(s[i] == ','){
      s.erase(i,1);
    }
    if(s[i] == '.'){
      s.erase(i,1);
    }
  }
}//end format
