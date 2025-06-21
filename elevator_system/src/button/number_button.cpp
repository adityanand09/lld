#include "button/number_button.h"

NumberButton::NumberButton(ButtonDispatcher* button_dispatcher, int number) : Button(button_dispatcher) {
	m_number = number;
}

void NumberButton::press() {
	m_button_dispatcher->performAction();
}

int NumberButton::getNumber() {
	return m_number;
}