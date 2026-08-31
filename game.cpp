/*
This is a program that picks a random number between 1-100 and then asks the user to guess it.
The program then tells the user if their guess was high, low, or correct.
When the user guesses the number right, the program tells them how many guesses they tool and gives them the option to play again or quit.

Created By: Matthew Graham

Last Updated: 8/31/26
*/

/*
3 Rules for this C++ class:
1) No Global Variables.
2) No Strings whatsoever
3) Use C++ commands instead of C commands (<iostream> instead of studio, new instead of malloc, delete instead of free)
Secret 4th and 5th strongly worded reccomendations:
4) Avoid using a mouse when possible
5) Avoid using Break/Continue unless you have to (like in a switch statement).
*/

// include libraries and set namespace
#include <iostream>
#include <ctime>
#include <cstdlib>
using namespace std;

//main loop
int main(){
  // defines all variables used in the program
  int targetNum = -1;
  int guess = -1;
  int guesses = 0;
  bool running = true;
  bool guessed = false;
  bool hasInput = false;
  char cont = 'n';
  char dialogue1[33] = "Guess a Number between 1 and 100";
  char dialogue2[22] = "Enter a Valid Number!";
  char dialogue3[34] = "Enter a Number between 1 and 100!";
  char dialogue4[43] = "You Guessed Correctly! Number of Guesses: ";
  char dialogue5[20] = "Too low! Try Again!";
  char dialogue6[22] = "Too high! Try Again!";
  char dialogue7[19] = "Try Again? (y/n): ";
  char dialogue8[9] = "Goodbye!";
  char dialogue9[22] = "Ok, Resetting Game...";
  char dialogue10[24] = "Please Enter 'y' or 'n'";

  //set random seed
  srand(time(NULL));

  // main game loop
  while (running == true){
    targetNum = (rand() % 100) + 1;
    guessed = false;
    // loops until correct guess
    while (guessed == false){
      hasInput = false;
      cout << dialogue1 << endl;
      // loops until correct input
      while (hasInput == false){
	cin >> guess;
	// checks if something other than an int was entered
	if (cin.fail()){
	  cout << dialogue2 << endl;
	  // resets cin function 
	  cin.clear();
	  cin.ignore(99999,'\n');
	  // checks if the guess is out of range
	} else if ((guess < 1) or (guess > 100)){
	  cout << dialogue3 << endl;
	  // increments guess counter if guess is valid
	} else {
	  hasInput = true;
	  guesses++;
	}
      }
      // checks if guess was right and outputs it/stops the loop
      if (guess == targetNum){
	cout << dialogue4 << guesses << endl;
	guessed = true;
	// outputs if guess was too low
      } else if (guess < targetNum){
	cout << dialogue5 << endl;
	// outputs if guess was too high
      } else if (guess > targetNum){
	cout << dialogue6 << endl;
      }
    }
    // checks if the user wants to restart
    hasInput = false;
    while (hasInput == false){
      // gets y/n input from the user
      cout << dialogue7;
      cin >> cont;
      // stops loop if user answers no to reset
      if (cont == 'n'){
	hasInput = true;
	cout << dialogue8 << endl;
	running = false;
	// resets game if user answers yes
      } else if (cont == 'y'){
	hasInput = true;
	cout << dialogue9 << endl;
	guesses = 0;
	// asks question again if there was no yes or no
      } else {
	cout << dialogue10 << endl;
      }
    }
  }
  return 0;
}

