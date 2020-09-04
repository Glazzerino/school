#include <iostream>
#include <algorithm>
#include <stack>
#include <vector>

using namespace std;

int partition(vector<int>& list, int start, int end) {
    int pivot = list[end];

    int pindex = start;

    for (int i = start; i < end; i++) {
        if (list[i] <= pivot) {
            swap(list[i], list[pindex]);
            pindex++;
        }
    }
    swap(list[pindex], list[end]);
    return pindex;
}

void quicksort(vector<int>& list) {
    stack<pair<int, int>> pairs;
    int end = list.size()-1;
    int start = 0;
    pairs.push(pair<int, int> {start, end});

    while(!pairs.empty()) {
        start = pairs.top().first;
        end = pairs.top().second;
        pairs.pop();
        int pivot = partition(list,start, end);
        if (pivot - 1 > start) {
            pairs.push(pair<int, int>{start, pivot - 1});
        }
        if (pivot +1 < end) {
            pairs.push(pair<int, int>{pivot+1, end});
        }
    }
    // return list;
}

void disp_vector(vector<int> list) {
    for (int x : list) {
        cout << x << " ";
    }
    cout << endl;
}

int main() {
    vector<int> list = {6, -3, 5, 1, 9, 8, 3, 2, -6};
    // auto n = quicksort(list);
    quicksort(list);
    disp_vector(list);

}