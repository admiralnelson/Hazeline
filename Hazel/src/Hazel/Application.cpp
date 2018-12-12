#include "../../hzpch.h"
#include "Application.h"
#include "../Events/Event.h"
#include "Log.h"
#include "../Events/ApplicationEvent.h"


namespace Hazel
{
    Application::Application()
    {
        //ctor
    }

    Application::~Application()
    {
        //dtor
    }
    void Application::Run()
    {
        WindowResizedEvent evt(720,280);
        HZ_INFO(evt);
        if(evt.isInCategory(Hazel::EventCategory::EventCategoryInput))
            HZ_INFO("Yes " + evt.ToString() + " is an application event");
        else
            HZ_WARN("No "+evt.ToString() + " is not an application event!");
        while(true);
    }

}
