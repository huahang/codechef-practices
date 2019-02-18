#include <iostream>
#include <string>
#include <vector>

using namespace std;

void parseInts(vector<int>& ints, const string& line) {
    char* p = (char*) line.c_str();
    char* begin = p;
    bool hitSpace = false;
    while (true) {
        if ((*p == '\0' || *p == ' ') && (!hitSpace)) {
            bool flip = *p == ' ';
            if (flip) {
                *p = '\0';
            }
            int n = atoi(begin);
            if (flip) {
                *p = ' ';
            }
            ints.push_back(n);
            hitSpace = true;
        } 
        if (*p == '\0') {
            break;
        }
        if (hitSpace && *p != ' ' && *p != '\0') {
            begin = p;
            hitSpace = false;
        }
        ++p;
    }
}

void processCase() {
    string line = "";
    getline(cin, line);
    int lines = atoi(line.c_str());
    for (int l = 0; l < lines; ++l) {
        string line = "";
        getline(cin, line);
        vector<int> ints;
        parseInts(ints, line);
    }
}

int main(int argc, char** argv) {
    string line = "";
    getline(cin, line);
    int cases = atoi(line.c_str());
    for (int c = 0; c < cases; ++c) {
        processCase();
    }
    return 0;
}
