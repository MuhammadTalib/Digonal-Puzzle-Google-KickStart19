#include<iostream>
#include<string>
#include<string.h>
using namespace std;


class CASE {
public:
	void init() {
		int n;
		cin >> n;
		this->N = n;
		this->grid = new char* [n];
	}
	void init_grid() {
		for (int i = 0; i < this->N; i++) {
			this->grid[i] = new char[this->N];
			string s;
			cin >> s;
			for (int j = 0; j < this->N; j++) {
				this->grid[i][j] = s.c_str()[j];
			}
		}
	}
	void solvePuzzle() {
		for (int i = 0; i < this->N; i++) {
			for (int j = 0; j < this->N; j++) {
				if (i == 0 || j == 0) {
					this->traverseRight(i, j, this->N-j);
					this->traverseLeft(i, this->N-j-1, this->N-j);
				}
			}
		}
	}
	void traverseRight(int fromRow, int fromColumn,int val) {
		int ft = 0;
		for (int i = 0; (i < this->N && i+fromRow < this->N && i + fromColumn < this->N); i++) {
			if (this->grid[i + fromRow][i + fromColumn] == '.') {
				ft++;
			}
		}
		if (ft == val) {
			this->Flip(fromRow, fromColumn, "right");
		}
	}
	void traverseLeft(int fromRow, int fromColumn,int val) {
		int ft = 0;
		for (int i = 0; (i < this->N && i + fromRow < this->N && fromColumn - i >= 0); i++) {
			if (this->grid[i + fromRow][fromColumn-i] == '.') {
				cout << i + fromRow << " " << fromColumn - i << endl;
				ft++;
			}
		}
		cout << "ft " << ft <<" "<< val<<endl;
		if (ft == val) {
			this->Flip(fromRow, fromColumn, "left");
		}
	}
	void Flip(int fromRow,int fromColumn,string side) {
		cout << "flip " << fromRow << " " << fromColumn << " " << side << endl;
		if (side == "left") {
			for (int i = 0; i < this->N; i++) {
				if (this->grid[i + fromRow][fromColumn - i] == '.') {
					this->grid[i + fromRow][fromColumn - i] = '#';
				}else if (this->grid[i + fromRow][fromColumn - i] == '#') {
					this->grid[i + fromRow][fromColumn - i] = '.';
				}
			}
		} 
		else if(side == "right") {
			for (int i = 0; i < this->N; i++) {
				if (this->grid[i + fromRow][i + fromColumn] == '.') {
					this->grid[i + fromRow][i + fromColumn] = '#';
				}
				else if (this->grid[i + fromRow][i + fromColumn] == '#') {
					this->grid[i + fromRow][i + fromColumn] = '.';
				}
			}
		}

	}
	void print() {
		cout << this->N << endl;
		for (int i = 0; i < this->N; i++) {
			for (int j = 0; j < this->N; j++) {
				cout << this->grid[i][j];
			}
			cout << endl;
		}
	}
	int N;
	char** grid;
private:

};

int main() {
	int T;
	cin >> T;
	CASE *cases=new CASE[T];
	for (int i = 0; i < T; i++) {
		cases[i].init();
		cases[i].init_grid();
	}
	for (int i = 0; i < T; i++) {
		cases[i].solvePuzzle();
	}
	for (int i = 0; i < T; i++) {
		cases[i].print();
	}


}
