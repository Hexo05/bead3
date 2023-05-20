
#include "jatekmester.hpp"
#include <iostream>

using namespace genv;
using namespace std;

jatekmester::jatekmester(std::vector<Widget*> &w, Aplication* p): widgets(w),
    _appparent(p)
{
    _gameover = false;
    _playcount = 0;
    _focus = -1;
    _jatekos = false;
    for (int i = 0; i < 20; ++i) {
        for (int j = 0; j < 20; ++j) {
            CheckBox* w1 = new CheckBox(_appparent,10+(i*30),75+(j*30),30,30, &_jatekos,i*100+j);
            _boxes.push_back(w1);
            //_boxes.insert({{i,j},w1});
            (void)w;
        }
    }

}


bool jatekmester::vizsgal(int merre ,int state)
{
    int x[4] = {0, 0, 0, 0};
    int y[4] = {0, 0, 0,0};

    if(merre == 1)//fell le
    {
        y[0] = 30;
        y[1] = 60;
        y[2] = 90;
        y[3] = 120;
    }
    else if(merre == 2)//jobb bal
    {
        x[0] = 30;
        x[1] = 60;
        x[2] = 90;
        x[3] = 120;
    }
    else if(merre == 3)//atlo bal
    {
        x[0] = 30;
        x[1] = 60;
        x[2] = 90;
        x[3] = 120;

        y[0] = 30;
        y[1] = 60;
        y[2] = 90;
        y[3] = 120;
    }
    else if(merre == 4)//atlo jobb
    {
        x[0] = -30;
        x[1] = -60;
        x[2] = -90;
        x[3] = -120;

        y[0] = 30;
        y[1] = 60;
        y[2] = 90;
        y[3] = 120;
    }



    for (CheckBox * w : _boxes) {
        if(w->ReturnState() == state)
        {
            for (CheckBox * w2 : _boxes) {
                if(w != w2)
                {
                    if(w2->ReturnState() == state and w2->getx() == w->getx()-x[0] and w2->gety() == w->gety()-y[0])
                    {
                        for (CheckBox * w3 : _boxes) {
                            if(w2 != w3)
                            {

                                if(w3->ReturnState() == state and w3->getx() == w->getx()-x[1] and w3->gety() == w->gety()-y[1])
                                {
                                    for (CheckBox * w4 : _boxes) {
                                        if(w3 != w4)
                                        {

                                            if(w4->ReturnState() == state and w4->getx() == w->getx()-x[2] and w4->gety() == w->gety()-y[2])
                                            {
                                                for (CheckBox * w5 : _boxes) {
                                                    if(w4 != w5)
                                                    {

                                                        if(w5->ReturnState() == state and w5->getx() == w->getx()-x[3] and w5->gety() == w->gety()-y[3])
                                                        {

                                                            return true;
                                                        }
                                                    }
                                                }

                                            }
                                        }
                                    }

                                }
                            }
                        }
                    }
                }
            }
        }

    }
}


bool jatekmester::GameOver()
{
    return _gameover;
}



void jatekmester::logik(bool jatekos)
{
    int state = 0;
    if(jatekos)
    {
        state = 1;
    }
    else if(jatekos == false)
    {
        state = 2;
    }

    if(vizsgal(1,state))
    {
        _gameover = true;
    }
    if(vizsgal(2,state))
    {
        _gameover = true;
    }
    if(vizsgal(3,state))
    {
        _gameover = true;
    }
    if(vizsgal(4,state))
    {
       _gameover = true;
    }

}



void jatekmester::handel(genv::event ev){
     int mehet = 0;
    if (ev.type == ev_mouse && ev.button==btn_left) {
        for (size_t i = 0;i < widgets.size(); i++) {
            if (widgets[i]->is_selected(ev.pos_x, ev.pos_y) && widgets[i]->getlock() == false) {
                _focus = i;

                jatekcounter();
                 mehet =1;


            }
        }

    }


    if (ev.type == ev_key && ev.keycode == key_escape) {
        exit(0);
    }


    if (_focus!=-1) {
        widgets[_focus]->lock();
        widgets[_focus]->handle(ev);
    }

    if(mehet == 1)
    {

      logik(_jatekos);
        mehet = 0;
    }

}

void jatekmester::jatekcounter()
{

    _jatekos = _jatekos ? false : true;
    _playcount++;

}

bool jatekmester::getplayer()
{
    return _jatekos;
}

int jatekmester::getplaycount()
{
    return _playcount;
}

