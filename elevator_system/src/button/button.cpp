#include "button/button.h"

Button::Button(ButtonDispatcher* button_dispatcher) {
	m_button_dispatcher = button_dispatcher;
}

void Button::setButtonStatus(BUTTON_STATUS button_status) {
	m_button_status = button_status;
}