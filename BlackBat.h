#include <allegro.h>
#include <iostream>
#ifndef BLACKBAT_H
#define BLACKBAT_H

using namespace std;
class BlackBat
{
    public:
        BlackBat();
        BITMAP *buffBat;
        BITMAP *bats;
        int posX,posY,contBat;
        bool muerto;
        void draw_bat(int f, BITMAP *buf);
        void act_bat();
        virtual ~BlackBat();
    protected:
    private:
};

#endif // BLACKBAT_H
