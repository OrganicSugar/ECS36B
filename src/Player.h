//
// Created by ryan on 4/29/22.
//

#ifndef BATTLESHIP_PLAYER_H
#define BATTLESHIP_PLAYER_H
#include <string>
#include "Board.h"
#include "Ships.h"

namespace Battleship {
    struct Coordinates {
        int x, y;
    };
    class Player {
    public:
        Player();
        ~Player() = default;
        void setUpPlayer(int rows, int cols, std::vector<Battleship::Ships> ships);
        void createPlacementBoard(int rows, int cols);
        void createFiringBoard(int rows, int cols);
        void givePlayerShips(const std::vector<Battleship::Ships>& shipsVec);
        std::vector<Battleship::Ships>& getShips() {
            return ships;
        }
        //SEt up a way to have the player to access their
        void setOpponent(Player& otherPlayer) {
            opponent = &otherPlayer;
            opposingPlayerBoard = opponent->getBoard().getBoard();
        }
        Board getBoard () {
            return placementBoard;
        }
        int playerRowSize() {
            return firingBoard.getRows();
        }
        int playerColSize() {
            return firingBoard.getCols();
        }
        void setUpPossibleFiringLocations();
        //void getOpponentBoard();
        virtual void placePlayerShips() = 0; // ADD VIRTUAL AND = 0 AKA PURE VIRTUAL
        bool isMoveValid(const std::string& coords, const std::string& direction, const std::string& size);
        static void convertCoordstoInts(const std::string &basicString, int& x, int& y);
        void addShipsToPlacementBoard(std::string coords, std::string direction, const Ships& ships);
        virtual void getPlayerAttackCoords(std::string name, int& x, int& y) = 0; // ADD VIRTUAL AND = 0 AKA PURE VIRTUAL
        bool checkVectorForCollisions(const std::string& coords, const std::string& direction, const int& size);
        virtual bool validAttackCoordinates(const int &x, const int &y) = 0;
        void printPlacementBoard();
        void printPlacementBoardwithText();
        void printFiringBoardwithText();
        const std::string& getName() const;
        bool checkWin() {
            return placementBoard.checkBoardforWin();
        }
        bool checkHit(const int& x, const int& y);
        void updatePlayerPlacementBoardwithHit(const int& x, const int& y);
        void updatePlayerFiringBoardwithHit(const int& x, const int& y);
        void updatePlayerPlacementBoardwithMiss(const int& x, const int& y);
        void updatePlayerFiringBoardwithMiss(const int& x, const int& y);
        char getHit(const int& x, const int& y);
        void removeDestroyedShip(int index);
        bool checkAttackSpot(const int& x, const int& y);
    protected:
        std::string playerName;
        Board firingBoard;
        Board placementBoard;
        Player* opponent;
        std::vector<Coordinates> possibleFiringLocations;
        std::vector<std::vector<char>> opposingPlayerBoard;
        std::vector<Battleship::Ships> ships;
    };
}

#endif //BATTLESHIP_PLAYER_H
