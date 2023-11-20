#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int id = 0;
int deadline = 1;
int profit = 2;

bool compare(const vector<int> &a, const vector<int> &b) {
    return a[profit] > b[profit];
}

int main() {
    vector<vector<int>> jobs = {
        {0, 2, 20},
        {1, 1, 10},
        {2, 3, 15},
        {3, 2, 5},
        {4, 3, 25}
    };
    
    sort(jobs.begin(), jobs.end(), compare);
    vector<bool> deadlines(20, false);
    
    int ans = 0;
    for (vector<int> j: jobs) {
        int i = j[deadline];
        while (i >= 0 && deadlines[i] != false) {
            i -= 1;
        }
        if (i >= 0) {
            deadlines[i] = true;
            ans += j[profit];
        }
    }

    cout << "Max profit is: " << ans << "\n";

    return 0;
}