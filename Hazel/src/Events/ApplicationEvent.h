#ifndef APPLICATIONEVENT_H_INCLUDED
#define APPLICATIONEVENT_H_INCLUDED

#include "Event.h"


namespace Hazel
{
    class HAZEL_API WindowResizedEvent : public Event
    {
        public:
            WindowResizedEvent(unsigned int width, unsigned int height) 
            {
                mHeight = height;
                mWidth = width;
            }
            inline unsigned int GetWidth() 
            {
                return mWidth;
            }
            inline unsigned int GetHeight() 
            {
                return mHeight;
            }

            std::string ToString() const override
            {
                std::stringstream sstream;
                sstream << "Window resied event: Width = " << mWidth 
                        << " Height =  "<< mHeight << ")";
                return sstream.str();
            }

            EVENT_CLASS_TYPE(WindowResize)
            EVENT_CLASS_CATEGORY(EventCategoryApplication)
            
        private:
            unsigned int mWidth;
            unsigned int mHeight;
    };
    
    class HAZEL_API WindowCloseEvent : public Event
    {
        public:
            WindowCloseEvent(){}
        
            EVENT_CLASS_TYPE(WindowClose)
            EVENT_CLASS_CATEGORY(EventCategoryApplication)
    };

    class HAZEL_API ApplicationTickEvent : public Event
    {
        public:
            ApplicationTickEvent(){}
        
            EVENT_CLASS_TYPE(ApplicationTick)
            EVENT_CLASS_CATEGORY(EventCategoryApplication)
    };

    class HAZEL_API ApplicationUpdateEvent : public Event
    {
        public:
            ApplicationUpdateEvent(){}
        
            EVENT_CLASS_TYPE(ApplicationUpdate)
            EVENT_CLASS_CATEGORY(EventCategoryApplication)
    };

    class HAZEL_API ApplicationRenderEvent : public Event
    {
        public:
            ApplicationRenderEvent(){}
        
            EVENT_CLASS_TYPE(ApplicationRender)
            EVENT_CLASS_CATEGORY(EventCategoryApplication)
    };
}



#endif // APPLICATIONEVENT_H_INCLUDED