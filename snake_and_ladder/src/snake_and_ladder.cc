#include "snake_and_ladder.h"
#include <iostream>

SnakeAndLadder::SnakeAndLadder() : m_board(nullptr), m_dice(nullptr) {
    initializeGame();
}

void SnakeAndLadder::initializeGame() {
    m_board = new Board(10, 10); // Assuming a 10x10 board
    m_dice = new Dice(1, 1, 6); // One die with values from 1 to 6
    m_board->addSnakes(10);
    m_board->addLadders(10);
    Player* player1 = new Player(1, "Alice");
    Player* player2 = new Player(2, "Bob");
    m_players.push_back(player1);
    m_players.push_back(player2);
    m_winners = 1;
}

void SnakeAndLadder::startGame() {
    int winner_count = 0;
    while (winner_count < m_winners) {
        Player* current_player = m_players.front();
        m_players.pop_front();
        int roll = m_dice->roll();
        int new_position = current_player->getPosition() + roll;
        if (!m_board->isPositionValid(new_position)) {
            m_players.push_back(current_player);
            continue;
        };
        if (m_board->isWinningPosition(new_position)) {
            winner_count++;
            std::cout << "Player " << current_player->getName() << " wins!" << std::endl;
            current_player->setPosition(new_position);
        } else {
            Cell* cell = m_board->getCell(new_position);
            Jump* jump = cell->getJump();
            if (jump) {
                if (jump->getStart() < jump->getEnd()) {
                    std::cout << "Player " << current_player->getName() << " hit a ladder from " 
                              << jump->getStart() << " to " << jump->getEnd() << std::endl;
                } else {
                    std::cout << "Player " << current_player->getName() << " hit a snake from " 
                              << jump->getStart() << " to " << jump->getEnd() << std::endl;
                }
                new_position = jump->getEnd();
            }
            current_player->setPosition(new_position);
            std::cout << "Player " << current_player->getName() << " rolled a " << roll 
                      << " and moved to position " << new_position << std::endl;
            m_players.push_back(current_player);
        }
    }
}