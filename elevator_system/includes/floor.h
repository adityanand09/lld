#ifndef __FLOOR__
#define __FLOOR__

#include "button_panel.h"

class Floor {
private:
	int m_floor_number;
	ButtonPanel* m_button_panel;
public:
	Floor(int floor_number);
	void attatchButtonPanel(ButtonPanel* button_panel);
	int getFloorNumber();
};

#endif