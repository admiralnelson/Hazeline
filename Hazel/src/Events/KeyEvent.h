#ifndef KEYEVENT_H_INCLUDED
#define KEYEVENT_H_INCLUDED

#include "Event.h"


namespace Hazel
{
    class HAZEL_API KeyEvent : public Event
    {
        public:
            inline int GetKeyCode() const 
            {
                return mKeyCode;
            }
            EVENT_CLASS_CATEGORY(EventCategoryInput | EventCategoryKeyboard)
        
        protected:
            KeyEvent(int keycode) : mKeyCode(keycode)  {}
            int mKeyCode;
    };

    class HAZEL_API KeyReleasedEvent : public KeyEvent
    {
        public:
            KeyReleasedEvent(int keycode, int repeat) : KeyEvent(keycode)
            {
                mRepeatCount = repeat;
            }
            inline int GetRepeatCount() const 
            { 
                return 0;
            }
            std::string ToString() const override
            {
                std::stringstream sstream;
                sstream << "Keypressed event: " << mKeyCode << " ( repeated: "<< mRepeatCount << ")";
                return sstream.str();
            }
            EVENT_CLASS_TYPE(KeyPressed);

        private:
            int mRepeatCount;
    };

    class HAZEL_API KeyReleasedEvent : public KeyEvent
    {
        public:
            KeyReleasedEvent(int keycode) : KeyEvent(keycode) {}
        
            std::string ToString() const override
            {
                std::stringstream sstream;
                sstream << "Keypressed released: " << mKeyCode;
                return sstream.str();
            }
            EVENT_CLASS_TYPE(KeyReleased);
    };
    
}



#endif // KEYEVENT_H_INCLUDED