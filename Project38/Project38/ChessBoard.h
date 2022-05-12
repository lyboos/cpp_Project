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
	int win;//ʤ������
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
		//������
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
		//������
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
		//б�ż��
		for (int i = 0; i < board->size() - win + 1; i++) {//һ���ж��ٺ����
			//����ÿһ���ر�ĺ����
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
		//����б��
		for (int i = 0; i < board->size() - win + 1; i++) {//һ���ж��ٺ����
			//����ÿһ���ر�ĺ����
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

