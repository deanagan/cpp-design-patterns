#include "BoldenText.h"
#include "TitleValueDecorator.h"

namespace DecoratorPattern
{

BoldenText::BoldenText(TextElement* textElement)
    : TitleValueDecorator(textElement)
{

}

std::string BoldenText::Value() const
{
    return std::string{};
}

}
