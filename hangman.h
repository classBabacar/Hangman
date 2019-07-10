#include <fstream>
#include <iostream>
#include <set>
#include <vector>
#include <stdlib.h>
#include <termios.h>
#include <unistd.h>

using namespace std;

class hangman
{
public:
  hangman()
  {
    triesLeft = 7;
    displayUser = "";
    topic = "";
    secretWord = "";
  }

  // User Dependencies
  void guessLetters();
  void setTopic(string x);
  void loserMessage();
  void winnerMessage();

  //Game Dependencies
  void resetEverything();
  void hangmanDrawing();
  void storeSecretWord(string x);
  void addTries();
  void displayHiddenWord();

  //Helper Function
  bool checkSet(set<char> mySet, char x);
  bool doesLetterMatch(char letter, string &displayUser, string secretWord);
  string captureUserGuess();
  char getLetter();

  //AI Function
  string AiWord();

private:
  set<char> repeatedCharSet;
  int triesLeft;
  string secretWord;
  string displayUser;
  string topic;
};
