#pragma once
#pragma once
#include<vector>
#include<string>
#include "Chess.h"
using namespace std;
class ChessBoard
{
private:
	vector<vector<char>>* board;
	int win;//胜利长度
public:
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
		//横向检查
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
		//纵向检查
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
		//斜着检查
		for (int i = 0; i < board->size() - win + 1; i++) {//一共有多少横向的
			//对于每一个特别的横向的
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
		//反向斜着
		for (int i = 0; i < board->size() - win + 1; i++) {//一共有多少横向的
			//对于每一个特别的横向的
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

