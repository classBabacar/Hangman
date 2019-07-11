/*
Babacar Ndoye
Enjoy and give me feedback
*/

#include "hangman.h"
#include "colors.h"
#include <iostream>
#include <termios.h>
#include <unistd.h>

int main()
{
    hangman obj;
    int choice;
    int loop = 1;
    char ans = 'n';
    string usersWord;
    string topic;

    while (ans == 'n' || ans == 'N')
    {
        cout << "Hello, my name is " << CYAN << "Babacar Ndoye " << WHITE << "and WELCOME TO MY GAME OF HANGMAN!!!!!!!!! " << endl;
        cout << endl;
        cout << RED << "Note :" << WHITE << " This is a Single or 2 Player Game, GOOD LUCK!!!! I hope you enjoy " << endl;
        cout << endl;
        cout << YELLOW << "Once you are ready, press any key and (ENTER) to continue." << WHITE << endl;
        cin >> ans;
        system("clear");
    }
    while (loop)
    {
        cout << RED << "\t***************************" << WHITE << endl;
        cout << BLUE << "\t1 - Insert Topic" << WHITE << endl;
        cout << YELLOW << "\t2 - Generate Computer Word" << WHITE << endl;
        cout << GREEN << "\t3 - Generate User Word" << WHITE << endl;
        cout << RED << "\t4 - Start Game" << WHITE << endl;
        cout << CYAN << "\t5 - Reset Game" << WHITE << endl;
        cout << WHITE << "\t6 - Leave Game" << endl;
        cout << YELLOW << "\t***************************" << endl;
        cout << WHITE << "\tYour choice here >";
        cin >> choice;
        cout << endl;

        if (choice == 1)
        {
            cout << "\tEnter a topic for the opposing player : " << endl;
            cin.ignore();
            cout << "\t";
            getline(cin, topic);
            obj.setTopic(topic);
            cout << endl;
            cout << endl;
        }

        else if (choice == 2)
        {
            string ComputerWord = obj.AiWord();
            cout << "\tThe Computer has generated a word." << endl;
            obj.storeSecretWord(ComputerWord);
        }
        else if (choice == 3)
        {
            termios oldt;
            tcgetattr(STDIN_FILENO, &oldt);
            termios newt = oldt;
            newt.c_lflag &= ~ECHO;
            tcsetattr(STDIN_FILENO, TCSANOW, &newt);
            //Making input invisible

            cout << "\tPut in the secret phrase...Press (Enter) once you're finished." << endl;
            cout << "\t";
            cin.ignore();
            getline(cin, usersWord);

            tcsetattr(STDIN_FILENO, TCSANOW, &oldt);
            //This is where it stops

            obj.storeSecretWord(usersWord);
            cout << "Your secret word has been stored!!!" << endl;
            cout << endl;
        }

        else if (choice == 4)
        {
            obj.guessLetters();
        }
        else if (choice == 5)
        {
            obj.resetEverything();
            cout << "\tEverything has been reset." << endl;
            cout << endl;
            cout << endl;
        }
        else if (choice == 6)
        {
            cout << "\tThank you for playing the game I hope you enjoyed it." << endl;
            loop = 0;
        }
    }
}