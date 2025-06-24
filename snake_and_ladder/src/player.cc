#include "player.h"

Player::Player(int id, std::string name) : m_id(id), m_name(std::move(name)), m_position(0) {}

int Player::getId() {
    return m_id;
}

int Player::getPosition() {
    return m_position;
}

void Player::setPosition(int position) {
    m_position = position;
}

std::string Player::getName() {
    return m_name;
}