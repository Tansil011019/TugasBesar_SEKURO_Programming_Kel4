#ifndef _ENEMYPLAYER_HPP_
#define _ENEMYPLAYER_HPP_

class EnemyPlayer{
    private:
        int health;
        const int damage;
    public:
        EnemyPlayer(); // default constructor
        int getHealth() const; // mengembalikan nilai health
        int getKillCount() const; // mengembalikan nilai killCount
        void setHealth(int); // melakukan perubahan terhadap nilai health
        void setKillCount(int); // melakukan perubahan terhadap nilai killCount
};

#endif