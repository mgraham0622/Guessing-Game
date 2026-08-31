/*
This is a program that picks a random number between 1-100 and then asks the user to guess it.
The program then tells the user if their guess was high, low, or correct.
When the user guesses the number right, the program tells them how many guesses they tool and gives them the option to play again or quit.
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

    
  srand(time(NULL));

  // TODO: Fix (probably)
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
	if (cin.fail()){
	  cout << dialogue2 << endl;
	  cin.clear();
	  cin.ignore(99999,'\n');	
	} else if ((guess < 1) or (guess > 100)){
	  cout << dialogue3 << endl;
	  cin.ignore(99999,'\n');
	} else {
	  hasInput = true;
	  guesses++;
	  cin.ignore(99999,'\n');
	}
      }
      // checks if guess was right
      if (guess == targetNum){
	cout << dialogue4 << guesses << endl;
	guessed = true;
      } else if (guess < targetNum){
	cout << dialogue5 << endl;
      } else if (guess > targetNum){
	cout << dialogue6 << endl;
      }
    }
    hasInput = false;
    while (hasInput == false){
      cout << dialogue7;
      cin >> cont;
      if (cont == 'n'){
	hasInput = true;
	cout << dialogue8 << endl;
	running = false;
      } else if (cont == 'y'){
	hasInput = true;
	cin.ignore(99999, '\n');
	cout << dialogue9 << endl;
	guesses = 0;
      } else {
	cout << dialogue10 << endl;
	cin.ignore(99999,'\n');
      }
    }
  }
  return 0;
}

