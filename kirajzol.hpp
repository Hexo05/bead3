
#ifndef KIRAJZOL_HPP
#define KIRAJZOL_HPP
#include <vector>
#include "widgets.hpp"

class kirajzol{

public:
    kirajzol(std::vector<Widget*> &w);
    void pajarajzol();
    void frissit();
    void playerrajzol(bool);
    void lepescountrajzol(int);
    void endscreen(bool,bool);
protected:
    std::vector<Widget*> &widgets;
};


#endif // KIRAJZOL_HPP
