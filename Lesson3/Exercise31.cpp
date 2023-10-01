//
// Created by Christiaan Vink on 12/09/2023.
//
#include <iostream>
#include <string>
#include <set>

using namespace std;

int main() {

    multiset<int> coolbagpack;

    while(true) {
        string input;
        cout << "";
        cin >> input;

        if (input == "quit") {
            break;
        } else if (input == "del"){
            int number;
            cin >> number;
            auto deleting = coolbagpack.find(number);
            if (deleting != coolbagpack.end()) {
                coolbagpack.erase(deleting);
            }
        } else if (input == "qry"){
            int number;
            cin >> number;
            if (coolbagpack.find(number) != coolbagpack.end()){
                cout << "T";
            } else {
                cout << "F";
            }

        } else if(input == "add") {
            int number;
            cin >> number;
            coolbagpack.insert(number);

        } else {
            // we do nothing i guess :)
        }

    }
    cout << endl;
    return 0;
}
