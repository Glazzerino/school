#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>

using namespace std;

std::pair<char, int> sequentialSearch(string line) {
    int comps = 0;
    for (int i=0; i<line.size(); i+=2) {
        comps++;
        if (line[i] != line[i+1]) {
            return pair<char, int>{line[i], comps};
        }
    }
    return pair<char, int>{' ', -1};
}

std::pair<char, int> binarySearch(string line) {
    int r,m,l;
    l = 0;
    r = line.size() -1;
    int comps = 0;
    m = (r + l) / 2;
    while (l <= r) {

        if (m % 2 == 0) {
            //odd    
            if (line[m] == line[m+1]) {
                l = m + 2;
                comps++;
            }
            else {
                r = m - 1;
            }
        } 
        else {
            if (line[m] == line[m-1]) {
                comps++;
                l = m + 2;
            } 
            else {
                r = m - 1;
            }
        }
        m = (r + l) / 2;
    }
    return std::pair<char, int>{line[m], comps};
}

int main() {
    // cout << "test" << endl;
    ifstream file;
    string line;
    stringstream filename;
    for (int i=1;i<=4;i++) {
        stringstream filename;
        filename << "0" << i << ".in";
        file.open(filename.str());
        cout << filename.str() << endl;
        while (getline(file, line)) {
            if  (std::isdigit(line[0])) {
                continue;
            }
            auto binary = binarySearch(line);
            auto sequential = sequentialSearch(line);
        
            cout << sequential.first  << " " << sequential.second << " ";
            cout << binary.first  << " " << binary.second << endl;
            }
        file.close();
        // filename.str().clear();
        }
        
}
