#include <iostream>
#include "nim game.hpp"

int main() {
    Variant_one game;
    player *players[2];
    cout << "player one enter your name: ";
    string name;
    cin>>name;
    players[0] = new player(name);
    players[1] = new computer_player(game);
    int move;
    cout << "1-you begin\n2-the computer begin\n";
    int i;
    cin >> i;
    while (i != 1 && i != 2) {
        cout << "enter valid number\n";
        cin >> i;
    }
    while (game.get_nubmer()) {
        if (i == 2) {
            cout << game.get_nubmer() << endl;
            players[1]->getmove(move);
            cout << "computer player: " << move << endl;
            game.get_nubmer() -= move;
            i = 1;
            players[1]->get_number() += move;
            continue;
        }

        if (i == 1) {
            cout << game.get_nubmer() << endl;
            cout << players[0]->get_name() << " enter the number between (1,3): ";
            players[0]->getmove(move);
            while (move > 3 || move < 1 || move > game.get_nubmer()) {
                cout << "enter valid number\n";
                players[0]->getmove(move);
            }
            game.get_nubmer() -= move;
            players[0]->get_number() += move;
            i = 2;
        }
    }
    if (game.is_winner(players[0]->get_number())) {
        cout << players[0]->get_name() << " is winner";
    } else {
        cout << players[1]->get_name() << " is winner";
    }
    delete players[0];
    delete players[1];

    return 0;
}
/*
*/