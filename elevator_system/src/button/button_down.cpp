#include "button/button_down.h"

ButtonDown::ButtonDown(ButtonDispatcher* button_dispatcher) : Button(button_dispatcher) {
	// ...
}

void ButtonDown::press() {
	m_button_dispatcher->performAction();
}