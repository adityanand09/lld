class Dice {
    private:
        int m_dice_count;
        int m_min_value;
        int m_max_value;
    public:
        Dice(int dice_count, int min_value, int max_value);
        int roll();
};