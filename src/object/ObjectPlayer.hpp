#ifndef _OBJECTPLAYER_HPP_
#define _OBJECTPLAYER_HPP_

typedef struct coordinate{
    int x;
    int y;
};

class ObjectPlayer{
    private:
        int health;
        const int damage;
        static int killCount;
        coordinate coor;
        bool isDeath;
        int attackRange;
        bool turn;
    public:
        ObjectPlayer(); // default constructor, coor = 0, 0 damage = 1, isDeath = false
        int getHealth() const; // mengembalikan nilai health
        int getDamage() const; // mengembalikan nilai damage
        int getKillCount() const; // mengembalikan nilai killCount
        int getAttackRange() const; // mengembalikan range attack
        void setHealth(int); // melakukan perubahan terhadap nilai health
        void setKillCount(int); // melakukan perubahan terhadap nilai killCount
        virtual coordinate getCoordinate(); // mengembalikan koordinat
        virtual void setCoordinate(int , int); // melakukan setting koordinat 
        bool getStatus() const; // mengembalikan isDeath
        bool getTurn();
        void setTurn(bool);
        void SOUTH();
        void WEST();
        void EAST();
        void NORTH();
        void reset();
};

#endif