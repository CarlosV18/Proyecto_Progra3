#include "WhiteBird.h"

WhiteBird::WhiteBird()
{
    buffWhiteBird = create_bitmap(32,32);
    birds = load_bitmap("birds.bmp",NULL);
    contWhiteBird=0;
    posX=0;
    posY=177;
    muerto=false;
}

WhiteBird::~WhiteBird()
{
    //dtor
}

void WhiteBird::draw_whiteBird(int f, BITMAP *buff){

    if(f%1==0){
        blit(birds,buffWhiteBird,contWhiteBird*32,0,0,0,32,32);
        draw_sprite(buff,buffWhiteBird,posX,posY);
        contWhiteBird++;

    }
    if(contWhiteBird>4){
        contWhiteBird=0;
    }
}

void WhiteBird::act_whiteBird(){
    posX+=15;
}
