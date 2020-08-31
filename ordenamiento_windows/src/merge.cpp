#include <iostream>
#include <vector>
using namespace std;

template<class T>
inline std::pair<vector<T>,vector<T>> split_vector(vector<T>& list) {
    size_t m = list.size()/2 + (list.size() % 2) -1;
    vector<T> first;
    vector<T> last;
    for (int i=0; i<list.size(); i++) {
        if (i > m) {
            last.push_back(list[i]);
        }
        else {
            first.push(list[i]);
        }
    }
    return std::pair<vector<T>, vector<T>> {first, last};
}

template<class T>
inline vector<T> merge(vector<T> first, vector<T> last) {
    vector<T> result;
    bool done = false;
    size_t counter = 0;
    
    return result;
}

template<class T>
void mergesort(vector<T>& list) {

    bool done = false;
    // split-phase
    vector<vector<T>> metalist;
    vector<vector<T>> splittemp;

    metalist.reserve(list.size()/2);
    int i=0;
    while(i < list.size()) {
        if (i == list.size()-1 && i % 2 != 0) {
            metalist.push_back(vector<T> { list[i] });
        }
        else {
            metalist.push_back(vector<T> {list[i], list[i+1]});
            i+=2;
        }
    }
    // merge phase

}

using namespace std;
int main() {
    vector<int> list {1,2,3,4,5,6,7,8};
    vector<int> list2{9,10,11,12};
    for (int x : merge<int>(list, list2)) {
        cout << x << " ";
    } 
    cout << endl;
}