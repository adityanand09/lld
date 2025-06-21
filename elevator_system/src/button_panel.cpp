#include "button_panel.h"

ButtonPanel::ButtonPanel() {
	// ...
}

void ButtonPanel::addButton(Button* button) {
	m_buttons.push_back(button);
}

std::vector<Button*> ButtonPanel::getButtons() {
	return m_buttons;
}