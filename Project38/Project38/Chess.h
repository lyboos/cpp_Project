#pragma once
#pragma once
class Chess
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