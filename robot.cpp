#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <map>
using namespace std;

int n;
int m;

vector<int> sprocket;
vector<int> prevs;
map <int, vector<int>> req;

//Memoized robotomaton construction algorithm
int MemoRobot(int t, vector<int> roboMemoArr)
{
    if (roboMemoArr[t - 1] == -1)
    {
        int sum = sprocket[t - 1];
        cout << "P: " << sum << endl;
        if (prevs[t - 1] == 0)
            roboMemoArr[t - 1] = sum;

        for (int i = 1; i <= prevs[t - 1]; i++){
            sum += MemoRobot(t - i, roboMemoArr);
            cout << "sum : " << sum << endl;
        }
            

        roboMemoArr[t - 1] = sum;
    }
    for(auto x : roboMemoArr){
        cout << x << " ";
    }
    cout << endl;
    return roboMemoArr[t - 1];
}

//Memoized omnidroid construction algorithm
int MemoOmni(int t, vector<int> omniMemoArr)
{
    if (omniMemoArr[t] == -1)
    {
        int sum = 0;
        if ((req.find(t)->second)[0] == -1)
        {
            sum = sprocket[t];
        }
        else
        {
            sum = sprocket[t];
            for (int i = 0; i < (req.find(t)->second).size(); i++)
            {
                sum = sum + MemoOmni((req.find(t)->second)[i], omniMemoArr);
            }
        }
        omniMemoArr[t] = sum;
    }
    return omniMemoArr[t];
}

//Function to convert char to string
string getString(char c)
{
    string s(1, c);
    return s;
}

//Function to take a string of two integers and place the integers in an int array
vector<int> readNum(string read)
{
    string num1;
    string num2;

    vector<int> out;

    int i;
    for (i = 0; (read.at(i) != ' '); i++)
        num1.append(1, read.at(i));

    for (i = i + 1; i < read.length(); i++)
        num2 += getString(read.at(i));

    out.push_back(stoi(num1));
    out.push_back(stoi(num2));
    return out;
}

int main()
{
    int numRobots;

    ifstream inputFile;
    inputFile.open("input.txt");
    ofstream outputFile;
    outputFile.open("output.txt");

    string read;
    string robotType;

    if (inputFile.is_open())
    {
        //Read number of robots to be constructed
        getline(inputFile, read);
        numRobots = stoi(read);

        for (int i = 0; i < numRobots; i++)
        {
            //Read type of robot to be constructed
            getline(inputFile, read);
            getline(inputFile, robotType);

            // cout << robotType << ": ";

            if (robotType == "omnidroid")
            {
                //Clear sprocket and req
                vector<int> sprocketEmpty;
                map <int, vector<int>> reqEmpty;

                sprocket = sprocketEmpty;
                req = reqEmpty;

                //Get n and m from input.txt
                getline(inputFile, read);
                n = readNum(read)[0];
                m = readNum(read)[1];

                //Initialize req to -1
                for (int i = 0; i < n; i++)
                    req.insert(pair<int, vector<int>>(i, { -1 }));

                //Fill req data structure with each part and the respective dependencies
                int i, j;
                for (int k = 0; k < m; k++)
                {
                    getline(inputFile, read);
                    i = readNum(read)[0];
                    j = readNum(read)[1];

                    if ((req.find(j)->second)[0] == -1)
                        (req.find(j)->second)[0] = i;
                    else
                        (req.find(j)->second).push_back(i);
                }

                //Fill sprocket array
                for (int k = 0; k < n; k++)
                {
                    getline(inputFile, read);
                    sprocket.push_back(stoi(read));
                }

                //Run the memoized omnidroid algorithm
                vector<int> omniMemoArr;
                for (int i = 0; i < n; i++)
                    omniMemoArr.push_back(-1);

                int output = MemoOmni(n - 1, omniMemoArr);
                outputFile << output << endl;

            }
            else if (robotType == "robotomaton")
            {
                //Clear sprocket and req
                vector<int> sprocketEmpty;
                vector<int> prevsEmpty;

                sprocket = sprocketEmpty;
                prevs = prevsEmpty;

                getline(inputFile, read);
                n = stoi(read);

                //Filling sprocket and prevs array
                int s, p;
                for (int k = 0; k < n; k++)
                {
                    getline(inputFile, read);
                    s = readNum(read)[0];
                    p = readNum(read)[1];

                    sprocket.push_back(s);
                    prevs.push_back(p);
                }

                //Run the memoized omnidroid algorithm
                vector<int> robotMemoArr;
                for (int i = 0; i < n; i++)
                    robotMemoArr.push_back(-1);

                outputFile << MemoRobot(n, robotMemoArr) << endl;
            }
        }
    }

    inputFile.close();
}
