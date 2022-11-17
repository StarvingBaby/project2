#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <deque>
using namespace std;

int main() {
    ifstream robotText;
    robotText.open("input.txt");
    // deque<string> fileText;
    vector<int> sprockets;
    vector<int> prev;
    int s;
    int p;
    string operation;
    int stages;
    if (robotText.is_open()) {
        getline(robotText, operation);
        string tmp;
        getline(robotText, tmp);
        stages = stoi(tmp);
        while (!robotText.eof()) {
            string sp;
            getline(robotText, sp);
            // fileText.push_back(sp);
            sscanf(sp.c_str(), "%d %d", &s, &p);
            sprockets.push_back(s);
            prev.push_back(p);
        }
        // fileText.pop_back();
        robotText.close();
    }
    // string operation = fileText[0];
    // int stages = stoi(fileText[1]);
    // fileText.pop_front();
    // fileText.pop_front();
    // for (auto x : fileText) {
    //     int whitespace = x.find(" ");
    //     int n = x.length();
    //     s = stoi(x.substr(0, whitespace));
    //     p = stoi(x.substr(whitespace, n - 1));
    //     sscanf(x.c_str(), "%d %d", &s, &p);
    //     sprockets.push_back(s);
    //     prev.push_back(p);
    // }



    int sum = 0;
    if (operation[0] == 'o') {
        cout << "omnidroid";
    }
    else if (operation[0] == 'r') {
        for (auto x : sprockets) {
            cout << x << ' ';
        }
        cout << '\n';
        for (auto x : prev) {
            cout << x << ' ';
        }
        cout << "\n\n";
        for (int i = 0; i < stages; i++) {
            if (prev[i] > 0) {
                sum += sprockets[i - prev[i]];
            }
            sum += sprockets[i];
        }
        cout << sum << '\n';
    }
    else {
        return 1;
    }
}

int robotomaton() {
    return 0;
}

int omnidroid() {
    return 0;
}

// for (auto x : sprockets) {
        //     cout << x << ' ';
        // }
        // cout << '\n';
        // for (auto x : prev) {
        //     cout << x << ' ';
        // }
