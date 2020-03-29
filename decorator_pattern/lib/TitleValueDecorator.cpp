#include "TitleValueDecorator.h"


namespace DecoratorPattern
{

TitleValueDecorator::TitleValueDecorator(ElementType::TextElementPtr& textToWrap)
    : wrappedText(std::move(textToWrap))
{

}

TextElement* TitleValueDecorator::GetWrappedTextElement() const
{
    return nullptr;
}

}
