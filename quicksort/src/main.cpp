#include <iostream>
#include <vector>
#include <deque>
using namespace std;

std::pair<vector<int>,vector<int>> partition(vector<int> list) {
    vector<int> left;
    vector<int> right;
    int pivot = list.begin();
    for (int i = 1; i < list.size(); i++) {
        if (list[i] < pivot) {
            left.push_back(list[i]);
        }
        else {
            right.push_back(list[i]);
        }
    }
    return std::pair<vector<int>,vector<int>> {left, right};
}

void quicksort(vector<int> list) {
    
}

int main() {
    vector<int> test {50,11,8,300,2,10};
    auto twins = partition(test);
    // for (int x =0; x<twins.first.size(); x++) {
    //     cout << x << " ";
    // }
    cout << endl;
    for (int x =0; x<twins.second.size(); x++) {
        cout << twins.second[x] << " ";
    }
    cout << endl;
}