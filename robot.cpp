#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <deque>
using namespace std;

vector<int> sprockets;
vector<int> previous;
int numRobots;
int s;
int p;
string operation = "";
int stages;

int robotomaton(int p, int i) {
    cout << sprockets[i] <<  "";
    if (p == 0) {
        return sprockets[i];
    }
    cout <<  " + ";
    return sprockets[i] + robotomaton(p-1, i-1);

    // return;
}

int omnidroid() {
    return 0;
}

int main() {
    ifstream robotText;
    robotText.open("input.txt");
    if (robotText.is_open()) {
        string tmp;
        getline(robotText, tmp);
        numRobots = stoi(tmp);
        for (int i = 0; i < numRobots; i++) {
            while (operation == "") {
                getline(robotText, operation);
            }
            if (operation[0] == 'r') {
                getline(robotText, tmp);
                stages = stoi(tmp);
                while (!robotText.eof()) {
                    string sp;
                    getline(robotText, sp);
                    sscanf(sp.c_str(), "%d %d", &s, &p);
                    sprockets.push_back(s);
                    previous.push_back(p);
                }
            }
            else if (operation[0] == 'o') {
                cout << "omnidroid";
            }
        }
        robotText.close();
    }



    int sum = 0;
    if (operation[0] == 'o') {
        cout << "omnidroid";
    }
    else if (operation[0] == 'r') {
        for (auto x : sprockets) {
            cout << x << ' ';
        }
        cout << '\n';
        for (auto x : previous) {
            cout << x << ' ';
        }
        cout << "\n\n";
        vector<int> tmpArray(stages);
        for (int i = 0; i < stages; i++) {
            int tmpSum = 0;
            if (previous[i] == 0) {
                cout << "prev = " << previous[i] << "   i = "<< i << " --->  "<< " = " << sprockets[i] <<'\n';
                sprockets[i] = sprockets[i];
            }
            else {
                cout << "prev = " << previous[i] << "   i = "<< i << " --->  ";
                sprockets[i] = robotomaton(previous[i], i);
                cout << " = " << sprockets[i] <<'\n';
            }
        }
        for (int i = 0; i < stages; i++) {
            sum = sprockets[i];
            cout << sprockets[i] << ' ';
        }
        cout << '\n' << sum << '\n';
    }
    else {
        return 1;
    }
}
