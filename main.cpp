#include "widgets.hpp"
#include "aplication.hpp"
#include "jatekmester.hpp"
#include "kirajzol.hpp"
#include <vector>
#include <iostream>
#include <fstream>
using namespace std;
using namespace genv;

class MyApp: public Aplication
{
public:
    MyApp()
    {

        jmester = new jatekmester(widgets, this);
        krajzol = new kirajzol(widgets);
    }
    void action(string id)
    {
       (void)id;
    }
    void event_loop() override{
       gout.open(620,680);
       event ev;
       while(gin >> ev ) {

           if(jmester->GameOver())
           {
               krajzol->endscreen(jmester->GameOver(),jmester->getplayer());
           }
           else
           {
               jmester->handel(ev);
               krajzol->pajarajzol();
               krajzol->lepescountrajzol(jmester->getplaycount());
               krajzol->playerrajzol(jmester->getplayer());
           }

       }
    }
    virtual ~MyApp(){}
};

int main()
{
    MyApp app;
    app.event_loop();
    return 0;
}
