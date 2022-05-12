#define  _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include<vector>
#include<string>

using namespace std;


//ÆåÅÌ
class ChessBoard
{
private:
	vector<vector<char>>* board;
	int win;
public:
	class Chess//Æå×Ó

	{
	private:
		char c;
		int x;
		int y;
	public:
		Chess(char chessType, int a, int b) {
			c = chessType;
			x = a;
			y = b;
		}
		char getChessType() {
			return c;
		}
		int getX() {
			return x;
		}
		int getY() {
			return y;
		}
	};


	ChessBoard(int n, int winNum) {
		win = winNum;
		vector<vector<char>>* temp = new vector<vector<char>>();
		for (int i = 0; i < n; i++) {
			vector<char> temp2;
			for (int j = 0; j < n; j++) {
				temp2.push_back(' ');
			}
			temp->push_back(temp2);
		}
		board = temp;
	}
	void putChess(Chess* chess) {
		board->at(chess->getX()).at(chess->getY()) = chess->getChessType();
	}

	bool isWin() {
		//ºáÓ®
		for (int i = 0; i < board->size(); i++) {
			for (int j = 0; j < board->size() - win + 1; j++) {
				char c = board->at(i).at(j);
				if (c == ' ') {
					continue;
				}
				bool situation = true;
				for (int m = 0; m < win; m++) {
					if (board->at(i).at(j + m) != c) {
						situation = false;
						break;
					}
				}
				if (situation) {
					return situation;
				}
			}
		}
		//ÊúÓ®
		for (int i = 0; i < board->size() - win + 1; i++) {
			for (int j = 0; j < board->size(); j++) {
				char c = board->at(j).at(i);
				if (c == ' ') {
					continue;
				}
				bool situation = true;
				for (int m = 0; m < win; m++) {
					if (board->at(i + m).at(j) != c) {
						situation = false;
						break;
					}
				}
				if (situation) {
					return situation;
				}
			}
		}
		//ÕýÐ±Ó®
		for (int i = 0; i < board->size() - win + 1; i++) {
			for (int j = 0; j < board->size() - i - win + 1; j++) {
				char c = board->at(i).at(j);
				if (c == ' ') {
					continue;
				}
				bool situation = true;
				for (int m = 0; m < win; m++) {
					if (c != board->at(i + m).at(j + m)) {
						situation = false;
						break;
					}
				}
				if (situation) {
					return true;
				}
			}
		}
		//·´Ð±Ó®
		for (int i = 0; i < board->size() - win + 1; i++) {
			for (int j = 0; j < board->size() - i - win + 1; j++) {
				char c = board->at(i).at(board->size() - 1 - j);
				if (c == ' ') {
					continue;
				}
				bool situation = true;
				for (int m = 0; m < win; m++) {
					if (c != board->at(i + m).at(board->size() - 1 - (j + m))) {
						situation = false;
						break;
					}
				}
				if (situation) {
					return true;
				}
			}
		}
		return false;
	}
};

int main() {
	int n, win;
	int x, y;
	char type = 'O';
	cin >> n >> win;
	ChessBoard* chessBoard = new ChessBoard(n, win);
	bool result = false;
	int temp = 0;
	while (temp < n * n) {
		if (temp % 2 == 0) {
			type = 'O';
		}
		else {
			type = 'X';
		}
		cin >> x >> y;
		ChessBoard::Chess* chess = new ChessBoard::Chess(type, x, y);
		chessBoard->putChess(chess);
		if (chessBoard->isWin()) {
			result = true;
			break;
		}
		temp++;
	}

	if (!result) {
		cout << "Dogfall";
	}
	else {
		if (type == 'O') {
			cout << "O Success";
		}
		else {
			cout << "X Success";
		}
	}
	return 0;
}