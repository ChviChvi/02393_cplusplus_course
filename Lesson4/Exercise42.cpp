//
// Created by Christiaan Vink on 19/09/2023.
//

//
// Created by Christiaan Vink on 19/09/2023.
//

#include <iostream>

#define NROWS 12
#define NCOLS 16

using namespace std;

typedef enum { wood, stone } material;

struct tile {
    int x, y;
    bool isWall;
    material type;
};

//visualize the array by iterating and checking where the player and the walls are
void visual(tile** playground, int input_rows, int input_collumns , int playerX, int playerY) {
    for (int i = 0; i < input_rows; i++) {
        for (int j = 0; j < input_collumns; j++) {
            if (i == playerY && j == playerX) {
                cout << "O";
            } else if (playground[i][j].isWall) {
                cout << "*";
            } else {
                cout << " ";
            }
        }
        cout << endl;
    }
}
int main() {

    int input_rows;
    int input_collumns;

    cout << "";
    cin >> input_rows;
    cout << "";
    cin >> input_collumns;


    tile** playground = new tile*[input_rows];
    for (int i = 0; i < input_rows; i++) {
        playground[i] = new tile[input_collumns];
    }

    for (int i = 0; i < input_rows; i++) {
        for (int j = 0; j < input_collumns; j++) {
            playground[i][j].x = j;
            playground[i][j].y = i;
            //here the walls are set   left //       bottom //top (except j3) // right
            playground[i][j].isWall = (j==0 || i==(input_rows-1) || (i==0 && j!=3) || j==(input_collumns-1));
            if (playground[i][j].isWall) {
                playground[i][j].type = stone;
            } else {
                playground[i][j].type = wood;
            }
        }
    }

    int player_X = input_collumns/2;
    int player_Y = input_rows/2;
    char command;

    while (true) {

        visual(playground,input_rows,input_collumns, player_X, player_Y);

        cout << "";
        cin >> command;

        switch (command) {
            case 'q':

                //cleaning up the memory because it is in on the heap :)
                for (int i = 0; i < input_rows; i++) {
                    delete[] playground[i];
                }
                delete[] playground;
                return 0;
            case 'l':

                //check if player not walking in a wall
                if (player_X > 0 && !playground[player_Y][player_X - 1].isWall) {
                    player_X--;
                }
                break;
            case 'r':
                if (player_X < input_collumns - 1 && !playground[player_Y][player_X + 1].isWall) {
                    player_X++;
                }
                break;
            case 'u':
                if (player_Y > 0 && !playground[player_Y - 1][player_X].isWall) {
                    player_Y--;
                }
                break;
            case 'd':
                if (player_Y < input_rows - 1 && !playground[player_Y + 1][player_X].isWall) {
                    player_Y++;
                    break;
                }
        }
    }
    return 0;
}
