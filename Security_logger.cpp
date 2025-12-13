#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <algorithm>
#include <cstdio>

using namespace std;


//global variables.


string inputFile = "system_logs.txt";
string outputFile = "security_events.log";

vector<string> keywords = {
    "failed",
    "denied",
    "unauthorized",
    "invalid",
    "authentication",
    "error",
    "ssh",
    "sudo",
    "polkit"
};


string toLower(string s) {
    transform(s.begin(), s.end(), s.begin(), ::tolower);
    return s;
}


bool isSecurityLine(const string& line) {
    string lower = toLower(line);
    for (const string& k : keywords) {
        if (lower.find(k) != string::npos) return true;
    }
    return false;
}


struct Event {
    string message;
};

Event parseEvent(const string& line) {
    Event e;
    e.message = line;
    return e;
}







void runProgram();

int main() {
    runProgram();
    return 0;
}
