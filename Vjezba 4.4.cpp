#include <iostream>
#include <string>
#include <vector>
#include <sstream>

using namespace std;

bool samoglas(char c) {
    c = tolower(c);
    return (c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u');
}

string pig_latin_rijec(string& word) {
    if (word.empty())
        return "";
    if (samoglas(word[0]))
        return word + "hay";
    size_t sgpoz = 0;
    while (sgpoz < word.length() && !samoglas(word[sgpoz])) {
        sgpoz++;
    }
    return word.substr(sgpoz) + word.substr(0, sgpoz) + "ay";
}

vector<string> prevod_recenica(vector<string>& vec) {
    vector<string> piglatinrec;
    for (string& vec : vec) {
        std::istringstream iss(vec);
        string word;
        string piglatinrecenice;
        while (iss >> word) {
            piglatinrecenice += pig_latin_rijec(word) + " ";
        }
        piglatinrec.push_back(piglatinrecenice);
    }
    return piglatinrec;
}

int main() {
    vector<string> vec;
    string str1 = "what time is it";
    vec.push_back(str1);
    vector<string> piglatinrec = prevod_recenica(vec);
    for (const string& vec : piglatinrec) {
        cout << vec << endl;
    }
    return 0;
}
