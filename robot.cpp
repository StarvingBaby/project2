#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <deque>
using namespace std;

int main() {
    ifstream robotText;
    robotText.open("input.txt");
    deque<string> fileText;
    vector<int> sprockets;
    vector<int> prev;
    int s;
    int p;
    if (robotText.is_open()) {
        while (robotText) {
            string d;
            getline(robotText, d);
            fileText.push_back(d);
        }
        fileText.pop_back();
    }
    string operation = fileText[0];
    fileText.pop_front();
    int newLine = fileText[0].find("\n");
    int stages = stoi(fileText[0]);
    fileText.pop_front();
    for (auto x : fileText) {
        int whitespace = x.find(" ");
        int n = x.length();
        s = stoi(x.substr(0, whitespace));
        p = stoi(x.substr(whitespace, n-1));
        sprockets.push_back(s);
        prev.push_back(p);
    }



    int sum = 0;
    if (operation == "robotomaton") {
        for (auto x : sprockets) {
            cout<<x<<' ';
        }
        cout<<'\n';
        for (auto x : prev) {
            cout<<x<<' ';
        }
        cout<<"\n\n";
        for(int i = 0; i < stages; i++){
            if(prev[i] > 0){
                sum += sprockets[i - prev[i]];
            }
            sum += sprockets[i];
        }
        cout<<sum<<'\n';
    }
    else if (operation == "omnidroid") {
        cout << "omnidroid";
    }
}