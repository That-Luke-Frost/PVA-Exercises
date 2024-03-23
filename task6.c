#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <map>
//#include <locale>
//#include <strings.h>
#include <algorithm>
//#include <cctype>
using namespace std;

int main() {
    char ch;
//    cin.get(ch); // nacte znak
    bool newregal = true;

//    ifstream soubor(std::cin);
//    ifstream soubor;
//    soubor.rdbuf(cin.rdbuf());
    if (!cin) {
        return 1;
    }

    //sekce s regalama
    vector<vector<string>> seznamRegalu;
    int regalindex = 0;
    while (newregal) {
        seznamRegalu.push_back(vector<string>{}); //vytvori regal v seznamu regalu
        newregal = false;

//        cout << "regalsize: " << seznamRegalu.size() << endl;

        cin >> ch;
        if (ch != '#') {
            return 2;
        }
        int value;
        cin >> value;
        if (value != regalindex) {
            return 3;
        }
        regalindex++;
        cin.get(ch);
        if (ch != '\n') {
            return 4;
        }
        //veci v regalech

        string s;
//        std::vector<std::string> regal;

    //    for (int k = 0; k < 10; k++) {
        while (true) {
            if (cin.peek() == '#') {
                newregal = true;
                break;
            }
            getline(cin, s);
    //        cout << "[" << s << "]" << endl;

            if (s == "") {
    //            cout << "broke" << endl;
                break;
            }
            if (cin.eof())
                break;
//            regal.push_back(s);
            seznamRegalu[seznamRegalu.size() - 1].push_back(s);
        }
    }
    //printregals

//    cout << seznamRegalu.size() << endl;
//    for (int vypisregaly = 0; vypisregaly < seznamRegalu.size(); vypisregaly++) {
//        cout << "regal numero " << vypisregaly << endl;
//        for (int vypisregal = 0; vypisregal < seznamRegalu[vypisregaly].size(); vypisregal++) {
//            cout << "  " << seznamRegalu[vypisregaly][vypisregal] << endl;
//        }
//    }

    //seznamy

    bool newSeznam = true;
    bool notEmpty = false;
    vector<vector<string>> seznamSeznamu;
    while (newSeznam) {

        seznamSeznamu.push_back(vector<string>{}); //vytvori regal v seznamu regalu

//        cout << "seznamSize: " << seznamSeznamu.size() << endl;

//        cin >> ch;
//        if (ch != '#') {
//            return 2;
//        }
//        int value;
//        cin >> value;
//        if (value != regalindex) {
//            return 3;0
//        }
//        regalindex++;
//        cin.get(ch);
//        if (ch != '\n') {
//            return 4;
//        }
//        //veci v regalech

        string s;
//        std::vector<std::string> regal;

    //    for (int k = 0; k < 10; k++) {
        while (true) {
//            if (cin.peek() == '#') {
//                newregal = true;
//                break;
//            =  }
            getline(cin, s);
//            cout << "[" << s << "]" << endl;
    //        cout << "[" << s << "]" << endl;

            if (s == "") {
                if (cin.eof())
                    newSeznam = false;
    //            cout << "broke" << endl;
                break;
            }
//            regal.push_back(s);
            seznamSeznamu[seznamSeznamu.size() - 1].push_back(s);
            if (cin.eof()) {
                newSeznam = false;
                break;
            }
            if (!notEmpty)
                notEmpty = true;
        }
    }

    if (notEmpty == false) {
        cout << "Invalid input." << endl;
        return 5;
    }

//    cout << seznamSeznamu.size();
//    for (int vypisSeznamy = 0; vypisSeznamy < seznamSeznamu.size(); vypisSeznamy ++) {
//        cout << "seznam numero " << vypisSeznamy << endl;
//        for (int vypisSeznam = 0; vypisSeznam < seznamSeznamu[vypisSeznamy].size(); vypisSeznam++) {
//            cout << "  " << seznamSeznamu[vypisSeznamy][vypisSeznam] << endl;
//        }
//    }

//    cout << "Nacteny znak: " << ch << value << s << endl;


    //Hledani optimalni trasy
    vector<multimap<int, pair<string, string>>> finalniSeznam;
    for (int seznamCislo = 0; seznamCislo < seznamSeznamu.size(); seznamCislo++) {
        finalniSeznam.push_back({});
        for (int hodnotaVSeznamu = 0; hodnotaVSeznamu < seznamSeznamu[seznamCislo].size(); hodnotaVSeznamu++) {
            //hledame pro kazdou hodnotu v seznamu odpovidajici regal.
    //        seznamSeznamu[0][hodnotaVSeznamu];

            string transformedSeznamSeznamu = seznamSeznamu[seznamCislo][hodnotaVSeznamu];
            transform(transformedSeznamSeznamu.begin(), transformedSeznamSeznamu.end(), transformedSeznamSeznamu.begin(),  [](char c){ return std::tolower(c);});
            bool found = false;
            for (int i2 = 0; i2 < seznamRegalu.size(); i2++) {
                for (int j2 = 0; j2 < seznamRegalu[i2].size(); j2++) {
    //                cout << "{" << strcasecmp(seznamSeznamu[0][hodnotaVSeznamu].c_str(), seznamRegalu[i2][j2].c_str()) << "}" << endl;
//                    if (strcasecmp(seznamSeznamu[seznamCislo][hodnotaVSeznamu].c_str(), seznamRegalu[i2][j2].c_str()) == 0) {
                        string transformedSeznamRegalu = seznamRegalu[i2][j2];
                        transform(transformedSeznamRegalu.begin(), transformedSeznamRegalu.end(), transformedSeznamRegalu.begin(), [](char c){ return std::tolower(c);});

                        if (transformedSeznamSeznamu == transformedSeznamRegalu) {
//                        cout << "Cislo seznamu: " << seznamCislo << "Hodnota v seznamu: [" << seznamSeznamu[seznamCislo][hodnotaVSeznamu].c_str() << "] Hodnota v regalu: [" << seznamRegalu[i2][j2].c_str() << "] Nalezeno na: " << i2 << endl;
                        //Struktura ukladani: Key je index isle, value je jmeno itemu na seznamu + v regalu
                        finalniSeznam[seznamCislo].insert({i2, {seznamSeznamu[seznamCislo][hodnotaVSeznamu], seznamRegalu[i2][j2]}});

                        found = true;
                        break;
                    }
                }
                if (found)
                    break;
            }
            if (!found) {
                //transformace stringu na mala pismena
//                string transformedSeznamSeznamu = seznamSeznamu[seznamCislo][hodnotaVSeznamu];
//                auto itt =transformedSeznamSeznamu.begin();
//                transform(transformedSeznamSeznamu.begin(), transformedSeznamSeznamu.end(), transformedSeznamSeznamu.begin(), std::tolower);

                for (int i2 = 0; i2 < seznamRegalu.size(); i2++) {
                    for (int j2 = 0; j2 < seznamRegalu[i2].size(); j2++) {
        //                cout << "{" << strcasecmp(seznamSeznamu[0][hodnotaVSeznamu].c_str(), seznamRegalu[i2][j2].c_str()) << "}" << endl;
                        string transformedSeznamRegalu = seznamRegalu[i2][j2];
                        transform(transformedSeznamRegalu.begin(), transformedSeznamRegalu.end(), transformedSeznamRegalu.begin(), [](char c){ return std::tolower(c);});

                        if (transformedSeznamRegalu.find(transformedSeznamSeznamu) != std::string::npos) {
//                            cout << "Cislo seznamu: " << seznamCislo << "Hodnota v seznamu: [" << seznamSeznamu[seznamCislo][hodnotaVSeznamu].c_str() << "] Hodnota v regalu: [" << seznamRegalu[i2][j2].c_str() << "] Nalezeno na: " << i2 << endl;
                            //Struktura ukladani: Key je index isle, value je jmeno itemu na seznamu + v regalu
                            finalniSeznam[seznamCislo].insert({i2, {seznamSeznamu[seznamCislo][hodnotaVSeznamu], seznamRegalu[i2][j2]}});

                            found = true;
                            break;
                        }
                    }
                    if (found)
                        break;
                }
            }
            if (!found)
                finalniSeznam[seznamCislo].insert({-1, {seznamSeznamu[seznamCislo][hodnotaVSeznamu], "N/A"}}); //-1 means not found

        }
    }
    //vyspani hodnot v finalnim seznamu

//    finalniSeznam.equal_range(1)
    for (int seznamCislo = 0; seznamCislo < seznamSeznamu.size(); seznamCislo++) {
        cout << "Optimised list:" << endl;
        int index = 0;
        multimap<int, pair<string, string>>::iterator it = finalniSeznam[seznamCislo].lower_bound(0);
    //    for (const auto& pair: finalniSeznam) {
        for (; it != finalniSeznam[seznamCislo].end(); it++) {
            std::cout << " " << index << ". " << it->second.first << " -> #" << it->first << " " << it->second.second << std::endl;
            index++;
        }
    //    for (it = finalniSeznam.lower_bound(-1); it != )
        it = finalniSeznam[seznamCislo].lower_bound(-1);
        for (;it != finalniSeznam[seznamCislo].upper_bound(-1); it++) {
            std::cout << " " << index << ". " << it->second.first << " -> " << it->second.second << std::endl;
            index++;
        }
    }

    return 0;
}
