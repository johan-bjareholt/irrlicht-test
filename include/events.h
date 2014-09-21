#ifndef EVENTS_H_INCLUDED
#define EVENTS_H_INCLUDED


class EventReceiver : public IEventReceiver
{
private:
	 bool KeyIsDown[KEY_KEY_CODES_COUNT];
public:
	virtual bool OnEvent(const SEvent& event);
    virtual const bool IsKeyDown(EKEY_CODE keyCode);
    EventReceiver();
};

// EventReceiver
extern EventReceiver eventReceiver;

#endif