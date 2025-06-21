#ifndef __NUMBER_BUTTON__
#define __NUMBER_BUTTON__

#include "button/button.h"

class NumberButton : public Button {
private:
	int m_number;
public:
	NumberButton(ButtonDispatcher* button_dispatcher, int number);
	void press() override;
	int getNumber();
};

#endif