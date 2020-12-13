// Arnold Lev
// CSIS 137 (Online)
// Homework #1

#include "TicTacToe.h"
#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;

/* Intializing Constructor */
TicTacToe::TicTacToe() {
	srand((unsigned int)time(NULL));
	setRows(3);
	setColumns(3);
	setPlayer(rand() % 2 + 1);
	setWinner(0);
	for (int r = 0; r < 3; r++) {
		for (int c = 0; c < 3; c++) {
			board[r][c] = 0;
		}
	}
}

/* Copy Constructor */
TicTacToe::TicTacToe(TicTacToe& t) {
	t.setRows(3);
	t.setColumns(3);
	t.setPlayer(getPlayer());
	t.setWinner(getWinner());
	for (int r = 0; r < 3; r++) {
		for (int c = 0; c < 3; c++) {
			t.board[r][c] = board[r][c]; // I wanted to make a private getBoard() but unsure
		}                                // how to return a 2D Array / Pointer
	}
}

/* Changes the turn for the player */
void TicTacToe::changeTurn() {
	if (getPlayer() == 1) {
		setPlayer(2);
	} else {
		setPlayer(1);
	}
}

/* Checks if the game ended in a tie */
bool TicTacToe::isTie() {
	int counter = 0;
	for (int r = 0; r < 3; r++) {
		for (int c = 0; c < 3; c++) {
			if (board[r][c] != 0) {
				counter++;
			}
		}
	}
	return counter >= 9;
}

/* Checks if a game has finished */
bool TicTacToe::checkWin() {
	for (int c = 0; c < 3; c++) {
		if (board[0][c] == board[1][c] && board[0][c] == board[2][c]) {
			setWinner(board[0][c]);
			return true;
		}
	}
	for (int r = 0; r < 3; r++) {
		if (board[r][0] == board[r][1] && board[r][0] == board[r][2]) {
			setWinner(board[r][0]);
			return true;
		}
	}

	if (isTie()) {
		setWinner(3);
		return true;
	} else if (board[0][2] == board[1][1] && board[1][1] == board[2][0]) {
		setWinner(board[0][2]);
		return true;
	} else if (board[0][0] == board[1][1] && board[1][1] == board[2][2]) {
		setWinner(board[0][0]);
		return true;
	} else {
		return false;
	}


}

/* Allows the client to initiate a move*/
bool TicTacToe::makeMove(int r, int c) {
	if ((r > 2 || r < 0) || (c > 2 || c < 0)) {
		return false;
	} else if (board[r][c] != 0) {
		return false;
	} else {
		board[r][c] = player;
		changeTurn();
		printBoard();
		checkWin();
		return true;
	}
	
}

/* Prints a nice format of the board */
void TicTacToe::printBoard() {
	cout << " C O L U M N S  ";
	for (int r = 0; r < 3; r++) { 
		cout << endl;
		cout << "   ____________" << endl;
		for (int c = 0; c < 3; c++) {
			if (c == 0)
				cout << changeLetter(r) << " | ";
			cout << board[r][c] << " | ";
		}
	}
	cout << endl;
}

/* PRIVATE UTILITY METHOD FOR BOARD DISPLAY*/
char TicTacToe::changeLetter(int row) const {
	if (row == 0) {
		return 'R';
	}
	else if (row == 1) {
		return 'O';
	}
	else {
		return 'W';
	}
}

/* PRIVATE UTILITY METHOD FOR COPY CONSTURCTOR */
void TicTacToe::setRows(int r) {
	rows = r;
}

/* PRIVATE UTILITY METHOD FOR COPY CONSTURCTOR */
void TicTacToe::setColumns(int c) {
	columns = c;
}

bool TicTacToe::setPlayer(int p) {
	if (p < 1 || p > 2) {
		return false;
	}
	player = p;
	return true;
}

bool TicTacToe::setWinner(int w) {
	if (w < 0 || w > 3) {
		return false;
	}
	winner = w;
	return true;
}

int TicTacToe::getRows() const {
	return rows;
}

int TicTacToe::getColumns() const {
	return columns;
}

int TicTacToe::getPlayer() const {
	return player;
}

/* 
0 = No Winner
1 = Player 1
2 = Player 2
3 = Tie
*/
int TicTacToe::getWinner() const {
	return winner;
}