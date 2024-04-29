#include <iostream>

/*
DRY
KISS
YAGNI
SOLID
*/

class Player
{
private:
	char sign;
protected:

public:
	/*Player(char s)
	{
		sign = s;
	}*/

	char GetSign()
	{
		return sign;
	}

	void SetSign(char s)
	{
		sign = s;
	}

	int GetPlaceOnBoard()
	{
		int fieldNumber;
		std::cout << "Gracz " << sign << " wykonuje ruch\n";
		std::cout << "Podaj numer pola:\n";
		std::cin >> fieldNumber;

		return fieldNumber;
	}
};

class Board
{
private:
	unsigned short size = 3;
	char board[3 * 3];

	void drawRow(int row)
	{
		for (int col = 0; col < size; col++)
		{
			std::cout << " " << board[size * row + col] << " ";
			if (col < size - 1)
				std::cout << "|";
		}
		std::cout << "\n";
	}

	void drawHorizontalFrame(int row)
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

	bool isWinInRow(char currentPlayerSign, int row)
	{
		for (int fieldInRow = 0; fieldInRow < size; fieldInRow++)
		{
			if (board[size * row + fieldInRow] != currentPlayerSign)
				return false;
		}
		return true;
	}

	bool isWinInRows(char currentPlayerSign)
	{
		for (int row = 0; row < size; row++)
		{
			if (isWinInRow(currentPlayerSign, row))
				return true;
		}
		return false;
	}

	bool isWinInCol(char currentPlayerSign, int col)
	{
		for (int fieldInCol = 0; fieldInCol < size; fieldInCol++)
		{
			if (board[size * fieldInCol + col] != currentPlayerSign)
				return false;
		}
		return true;
	}

	bool isWinInCols(char currentPlayerSign)
	{
		for (int col = 0; col < size; col++)
		{
			if (isWinInCol(currentPlayerSign, col))
				return true;
		}
		return false;
	}

	bool isWinInLeftDiagonal(char currentPlayerSign)
	{
		for (int fieldInDiagonal = 0; fieldInDiagonal < size; fieldInDiagonal++)
		{
			if (board[size * fieldInDiagonal + fieldInDiagonal] != currentPlayerSign)
				return false;;
		}
		return true;
	}

	bool isWinInRightDiagonal(char currentPlayerSign)
	{
		for (int fieldInDiagonal = 0; fieldInDiagonal < size; fieldInDiagonal++)
		{
			if (board[size * fieldInDiagonal + size - fieldInDiagonal - 1] != currentPlayerSign)
				return false;;
		}
		return true;
	}

	bool isWinInDiagonals(char currentPlayerSign)
	{
		if (isWinInLeftDiagonal(currentPlayerSign))
			return true;

		if (isWinInRightDiagonal(currentPlayerSign))
			return true;

		return false;
	}
public:
	void clearBoard()
	{
		for (int i = 0; i < size * size; i++)
			board[i] = ' ';
	}

	void drawBoard()
	{
		for (int row = 0; row < size; row++)
		{
			drawRow(row);
			drawHorizontalFrame(row);
		}
	}

	bool isWin(char currentPlayerSign)
	{
		if (isWinInRows(currentPlayerSign))
			return true;

		if (isWinInCols(currentPlayerSign))
			return true;

		if (isWinInDiagonals(currentPlayerSign))
			return true;

		return false;
	}

	bool isDraw()
	{
		for (int i = 0; i < size * size; i++)
		{
			if (board[i] == ' ')
				return false;
		}
		return true;
	}

	bool isFieldCorrect(int fieldNumber)
	{
		if (fieldNumber < 0
			|| fieldNumber >= size * size
			|| board[fieldNumber] != ' ')
			return true;
		return false;
	}

	void SetField(int fieldNumber, char sign)
	{
		board[fieldNumber] = sign;
	}
};

class AiPlayer
{

};

int main()
{
	Board board;

	const unsigned short NUMBER_OF_PLAYERS = 3;
	Player players[NUMBER_OF_PLAYERS];
	players[0].SetSign('X');
	players[1].SetSign('O');
	short currentPlayer = 0;

	board.clearBoard();

	while (true)
	{
		int fieldNumber;
		system("cls");
		board.drawBoard();

		fieldNumber = players[currentPlayer].GetPlaceOnBoard();

		if (board.isFieldCorrect(fieldNumber))
			continue;

		board.SetField(fieldNumber, players[currentPlayer].GetSign());

		system("cls");
		board.drawBoard();

		if (board.isWin(players[currentPlayer].GetSign()))
		{
			std::cout << "Wygrana " << players[currentPlayer].GetSign() << "\n";
			break;
		}

		if (board.isDraw())
		{
			std::cout << "Reamis!!\n";
			break;
		}

		currentPlayer = (currentPlayer + 1) % NUMBER_OF_PLAYERS;
	}
}