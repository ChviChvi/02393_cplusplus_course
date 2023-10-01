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
void visual(tile playground[NROWS][NCOLS], int playerX, int playerY) {
    for (int i = 0; i < NROWS; i++) {
        for (int j = 0; j < NCOLS; j++) {
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



    //making the initial array
    tile playground[NROWS][NCOLS];
    for (int i = 0; i < NROWS; i++) {
        for (int j = 0; j < NCOLS; j++) {
            playground[i][j].x = j;
            playground[i][j].y = i;
            //here the walls are set   left //       bottom //top (except j3) // right
            playground[i][j].isWall = (j==0 || i==(NROWS-1) || (i==0 && j!=3) || j==(NCOLS-1));
            if (playground[i][j].isWall) {
                playground[i][j].type = stone;
            } else {
                playground[i][j].type = wood;
            }
        }
    }

    int player_X = 5;
    int player_Y = 5;
    char command;

    while (true) {

        visual(playground, player_X, player_Y);

        cout << "";
        cin >> command;

        switch (command) {
            case 'q':
                return 0;
            case 'l':

                //check if player not walking in a wall
                if (player_X > 0 && !playground[player_Y][player_X - 1].isWall) {
                    player_X--;
                }
                break;
            case 'r':
                if (player_X < NCOLS - 1 && !playground[player_Y][player_X + 1].isWall) {
                    player_X++;
                }
                break;
            case 'u':
                if (player_Y > 0 && !playground[player_Y - 1][player_X].isWall) {
                    player_Y--;
                }
                break;
            case 'd':
                if (player_Y < NROWS - 1 && !playground[player_Y + 1][player_X].isWall) {
                    player_Y++;
                    break;
                }
        }
    }
    return 0;
}
