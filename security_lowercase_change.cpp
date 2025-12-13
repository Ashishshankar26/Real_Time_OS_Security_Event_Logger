#include <iostream>
#include <string>
#include <algorithm>

string toLower(string s) {
    transform(s.begin(), s.end(), s.begin(), ::tolower);
    return s;
}
