#include <iostream>
#include "Player.h"
#include "Ranklist.h"
int main () {
    // std::ofstream outFile("player.txt",std::ios::app);
    // if(outFile.is_open()) {
    //     outFile << "Information3" << '\n';
    // }else {
    //     std::cout << "Error in opening!";
    // }

    //outFile.close();
    //std::ifstream inFile

    Player p1("dani","liqued",420,7);
    Player p2("beray","liqued",6,9);
    Player p3("kosio","liqued",5,7);
    
    
    Ranklist players;
    players.add(p1);
    players.add(p2);
    players.add(p3);
    
    //std::ofstream playersOut("players.txt");
    //players.savePlayers(playersOut);
    
    std::ifstream playersIn("players.txt");
    Ranklist players2;
    players2.loadPlayers(playersIn);
    players2.print();
}