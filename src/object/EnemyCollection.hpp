#ifndef _ENEMYCOLLECTION_HPP_
#define _ENEMYCOLLECTION_HPP_
#include "EnemyPlayer.hpp"
#include <vector>
using namespace std;

class EnemyCollection{
    private:
        vector<EnemyPlayer> arrOfEnemy;
        int Neff;
    public:
        EnemyCollection(); // default constructor
        int getNeff() const; // mengembalikan jumlah musuh saat ini
};

#endif