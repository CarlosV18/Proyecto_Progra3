#include <allegro.h>
#include <iostream>
#ifndef WHITEBIRD_H
#define WHITEBIRD_H

using namespace std;

class WhiteBird
{
    public:
        WhiteBird();
        BITMAP *buffWhiteBird;
        BITMAP *birds;
        int contWhiteBird,posX,posY;
        bool muerto;
        void draw_whiteBird(int f, BITMAP *buff);
        void act_whiteBird();
        virtual ~WhiteBird();
    protected:
    private:
};

#endif // WHITEBIRD_H
