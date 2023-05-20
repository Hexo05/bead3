
#include "kirajzol.hpp"
using namespace genv;
kirajzol::kirajzol(std::vector<Widget*> &w) : widgets(w){}


void kirajzol::frissit()
{

    genv::gout << genv::refresh;
}

void kirajzol::pajarajzol()
{
    gout<< move_to(290,20) << color(0,255,0) << text("Amoba");
    for (Widget * w : widgets) {
        w->draw();
    }
    frissit();
}

void kirajzol::playerrajzol(bool player)
{
    gout<< move_to(500,10) << color(0,0,0)<<  box(100,60);
    if(player)
    {
       gout << move_to(520,50)<< color(0,255,0) << text("Player two");
    }
    else if(player == false)
    {
       gout << move_to(520,50)<< color(255,255,255) << text("Player one");
    }
    frissit();
}


void kirajzol::lepescountrajzol(int count)
{
    gout<< move_to(10,50)<<box(150,-30);
    gout<< move_to(10,50)<< color(255,255,255) << text("Move count:"+std::to_string(count));
    frissit();
}

void kirajzol::endscreen(bool game,bool player)
{
    if(game)
    {
        gout<< move_to(00,00)<< color(0,0,0) <<box(620,680);
       if(player)
       {
           gout << move_to(225,320)<< color(255,255,255) << text("Player one won the game!");
           gout << move_to(225,350)<< color(255,255,0) << text("Press ESCAPE to exit");
       }
       else if(player == false)
       {
           gout << move_to(225,320)<< color(0,255,0) << text("Player two won the game!");
           gout << move_to(225,350)<< color(255,255,0) << text("Press ESCAPE to exit");
       }
       frissit();
    }

}

/*void kirajzol::copywidgets(const std::vector<Widget*> &ref)
{
    widgets = ref;
}*/


