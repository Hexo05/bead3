#include "checkbox.hpp"
#include "graphics.hpp"
#include "math.h"
using namespace genv;

CheckBox::CheckBox(Aplication* parent,int x, int y, int sx, int sy, bool *j,int id)
    :Widget(parent,x,y,sx,sy),
    _jatekos(j),
    _id(id)
{
    _state=0;
}

int CheckBox::ReturnState() const{
    return _state;
}
void CheckBox::draw()
{
    if(_state == 1)
    {
        gout << color(255,255,255);
        gout << move_to(_x+4, _y+4) << line(_size_x-8, _size_y-8);
        gout << move_to(_x+5, _y+4) << line(_size_x-8, _size_y-8);
        gout << move_to(_x+_size_x-4, _y+4) << line(-_size_x+8, _size_y-8);
        gout << move_to(_x+_size_x-5, _y+4) << line(-_size_x+8, _size_y-8);
    }
    else if(_state == 2)
    {
        gout << color(0, 255, 0);
        int radius = (_size_x < _size_y) ? _size_x / 2 - 3 : _size_y / 2 - 3;
        int centerX = _x + _size_x / 2;
        int centerY = _y + _size_y / 2;
        for (int angle = 0; angle < 360; angle += 5) {
            double x = centerX + radius * cos(angle * M_PI / 180);
            double y = centerY + radius * sin(angle * M_PI / 180);
            double x2 = centerX + radius * cos((angle + 5) * M_PI / 180);
            double y2 = centerY + radius * sin((angle + 5) * M_PI / 180);
            gout << move_to(x, y) << line_to(x2, y2);
        }
    }
    else
    {
        gout << move_to(_x, _y) << color(255,255,255) << box(_size_x, _size_y);
        gout << move_to(_x+2, _y+2) << color(0,0,0) << box(_size_x-4, _size_y-4);
    }

}

void CheckBox::handle(event ev)
{
    if(*_jatekos && _state == 0)
    {
         _state = 1;
    }
    else if(*_jatekos == false && _state == 0)
    {
          _state = 2;
    }
}
bool CheckBox::is_checked()
{
    return _state;
}

void CheckBox::setstate(int state)
{
    _state = state;
}
