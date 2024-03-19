#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

int main() {

    cout << "Input sequence:" << endl;
    std::vector<int> cisla;
    int cislo;

    while (std::cin >> cislo) {
        if (std::cin.fail()) {
            std::cout << "Invalid input." << std::endl;
            std::cin.clear();
            continue;
        }

        cisla.push_back(cislo);

        if (cisla.size() > 2000) {
            std::cout << "Invalid input." << std::endl;
            return 1;
        }
    }

    if (cisla.empty()) {
        std::cout << "Invalid input." << std::endl;
        return 1;
    }

    int indexLength = cisla.size();
    std::unordered_map<int, int> cisloPocet;

    for (int i = 0; i < indexLength; ++i) { //Calculates the sum for every sequence and puts it in unordered map cisloPocet (index: sum, value: amount of occurrence)
        //i, j, are used to define the bounds of a sequence.
        for (int j = i; j <= indexLength; ++j) { //"<=" has to be here
            if (j - i < 2) { //sequence has fewer than 2 elements. Skipping...
                continue;
            }
            int temp = 0; //initialises to 0 every time
            for (int k = i; k < j; ++k) { //counts the sum for this sequence
                temp += cisla[k];

            }

            if (cisloPocet.find(temp) != cisloPocet.end()) { //index exists, adding +1 to the number of occurrences
                cisloPocet[temp] += 1;
            }
            else { //index doesn't exist. Creating new.
                cisloPocet[temp] = 1;
            }
        }
    }

    //iterating through the whole cisloPocet unordered map, and counting the ammout of pairs.
    int numberOfPairs= 0;
    for (std::unordered_map<int, int>::iterator i = cisloPocet.begin(); i != cisloPocet.end(); ++i) {
        if (i->second > 1) { //there's at least one pair, (2 elements), I can calculate the ammount of pairs.
            numberOfPairs += (i->second * (i->second - 1 )) / 2;
        }
    }

    cout << "Total pairs: " << numberOfPairs << endl;


}
