#pragma once
#include "Player.h"

class Ranklist {
private:
    Player players[5];
    size_t size;
public:
    Ranklist(){
        size = 0;
    }

    void add(const Player& _player) {
        players[size++] = _player;
    }

    void savePlayers(std::ofstream& out) const {
        out << size << '\n';     

        for (size_t i = 0; i < size; i++) {
            players[i].savePlayer(out);
        }
    }

    void loadPlayers(std::ifstream& in) {
        in >> size;
        in.ignore();

        for (size_t i = 0; i < size; i++) {
            Player temp;
            temp.loadPlayer(in);
            // this->add(players[i]) - грешка при упражнението - увеличаваме size и i едновременно и става безкраен цикъл
            this->players[i] = temp;
            in.ignore();
        }
    }

    void print() const {
        for (size_t i = 0; i < size; i++) {
            players[i].printInfo();
        }
    }
};  
