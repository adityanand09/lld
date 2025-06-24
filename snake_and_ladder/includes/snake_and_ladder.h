#include "board.h"
#include "dice.h"
#include "player.h"
#include <deque>

class SnakeAndLadder {
    private:
        Board* m_board;
        Dice* m_dice;
        std::deque<Player*> m_players;
        int m_winners;
    public:
        SnakeAndLadder();
        void initializeGame();
        void startGame();
};