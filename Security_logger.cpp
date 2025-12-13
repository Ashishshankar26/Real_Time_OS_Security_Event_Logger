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



void runProgram();

int main() {
    runProgram();
    return 0;
}
