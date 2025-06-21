#ifndef __BUTTON_UP__
#define __BUTTON_UP__

#include "button/button.h"

class ButtonUp : public Button{
private:
	// ...
public:
	ButtonUp(ButtonDispatcher* button_dispatcher);
	void press() override;
};

#endif