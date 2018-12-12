#ifndef MOUSEEVENT_H_INCLUDED
#define MOUSEEVENT_H_INCLUDED

#include "Event.h"


namespace Hazel
{
    class HAZEL_API MouseMovedEvent : public Event
    {
        public:
            MouseMovedEvent(float x, float y)
            {
                mMouseX = x;
                mMouseY = y;
            }

            inline float GetX() const 
            {
                return mMouseX;
            }
            inline float GetY() const 
            {
                return mMouseX;
            }

            std::string ToString() const override
            {
                std::stringstream sstream;
                sstream << " Mouse Position : X = " << GetX() << " Y = " << GetY() ;
                return sstream.str();
            }

            EVENT_CLASS_TYPE(MouseMoved)
            EVENT_CLASS_CATEGORY(EventCategoryInput | EventCategoryMouse)
        private:
            float mMouseX, mMouseY;
    };

    class HAZEL_API MouseScrolledEvent : public Event
    {
        public:
            MouseScrolledEvent(float xOffset, float yOffset)
            {
                mScrollOffsetX = xOffset;
                mScrollOffsetY = yOffset;
            }
            inline float GetOffsetX() const 
            {
                return mScrollOffsetX;
            }
            inline float GetOffsetY() const 
            {
                return mScrollOffsetY;
            }
            std::string ToString() const override
            {
                std::stringstream sstream;
                sstream << " Mouse Scroll position : OffsetX = " << GetOffsetX() 
                        << " OffsetY = " << GetOffsetY() ;
                return sstream.str();
            }

        EVENT_CLASS_TYPE(MouseScrolled)
        EVENT_CLASS_CATEGORY(EventCategoryInput | EventCategoryMouse)
        private:
            float mScrollOffsetX, mScrollOffsetY;
    };

    class HAZEL_API MouseButtonEvent : public Event
    {
        public:
            inline int GetMouseButton() const 
            {
                return  mMouseButton;
            }

            EVENT_CLASS_CATEGORY(EventCategoryMouse | EventCategoryInput)
        
        protected:
            MouseButtonEvent(int button)
            {
                mMouseButton = button;
            }
            int mMouseButton;
            
    };

    class HAZEL_API MouseButtonPressedEvent : public MouseButtonEvent
    {
        public:
            MouseButtonPressedEvent(int button) : MouseButtonEvent(button) {}


            std::string ToString() const override
            {
                std::stringstream sstream;
                sstream << " Mouse Button pressed : Button = " << mMouseButton;
                return sstream.str();
            }
            EVENT_CLASS_TYPE(MouseButtonPressed)
    };

    class HAZEL_API MouseButtonReleasedEvent : public MouseButtonEvent
    {
        public:
            MouseButtonReleasedEvent(int button) : MouseButtonEvent(button) {}


            std::string ToString() const override
            {
                std::stringstream sstream;
                sstream << " Mouse Button released : Button = " << mMouseButton;
                return sstream.str();
            }
            EVENT_CLASS_TYPE(MouseButtonReleased)
    };

}



#endif //MOUSEEVENT_H_INCLUDED