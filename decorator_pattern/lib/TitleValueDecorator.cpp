#include "TitleValueDecorator.h"


namespace DecoratorPattern
{

TitleValueDecorator::TitleValueDecorator(TextElement* textToWrap)
    : wrappedText(textToWrap)
{

}

TextElement* TitleValueDecorator::GetWrappedTextElement() const
{
    return wrappedText;
}

}
