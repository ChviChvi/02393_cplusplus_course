//
// Created by Christiaan Vink on 12/09/2023.
//
#include <iostream>
#include <string>
#include <sstream>
#include <set>

using namespace std;

struct info {
    string firstName;
    string middleName;
    string lastName;
    string phoneNumber;
    string streetAddress;
    string houseNumber;
    string zipCode;
    string region;
    bool operator<(const info& bypasstothissystem) const {
        return false;
    }
};

int main() {

    multiset<info> book[51];

    while (true) {
        string input;
        cin >> input;

        if (input == "quit") {
            break;
        } else if (input == "add") {
            int page;
            cin >> page;
            if (page >= 1 && page <= 50) {
                info contact;
                cin >> contact.firstName;
                cin >> contact.middleName;
                cin >> contact.lastName;
                cin >> contact.phoneNumber;
                cin >> contact.streetAddress;
                cin >> contact.houseNumber;
                cin >> contact.zipCode;
                cin >> contact.region;

                if (book[page].count(contact) == 0) {
                    book[page].insert(contact);
                }
            }
        } else if (input == "clr") {
            int page;
            cin >> page;
            if (page >= 1 && page <= 50) {
                book[page].clear();
            }
        } else if (input == "qry") {
            int page;
            cin >> page;
            if (page >= 1 && page <= 50 && !book[page].empty()) {
                for (const auto& contact : book[page]) {
                    cout << contact.firstName << ",";
                    cout << contact.middleName << ",";
                    cout << contact.lastName << ",";
                    cout << contact.phoneNumber << ",";
                    cout << contact.streetAddress << ",";
                    cout << contact.houseNumber << ",";
                    cout << contact.zipCode << ",";
                    cout << contact.region << endl;
                }
            }
        }
    }

    return 0;
}

