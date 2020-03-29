#include "HtmlifyText.h"
#include "TitleValueDecorator.h"

namespace DecoratorPattern
{

HtmlifyText::HtmlifyText(ElementType::TextElementPtr& textElement)
    : TitleValueDecorator(textElement)
{

}

std::string HtmlifyText::Value() const
{
    return std::string{};
}



}
