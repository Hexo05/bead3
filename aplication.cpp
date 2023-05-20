#include "aplication.hpp"
#include "jatekmester.hpp"
#include "widgets.hpp"
#include <iostream>
using namespace genv;
using namespace std;
Aplication::~Aplication()
{
    delete jmester;
    delete krajzol;
    for (Widget * w : widgets) {
        delete w;
    }
    widgets.clear();
}

void Aplication::event_loop() {
    event ev;
    int focus = -1;
    while(gin >> ev ) {
        if (ev.type == ev_mouse && ev.button==btn_left) {
            for (size_t i=0;i<widgets.size();i++) {
                if (widgets[i]->is_selected(ev.pos_x, ev.pos_y)) {
                        focus = i;


                }
            }
        }

        if(ev.type == ev_key && ev.keycode == key_escape)
        {
           exit(0);
        }

        if (focus!=-1) {
            widgets[focus]->handle(ev);
           // jatekmester.lepett(widgets[focus],1)

        }

    }
}


void Aplication::register_widget(Widget* w)
{
    widgets.push_back(w);
}


