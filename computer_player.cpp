#include "nim game.hpp"

computer_player_Variant_one::computer_player_Variant_one(Variant_one &game) : game_computer{game} {
    name = "computer player";
    number_coin = 0;
}

void computer_player_Variant_one::getmove(int &num) {
    int best_score = -1000;
    num = 0;
    for (int i = 1; i <= min(3, game_computer.total_number()); ++i) {
        game_computer.total_number() -= i;
        int score = minimax(game_computer, false, i + number_coin);
        if (score >= best_score) {
            num = i;
            best_score = score;
        }
        game_computer.total_number() += i;
    }
}

int computer_player_Variant_one::minimax(Variant_one game, bool mx, int number) {
    if (!game.total_number()) {
        if (game.is_winner(number))return 1;
        else return -1;
    }
    if (mx) {
        int score = -1000;
        for (int i = 1; i <= min(game.total_number(), 3); ++i) {
            game.total_number() -= i;
            score = max(score, minimax(game, false, number + i));
            game.total_number() += i;
        }
        return score;
    } else {
        int score = 1000;
        for (int i = 1; i <= min(game.total_number(), 3); ++i) {
            game.total_number() -= i;
            score = min(score, minimax(game, true, number));
            game.total_number() += i;
        }
        return score;
    }
}

computer_player_Variant_two::computer_player_Variant_two(Variant_two &game) : game_computer(game) {
    name = "computer player";
    memset(dp,0,sizeof dp);

}

void computer_player_Variant_two::getmove(int &index, int &num) {
    int best_score = -1000;
    for (int i = 0; i < 3; ++i) {
        for (int j = 1; j <= (min({3, game_computer[i], game_computer.total_number() - 1})); ++j) {
            game_computer[i] -= j;
            int score = minimax(game_computer, 0);
            game_computer[i] += j;
            if (score > best_score) {
                best_score = score;
                num = j;
                index = i;
            }

        }
    }
}

int computer_player_Variant_two::minimax(Variant_two game, bool mx) {
    if (game.is_lose()) {
        if (mx)
            return -1;
        else
            return 1;
    }
    int &ret = dp[game[0]][game[1]][game[2]][mx];
    if (ret)
        return ret;
    if (mx) {
        int best_score = -1000;
        for (int i = 0; i < 3; ++i) {
            for (int j = 1; j <= (min({3, game[i], game.total_number() - 1})); ++j) {
                game[i] -= j;
                int score = minimax(game, false);
                game[i] += j;
                best_score = max(best_score, score);
            }
        }
        return ret = best_score;
    } else {
        int best_score = 1000;
        for (int i = 0; i < 3; ++i) {
            for (int j = 1; j <= (min({3, game[i], game.total_number() - 1})); ++j) {
                game[i] -= j;
                int score = minimax(game, true);
                game[i] += j;
                best_score = min(best_score, score);
            }
        }
        return ret = best_score;
    }


}


