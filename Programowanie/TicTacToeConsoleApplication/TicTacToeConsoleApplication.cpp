#include <iostream>

/*
DRY
KISS
YAGNI
SOLID
*/

void clearBoard(char board[], unsigned short size)
{
	for (int i = 0; i < size * size; i++)
		board[i] = ' ';
}

void drawRow(char board[], unsigned short size, int row)
{
	for (int col = 0; col < size; col++)
	{
		std::cout << " " << board[size * row + col] << " ";
		if (col < size - 1)
			std::cout << "|";
	}
	std::cout << "\n";
}

void drawHorizontalFrame(unsigned short size, int row)
{
	if (row < size - 1)
	{
		for (int col = 0; col < size; col++)
		{
			std::cout << "---";
			if (col != size - 1)
				std::cout << "+";
		}
		std::cout << "\n";
	}
}

void drawBoard(char board[], unsigned short size)
{
	for (int row = 0; row < size; row++)
	{
		drawRow(board, size, row);
		drawHorizontalFrame(size, row);
	}

}

int GetPlaceOnBoard(char playerSign)
{
	int fieldNumber;
	std::cout << "Gracz " << playerSign << " wykonuje ruch\n";
	std::cout << "Podaj numer pola:\n";
	std::cin >> fieldNumber;

	return fieldNumber;
}

bool isWinInRow(char board[], unsigned short size, char currentPlayerSign, int row)
{
	for (int fieldInRow = 0; fieldInRow < size; fieldInRow++)
	{
		if (board[size * row + fieldInRow] != currentPlayerSign)
			return false;
	}
	return true;
}

bool isWinInRows(char board[], unsigned short size, char currentPlayerSign)
{
	for (int row = 0; row < size; row++)
	{
		if (isWinInRow(board, size, currentPlayerSign, row))
		     return true;
	}
	return false;
}

bool isWinInCol(char board[], unsigned short size, char currentPlayerSign, int col)
{
	for (int fieldInCol = 0; fieldInCol < size; fieldInCol++)
	{
		if (board[size * fieldInCol + col] != currentPlayerSign)
			return false;
	}
	return true;
}

bool isWinInCols(char board[], unsigned short size, char currentPlayerSign)
{
	for (int col = 0; col < size; col++)
	{
		if (isWinInCol(board, size, currentPlayerSign, col))
			return true;
	}
	return false;
}

bool isWinInLeftDiagonal(char board[], unsigned short size, char currentPlayerSign)
{
	for (int fieldInDiagonal = 0; fieldInDiagonal < size; fieldInDiagonal++)
	{
		if (board[size * fieldInDiagonal + fieldInDiagonal] != currentPlayerSign)
			return false;;
	}
	return true;
}

bool isWinInRightDiagonal(char board[], unsigned short size, char currentPlayerSign)
{
	for (int fieldInDiagonal = 0; fieldInDiagonal < size; fieldInDiagonal++)
	{
		if (board[size * fieldInDiagonal + size - fieldInDiagonal - 1] != currentPlayerSign)
			return false;;
	}
	return true;
}

bool isWinInDiagonals(char board[], unsigned short size, char currentPlayerSign)
{
	if (isWinInLeftDiagonal(board, size, currentPlayerSign))
		return true;

	if (isWinInRightDiagonal(board, size, currentPlayerSign))
		return true;

	return false;
}

bool isWin(char board[], unsigned short size, char currentPlayerSign)
{
	if (isWinInRows(board, size, currentPlayerSign))
		return true;

	if (isWinInCols(board, size, currentPlayerSign))
		return true;

	if (isWinInDiagonals(board, size, currentPlayerSign))
		return true;

	return false;
}

bool isDraw(char board[], unsigned short size)
{
	for (int i = 0; i < size * size; i++)
	{
		if (board[i] == ' ')
			return false;
	}
	return true;
}

int main()
{
	const unsigned short SIZE = 3;
	char board[SIZE * SIZE];

	const unsigned short NUMBER_OF_PLAYERS = 2;
	char players[NUMBER_OF_PLAYERS] = { 'O', 'X' };
	short currentPlayer = 0;

	clearBoard(board, SIZE);

	while (true)
	{
		int fieldNumber;
		system("cls");
		drawBoard(board, SIZE);

		fieldNumber = GetPlaceOnBoard(players[currentPlayer]);

		if (fieldNumber < 0
			|| fieldNumber >= SIZE * SIZE
			|| board[fieldNumber] != ' ')
			continue;

		board[fieldNumber] = players[currentPlayer];

		system("cls");
		drawBoard(board, SIZE);

		if (isWin(board, SIZE, players[currentPlayer]))
		{
			std::cout << "Wygrana " << players[currentPlayer] << "\n";
			break;
		}

		if (isDraw(board, SIZE))
		{
			std::cout << "Reamis!!\n";
			break;
		}

		currentPlayer = (currentPlayer + 1) % NUMBER_OF_PLAYERS;
	}
}