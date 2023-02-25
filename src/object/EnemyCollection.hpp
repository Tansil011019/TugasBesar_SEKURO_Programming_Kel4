#ifndef _ENEMYCOLLECTION_HPP_
#define _ENEMYCOLLECTION_HPP_
#include "EnemyPlayer.hpp"
#include <vector>
using namespace std;

class EnemyCollection : public EnemyPlayer{
    private:
        vector<EnemyPlayer> arrOfEnemy;
        int Neff;
    public:
        EnemyCollection(); // default constructor
        int getNeff(); // mengembalikan jumlah musuh saat ini
        void addEnemy(EnemyPlayer); // menambah enemy ke vector
        vector<EnemyPlayer> getEnemyArray(); 
        void removeEnemy(int);
        void reset();
        void changeHealth(vector<EnemyPlayer>);
};

#endif