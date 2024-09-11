#include "rectangle.h"

int Rectangle::getWidth() const
{
    return width;
}

void Rectangle::setWidth(int newWidth)
{
    width = newWidth;
}

int Rectangle::getHeight() const
{
    return height;
}

void Rectangle::setHeight(int newHeight)
{
    height = newHeight;
}

int Rectangle::getArea() const
{
    return width * height;
}

int Rectangle::getPerimeter() const
{
    return 2 * (width + height);
}

Rectangle::Rectangle()
{

}
