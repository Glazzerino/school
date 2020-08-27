#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
using namespace std;

int getUnique(string line) {
    for (int i=0;i<line.size(); i+=2) {
        if (line[i] != )
    }
}

template<class T>
size_t binarySearch(vector<T> list) {
    // Timer timer;
    int r, l, m;
    l = 0;
    r = list.size()-1;
    while (r >= l) {
        int m = l + (r - l) / 2;
        if (list[m] == query ) {
            return m;
        }
        else if (list[m] < query ) {
            l = m+1;
        }
        else {
            r = m-1;
        }
    }
    return -1;
}
template<class T>
size_t sequential(vector<T>& list, T query) {
    size_t x;
    for (x = 0; x < list.size(); x++) {
        if (list[x] == query) {
            return x;
        }
    }
    return -1;
}
int main() {
    cout << "test" << endl;
    ifstream file;
    file.open("01.in");
    int lines;
    file >> lines;
    stringstream line;
    for (int i=0; i < lines; i++) {

    }
}
