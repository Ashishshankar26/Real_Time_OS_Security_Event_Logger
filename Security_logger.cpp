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

void scanFromFile() {
    ifstream in(inputFile);
    ofstream out(outputFile, ios::app);

    if (!in.is_open()) {
        cout << "Cannot open " << inputFile << ". Make sure you ran: sudo journalctl -o short > system_logs.txt" << endl;
        return;
    }

    cout << "\n--- Scanning exported system logs ---\n";

    string line;
    int count = 0;

    while (getline(in, line)) {
        if (isSecurityLine(line)) {
            Event e = parseEvent(line);
            cout << "[SECURITY] " << e.message << endl;
            out << e.message << endl;
            count++;
        }
    }

    cout << "\nScan complete. Security events found: " << count << endl;
    cout << "Saved to: " << outputFile << endl;
}








void runProgram();

int main() {
    runProgram();
    return 0;
}
