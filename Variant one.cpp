#include"nim game.hpp"

Variant_one::Variant_one() {
    number_coins = 23;
}

int &Variant_one::total_number() {
    return number_coins;
}

bool Variant_one::is_winner(int number) {
    return (number % 2 == 0);
}

