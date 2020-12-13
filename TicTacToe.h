// Arnold Lev
// CSIS 137 (Online)
// Homework #1

#ifndef TICTACTOE_H
#define TICTACTOE_H

class TicTacToe {
	private:
		int board[3][3];
		int rows;
		int columns;
		int player;
		int winner;
		char changeLetter(int) const;
		void setColumns(int);
		void setRows(int);
	public:
		TicTacToe();
		TicTacToe(TicTacToe&);
		int getRows() const;
		int getColumns() const;
		int getPlayer() const;
		int getWinner() const;
		bool setPlayer(int);
		bool setWinner(int);
		bool makeMove(int, int);
		bool checkWin();
		bool isTie();
		void printBoard();
		void changeTurn();
};

#endif