#pragma once
#include <iostream>
#include <fstream>    
#include <cstring>        
class Player {
private:
	char playerName[11];
	char teamName[11];
	size_t wins;
	size_t loses;

    void nameReaderHelper(std::ifstream& in,char* name);
public:
	Player();
	Player(const char* _playerName,const char* _teamName, size_t _wins, size_t _loses);
	void printInfo() const;
    void savePlayer(std::ofstream& out) const;
    void loadPlayer(std::ifstream& in);
	Player& operator=(const Player& other);
};