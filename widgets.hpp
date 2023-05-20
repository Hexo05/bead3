#ifndef WIDGETS_HPP_INCLUDED
#define WIDGETS_HPP_INCLUDED
#include "graphics.hpp"
#include "aplication.hpp"

#define LOG(x) std::cout<<x<<std::endl
class Widget {
protected:
    Aplication* _parent;
    int _x, _y, _size_x, _size_y;
    bool _locked;
public:
    Widget(Aplication*,int x, int y, int sx, int sy);
    virtual ~Widget();

    virtual bool is_selected(int mouse_x, int mouse_y);
    virtual void draw() = 0;
    virtual void handle(genv::event ev) = 0;
    void lock();
    bool getlock();
    int getx();
    int gety();
    //virtual void coursorflash(int);
};

                                                                                                                                                                                                                                                                  //szeretnek pontlevonast kerni a beadandomra mert feltoltottem egy oktatasi segedletet sajat munka helyett :)

#endif // WIDGETS_HPP_INCLUDED
