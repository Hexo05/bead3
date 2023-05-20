#ifndef CHECKBOX_H
#define CHECKBOX_H

#include "graphics.hpp"
#include "widgets.hpp"

class CheckBox : public Widget {
protected:
    int _state;
    bool *_jatekos;
    int _id;
public:
    CheckBox(Aplication*,int x, int y, int sx, int sy, bool* jatekos,int);
    virtual void draw() ;
    virtual void handle(genv::event ev);
    virtual bool is_checked() ;
    virtual void setstate(int);
    int ReturnState() const;
};


#endif // CHECKBOX_H
