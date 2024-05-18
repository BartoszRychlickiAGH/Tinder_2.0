#include <iostream>
#include <string>
#include <map>
#include <cassert>
#include <vector>


using std::map, std::pair, std::endl, std::cout, std::cin, std::string, std::vector;

bool Contains(string name, map<string, string>mapa) {
    for (auto i = mapa.begin(); i != mapa.end(); i++) {
        if (name == i->first) {
            return true;
        }
    }
    return false;
}
int main()
{
    cout << "\u2665";
    map <string, string>women;
    map <string, string>men;
    vector <string>result;
    string input1{ "" }, input2{ "" };
    int k{ 0 };
    while (true) {
        cout << "Enter woman's name: " << endl, cin >> input1;
        if (input1 == "koniec") {
            break;
        }
        if (Contains(input1, women)) {
            cout << "Name already exist. Restarting..." << endl;
            continue;
        }
        cout << "Enter name of the man which you want to have a date: " << endl;
        cin >> input2;
        if (input2 == "koniec") {
            break;
        }
        women.insert(pair<string, string>(input1, input2));
        cout << endl;
    }
    while (true) {
        cout << "Enter man's name: " << endl, cin >> input1;
        if (input1 == "koniec") {
            break;
        }
        if (Contains(input1, men)) {
            cout << "Name already exist. Restarting..." << endl;
            continue;
        }
        cout << "Enter name of the woman which you want to have a date: " << endl;
        cin >> input2;
        if (input2 == "koniec") {
            break;
        }
        men.insert(pair<string, string>(input1, input2));
        cout << endl;
    }
    for (auto j = women.begin(); j != women.end(); j++) {
        for (auto i = men.begin(); i != men.end(); i++) {
            if (j->first == i->second && j->second == i->first) {
                result.push_back(i->first + " - " + i->second);//póki co \u2665 jest czytany jako "?", a nie jako serce  ,edit: jak znajdzie się rozwiązanie to zamienić na serce: \u2665
                k++;
            }
        }
    }
    cout << "Ilosc znalezionych par to: " << k << endl;
    for (int i = 0; i <= result.size() - 1; i++) {
        cout << result[i] << endl;
    }
    return 0;
}
