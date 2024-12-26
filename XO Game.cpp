

#include <iostream>
using namespace std;
#include<map>
#include<windows.h>

enum enMode{X,O};
enum enMode mode = X;
struct stPairs {
	int x; int y;
};
stPairs Pair;

 stPairs AskUserForNextEntry() {
	 cout << "Please choose which block: ";
	 int n1 = 0, n2 = 0;
	 cin >> n1 >> n2;
	 Pair.x = n1;
	 Pair.y = n2;
	 return Pair;
}

void  PlayerTurn() {
	if (mode == X)
	{
		cout << "\nX is next\n";
		mode = enMode::O;
	}
	else
	{
		cout << "\nO is next\n";
		mode = enMode::X;
	}
}

void UpdateGrid(char board[3][3],string txt) {

	cout << "\nAdding " + txt;
	cout << " to the Grid....\n";
	
	for (int i = 0; i < 7; i++)
	{
		if (!(i % 2))//if(i % 2 == 0)
		{
			for (int j = 0; j < 12; j++)
			{
				cout << "-";
			}
		}
		else
		{
			for (int j = 0; j < 4; j++)
			{
				if (board[i / 2][j] && j < 3)
				{
					cout << "| " << board[i / 2][j] << " ";
				}
				else
				{
					cout << "|   ";
				}
			}
		}
		cout << endl;
	}
}

char CheckWinner(char board[3][3]) {

	//Check horizontally first
	for (int i = 0; i < 3; i++)
	{
		if (board[i][0] == board[i][1]
			&& board[i][1] == board[i][2] && board[i][0] != ' ')
		{
			return board[i][0];
		}
	}


	//Check vertically first
	for (int i = 0; i < 3; i++)
	{
		if (board[0][i] == board[1][i]
			&& board[1][i] == board[2][i] && board[0][i] != ' ')
		{
			return board[0][i];
		}
	}


	if (board[0][0] == board[1][1] && board[1][1] == board[2][2]
		&& board[0][0] != ' ')
	{
		return board[0][0];
	}


	if (board[2][0] == board[1][1] && board[1][1] == board[0][2] &&
		board[2][0] != ' ')
	{
		return board[2][0];
	}


	return '\0';


}

void ShowTheWinner(char res) {
	
	cout << "\n\n\t\t\t-----------------------------\n";
	cout << "\t\t\t\t" << res;
	cout << " Won the game ;)\n";
	cout << "\n\t\t\t-----------------------------\n";
	cout << '\a'; 
	if (res == 'X')
		system("color 2e");
	else
		system("color 3e");
}
void PlayGame() {

	char Matrix[3][3] = { {},{},{} };
	int counter = 0;
	string txt = "X ";
	char c = 'X';
	stPairs pair;
	char res = ' ';

	while(res==' '|| counter<9){

			if (mode == enMode::O)
			{
				txt = "O ";
				c = 'O';
			}
			else
			{
				c = 'X';
				txt = 'X';
			}
			PlayerTurn();

			pair = AskUserForNextEntry();
			if (Matrix[Pair.x][pair.y]) {
				cout << "\nthis cell is occupied,Choose another Cell!";
				continue;
			}
			Matrix[Pair.x][pair.y] = c;
			

			UpdateGrid(Matrix,txt);
			res = CheckWinner(Matrix);

			if (res)
			{
				ShowTheWinner(res);
				break;;

			}

			counter++;
	 }
		
		if (counter == 9)
			cout << "Nobody Won!\n";

	}




 void DrawGrid() {
	cout << "-------------\n";
	for (int i = 2; i < 7; i += 2) {
		for (int j = 0; j < 4; j++) {
			cout << "|   ";
		}
		cout << "\n-------------\n";
	}

	PlayGame();
}


int main()
{
	
	DrawGrid();
}


