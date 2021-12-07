#include <iostream>
#include <fstream>
#include "Player.h"
#include <math.h>
#include <iomanip>
using namespace std;


Player::Player()
{
    
}

string Player::getName()
{
    return name;
}
void Player::setName(string x)
{
    name = x;
}

string Player::getTeam()
{
    return team;
}
void Player::setTeam(string x)
{
    team = x;
}

void Player::setIteam(int x)
{
    iteam = x;
}
int Player::getIteam()
{
    return iteam;
}