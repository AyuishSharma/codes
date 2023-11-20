#include <iostream>
#include <vector>

using namespace std;

vector<bool> row(8, false);
vector<bool> col(8, false);
vector<bool> d1(15, false);
vector<bool> d2(15, false);

vector<vector<bool>> board(8, vector<bool> (8, false));

int fixed_row;

void display_board() {
    for (int i=0; i<8; i++) {
        for (int j=0; j<8; j++) {
            cout << ((board[i][j]) ? "Q" : "."); 
        }
        cout << "\n";
    }
    cout << "\n\n";
}

bool is_safe(int i, int j) {
    return !(row[i] || col[j] || d1[i+j] || d2[i-j+7]);
}

bool nqueen(int i=0) {
    if (i == 8) {
        display_board();
        return true;
    }
    if (i == fixed_row) {
        return nqueen(i+1);
    }

    for (int j=0; j < 8; j++) {
        if (is_safe(i, j)) {
            row[i] = col[j] = d1[1+j] = d2[i-j+7] = board[i][j] = true;
            nqueen(i+1);
            row[i] = col[j] = d1[1+j] = d2[i-j+7] = board[i][j] = false;
        }
    }

    return false;
}

int main() {
    int c;
    cout << "Enter fixed position: " << "\n";
    cin >> fixed_row >> c;

    row[fixed_row] = col[c] = d1[fixed_row+c] = d2[fixed_row-c+7] = board[fixed_row][c] =true;
    nqueen(0);

    return 0;
}
