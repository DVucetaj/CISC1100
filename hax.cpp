#include <iostream>
#include <iomanip>
#include <sstream>
#include <map>
#include <cctype>
using namespace std;
void removePunct(string&);
void toLower(string&);
bool isApostrophe(const char);
int diffwords(const map<string,int>&);
int wordcount(const map<string,int>&);
void printcount(const map<string,int>&);
int main(int argc, char *argv[]) {
  map<string,int> freq;
  string file,line,word;
  stringstream ss;
  //
  // Read lines from stdin and count word frequencies until EOF (Ctrl-d if
  // running interactively, or input may be piped in from a file).
  //
  while (getline(cin,line)) {
    ss.str(line);
    while (ss.good()) {
      if (ss >> word) {
        removePunct(word);
        toLower(word);
        if (freq.find(word) == freq.end()) {
          freq.insert(pair<string,int>(word,1));
        } else {
          freq[word]++;
        }
      }
    }
    ss.clear();
  }
  cout << "Number of different words: " << diffwords(freq) << endl;
  printcount(freq);
  return(0);
}

int diffwords(const map<string,int> &wordMap) {
  return wordMap.size();
}

int wordcount(const map<string,int> &wordMap) {
  // nothing to do, wordMap already contains counts
  return 0;
}

// Display words and counts in wordMap, in
// alphabetical order.
void printcount(const map<string,int> &wordMap) {
  map<string,int>::const_iterator i;

  cout << endl;
  cout << " Word : Count" << endl;
  cout << "----------------- -----" << endl;
  for (i = wordMap.begin();i != wordMap.end(); ++i) {
    cout << setw(14) << i->first;
    cout << setw(10) << i->second << endl;
  }
  cout << endl;
}

void removePunct(string &s) {
  string::iterator i = s.begin();
  while (i != s.end()) {
    if ((ispunct(*i)) && (!isApostrophe(*i))) {
      s.erase(i);
    } else {
      ++i;
    }
  }
}

bool isApostrophe(const char c) {
  return c == '\'';
}

void toLower(string &s) {
  string::iterator i = s.begin();
  while (i != s.end()) {
    *i = tolower(*i);
    ++i;
  }
}
