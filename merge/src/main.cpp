#include <vector>
#include <iostream>

using namespace std;

// template<class T>
// vector

template<class T>
std::pair<vector<T>, vector<T>> split(vector<T> list) {
    size_t m = list.size()/2;
    vector<T> right;
    right.reserve(m);
    vector<T> left;
    left.reserve(m);
    for (int i = 0; i < m+1; i++) {
        left.push_back(list[i]);
    } 
    for (int i = m+1; i < list.size(); i++) {
        right.push_back(list[i]);
    }
    return std::pair<vector<T>, vector<T>>{left,right};
}

template<class T>
inline vector<T> merge(vector<T>& left, vector<T>& right) {
    vector<T> final;
    size_t total = left.size() + right.size();
    final.reserve(total);

    for (int i = 0; i < total; i++) {
        if (left.size() == 0) {
            for (T x : right) {
                final.push_back(x);
            }
            return;
        }
        else if (right.size() == 0) {
            for (T x : left) {
                final.push_back(x);
            }
            return;
        }
        if (left.front() < right.front()) {
            final.push_back(left.front());
            left.erase(left.begin());
        } 
        else {
            final.push_back(right.front());
            right.erase(right.begin());
        }
    }
    return final;
}

template<class T>
inline vector<vector<T>> initial_split(vector<T>& list) {
    vector<vector<T>> meta;
    int i=0;
    bool odd = false;
    if (list.size() % 2 != 0) {
        odd = true;
    }

    while(i < list.size()) {
        if (i == 0 && odd) {
            meta.push_back(vector<T>{list[i], list[i+1], list[i+2]});
            i+=3;
            continue;
        }
        meta.push_back(vector<T>{list[i], list[i+1]});
        i+=2;
    }
    return meta;
}


template<class T>
inline void swapp(T& a,T& b) {
    T aux = a;
    a = b;
    b = aux;
}

template<class T>
void mergesort(vector<T>& list) {
    vector<T> alt1;
    vector<T> alt2;
    bool turn = false;
    vector<vector<T>> pairs = initial_split(list);

    for (int i = 0; i < pairs.size()-1; i++) {
        auto merged = merge(pairs[i], pairs[i+1]);
        alt1.push_back(merged);
    }
    for (T x : alt1) {
        cout << x << " ";
    }
    cout << endl;
}

int main() {
    vector<int> list {8,5,7,4,2,1,3,6};  
    vector<int> test {1,5,3,4};  
    vector<int> right {3,4};
    vector<int> left {1,5};
    vector<int> final;
    // merge(left,right,final);
    mergesort(list);
    

}