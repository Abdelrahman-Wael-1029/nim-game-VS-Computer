
#include <utility>

#include "nim game.hpp"
player::player(string str) {
    name=std::move(str);
    number_coin=0;
}
player::player():number_coin(0){
}
void player::getmove(int &num) {
    cin>>num;
}
string player::get_name() {
    return name;
}
int& player::get_number() {
    return number_coin;
}
