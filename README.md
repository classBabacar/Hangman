
# To knows
This program contains a linux library, the reason I included this library was because 
there is a way to make a user's input invisible and that is ideal when playing hangman with someone who is in the same room as you and don't want them to see the secret code you just typed. 
# Inspiration
I like the game of hangman, and decided to make it after my first programming class, I primarily made this game to 
play with my nephews also to kind of teach them how to problem solve...Why is this letter a good choice? Could there be a better one? Is it worth it guessing a whole word when there is one revealed letter out of 10 letters?

# Features                                                      
- 1v1 Play                                                                                           
- AI Selected Word                                                                

# Bugs
Bug Fix: **10/22/2018**
- An infinite loop if someone entered a space as a secret word.
- If someone entered a capital letter as a secret word, the program would expect a capital letter from the guesser. 

Bug Fix: **03/06/2019**
- Since I was improperly clearing a set if someone happened to use the same letter again for a completely new word(where intances of letters should be reset), it wouldn't allow you to use the first letter that appears in the set for that new word.

Bug Fix: **03/26/2019**
- If someone entered a empty string as their secret word it would be accepted. Funnily enough, this was the bug that was produced from the bug patch above. This taught me how to have foresight in catching more bugs.

Bug Fix: **7/9/2019 (Complete Re-model)** 
- Complete re-model of what I wrote before it was really hard to maintain also there was a huge bug where if a secretWord was "bob" and I decided to guess the whold word with "Bob" this would would be incorrect in computers eyes.

# Running Code using Makefile

I recommend that you compile with ``make build``

Run the program with ``./game``

To delete the ``./game`` do:

 ``make clean``

