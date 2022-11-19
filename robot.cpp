#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <deque>
using namespace std;

vector<int> sprockets;

int robotomaton(int p, int i) {
    cout << sprockets[i] << "";
    if (p == 0) {
        return sprockets[i];
    }
    cout << " + ";
    return sprockets[i] + robotomaton(p - 1, i - 1);
}

int omnidroid() {
    return 0;
}

int main() {
    ifstream robotText;
    vector<int> previous;
    int numRobots;
    int s;
    int p;
    int n;
    int m;
    string operation = "";
    int stages;
    robotText.open("input.txt");
    if (robotText.is_open()) {
        string tmp;
        getline(robotText, tmp);
        numRobots = stoi(tmp);
        for (int i = 0; i < numRobots; i++) {
            getline(robotText, operation);
            while (operation == "") {
                getline(robotText, operation);
            }
            if (operation[0] == 'r') {
                getline(robotText, tmp);
                stages = stoi(tmp);
                string sp;
                for (int i = 0; i < stages; i++) {
                    getline(robotText, sp);
                    sscanf(sp.c_str(), "%d %d", &s, &p);
                    sprockets.push_back(s);
                    previous.push_back(p);
                }
                for (int i = 0; i < stages; i++) {
                    if (previous[i] == 0) {
                        cout << "prev = " << previous[i] << "   i = " << i << " --->  " << " = " << sprockets[i] << '\n';
                        sprockets[i] = sprockets[i];
                    }
                    else {
                        cout << "prev = " << previous[i] << "   i = " << i << " --->  ";
                        sprockets[i] = robotomaton(previous[i], i);
                        cout << " = " << sprockets[i] << '\n';
                    }
                }
                cout << sprockets[stages - 1] << '\n';
            }
            else if (operation[0] == 'o') {
                string nm, tmp;
                int x, y;
                getline(robotText, nm);
                cout << nm << '\n';
                sscanf(nm.c_str(), "%d %d", &n, &m);
                for (int i = 0; i < m; i++) {
                    getline(robotText, tmp);
                    cout << tmp << '\n';
                    sscanf(tmp.c_str(), "%d %d", &x, &y);
                    // use x and y to load arrays
                }
                for (int i = 0; i < n; i++) {
                    getline(robotText, tmp);
                    cout << tmp << '\n';
                    sscanf(tmp.c_str(), "%d", &x);
                    // use x to load sprockets array
                }
                continue;
            }
        }
        robotText.close();
    }
}
