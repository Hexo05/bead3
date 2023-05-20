
#ifndef JATEKMESTER_HPP
#define JATEKMESTER_HPP
#include <vector>
#include "graphics.hpp"
#include "widgets.hpp"
#include "checkbox.hpp"
//#include "unordered_map"

class Aplication;

class jatekmester
{
public:
    jatekmester(std::vector<Widget*> &w, Aplication* p);
    virtual void handel(genv::event ev);
    virtual ~jatekmester(){}
    void jatekcounter();
    void logik(bool);
    bool vizsgal(int,int);
    int getplaycount();
    bool getplayer();
    bool GameOver();
protected:
    bool CheckNeighboursUp();
    std::vector<Widget*> &widgets;
    Aplication* _appparent;
    bool _jatekos;
    int _focus;
    int _playcount;
    bool _gameover;
    std::vector<CheckBox*> _boxes;
    //std::unordered_map<std::pair<int,int>, CheckBox*> _boxes;
};

#endif // JATEKMESTER_HPP
