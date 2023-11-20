#include <iostream>
#include <vector>

using namespace std;

int LIMIT = 100;

vector<vector<int>> dp;

int cofficient(int n, int r) {
    if (dp[n][r] == -1) {
        dp[n][r] = cofficient(n-1, r-1) + cofficient(n-1, r);
    }
    return dp[n][r];
}

int main() {

    int n, r;
    cout << "Enter n r: ";
    cin >> n >> r;

    if (n < r || r < 0 || n < 0) {
        return -1;
    }

    dp.resize(LIMIT+1, vector<int>(LIMIT+1, -1));

    for (int i=0; i<=LIMIT; ++i) {
        dp[i][0] = 1;
        dp[i][i] = 1;
    }

    cout << "Cofficient is: " << cofficient(n, r) << endl;

    return 0;
}