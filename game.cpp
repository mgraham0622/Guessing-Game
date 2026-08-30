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
using namespace std;

//main loop
int main(){
  int targetNum = -1;
  int guess = -1;
  bool running = true;
  bool guessed = false;
  bool has_input = false;

  srand(time(NULL));

  // TODO: Ask galbraith if printing with cout like this counts as using strings
  // TODO: Fix (probably)
  while (running == true){
    targetNum = rand() % 100;
    cout << "Guess a Number between 1 and 100" << endl
    while (guessed == false){
      cin >> guess;
      if (cin.fail()){
	cout << "Enter a Valid Number!" << endl
      }
    }
  }
  return 0;
}
 
