#ifndef __BUTTON_DOWN__
#define __BUTTON_DOWN__

#include "button/button.h"

class ButtonDown : public Button {
private:
	// ...
public:
	ButtonDown(ButtonDispatcher* button_dispatcher);
	void press() override;
};

#endif