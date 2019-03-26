/*

Babacar Ndoye
Enjoy and give me feedback
*/

#include "TheGame.h"
#include "colors.h"
#include <cstdlib>
#include <iostream>
#include <termios.h>
#include <unistd.h>

int main() {
  Thegame obj;
  int choice;   // the bread and butter of the classes letter the user over and
                // over until they get tired
  int loop = 1; // used for the while loop below
  char ans = 'n';   // the original condition of the while loop
  string usersWord; // the secret word the user enters
  string topic;     // the topic for the hangman game

  while (ans == 'n' || ans == 'N') {
    cout << "Hello, my name is " << CYAN << "Babacar Ndoye " << WHITE
         << "and WELCOME TO MY GAME OF HANGMAN!!!!!!!!! " << endl;
    cout << endl;
    cout << RED << "RULE #1:" << WHITE
         << "This can be a 2+ player game or single player game" << endl;
    cout << "When you are past this screen: Select choice #1 and follow the "
            "directions."
         << endl;
    cout << "GOOD LUCK!!!!" << endl;
    cout << endl;
    cout << YELLOW << "Once you are ready,press any key and ENTER continue"
         << WHITE << endl;
    cin >> ans;
    system("clear");
  }
  while (loop) {
    cout << RED << "\t***************************" << WHITE << endl;
    cout << BLUE << "\t1)PUT IN THE WORD         *" << WHITE << endl;
    cout << YELLOW << "\t2)INSERT IN A TOPIC       *" << WHITE << endl;
    cout << GREEN << "\t3)Generate Computer Word  *" << WHITE << endl;
    cout << RED << "\t4)START GUESSING          *" << WHITE << endl;
    cout << CYAN << "\t5)RESET EVERYTHING        *" << WHITE << endl;
    cout << WHITE << "\t6)LEAVE THE GAME          *" << endl;
    cout << YELLOW << "\t***************************" << endl;
    cout << WHITE << "\tYour choice here >";
    cin >> choice;
    cout << endl;
    if (choice == 1) {

      termios oldt;
      tcgetattr(STDIN_FILENO, &oldt);
      termios newt = oldt;
      newt.c_lflag &= ~ECHO;
      tcsetattr(STDIN_FILENO, TCSANOW, &newt);
      cout << "\tPut in the secret phrase...Press Enter After" << endl;
      cout << "\t";
      cin.ignore();
      getline(cin, usersWord);
      tcsetattr(STDIN_FILENO, TCSANOW, &oldt);
      obj.storetheword(usersWord);
      cout << "YOUR SECRET WORD WAS SUCCESSFUL!!" << endl;
      cout << endl;
      
    }
    else if (choice == 2) {
      
      cout << "\tEnter a topic for the player who is guessing" << endl;
      cin.ignore();
      cout << "\t";
      getline(cin, topic);
      obj.setTopic(topic);
      cout << endl;
      cout << endl;

    } else if (choice == 3) {
      
      string ComputerWord = obj.AiWord();
      cout << "\tThe Computer has generated a word" << endl;
      obj.storetheword(ComputerWord);

    } else if (choice == 4) {
      
      obj.tryLetters();

    } else if (choice == 5) {
      
      obj.resetword();
      cout << "\tEVERYTHING HAS BEEN RESET" << endl;
      cout << endl;
      cout << endl;

    } else if (choice == 6) {

      cout << "\tThank you for trying out the game." << endl;
      cout << "\tPeace!!" << endl;
      loop = 0;

    }
  }
}
