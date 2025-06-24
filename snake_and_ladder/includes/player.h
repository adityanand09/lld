#include <string>
class Player {
    private:
        int m_id;
        int m_position;
        std::string m_name;
    public:
        Player(int id, std::string name);
        int getId();
        int getPosition();
        void setPosition(int position);
        std::string getName();
};