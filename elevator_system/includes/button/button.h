#ifndef __BUTTON__
#define __BUTTON__

#include "button_dispatcher/button_dispatcher.h"
#include "enums.h"

class Button {

protected:

	BUTTON_STATUS m_button_status;
	ButtonDispatcher* m_button_dispatcher;

public:

	Button(ButtonDispatcher* button_dispatcher);

	void setButtonStatus(BUTTON_STATUS button_status);

	virtual void press() = 0;
};

#endif