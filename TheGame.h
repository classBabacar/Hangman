#include <ctime>
#include <fstream>
#include <iostream>
#include <set>
#include <stdio.h>
#include <stdlib.h>
#include <string>
#include <time.h>
#include <vector>
#include <cstdlib>
#include <termios.h>
#include <unistd.h>

using namespace std;

class Thegame {
public:
  Thegame() {
    tries = 7;
    shown = "";
    topic = "";
    response = "";
  }
 
  void resetword(); // A function used to restore the hangman word for multiple uses
  void hangmandrawing(); // A function used to draw the hangman figure
  void tryLetters();  //guessing letters function
  void storetheword(string HangmanWord); //storing a users secret word
  void addTries();
  void setTopic(string x);
  
  
  void displayHiddenWord(); //keeping track of how many letters user gets correct

  bool checkSet(set<char> mySet, char x);
  string AiWord();
  

private:
  set<char> mySet;
  int tries;
  int showncounter;
  string response; // This stores the users secret word
  string shown; // This is used to show user how far they have gotten in guessing
  string topic;
};
