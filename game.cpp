/*
This is a program that picks a random number between 1-100 and then asks the user to guess it.
The program then tells the user if their guess was high, low, or correct.
When the user guesses the number right, the program tells them how many guesses they tool and gives them the option to play again or quit.
*/

/*
3 Rules for this C++ class:
1) No Global Variables.
2) No Strings. Period.
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

  srand(time(NULL));

  // Ask galbraith if printing with cout like this counts as using strings
  // TODO: Fix (probably)
  // main game loop
  while (running == true){
    targetNum = rand() % 100;
    guessed = false;
    // loops until correct guess
    while (guessed == false){
      hasInput = false;
      cout << "Guess a Number between 1 and 100" << endl;
      // loops until correct input
      while (hasInput == false){
	cin >> guess;
	if (cin.fail()){
	  cout << "Enter a Valid Number!" << endl;
	  cin.clear();
	  cin.ignore(99999,'\n');	
	} else if ((guess < 1) or (guess > 100)){
	  cout << "Enter a Number between 1 and 100!" << endl;
	  cin.ignore(99999,'\n');
	} else {
	  hasInput = true;
	  guesses++;
	  cin.ignore(99999,'\n');
	}
      }
      // checks if guess was right
      if (guess == targetNum){
	cout << "You Guessed Correctly! Number of Guesses: " << guesses << endl;
	guessed = true;
      } else if (guess < targetNum){
	cout << "Too low! Try Again!" << endl;
      } else if (guess > targetNum){
	cout << "Too high! try Again!" << endl;
      }
    }
    hasInput = false;
    while (hasInput == false){
      cout << "Try Again? (y/n): ";
      cin >> cont;
      if (cont == 'n'){
	hasInput = true;
	cout << "Goodbye!" << endl;
	running = false;
      } else if (cont == 'y'){
	hasInput = true;
	cin.ignore(99999, '\n')
	cout << "Ok, Resetting Game..." << endl;
      } else {
	cout << "Please Enter 'y' or 'n'" << endl;
	cin.ignore(99999,'\n');
      }
    }
  }
  return 0;
}

