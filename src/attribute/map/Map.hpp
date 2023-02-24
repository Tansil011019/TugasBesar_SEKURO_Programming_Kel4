#ifndef _MAP_HPP_
#define _MAP_HPP_
#include "../../object/ObjectPlayer.hpp"
#include "../../object/EnemyPlayer.hpp"

class Map: public EnemyPlayer, ObjectPlayer {
    private:
        int size_x;
        int size_y;
    public:
        /*
            print map dengan koordinat musuh dan main
        */
       void printMap();
};

#endif