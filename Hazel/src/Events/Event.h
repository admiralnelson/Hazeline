#ifndef EVENT_H_INCLUDED
#define EVENT_H_INCLUDED

#include "../Hazel/Core.h"


namespace Hazel
{

    /*
        Non buffered Event system
        Immediately executed.
        a.k.a "blocking event system"
    */

   #define EVENT_CLASS_TYPE(type)   static EventType GetStaticType()            \
                                    {                                           \
                                        return EventType::type;                \
                                    }                                           \
                                    virtual EventType GetEventType() const override \
                                    {                                           \
                                        return GetStaticType();                 \
                                    }                                           \
                                    virtual const char* GetName() const override    \
                                    {                                           \
                                        return #type;                           \
                                    }                                           

#define EVENT_CLASS_CATEGORY(category)  virtual int GetCategoryFlags() const override {return category; }


    enum class EventType
    {
        None = 0,

        WindowClose,
        WindowResize,
        WindowFocus,
        WindowLostFocus,
        WindowMoved,
        
        ApplicationTick,
        ApplicationUpdate,
        ApplicationRender,
        
        KeyPressed,
        KeyReleased,
        
        MouseButtonPressed,
        MouseButtonReleased,
        MouseMoved,
        MouseScrolled
    };

    enum EventCategory
    {
        None = 0,
        EventCategoryApplication    = BIT(0),
        EventCategoryInput          = BIT(1),
        EventCategoryKeyboard       = BIT(2),
        EventCategoryMouse          = BIT(3),
        EventCategoryMouseButton    = BIT(4)
    };

    class HAZEL_API Event
    {
        friend class EventDispatcher;
        public:
            virtual EventType GetEventType() const = 0;
            virtual const char* GetName() const = 0;
            virtual int GetCategoryFlags() const = 0;
            virtual std::string ToString() const 
            { 
                return GetName();
            }

            inline bool isInCategory(EventCategory category)
            {
                return GetCategoryFlags() & category;
            }
        protected:
            bool mHandled = false;
    };

    class EventDispacther
    {
        template<typename T>
        using EventFunction = std::function<bool(T&)>;
        public:
            EventDispacther(Event &event) : mEvent(event)
            { }

            template<typename T>
            bool Dispatch(EventFunction<T> func)
            {
                if(mEvent.GetEventType() == T::GetStaticType())
                {
                    mEvent.mHandled = func(*(T*) &mEvent);
                    return true;
                }
                return false;
            }
        private:
            Event &mEvent;
    };

    inline std::ostream& operator << (std::ostream& os, const Event& evt)
    {
        return os << evt.ToString();
    }
}


#endif // EVENT_H_INCLUDED