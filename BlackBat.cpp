#include "BlackBat.h"

BlackBat::BlackBat()
{
    buffBat = create_bitmap(32,32);
    bats = load_bitmap("bat.bmp",NULL);
    posX=698;
    posY=271;
    contBat=0;
    muerto=false;
}

BlackBat::~BlackBat()
{
    //dtor
}
void BlackBat::draw_bat(int f, BITMAP *buff){
    if(f%1==0){
        blit(bats,buffBat,contBat*32,0,0,0,32,32);
        draw_sprite(buff,buffBat,posX,posY);
        contBat++;
    }

     if(contBat>4){
        contBat=0;
    }
}

void BlackBat::act_bat(){
    posX-=7;
    posY-=7;
}
