// 2/18/2024; MEMORY GAME;

#include <iostream>
#include <string>
#include <fstream>
#include <time.h>
const int LENGTH = 4;
using namespace std;

// Function prototypes
void InitializeCards(int cards[][LENGTH]);
void ShowCards(int cards[][LENGTH], bool faceup[][LENGTH]);
void TempFlip(int cards[][LENGTH], bool faceup[][LENGTH],
int xCord1, int yCord1, int xCord2, int yCord2);
bool CheckGameOver(bool faceup[][LENGTH]);

// Main function
int main() {
	string userName;
	bool isGameOver = false;
	char userInput;
	bool faceup[LENGTH][LENGTH];
	int xCord1;
	int yCord1;
	int xCord2;
	int yCord2;
	int numTurns = 0;

	// 1) Welcome the user and ask him to enter his full name.
	cout << "Welcome to my game!" << endl << "Please enter your full name: ";
	getline(cin, userName);
	cout << endl << "Find all the matching pairs on the board!" << endl << endl;

	// 2) Create a two 2D array that will hold the number for each card.
  // Pass it to InitializeCards function.
	int cards[LENGTH][LENGTH];
	InitializeCards(cards);

	// 3) Create the 2D array of Booleans that represents whether or not the card is matched.
	// This should be initialized to all FALSE at first.
	for (int i = 0; i < LENGTH; i++) {
		for (int j = 0; j < LENGTH; j++) {
			faceup[i][j] = false;
		}
	}

	// 4) while the game is not over :
	while (isGameOver == false) {

		// Display the current state of the game board. Remember that non-matched pairs should be "facedown"
		// and that matched pairs should be "faceup"
		cout << "  0 1 2 3" << endl;
		cout <<  "  =========" << endl;
		ShowCards(cards, faceup);
		cout <<  "  =========" << endl;

		// Prompt the user to enter the coordinates of two cards
		// Note: user can choose to quit

		cout << endl;
		cout << "Enter x and y position of the first card: ";

		cin >> xCord1;
    cin >> yCord1;

    while ((xCord1 < 0 || xCord1 > 3) || (yCord1 < 0 || yCord1 > 3)) {
      cout << "Invalid Input(s). Please enter a number between 0 and 3: ";
      cin >> xCord1;
      cin >> yCord1;
    }

		cout << endl;
		cout << "Enter x and y position of the second card: ";

		cin >> xCord2;
		cin >> yCord2;

    while ((xCord2 < 0 || xCord2 > 3) || (yCord2 < 0 || yCord2 > 3)) {
      cout << "Invalid Input(s). Please enter a number between 0 and 3: ";
      cin >> xCord2;
      cin >> yCord2;
    }

		cout << endl;

		// If the values of the two coordinates match :
		// say that a match has been found and flip the cards over forever
		// else :
		// temporarily flip over the cards to show the user the values, then flip them over again.
		if (cards[xCord1][yCord1] == cards[xCord2][yCord2]) {
			cout << "A match has been found!" << endl << endl;
			faceup[xCord1][yCord1] = true;
			faceup[xCord2][yCord2] = true;
		}
		else {
      cout << "  0 1 2 3" << endl;
      cout <<  "  =========" << endl;
      TempFlip(cards, faceup, xCord1, yCord1, xCord2, yCord2);
      cout <<  "  =========" << endl << endl;

			cout << "No match" << endl;
			cout << "Flipping cards over again" << endl;
			cout << "Enter 'q' to quit or press any key to continue..." << endl;
			cin >> userInput;
		}

		numTurns++;

			// 5) Save the user’s name and how many turns it took to win the game into an output text file. If he quits
			// before winning save “Don’t give up” message in the file.
			isGameOver = CheckGameOver(faceup);

			if (isGameOver == true) {
				cout << "Congratulations, you won!!";
				ofstream myfile;
				myfile.open("gameHistory.txt");
				myfile << "Name: " << userName << endl;
				myfile << "Turns Used: " << numTurns << endl;
				myfile.close();
			}

			if (userInput == 'q') {
				cout << "Nice try, see you next time!";
				ofstream myfile;
				myfile.open("gameHistory.txt");
				myfile << "Don't give up!!!" << endl;
				myfile.close();
				isGameOver = true;
			}

		}
	}

// InitializeCards
// Places pairs of numbers in the 2D array and then randomly shuffles them.
// Recives cards array and returns nothing (void)

void InitializeCards(int cards[][LENGTH])
{
	//seed rand() - remember to always do this before using rand()
	// also make sure to include the <time.h> library.
	srand(time(NULL));
	int x1, y1, x2, y2;
	int temp;

	// Place pairs in known locations -   this is how our array looks like after
	cards[0][0] = 1; cards[0][1] = 1;//   1  1  2  2
	cards[0][2] = 2; cards[0][3] = 2;
	cards[1][0] = 3; cards[1][1] = 3;//   3  3  4  4
	cards[1][2] = 4; cards[1][3] = 4;
	cards[2][0] = 5; cards[2][1] = 5;//   5  5  6   6
	cards[2][2] = 6; cards[2][3] = 6;
	cards[3][0] = 7; cards[3][1] = 7;//   7  7  8   8
	cards[3][2] = 8; cards[3][3] = 8;

	// Now that 2D has been initialized with 8 pairs, we want to shuffle the board so
	// that the pairs aren't right next to each other
	for (int i = 0; i < 30; i++) {
		//Get set of random coordinates and swap
		//First random coordinate on our 2d "grid"
		y1 = rand() % LENGTH;
		x1 = rand() % LENGTH;
		//Second random coordinate of our 2d "grid"
		y2 = rand() % LENGTH;
		x2 = rand() % LENGTH;

		//Now we swap value at (x1, y1) with value at(x2, y2)
		temp = cards[x1][y1];
		cards[x1][y1] = cards[x2][y2];
		cards[x2][y2] = temp;
		//Note: just like with 1D arrays, modifying an n-dimensional array inside
		// a function will change the array itself
	}
}

// ShowCards: Generates a display on the screen.  If faceup=false,
// an * is output, otherwise the card in that slot is output.
// Receives two 2D arrays, cards and faceup
// Returns nothing

void ShowCards(int cards[][LENGTH], bool faceup[][LENGTH]) {

	for (int i = 0; i < LENGTH; ++i) {
		cout << i << "|";
		for (int j = 0; j < LENGTH; ++j) {
			if (faceup[i][j] == false) {
				cout << "* ";
			}
			else {
				cout << cards[i][j] << " ";
			}
		}
		cout << "|" << endl;
	}

}

// TempFlip: Essentially the same as ShowCards but also temporaily flips the
// cards that the user guesses, even if they don't match and displays them,
// Receives two 2D arrays: cards and faceup. Returns nothing.

void TempFlip(int cards[][LENGTH], bool faceup[][LENGTH],
int xCord1, int yCord1, int xCord2, int yCord2) {

  faceup[xCord1][yCord1] = true;
  faceup[xCord2][yCord2] = true;

	for (int i = 0; i < LENGTH; ++i) {
		cout << i << "|";
		for (int j = 0; j < LENGTH; ++j) {
			if (faceup[i][j] == false) {
				cout << "* ";
			}
			else {
				cout << cards[i][j] << " ";
			}
		}
		cout << "|" << endl;
	}

  faceup[xCord1][yCord1] = false;
  faceup[xCord2][yCord2] = false;

}

// CheckGameOver: Checks wether the game is over or not by iterating through the
// faceup array to check if every card is faceup. If so, it returns true.
// **receives faceup array

bool CheckGameOver(bool faceup[][LENGTH]) {
	bool isGameOver = true;
	for (int i = 0; i < LENGTH; i++) {
		for (int j = 0; j < LENGTH; j++) {
			if (faceup[i][j] == false) {
				isGameOver = false;
			}
		}
	}
	return isGameOver;
}

// CODE OUTPUT:
/*
Welcome to my game!
Please enter your full name: Jessica Nguyen

Find all the matching pairs on the board!

  0 1 2 3
  =========
0|* * * * |
1|* * * * |
2|* * * * |
3|* * * * |
  =========

Enter x and y position of the first card: -1 3
Invalid Input(s). Please enter a number between 0 and 3 [inclusive]: 1 3

Enter x and y position of the second card: 3 0

  0 1 2 3
  =========
0|* * * * |
1|* * * 3 |
2|* * * * |
3|6 * * * |
  =========

No match
Flipping cards over again
Enter 'q' to quit or press any key to continue...
i
  0 1 2 3
  =========
0|* * * * |
1|* * * * |
2|* * * * |
3|* * * * |
  =========

Enter x and y position of the first card: 2 0

Enter x and y position of the second card: 3 3

  0 1 2 3
  =========
0|* * * * |
1|* * * * |
2|8 * * * |
3|* * * 7 |
  =========

No match
Flipping cards over again
Enter 'q' to quit or press any key to continue...
q
Nice try, see you next time!
Press any key to continue . . .

*/
