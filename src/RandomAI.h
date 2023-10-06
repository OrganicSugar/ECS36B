//
// Created by ryan on 5/14/22.
//

#ifndef BATTLESHIPWITHAI_RANDOMAI_H
#define BATTLESHIPWITHAI_RANDOMAI_H

#include "AIPlayer.h"

namespace Battleship {
    class RandomAI : public AIPlayer {
    public:
        explicit RandomAI(int& i);
        void getPlayerAttackCoords(std::string name, int &x, int &y) override;
        bool validAttackCoordinates(const int &x, const int &y) override;
    };
}

#endif //BATTLESHIPWITHAI_RANDOMAI_H
