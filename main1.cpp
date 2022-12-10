#include <iostream>
#include "nim game.hpp"

int main() {
    int i = 1;
    int choice;
    while (true) {
        cout << "1-variant one\n2-variant two\n";

        cin >> choice;
        if (choice == 1) {
            Variant_one game;
            player_Variant_one *players[2];
            cout << "player one enter your name: ";
            string name;
            cin >> name;
            players[0] = new player_Variant_one(name);
            players[1] = new computer_player_Variant_one(game);
            int move;
            cout << "1-you begin\n2-the computer begin\n";
            cin >> i;
            while (i != 1 && i != 2) {
                cout << "enter valid number\n";
                cin >> i;
            }
            while (game.total_number()) {
                if (i == 2) {
                    cout << game.total_number() << endl;
                    players[1]->getmove(move);
                    cout << "computer player: " << move << endl;
                    game.total_number() -= move;
                    i = 1;
                    players[1]->get_number() += move;
                    continue;
                }

                if (i == 1) {
                    cout << game.total_number() << endl;
                    cout << players[0]->get_name() << " enter the number between (1,3): ";
                    players[0]->getmove(move);
                    while (move > 3 || move < 1 || move > game.total_number()) {
                        cout << "enter valid number: ";
                        players[0]->getmove(move);

                    }
                    game.total_number() -= move;
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
        } else if (choice == 2) {
            Variant_two game;
            player_Variant_two *players[2];
            cout << "player one enter your name: ";
            string name;
            cin >> name;
            players[0] = new player_Variant_two(name);
            players[1] = new computer_player_Variant_two(game);
            int move;
            cout << "1-you begin\n2-the computer begin\n";
            cin >> i;
            while (i != 1 && i != 2) {
                cout << "enter valid number\n";
                cin >> i;
            }
            int ind;
            while (true) {
                cout << "pile1: " << game[0] << endl;
                cout << "pile2: " << game[1] << endl;
                cout << "pile3: " << game[2] << endl;

                if (i == 1) {
                    cout << players[0]->get_name() << " enter number piles[1,3] and number coin[1,3]: ";
                    cin >> ind >> move;
                    --ind;
                    while ((ind != 1 && ind != 2 && ind != 0) || move > game[ind] || move == game.total_number()) {
                        cout << "Incorrect, enter again";
                        cin >> ind >> move;
                        --ind;
                    }
                    cout << players[0]->get_name() << " take " << move << " form " << "pile " << ind << endl;
                    game[ind] -= move;
                    i = 2;
                    continue;
                }
                if (game.is_lose(game.total_number())) {
                    cout << players[0]->get_name() << " is winner\n";
                    delete players[1];
                    delete players[0];
                    break;
                }
                if (i == 2) {
                    players[1]->getmove(ind, move);
                    game[ind] -= move;
                    cout << players[1]->get_name() << ": " << ind + 1 << " " << move << endl;
                    i = 1;
                }
                if (game.is_lose(game.total_number())) {
                    cout << "computer player is winner\n";

                    delete players[1];
                    delete players[0];
                    break;
                }
            }


        } else break;
        return 0;
    }
}
/*
*/