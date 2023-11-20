#include <iostream>
#include <vector>

using namespace std;

vector<vector<int>> dp;

int knapsack(int capacity, vector<int> &weights, vector<int> &values, int n) {
    if (capacity == 0 || n == 0) {
        return 0;
    }

    if (dp[n][capacity] != -1) {
        return dp[n][capacity];
    }

    if (weights[n - 1] > capacity) {
        dp[n][capacity] = knapsack(capacity, weights, values, n - 1);
    } else {
        dp[n][capacity] = max(values[n - 1] + knapsack(capacity - weights[n - 1], weights, values, n - 1), 
            knapsack(capacity, weights, values, n - 1));
    }

    return dp[n][capacity];
}

int main() {
    int capacity;
    cout << "Enter the knapsack capacity: ";
    cin >> capacity;

    int n;
    cout << "Enter the number of items: ";
    cin >> n;

    vector<int> weights(n);
    vector<int> values(n);

    cout << "Enter the weight and value for each item:" << endl;
    for (int i = 0; i < n; i++) {
        cin >> weights[i] >> values[i];
    }

    dp.resize(n + 1, vector<int>(capacity + 1, -1));

    cout << "Maximum value in the knapsack: " << knapsack(capacity, weights, values, n) << endl;

    return 0;
}