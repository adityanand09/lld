#include "dice.h"
#include <random>

Dice::Dice(int dice_count, int min_value, int max_value) : m_dice_count(dice_count), m_min_value(min_value), m_max_value(max_value) {}

int Dice::roll() {
    std::random_device rd;  // Obtain a random number from hardware
    std::mt19937 eng(rd());  // Seed the generator
    std::uniform_int_distribution<> distr(m_min_value, m_max_value);  // Define the range

    int total = 0;
    for (int i = 0; i < m_dice_count; ++i) {
        total += distr(eng);  // Generate random number in range [1, 6]
    }
    return total;
}