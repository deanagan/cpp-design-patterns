#include "Hello.h"

#include <string>


namespace State
{
std::string HelloClass::Hello(const std::string& name) const
{
    return std::string{ "Hello " + name};
}

}