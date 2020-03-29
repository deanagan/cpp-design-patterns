#include "TitleValue.h"
#include <string>

namespace DecoratorPattern
{
TitleValue::TitleValue(std::string title)
    : title(std::move(title))
{

}

std::string TitleValue::Value() const
{
    return title;
}

}
