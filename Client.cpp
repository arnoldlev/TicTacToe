// Arnold Lev
// CSIS 137 (Online)
// Homework #1

#include <iostream>
#include "TicTacToe.h"
using namespace std;

int main() {
	TicTacToe game;
	int row, column;

	cout << "Time to play Tic Tac Toe! " << endl;
	game.printBoard();
	cout << endl;

	while (game.getWinner() == 0) {
		cout << "Player " << game.getPlayer() << " Turn: " << endl;
		cout << "Enter a row: ";
		cin >> row;
		cout << "Enter a column: ";
		cin >> column;
		 
		while (!game.makeMove(row - 1, column - 1)) {
			cout << "Error: That is not a valid row / column! Try again" << endl;
			cout << "Enter a row: ";
			cin >> row;
			cout << "Enter a column: ";
			cin >> column;
		}
	}

	if (game.getWinner() != 3) {
		cout << "Congraulations to Player " << game.getWinner() << " on winning the game!" << endl;
	} else {
		cout << "It was a tie! Good game" << endl;
	}

	return 0;
}