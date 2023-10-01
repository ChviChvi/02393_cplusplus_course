//
// Created by Christiaan Vink on 12/09/2023.
//

#include <iostream>
#include <string>
#include <sstream>
#include <set>

using namespace std;

const int Informationfields = 8;

//doesnt work
int main() {
    string contactInfo[50][Informationfields];

    while (true) {
        string command;
        cin >> command;

        if (command == "quit") {
            break;
        } else if (command == "add") {
            int page;
            cin >> page;
            if (page >= 1 && page <= 50) {
                for (int i = 0; i < Informationfields; ++i) {
                    cin >> contactInfo[page][i];
                }
            }
        } else if (command == "clr") {
            int page;
            cin >> page;
            if (page >= 1 && page <= 50) {
                for (int i = 0; i < Informationfields; ++i) {
                    contactInfo[page][i] = "";
                }
            }
        } else if (command == "qry") {
            int page;
            cin >> page;
            if (page >= 1 && page <= 50 && !contactInfo[page][0].empty()) {
                for (int i = 0; i < Informationfields; ++i) {
                    cout << contactInfo[page][i];
                    if (i < Informationfields - 1) {
                        cout << ",";
                    } else {
                        cout << endl;
                    }
                }
            }
        }
    }

    return 0;
}
