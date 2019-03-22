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
  }
  void resetword(); // A function used to restore the hangman word for multiple uses
  void hangmandrawing(); // A function used to draw the hangman figure
  void tryLetters();     // function that used the different letters used in the
                     // hangman setting
  void storetheword(string HangmanWord); // this function stores the word in the
                                         // private variable making it
                                         // untouchable
  void addTries();
  int displayHiddenWord();

  bool checkSet(set<char> mySet, char x);
  string AiWord();
  void completehangman();

private:
  set<char> mySet;
  int tries;
  int showncounter;
  string response; // This stores the users secret word
  string shown; // This is used to show user how far they have gotten in guessing
};
