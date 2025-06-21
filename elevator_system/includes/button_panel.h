#ifndef __BUTTON_PANEL__
#define __BUTTON_PANEL__

#include <vector>
#include "button/button.h"

class ButtonPanel {
private:
	std::vector<Button*> m_buttons;
public:
	ButtonPanel();
	void addButton(Button* button);
	std::vector<Button*> getButtons();
};

#endif