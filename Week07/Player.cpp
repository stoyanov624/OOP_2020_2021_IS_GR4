#include "Player.h"
#include <iostream>

Player::Player() {
	strcpy_s(this->playerName, 6,"Beray");
	strcpy_s(this->teamName, 6, "anton");
    this->wins = 0;
    this->loses = 0;
}

Player::Player(const char* _playerName, const char* _teamName, size_t _wins, size_t _loses)
{
	strcpy_s(playerName, strlen(_playerName) + 1, _playerName);
	strcpy_s(teamName, strlen(_teamName) + 1, _teamName);
	wins = _wins;
	loses = _loses;
}

    
void Player::printInfo() const {
    std::cout << this->playerName << std::endl;
    std::cout << this->teamName << std::endl;
    std::cout << this->wins << std::endl;
    std::cout << this->loses << std::endl;
}

void Player::savePlayer(std::ofstream& out) const {
    out << this->playerName << '\n';
    out << this->teamName << '\n';
    out << this->wins << '\n';
    out << this->loses << '\n';
}

void Player::nameReaderHelper(std::ifstream& in,char* name) {
    char ch = ' ';
    size_t counter = 0;
    while(ch != '\n') {
        ch = in.get();
        if(ch != '\n' && counter < 10) {
            name[counter++] = ch;
        }
    }
    name[counter] = '\0';
}

void Player::loadPlayer(std::ifstream& in) {
    nameReaderHelper(in, playerName);
    nameReaderHelper(in, teamName);
    in >> wins;
    in >> loses;
}

Player& Player::operator=(const Player& other)
{
    if(this != &other){
      strcpy_s(this->playerName, strlen(other.playerName) + 1, other.playerName);
      strcpy_s(this->teamName, strlen(other.teamName) + 1, other.teamName);
      this->wins = other.wins;
      this->loses = other.loses;
    }

    return *this;
}