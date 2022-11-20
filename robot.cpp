#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <deque>
using namespace std;

vector<int> sprockets;

int robotomaton(int p, int i) {
    // cout << sprockets[i] << "";
    if (p == 0) {
        return sprockets[i];
    }
    // cout << " + ";
    return sprockets[i] + robotomaton(p - 1, i - 1);
}

int omnidroid() {
    return 0;
}

int main() {
    ifstream inputText;
    ofstream outputText;
    vector<int> previous;
    int numRobots;
    int s;
    int p;
    int n;
    int m;
    string operation = "";
    int stages;
    inputText.open("input.txt");
    outputText.open("output.txt");
    if (inputText.is_open()) {
        string tmp;
        getline(inputText, tmp);
        numRobots = stoi(tmp);
        for (int i = 0; i < numRobots; i++) {
            getline(inputText, operation);
            while (operation == "") {
                getline(inputText, operation);
            }
            if (operation[0] == 'r') {
                getline(inputText, tmp);
                stages = stoi(tmp);
                string sp;
                for (int i = 0; i < stages; i++) {
                    getline(inputText, sp);
                    sscanf(sp.c_str(), "%d %d", &s, &p);
                    sprockets.push_back(s);
                    previous.push_back(p);
                }
                for (int i = 0; i < stages; i++) {
                    if (previous[i] == 0) {
                        // cout << "prev = " << previous[i] << "   i = " << i << " --->  " << " = " << sprockets[i] << '\n';
                        sprockets[i] = sprockets[i];
                    }
                    else {
                        // cout << "prev = " << previous[i] << "   i = " << i << " --->  ";
                        sprockets[i] = robotomaton(previous[i], i);
                        // cout << " = " << sprockets[i] << '\n';
                    }
                }
                // cout << sprockets[stages - 1] << '\n';
                outputText << sprockets[stages - 1] << '\n';
                sprockets.clear();
                previous.clear();
            }
            else if (operation[0] == 'o') {
                string nm, tmp;
                int x, y;
                getline(inputText, nm);
                // cout << nm << '\n';
                sscanf(nm.c_str(), "%d %d", &n, &m);
                for (int i = 0; i < m; i++) {
                    getline(inputText, tmp);
                    // cout << tmp << '\n';
                    sscanf(tmp.c_str(), "%d %d", &x, &y);
                    // use x and y to load arrays
                }
                for (int i = 0; i < n; i++) {
                    getline(inputText, tmp);
                    // cout << tmp << '\n';
                    sscanf(tmp.c_str(), "%d", &x);
                    // use x to load sprockets array
                }
                outputText << "... omni answer ..." << '\n';
                continue;
            }
        }
        inputText.close();
        outputText.close();
    }
}
