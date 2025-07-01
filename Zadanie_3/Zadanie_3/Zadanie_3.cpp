#include <iostream>
using namespace std;

string board[3][3] = { {"1", "2", "3"},{"4", "5", "6"},{"7", "8", "9"} };
bool winning = false;
bool tie = false;
string currentPlayer = "X";
int input;


static void Render() {// Render current game Board in console and print which player won or if it is a tie
	system("cls");
	for (int i = 0;i < 3;i++) {
		for (int j = 0;j < 3;j++) {
			cout << "| " <<  board[i][j]  << " |";
		}
		cout << endl;

	}
	if (winning) {
		if (currentPlayer == "X")
			cout << "Wygral gracz grajacy jako O";
		else
			cout << "Wygral gracz grajacy jako X";
	}
	else if (tie) {
		cout << "Gra zakonczyla sie remisem";
	}

}

static string GetBoardValue(int* x){// Get Value that is currently on the input to further check if it is avaliable
	
	string value;
	switch (*x) {
		case 1:
			value = board[0][0];
			break;
		case 2:
			value = board[0][1];
			break;
		case 3:
			value = board[0][2];
			break;
		case 4:
			value = board[1][0];
			break;
		case 5:
			value = board[1][1];
			break;
		case 6:
			value = board[1][2];
			break;
		case 7:
			value = board[2][0];
			break;
		case 8:
			value = board[2][1];
			break;
		case 9:
			value = board[2][2];
			break;
		default:
			value = "X";
			break;
	}
	return value;
}


static void ProcessInput() {// Process Input and check if there are no errors with players choice 

	int* pointInput = &input;

	do {
		
		cout << "Teraz gracz grajacy jako " << currentPlayer << endl;
		cout << "Prosze podac numer kratki:" << endl;
		cin >> input;
		if (GetBoardValue(pointInput) == "X" || GetBoardValue(pointInput) == "O") {
			cout << "Wybrana zosta³a Bledna komorka."<< endl;
		}

	}while (GetBoardValue(pointInput) == "X" || GetBoardValue(pointInput) == "O");

}


static void CheckWin() {// check by the row column and diagonals if there are three same signs 
	int countX;
	int countO;

	for (int i = 0;i < 3;i++) { //Rows
		countX = 0;
		countO = 0;
		for (int j = 0;j < 3;j++) {
			if (board[i][j] == "X") {
				countX++;
			}	
			else if (board[i][j] == "O") {
				countO++;
			}			
		}
		if (countX == 3 || countO == 3) {
			winning = true;
			break;
		}			
	}

	for (int i = 0;i < 3;i++) { //Columns
		countX = 0;
		countO = 0;
		for (int j = 0;j < 3;j++) {
			if (board[j][i] == "X") {
				countX++;
			}
			else if (board[j][i] == "O") {
				countO++;
			}
		}
		if (countX == 3 || countO == 3) {
			winning = true;
			break;
		}
	}
	countX = 0;
	countO = 0;
	for (int i = 0;i < 3;i++) { //Diagonal
			if (board[i][i] == "X") {
				countX++;
			}
			else if (board[i][i] == "O") {
				countO++;
			}
		if (countX == 3 || countO == 3) {
			winning = true;
			break;
		}
	}
	countX = 0;
	countO = 0;
	for (int i = 0;i < 3;i++) { //Anti Diagonal
		if (board[i][2 - i] == "X") {
			countX++;
		}
		else if (board[i][2 - i] == "O") {
			countO++;
		}
		if (countX == 3 || countO == 3) {
			winning = true;
			break;
		}
	}


}

static bool CheckTie() { // checking if the board is full and there are no three same signs in any direction 
	for (int i = 0;i < 3;i++) {
		for (int j = 0;j < 3;j++) {
			if (board[i][j] != "X" && board[i][j] != "O")
				return false;
		}
	}
	return true;
}

static void Update() {// Update appropiate value on the board from players input, also update current player and check if after update there are no winning situation.

	int* pointInput = &input;
	string& player = currentPlayer;
	string value;
	switch (*pointInput) {
	case 1:
		board[0][0] = player;
		break;
	case 2:
		board[0][1] = player;
		break;
	case 3:
		board[0][2] = player;
		break;
	case 4:
		board[1][0] = player;
		break;
	case 5:
		board[1][1] = player;
		break;
	case 6:
		board[1][2] = player;
		break;
	case 7:
		board[2][0] = player;
		break;
	case 8:
		board[2][1] = player;
		break;
	case 9:
		board[2][2] = player;
		break;
	}

	if (player == "X") {
		player = "O";
	}
	else {
		player = "X";
	}
	CheckWin();
	if (!winning) {
		tie = CheckTie();
	}
	
}



int main() {


	Render();//Initial Render

	while (!winning && !tie) { //Game Loop
		ProcessInput();
		Update();
		Render();
	}


	return 0;
}