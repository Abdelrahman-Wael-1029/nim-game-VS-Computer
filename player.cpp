
#include <utility>

#include "nim game.hpp"

player_Variant_one::player_Variant_one(string str) {
    name = std::move(str);
    number_coin = 0;
}

player_Variant_one::player_Variant_one() : number_coin(0) {
}

void player_Variant_one::getmove(int &num) {
    cin >> num;
}

string player_Variant_one::get_name() {
    return name;
}

int &player_Variant_one::get_number() {
    return number_coin;
}

string player_Variant_two::get_name() {
    return name;
}

player_Variant_two::player_Variant_two(string name):name(std::move(name)) {

}

void player_Variant_two::getmove(int &index,int &num) {
    cin>>index>>num;
}

player_Variant_two::player_Variant_two() =default;

