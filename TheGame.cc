#include "TheGame.h"
#include "colors.h"

// Function : DisplayHiddenWord
// Purpose : To display the word as a combination of (-) example:dog as  (---)
void Thegame::displayHiddenWord() {
  if (topic != "") {
    cout << "\tThe Topic is : " << topic << endl;
    cout << endl;
  }
  for (int i = 0; i < (int)response.length(); i++) {
    if (isalnum(response[i])) {
      shown = shown + "-"; // keeping track of user letters
    } else {
      shown = shown + response[i]; // If the character is not a letter
    }
  }
  cout << "\t" << shown << endl; // diplaying hidden word
}

// function : TryLetters
// purpose : the bread and butter of hangman guessing the letters
void Thegame::tryLetters() {

  bool loop = true;
  bool guessCapture = false; // if user attempts to guess make display
  displayHiddenWord(); // in function display hidden word that return

  while (loop) {
     
    bool tracker = false; // used to keep track of the tries 

    char letter;
    cout << "\tGuess a letter that you think is in the phrase or enter (?) to guess the word" << endl;
    cout << "\t";
    cin >> letter;

    if (letter == '?') // leaving
    {
      cout << "\tWhat do you think the secret word is : " << endl;
      string theirGuess;
      cin.ignore();
      cout << "\t";
      getline(cin, theirGuess);

      if(theirGuess == response){
      guessCapture = true; //if user gets it correct you dont want it to show 2 winning screens
      cout << "\tSecret Word: " << RED << response << WHITE << endl;
      cout << CYAN << "\tCONGRATS YOU WIN!!!" << WHITE << endl;
      cout << "\tTry the game again... Thank you" << endl;
      loop = false;
      tracker = true;
      shown = response;
      resetword();
      }

    } else if (checkSet( mySet, letter )) // checking if the letter hasn't been used before
    {
      mySet.insert(letter); // input letter into set

      for (int b = 0; b < (int)response.size(); b++) {
        if (toupper(letter) == toupper(response[b])) {
          shown[b] = tolower(letter); //
          tracker = true; // to capture if that letter is in the word or not
        }
      }
    } else {
      cout << RED << "\tThis letter has been used before" << endl;
      tracker = true;
      cout << WHITE;
    }

    if (tracker == false) // if no letters matched the string
    {
      addTries();
      hangmandrawing();
    }
    
    //this if is purely for those individuals that guessed with characters
    //not the string as a whole
    if (shown == response && guessCapture == false) // if you hit the last step in guessing letter
    {
      loop = false;
      cout << "\tSecret Word: " << RED << response <<WHITE<< endl;
      cout << CYAN << "\tCONGRATS YOU WIN!!!" << WHITE << endl;
      cout << "\tTry the game again... Thank you" << endl;
      resetword();
    } 
    cout << "\t" << shown << endl;
    if (tries == 0) {
      loop = false;
      cout << "\tSorry you lose" << endl;
      cout << "\tTHE SECRET WORD WAS: " << response << endl;
      cout << "\tTry the game again." << endl;
      resetword();

      cout << endl;
      cout << endl;
    }
  }
}

// function : AiWord
// purpose : to generate a random word using files
string Thegame::AiWord() {
  resetword();
  vector<string> theVector;
  ifstream inFile;
  inFile.open("words.txt");

  srand(time(NULL));
  int counter = 0; // counter used to find the size of the file
  string catcher;
  while (inFile >> catcher) // counting words in file
  {
    theVector.push_back(catcher); // puts it in a vector
    counter++;                    // to keep track of the total in that file
  }
  int random = rand() % counter;
  string word = theVector.at(random);
  return word;
}

// function: checkSet
// purpose : to figure out if a word is repeated when they are guessing
bool Thegame::checkSet(set<char> mySet, char x) {
  set<char>::iterator it;
  for (it = mySet.begin(); it != mySet.end(); ++it) {
    if (*it == x) {
      return false;
    }
  }
  return true;
}

// function : storetheword
// purpose : storing the secret word
// simply placing the secret phrase in a private variable
void Thegame::storetheword(string x) {
  response = x;
  while (response == "") // If user enters a empty string
  {
    termios oldt;
    tcgetattr(STDIN_FILENO, &oldt);
    termios newt = oldt;
    newt.c_lflag &= ~ECHO;
    tcsetattr(STDIN_FILENO, TCSANOW, &newt);
    cout << "Invalid phrase try another word :" << endl;
    cout << "\t";
    getline(cin, response);
    tcsetattr(STDIN_FILENO, TCSANOW, &oldt);
  }

  for (int i = 0; i < (int)response.size(); ++i) {
    response[i] = tolower(response[i]);
  }
}

void Thegame::setTopic(string x) { topic = x; }

// function : resetWord
// purpose : Refreshes everything to a new game
void Thegame::resetword() {
  mySet.clear();
  response = "";
  shown = "";
  topic = "";
  tries = 7;
}

void Thegame::addTries() { tries--; }

void Thegame::hangmandrawing() {
  if (tries == 6 || tries == 7) {
    cout << "\t ___________" << endl;
    cout << "\t|        |" << endl;
    cout << "\t|         " << endl;
    cout << "\t|______________" << endl;
    cout << endl;
  } else if (tries == 5) {
    cout << "\t___________" << endl;
    cout << "\t|         |" << endl;
    cout << "\t|         0 " << endl;
    cout << "\t|______________" << endl;
    cout << endl;

  } else if (tries == 4) {
    cout << "\t___________" << endl;
    cout << "\t|         |" << endl;
    cout << "\t|       \\ 0 " << endl;
    cout << "\t|______________" << endl;
    cout << endl;
  } else if (tries == 3) {
    cout << "\t ___________" << endl;
    cout << "\t|         |" << endl;
    cout << "\t|       \\ 0 /" << endl;
    cout << "\t|______________" << endl;
    cout << endl;
  } else if (tries == 2) {
    cout << "\t ___________" << endl;
    cout << "\t|        |" << endl;
    cout << "\t|      \\ 0 /" << endl;
    cout << "\t|        |" << endl;
    cout << "\t|______________" << endl;
    cout << endl;
  } else if (tries == 1) {
    cout << "\t ___________" << endl;
    cout << "\t|         |" << endl;
    cout << "\t|       \\ 0 /" << endl;
    cout << "\t|         | " << endl;
    cout << "\t|        /  " << endl;
    cout << "\t|______________" << endl;
    cout << endl;
  } else {
    cout << "\t ___________" << endl;
    cout << "\t|         |" << endl;
    cout << "\t|       \\ 0 /" << endl;
    cout << "\t|         | " << endl;
    cout << "\t|        / \\ " << endl;
    cout << "\t|______________" << endl;
    cout << endl;
  }
}
