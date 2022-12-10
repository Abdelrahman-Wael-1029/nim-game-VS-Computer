#include "nim game.hpp"

Variant_two::Variant_two() {
    piles[0] = piles[1] = 8;
    piles[2] = 9;
}

bool Variant_two::is_lose(int number) {
    return number == 1;
}

int Variant_two::total_number() {
    return piles[0] + piles[1] + piles[2];
}

int &Variant_two::operator[](int n) {
    return piles[n];
}
