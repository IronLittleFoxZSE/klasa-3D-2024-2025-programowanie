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

int main()
{
	const unsigned short SIZE = 3;
	char board[SIZE * SIZE];

	const unsigned short NUMBER_OF_PLAYERS = 2;
	char players[NUMBER_OF_PLAYERS] = { 'O', 'X' };
	short currentPlayer = 0;

	clearBoard(board, SIZE);
	
	//przygotawanie do gry

	while (true)
	{
		int fieldNumber;
		do
		{
			system("cls");
			drawBoard(board, SIZE);
			std::cout << "Gracz " << players[currentPlayer] << " wykonuje ruch\n";
			std::cout << "Podaj numer pola:\n";
			std::cin >> fieldNumber;
		} while (board[fieldNumber] != ' ');

		board[fieldNumber] = players[currentPlayer];

		drawBoard(board, SIZE);

		//sprawdzenie czy aktualny gracz wygrał
		{
			//wyświelenie o wygraniej aktualnego gracza
			//break;
		}

		//sprawdzenie czy remis
		{
			//wyświetlenie informacji o remisie
			//break;
		}

		//zmieniamy gracza na kolejnego
		currentPlayer = (currentPlayer + 1) % NUMBER_OF_PLAYERS;
	}
}