
# To knows
This program contains a linux library, the reason I included this library was because 
there is a way to make a users input invisible and that is ideal when playing hangman because 
it would defeat the purpose of playing with someone in the same room.

# Inspiration
I like the game of hangman, and decided to make it after my first programming class, I primarily made this game to 
play with my nephews.

# Features                                                      
- 1v1 Play                                                                                           
- AI choosing a word for you to guess                                                                 

# Bugs
Bug Fix: **10/22/2018**
- An infinite loop if someone entered a space as a secret word
- If someone entered a capital letter as a secret word, the program would expect a capital letter from the guesser. 

Bug Fix: **03/06/2019**
- Since I was improperly clearing a set if someone happened to use the same word again it would pick a random character in that string and wouldnt allow you to use it, so in turn never ending the game           

Bug Fix: **03/26/2019**
- If someone entered a empty string it would accept their secret word so to fix this problem I just ask them again

Bug Fix: **7/9/2019 (Complete Remodel)** 
- Complete re-model of what I wrote before it was really hard to maintain also there was a huge bug where if a secretWord was "bob" and I decided to guess with the word
"Bob" this would be incorrect in the computers eyes.

