@echo off
cd src
g++ main.cpp object/EnemyPlayer.cpp object/ObjectPlayer.cpp object/EnemyCollection.cpp attribute/map/Map.cpp -o a
a
cd..
cmd /k