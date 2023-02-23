#ifndef _OBJECTPLAYER_HPP_
#define _OBJECTPLAYER_HPP_

class ObjectPlayer{
    private:
        int health;
        const int damage;
        static int killCount;
    public:
        ObjectPlayer(); // default constructor
        int getHealth() const; // mengembalikan nilai health
        int getDamage() const; // mengembalikan nilai damage
        int getKillCount() const; // mengembalikan nilai killCount
        void setHealth(int); // melakukan perubahan terhadap nilai health
        void setKillCount(int); // melakukan perubahan terhadap nilai killCount
};

#endif