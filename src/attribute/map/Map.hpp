#ifndef _MAP_HPP_
#define _MAP_HPP_
#include "../../object/ObjectPlayer.hpp"
// #include "../../object/EnemyPlayer.hpp"
#include "../../object/EnemyCollection.hpp"

class Map{
    private:
        int size_x;
        int size_y;
    public:
        Map(); // default constructor
        /*
            print map dengan koordinat musuh dan main
        */
       void printMap(ObjectPlayer player, EnemyCollection arrOfEnemy);
};

#endif