#ifndef _ENEMYPLAYER_HPP_
#define _ENEMYPLAYER_HPP_
#include "ObjectPlayer.hpp"

typedef struct coordinate{
    int x;
    int y;
};

class EnemyPlayer: public ObjectPlayer{
    private:
        int health;
        const int damage;
        coordinate coor;
        double attackRange;
        double distanceWithPlayer;
        bool turn;
    public:
        EnemyPlayer(); // default constructor, coordinate random
        int getHealth() const; // mengembalikan nilai health
        int getAttackRange() const; // mengembalikan range attack
        int getDistanceWithPlayer(); // mengembalikan distance dari player
        void setDistanceWithPlayer(double); // melakukan perubahan distance dari player
        void setHealth(int); // melakukan perubahan terhadap nilai health
        coordinate getCoordinate(); // mendapatkan koordinat
        double distance(ObjectPlayer, EnemyPlayer); // menghitung jarak dengan player
        bool getTurn();
        void setTurn(bool);
};

#endif