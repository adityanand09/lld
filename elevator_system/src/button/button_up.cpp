#include "button/button_up.h"

ButtonUp::ButtonUp(ButtonDispatcher* button_dispatcher) : Button(button_dispatcher) {
	// ...
}

void ButtonUp::press() {
	m_button_dispatcher->performAction();
}