//
// Created by Christiaan Vink on 29/08/2023.
//

#include <iostream>

using namespace std;

int main()
{
    int x, y;

    cout << "";
    cin >> x;

    cin >> y;

    if (x == y) {
        cout << x << " is equal to " << y << endl;
    } else if (x > y) {
        cout << x << " is bigger than " << y << endl;
    } else {
        cout << x << " is smaller than " << y << endl;
    }

    return 0;
}
