#include "nim game.hpp"

computer_player::computer_player(Variant_one &game) : game_computer{game} {
    name = "computer player";
    number_coin = 0;
}

void computer_player::getmove(int &num) {
    int best_score = -1000;
    num = 0;
    for (int i = 1; i <= min(3, game_computer.get_nubmer()); ++i) {
        game_computer.get_nubmer() -= i;
        int score = minimax(game_computer, false,i+number_coin);
        if (score >= best_score) {
            num = i;
            best_score = score;
        }
        game_computer.get_nubmer() += i;
    }
}

int computer_player::minimax(Variant_one game, bool mx,int number) {
    if (!game.get_nubmer()) {
        if (game.is_winner(number))return 1;
        else return -1;
    }
    if (mx) {
        int score = -1000;
        for (int i = 1; i <= min(game.get_nubmer(), 3); ++i) {
            game.get_nubmer() -= i;
            score = max(score, minimax(game, false,number+i));
            game.get_nubmer() += i;
        }
        return score;
    } else {
        int score = 1000;
        for (int i = 1; i <= min(game.get_nubmer(), 3); ++i) {
            game.get_nubmer() -= i;
            score = min(score, minimax(game, true,number));
            game.get_nubmer() += i;
        }
        return score;
    }
}