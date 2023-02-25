#ifndef _OBJECTPLAYER_HPP_
#define _OBJECTPLAYER_HPP_

struct coordinate{
    int x;
    int y;
};

class ObjectPlayer{
    private:
        int health;
        static int killCount;
        coordinate coor;
        double attackRange;
    public:
        ObjectPlayer(); // default constructor, coor = 0, 0 damage = 1, isDeath = false
        int getHealth() const; // mengembalikan nilai health
        int getDamage() const; // mengembalikan nilai damage
        int getKillCount() const; // mengembalikan nilai killCount
        double getAttackRange() const; // mengembalikan range attack
        void setHealth(int); // melakukan perubahan terhadap nilai health
        void setKillCount(int); // melakukan perubahan terhadap nilai killCount
        coordinate getCoordinate(); // mengembalikan koordinat
        void setCoordinate(int , int); // melakukan setting koordinat 
        bool getStatus(); // mengembalikan isDeath
        void SOUTH();
        void WEST();
        void EAST();
        void NORTH();
        void reset();
        void killEnemy();
};

#endif