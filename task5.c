#include <iostream>
#include <vector>
#include <string>
#include <cmath>
#include <iomanip>

using namespace std;
int main() {

    struct plane {
        float locationX;
        float locationY;
        string name;
    };
    vector<plane> planeList;

    std::cout << "Plane coordinates:" << endl;

    float num1, num2;
    std::string tempStr;
    std::string line;
    while (getline(std::cin, line)) {
        std::stringstream ss(line);
        if (ss >> num1 && ss.peek() == ',' && ss.ignore() && ss >> num2 && ss.peek() == ':' && ss.ignore() && ss.peek() == ' ' && ss.ignore()) {
            ss >> tempStr;
            if (ss.eof()) {
            planeList.push_back({num1, num2, tempStr});
            } else {
                std::cout << "Invalid input." << std::endl;
                return 1;
            }
        } else {
            std::cout << "Invalid input." << std::endl;
            return 2;
        }
    }

    /*
    planeList.push_back({0, 0, "KLM"});
    planeList.push_back({5, 0, "Lufthansa"});
    planeList.push_back({10, 0, "SmartWings"});
    planeList.push_back({7, 0, "AirFrance"});
    planeList.push_back({2, 0, "Qantas"});
    */
/*
planeList.push_back({0, 5, "Qantas"});
planeList.push_back({5, 0, "KLM"});
planeList.push_back({0, 0, "AirFrance"});
planeList.push_back({5, 5, "Lufthansa"});
planeList.push_back({2.5, 2.5, "KLM"});
*/
/*0,5: Qantas
5,0: KLM
0,0: AirFrance
5,5: Lufthansa
2.5,2.5: KLM*/

    double shortestDistance;
    struct shortestPair {
        int index1;
        int index2;
    };
    vector<shortestPair> pairList;
    //pairList.push_back({0, 1}); is included in the for loops
    shortestDistance = sqrt(pow(abs(planeList[0].locationX - planeList[1].locationX), 2) + pow(abs(planeList[0].locationY - planeList[1].locationY), 2));

    //if at least two planes

    //calculating positions
    int maxIndex = planeList.size();
    for (int i = 0; i < (maxIndex - 1); i++) {
        for (int j = i + 1; j < maxIndex; j++) {
//            cout << planeList[i].name << " vs " << planeList[j].name << endl;
            double distance = sqrt(pow(abs(planeList[i].locationX - planeList[j].locationX), 2) + pow(abs(planeList[i].locationY - planeList[j].locationY), 2)) ; //pythagorius

            if (shortestDistance == distance) {
                pairList.push_back({i, j});
            }
            if (shortestDistance > distance) {
                pairList.clear();
                pairList.push_back({i, j});
                shortestDistance = distance;
            }
//            cout << distance << endl;
        }

    }

    //printint result
    cout << fixed << setprecision(6) << "Minimum airplane distance: " << shortestDistance << endl;
    cout << "Pairs found: " << pairList.size() << endl;
    for (int i = 0; i < pairList.size(); i++) {
        cout << /*pairList[i].index1 << ", " <<*/ planeList[pairList[i].index1].name << " - " << /*pairList[i].index2 << ", " <<*/ planeList[pairList[i].index2].name << endl;
    }
//    cout << sqrt(pow(abs(planeList[0].locationX - planeList[4].locationX), 2) + pow(abs(planeList[0].locationY - planeList[4].locationY), 2)) << endl;

//    cout << planeList.size() << endl;

//    cout << planeList[0].location << ' ' << planeList[0].name << " " << planeList.size() << endl;

    //4 + 3 + 2 + 1 + 0... the ammount of possible combinations for 5 planes
    return 0;
}
