#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <map>
using namespace std;

pair<char, int> sequential(string line) {
    int comps = 0;
    int i = 0;
    for (int i=0; i<line.size(); i+=2) {
        comps++;
        if (line[i] != line[i+1]) {
            return pair<char, int>{line[i], comps};
        }
        
    }
    return pair<char, int>{' ', -1};
}


int main() {
    cout << "test" << endl;
    ifstream file;
    file.open("01.in");
    string line;

    while (getline(file, line)) {
        if  (line.size() == 1) {
            continue;
        }
        auto ans = sequential(line);
        cout << ans.first  << " " << ans.second << endl;
    }
    
}
