#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

template<class T>
void display_vector(vector<T> &list) {
    for (T x : list) {
        cout << x << " ";
    }
    cout << endl;
}

template<class T>
inline void linear_sort(vector<T> *list) {
    for (int i = 0; i < list.size() - 1; i++) {
        if (list[i + 1] < list[i]) {
            swap(list[i + 1], list[i]);
        }
    }
}


template<class T>
vector<vector<T>> initial_split(vector<T> &list) {
    vector<vector<T>> final;
    int i = 0;
    vector<T> cell;
    while (i < list.size()) {
        cell.clear();
        if (i == 0 && ((list.size() % 2) != 0 && list.size() != 1)) {
//            vector<T> cell{list[i], list[i + 1], list[i + 2]};
            cell.push_back(list[i]);
            cell.push_back(list[i + 1]);
            cell.push_back(list[i + 2]);
            if (cell[0] > cell[1]) { swap(cell[0], cell[1]); }
            if (cell[0] > cell[2]) { swap(cell[0], cell[2]); }
            if (cell[1] > cell[2]) { swap(cell[1], cell[2]); }
            i += 3;
//            display_vector(cell);
        } else if (list.size() > 1){
            int a = list[i];
            int b = list[i + 1];
            if (a > b) { swap(a, b); }
            cell.push_back(a);
            cell.push_back(b);
            i += 2;
        } else {
            cell.push_back(list[0]);
            final.push_back(cell);
            break;
        }
        final.push_back(cell);
    }
    return final;
}

template<class T>
vector<T> merge(vector<T> a, vector<T> b) {
    int total = a.size() + b.size();
    int ac = 0;
    int bc = 0;
    int i = 0;
    vector<T> c;
    c.reserve(total);
    while(ac < a.size() && bc < b.size()) {
        if (a[ac] < b[bc]) {
            c.push_back(a[ac]);
            ac++;
        } else {
            c.push_back(b[bc]);
            bc++;
        }
        if (bc == b.size()) {
            for (int x = ac; x < a.size(); x++) {
                c.push_back(a[x]);
            }
            break;
        } else if (ac == a.size()) {
            for (int x = bc; x < b.size(); x++) {
                c.push_back(b[x]);
            }
            break;
        }
        i++;
    }
    return c;
}

template<class T>
void mergesort(vector<T> &list) {
    vector<vector<T>> temp;
    vector<vector<T>> heads;
    bool control = false;
    vector<vector<T>> metalist = initial_split(list);
//
//    for (vector<T> x : metalist) {
//        display_vector(x);
//    }
//    auto merged = merge(metalist[0], metalist[1]);
//    auto merged2 = merge(merged, metalist[2]);
//    display_vector<int>(merged2);

    while(metalist.size() > 1) {

//        cout << "spinch" << endl;
        for (int i = 0; i < metalist.size() - 1; i+=2) {
            temp.push_back(merge(metalist[i], metalist[i + 1]));
        }
//        if (!metalist.empty()) {
//            cout << metalist.size() << endl;
//        }
        swap(metalist, temp);
        temp.clear();
    }
    swap(list, metalist[0]);
//    temp.clear();
}

int main() {
    vector<int> list{1};
    display_vector(list);
    vector<int> a{1, 3, 5};
    vector<int> b{2, 4};
    mergesort<int>(list);
    display_vector(list);

}