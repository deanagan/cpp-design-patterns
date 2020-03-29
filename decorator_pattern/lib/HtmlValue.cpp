#include "HtmlValue.h"
#include <string>

namespace DecoratorPattern
{
HtmlValue::HtmlValue(std::string title)
    : title(std::move(title))
{

}

std::string HtmlValue::Value() const
{
    return title;
}

}
