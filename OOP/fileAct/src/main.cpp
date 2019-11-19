#include<fstream>
#include<iostream>
#include<string>
#include<sstream>
#include<vector>
using namespace std;
size_t count(string &line,char target) {
    size_t count = 0;
    for (int i=0;i<line.length();i++) {
        if (line[i] == target) {
            count++;
        }
    }
    return count;
}
size_t myfind(string &line, char target) {
    for (size_t i=0;i<line.length();i++) {
        if (line[i] == target) {
            return i;
        }
    }
    //if not found
    return 0;
}
size_t revfind(string &line, char target) {
    for (size_t i=line.length();i>0;i--){
        if (line[i] == target) {
            return i;
        }
    }
    return line.length();
}
int main() {
    ifstream infile;
    ofstream outfile;
    infile.open("Data.txt");

    outfile.open("nuevasFrases.txt");
    string line;
    bool endlcontrol = false;
    while(getline(infile,line)) {
        if (endlcontrol) {
            outfile << endl;
        }
        endlcontrol = true;
        if (count(line,' ') > 1) {
            for (int i = myfind(line,' ')+1;i<revfind(line, ' ');i++) {
                outfile << line[i];
            }
        } else {
            outfile << line;
        }
    }
    outfile.close();
    infile.close();
    return 0;
}   