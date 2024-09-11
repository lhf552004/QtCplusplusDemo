#ifndef RECTANGLE_H
#define RECTANGLE_H


class Rectangle
{
private:
    int width;
    int height;
public:
    Rectangle();
    int getWidth() const;
    void setWidth(int newWidth);
    int getHeight() const;
    void setHeight(int newHeight);
    int getArea() const;
    int getPerimeter() const;
};

#endif // RECTANGLE_H
