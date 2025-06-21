#ifndef __BUTTON_DISPATCHER__
#define __BUTTON_DISPATCHER__

class ButtonDispatcher {
private:
public:
	ButtonDispatcher();
	virtual void performAction() = 0;
};

#endif