//
// Created by ryan on 4/24/22.
//
//
//#include "gtest/gtest.h"
//#include "Game.h"
//#include "Ships.h"
//#include <memory>
//
//TEST(isMoveValidTests, CopyWasMade){
/*
// * Given a set of coordinates, I would like to see if the move are valid.
// * I will be testing a lot of inputs as this is a key component of Battleship.
// */
//    int rows = 3, cols = 3;
//    std::unique_ptr<Battleship::Player> TestPlayer = std::make_unique<Battleship::Player>("Test");
//    TestPlayer->createPlacementBoard(rows, cols);
//    TestPlayer->createFiringBoard(rows, cols);
//    std::vector<Battleship::Ships> ships;
//    std::string name = "H";
//    int size = 2;
//    Battleship::Ships testShip(name, size); //create
//    ships.push_back(testShip);
//    TestPlayer->givePlayerShips(ships);
//    std::string coords = "10 10";
//    std::string direction = "h";
//    std::string shipSize = "2";
//    bool var = Battleship::Game::isMoveValid();
//}