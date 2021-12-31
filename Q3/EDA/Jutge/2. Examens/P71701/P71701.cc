#include <iostream>
#include <vector>
#include <queue>
using namespace std;

typedef vector<vector<char>> Matriu;

void print_possibility(vector<vector<char>>board) {
    for(int i = 0; i < board.size(); ++i) {
        for(int j = 0; j < board[i].size(); ++j) {
            cout << board[i][j];
        }
        cout << endl;
    }
    cout << "----------" << endl;
}

bool check_position(int i, int j, Matriu& board) {
	if (board[i][j] == 'K') return false;
	else if (i-1 >= 0 and board[i-1][j] == 'K') return false;
	else if (i+1 < board.size() and board[i+1][j] == 'K') return false;
	else if (j-1 >= 0 and board[i][j-1] == 'K') return false;
	else if (j+1 < board.size() and board[i][j+1] == 'K') return false;
	else if (i-1 >= 0 and j-1 >= 0 and board[i-1][j-1] == 'K') return false;
	else if (i+1 < board.size() and j-1 >= 0 and board[i+1][j-1] == 'K') return false;
	else if (i+1 < board.size() and j-1 >= 0 and board[i+1][j-1] == 'K') return false;
	else if (i-1 >= 0 and j+1 < board.size() and board[i-1][j+1] == 'K') return false;
	else return true;
}

void search(int k, int x, int y, int n, int r, Matriu& board) {
    if (k == r) print_possibility(board);
	else {
		bool first = true;
		for (int i=x; i < n; ++i) {
			for (int j=0; j < n; ++j) {
				if (first) {first = false; j = y;}
				if (check_position(i, j, board)) {
					board[i][j] = 'K';
					search(k+1, i, j, n, r, board);
					board[i][j] = '.';
				}
			}
		}
	}
}

int main() {
    int n, m;
    cin >> n >> m;
    vector<vector<char>>board(n, vector<char>(n,'.'));
    search(0,0,0,n,m,board);
}