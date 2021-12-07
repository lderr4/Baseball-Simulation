#ifndef PLAYER_H
#define PLAYER_H
#include <string>

class Player
{
    private:
    std::string name;
    std::string team;
    int iteam;
   

    public:
    Player();

    void setName(std::string);
    std::string getName();

    void setTeam(std::string);
    std::string getTeam();

    void setIteam(int);
    int getIteam();


};

#endif