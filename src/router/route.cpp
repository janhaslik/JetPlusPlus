#include "../../include/jetplusplus/router/route.hpp"
#include <string>
#include <stdio.h>

namespace JETPP
{
    Route::Route(std::string name, JETPP::Methods method, void (*callback)(Request &, Response &))
    {
        this->name = name;
        this->method = method;
        this->callback = callback;
    }

    std::string Route::getName()
    {
        return this->name;
    }

    JETPP::Methods Route::getMethod()
    {
        return this->method;
    }

    void Route::execute(Request &request, Response &response)
    {
        try
        {
            this->callback(request, response); // Execute the callback function
        }
        catch (const std::runtime_error &)
        {
            std::cout << "Couldn't execute callback function of route: " << this->getName() << std::endl;
        }
    }
}
