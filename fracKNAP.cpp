#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

struct Item {
    int weight;
    int value;
    float ratio;
};

bool compare(const Item &a, const Item &b) {
    return a.ratio > b.ratio;
}

float fr_knapsack(float capacity, vector<Item> &items) {
    
    sort(items.begin(), items.end(), compare);

    float ans = 0.0;

    for (const Item &item : items) {
        if (capacity >= item.weight) {
            ans += item.value;
            capacity -= item.weight;
        } else {
            ans += item.ratio * capacity;
            break;
        }
    }

    return ans;
}

int main() {

    int n;
    cout << "Enter number of items: ";
    cin >> n;

    float k;
    cout << "Enter knapsack capacity: ";
    cin >> k;

    vector<Item> items(n);

    cout << "Enter Item weight and value";
    for (int i=0; i<n; i++) {
        cin >> items[i].weight >> items[i].value;
        items[i].ratio = items[i].value/ (float) items[i].weight;
    }

    cout << "Max value of knapscak is: " << fr_knapsack(k, items) << "\n";

    return 0;
}