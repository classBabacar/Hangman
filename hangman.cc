#include "hangman.h"
#include "colors.h"

//************************************************************************
// Function: displayHiddenWord()
// Purpose:  To display a word in hashed format  ex. dog -> ---
//************************************************************************
void hangman::displayHiddenWord()
{
  //Displaying a topic if one exists
  if (topic != "")
  {
    cout << "\tThe Topic is : " << topic << endl;
    cout << endl;
  }
  for (int i = 0; i < secretWord.size(); i++)
  {
    if (isalnum(secretWord[i]))
    {
      displayUser = displayUser + "-";
    }
    else
    {
      displayUser = displayUser + secretWord[i];
    }
  }
  cout << "\t" << displayUser << endl;
}

//************************************************************************
// Function: setTopic()
// Purpose:  Setting a topic to make the game more enjoyable
//************************************************************************
void hangman::setTopic(string x) { topic = x; }

void hangman::addTries() { triesLeft--; }

//************************************************************************
// Function: resetEverything()
// Purpose:  Setting everything to base object
//************************************************************************
void hangman::resetEverything()
{
  repeatedCharSet.clear();
  secretWord = "";
  displayUser = "";
  topic = "";
  triesLeft = 7;
}

//************************************************************************
// Function: getLetter()
// Purpose:  for users to guess a letter in a word
//************************************************************************
char hangman::getLetter()
{
  string guess;
  cout << "\tGuess a letter that you think is in the phrase or enter (?) to guess the word" << endl;
  cout << "\t";
  cin >> guess;

  if (isalpha(guess[0]) || guess[0] == '?')
  {
    return tolower(guess[0]);
  }
  else
  {
    cout << RED << "\tThis is not a letter." << WHITE << endl;
    cout << endl;
    getLetter();
  }
}

//************************************************************************
// Function: captureUserGuess()
// Purpose:  in the case that the user thinks they know the secret code
//************************************************************************
string hangman::captureUserGuess()
{
  cout << "\tWhat do you think the secret word is : " << endl;
  string wordGuess;
  cin.ignore();
  cout << "\t";
  getline(cin, wordGuess);

  for (int i = 0; i < wordGuess.size(); i++)
  {
    wordGuess[i] = tolower(wordGuess[i]);
  }

  return wordGuess;
}

void hangman::winnerMessage()
{
  cout << YELLOW << "\tCongrats! You guessed the secret word it was : " << GREEN << secretWord << WHITE << endl;
  cout << "\tThank you for playing." << endl;
}

void hangman::loserMessage()
{
  cout << "\tSorry, you lose the secret word was : " << GREEN << secretWord << WHITE << endl;
  cout << "\tThank you for playing." << endl;
}

//************************************************************************
// Function: doesLetterMatch(char letter, string &displayUser, string secretWord)
// Purpose: To keep track if a user has guessed a correct letter in a word
//************************************************************************
bool hangman::doesLetterMatch(char letter, string &displayUser, string secretWord)
{
  bool myTracker = false;
  for (int i = 0; i < secretWord.size(); i++)
  {
    if (tolower(letter) == secretWord[i])
    {
      displayUser[i] = tolower(letter);
      myTracker = true;
    }
  }
  return myTracker;
}

//************************************************************************
// Function: guessLetters()
// Purpose: Game loop that continues until:
// 1. User runs out of tries
// 2. User guess completed word
// 3. My the use of letters only they guess and completed a word
//************************************************************************
void hangman::guessLetters()
{
  bool gameLoop = true;
  displayHiddenWord();

  while (gameLoop)
  {
    bool checkifWon = false;
    char letter = getLetter();
    cout << endl;

    if (letter == '?')
    {
      string userGuess = captureUserGuess();
      if (userGuess == secretWord)
      {
        winnerMessage();
        gameLoop = false;
        checkifWon = true;
        resetEverything();
      }
    }
    else if (checkSet(repeatedCharSet, letter))
    {
      repeatedCharSet.insert(letter);
      checkifWon = doesLetterMatch(letter, displayUser, secretWord);
      if (displayUser == secretWord)
      {
        gameLoop = false;
        winnerMessage();
        resetEverything();
      }
    }
    else
    {
      cout << RED << "\tThis letter has been used before" << WHITE << endl;
      cout << endl;
      checkifWon = true;
    }

    if (checkifWon == false)
    {
      addTries();
      hangmanDrawing();
    }

    cout << "\t" << displayUser << endl;
    if (triesLeft == 0)
    {
      gameLoop = false;
      loserMessage();
      resetEverything();

      cout << endl;
      cout << endl;
    }
  }
}

//************************************************************************
// Function: AiWord()
// Purpose: Generating a random word
//************************************************************************
string hangman::AiWord()
{
  resetEverything();
  vector<string> theVector;
  ifstream inFile;
  inFile.open("words.txt");

  srand(time(NULL));
  int counter = 0;
  string catcher;
  while (inFile >> catcher)
  {
    theVector.push_back(catcher);
    counter++;
  }
  int random = rand() % counter;
  string word = theVector.at(random);
  return word;
}

//************************************************************************
// Function: checkSet(set<char> repeatedCharSet, char x)
// Purpose: Making sure no letters are used more than once
//************************************************************************
bool hangman::checkSet(set<char> repeatedCharSet, char x)
{
  set<char>::iterator it;
  for (it = repeatedCharSet.begin(); it != repeatedCharSet.end(); it++)
  {
    if (*it == x)
    {
      return false;
    }
  }
  return true;
}

//************************************************************************
// Function: storeSecretWord(string x)
// Purpose: Storing the secret word
//************************************************************************
void hangman::storeSecretWord(string x)
{
  secretWord = x;
  while (secretWord == "")
  {
    termios oldt;
    tcgetattr(STDIN_FILENO, &oldt);
    termios newt = oldt;
    newt.c_lflag &= ~ECHO;
    tcsetattr(STDIN_FILENO, TCSANOW, &newt);
    cout << "Invalid phrase try another word :" << endl;
    cout << "\t";
    getline(cin, secretWord);
    tcsetattr(STDIN_FILENO, TCSANOW, &oldt);
  }

  for (int i = 0; i < secretWord.size(); i++)
  {
    secretWord[i] = tolower(secretWord[i]);
  }
}

void hangman::hangmanDrawing()
{
  if (triesLeft == 6 || triesLeft == 7)
  {
    cout << "\t ___________" << endl;
    cout << "\t|        |" << endl;
    cout << "\t|         " << endl;
    cout << "\t|______________" << endl;
    cout << endl;
  }
  else if (triesLeft == 5)
  {
    cout << "\t___________" << endl;
    cout << "\t|         |" << endl;
    cout << "\t|         0 " << endl;
    cout << "\t|______________" << endl;
    cout << endl;
  }
  else if (triesLeft == 4)
  {
    cout << "\t___________" << endl;
    cout << "\t|         |" << endl;
    cout << "\t|       \\ 0 " << endl;
    cout << "\t|______________" << endl;
    cout << endl;
  }
  else if (triesLeft == 3)
  {
    cout << "\t ___________" << endl;
    cout << "\t|         |" << endl;
    cout << "\t|       \\ 0 /" << endl;
    cout << "\t|______________" << endl;
    cout << endl;
  }
  else if (triesLeft == 2)
  {
    cout << "\t ___________" << endl;
    cout << "\t|        |" << endl;
    cout << "\t|      \\ 0 /" << endl;
    cout << "\t|        |" << endl;
    cout << "\t|______________" << endl;
    cout << endl;
  }
  else if (triesLeft == 1)
  {
    cout << "\t ___________" << endl;
    cout << "\t|         |" << endl;
    cout << "\t|       \\ 0 /" << endl;
    cout << "\t|         | " << endl;
    cout << "\t|        /  " << endl;
    cout << "\t|______________" << endl;
    cout << endl;
  }
  else
  {
    cout << "\t ___________" << endl;
    cout << "\t|         |" << endl;
    cout << "\t|       \\ 0 /" << endl;
    cout << "\t|         | " << endl;
    cout << "\t|        / \\ " << endl;
    cout << "\t|______________" << endl;
    cout << endl;
  }
}
