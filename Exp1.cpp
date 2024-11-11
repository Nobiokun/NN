#include <bits/stdc++.h>
using namespace std;

struct Item {
    int value;
    int weight;
};

bool compare1(const Item &a, const Item &b) {
    return (a.value / (double)a.weight) > (b.value / (double)b.weight);
}
bool compare2(const Item &a, const Item &b) {
    return a.value > b.value;
}
bool compare3(const Item &a, const Item &b) {
    return a.weight < b.weight;
}
double fractionalknapsack1(int w, Item items[], int n) {
    sort(items, items + n, compare1);

    double max_val = 0;
    int curr_w = 0;

    for (int i = 0; i < n; i++) {
        if (curr_w + items[i].weight <= w) {
            curr_w += items[i].weight;
            max_val += items[i].value;
        } else {
            int rem_w = w - curr_w;
            max_val += items[i].value * ((double)rem_w / items[i].weight);
            break;
        }
    }
    return max_val;
}
double fractionalknapsack2(int w, Item items[], int n) {
    sort(items, items + n, compare2);

    double max_val = 0;
    int curr_w = 0;

    for (int i = 0; i < n; i++) {
        if (curr_w + items[i].weight <= w) {
            curr_w += items[i].weight;
            max_val += items[i].value;
        } else {
            int rem_w = w - curr_w;
            max_val += items[i].value * ((double)rem_w / items[i].weight);
            break;
        }
    }
    return max_val;
}
double fractionalknapsack3(int w, Item items[], int n) {
    sort(items, items + n, compare3);

    double max_val = 0;
    int curr_w = 0;

    for (int i = 0; i < n; i++) {
        if (curr_w + items[i].weight <= w) {
            curr_w += items[i].weight;
            max_val += items[i].value;
        } else {
            int rem_w = w - curr_w;
            max_val += items[i].value * ((double)rem_w / items[i].weight);
            break;
        }
    }
    return max_val;
}

int main() {
    int n, w;
    cout << "Enter no. of objects: ";
    cin >> n;
    cout << "Enter total knapsack weight: ";
    cin >> w;
    Item items[n];

    cout << "Enter values of the items: ";
    for (int i = 0; i < n; i++) {
        cin >> items[i].value;
    }

    cout << "Enter weights of the items: ";
    for (int i = 0; i < n; i++) {
        cin >> items[i].weight;
    }

    cout << "Maximun Profit achieved by Profit by weight ratio:"<<fractionalknapsack1(w, items, n) << endl;
    cout << "Maximun Profit achieved by Maximum Profit:"<<fractionalknapsack2(w, items, n) << endl;
    cout << "Maximun Profit achieved by minimum weight:"<<fractionalknapsack3(w, items, n) << endl;

    return 0;
}
