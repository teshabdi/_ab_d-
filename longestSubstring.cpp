// name abdi teshome ru 2381
#include <iostream>
#include <unordered_set>
#include <algorithm>
using namespace std;

int lengthOfLongestSubstring(string s) {
    int n = s.length();
    int maxLength = 0, i = 0, j = 0;
    unordered_set<char> uniqueChars; // to store the unique characters in the substring

    while (i < n && j < n) {
        if (uniqueChars.find(s[j]) == uniqueChars.end()) {
            uniqueChars.insert(s[j]);
            maxLength = max(maxLength, j - i + 1);
            j++;
        }
        else {
            uniqueChars.erase(s[i]);
            i++;
        }
    }

    return maxLength;
}

int main() {
    string s;
    cout << "enter the character"<< endl;
    cin>> s;
    int length = lengthOfLongestSubstring(s);
    cout << "Length of the longest substring without repeating characters: " << length << endl;
    return 0;
}

