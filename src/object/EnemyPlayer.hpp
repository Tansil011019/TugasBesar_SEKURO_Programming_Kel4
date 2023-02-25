#ifndef _ENEMYPLAYER_HPP_
#define _ENEMYPLAYER_HPP_
#include "ObjectPlayer.hpp"

class EnemyPlayer: public ObjectPlayer{
    private:
        int health;
        coordinate coor;
        double attackRange;
        double distanceWithPlayer;
    public:
        EnemyPlayer(); // default constructor, coordinate random
        int getHealth() const; // mengembalikan nilai health
        double getAttackRange() const; // mengembalikan range attack
        double getDistanceWithPlayer(coordinate); // mengembalikan distance dari player
        void setHealth(int); // melakukan perubahan terhadap nilai health
        coordinate getCoordinate(); // mendapatkan koordinat
};

#endif