#include "widgets.hpp"
#include "graphics.hpp"
using namespace genv;

Widget::Widget(Aplication* parent ,int x, int y, int sx, int sy) : _parent(parent), _x(x), _y(y), _size_x(sx), _size_y(sy)
{
    _parent->register_widget(this);
    _locked= false;
}

bool Widget::is_selected(int mouse_x, int mouse_y) 
{
    return mouse_x>_x && mouse_x<_x+_size_x && mouse_y>_y && mouse_y<_y+_size_y;
}

void Widget::lock()
{
    _locked = true;
}

bool Widget::getlock()
{
    return _locked;
}

Widget::~Widget(){

}

int Widget::getx()
{
    return _x;
}

int Widget::gety()
{
    return _y;
}





