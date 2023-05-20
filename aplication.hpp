#ifndef APLICATION_HPP
#define APLICATION_HPP
#include<vector>
#include <string>

class kirajzol;
class jatekmester;

class Widget;

class Aplication
{
public:

   // Aplication() = default;
    virtual void event_loop();
    void register_widget(Widget*);
    virtual void action(std::string) = 0;
    virtual ~Aplication();
protected:
    std::vector<Widget*> widgets;
    jatekmester* jmester;
    kirajzol* krajzol;
};

#endif // APLICATION_HPP
