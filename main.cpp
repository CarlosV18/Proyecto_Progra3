#include <allegro.h>
#include <iostream>
#include <fstream>
#include <allegro/sound.h>
#include "BlackBat.h"
#include "WhiteBird.h"

using namespace std;


BITMAP *buffer;
BITMAP *buffer2;
BITMAP *bufferWin;
BITMAP *bufferLose;
BITMAP *buffTitulo,*buffInsT,*buffGane,*buffPerdi;
BITMAP *b1Buff,*b2Buff,*b3Buff, *b4Buff,*br1Buff,*br2Buff;
BITMAP *fondo,*explosiones1;
BITMAP *fondoMenu,*fondoInstrucciones, *fondoGane, *fondoPerdi;
BITMAP *shooter;
BITMAP *aux,*boton1,*boton2,*boton3, *boton4,*auxIns,*buttonR1, *buttonR2;
BITMAP *birds_left,*buffWbLeft;
BlackBat *bb;
WhiteBird *wb;
bool win,lose;
int frames=0,contWin=0,contWinF=0,frameAux=0,contTitulos=1,contLoop=0,contIns=1;
int cambioPantalla,contGane=0;
int contWbLeft=0,framesJuego=0;
int crib_x, crib_y;

void winF(int f){
    contWinF++;
    if(contWinF<=1){
        frameAux=f;
    }
}

void pantallaJuego(){
    blit(fondo,buffer,0,0,0,0,700,350);

        if (contLoop==0){
            bb = new BlackBat();
            wb =  new WhiteBird();
        }
        contLoop++;

        if(bb->muerto==false){
           bb->draw_bat(frames,buffer);
           bb->act_bat();
        }

        if(wb->muerto==false){
            wb->draw_whiteBird(frames,buffer);
            wb->act_whiteBird();
        }

        if(frames%50==0)
            bb = new BlackBat();
        if(frames%70==0)
            wb =  new WhiteBird();


        if((mouse_b & 1) && (wb->posX>=mouse_x-25 && wb->posX<=mouse_x+25) && (wb->posY>=mouse_y-25 && wb->posY<=mouse_y+25)){
            wb->muerto=true;
            cout<<"Le pego"<<endl;
//            cout<<"frame: "<<frames<<endl;
            winF(frames);
//            cout<<"frame Auxiliar: "<<frameAux<<endl;
            //if(frameAux==frames)
                contWin++;

        }
        if((mouse_b & 1) && (bb->posX>=mouse_x-25 && bb->posX<=mouse_x+25) && (bb->posY>=mouse_y-25 && bb->posY<=mouse_y+25)){
            bb->muerto=true;
//            winF(frames);
//            cout<<"frame: "<<frames<<endl;
//            cout<<"frame Auxiliar: "<<frameAux<<endl;
//            if(frameAux==frames)
                contWin++;
        }

        if(contWin==10){
            cambioPantalla=4;
        }

        if(framesJuego>2390 && contWin<10){
            cambioPantalla = 5;
        }
        draw_sprite(buffer,buffer2,0,0);
        draw_sprite(buffer,shooter,mouse_x - 75, mouse_y - 17);
        framesJuego++;
        cout<<"frames juego: "<<framesJuego<<endl;

}

void buttons(){

    if((mouse_x>=203 && mouse_x<= 482)&& (mouse_y>=129 && mouse_y<=165 )){
        boton1 = load_bitmap("Botones/jugar2.bmp",NULL);
    }else{
        boton1 = load_bitmap("Botones/jugar1.bmp",NULL);
    }

    if((mouse_x>=203 && mouse_x<= 482)&& (mouse_y>=179 && mouse_y<=215 )){
        boton2 = load_bitmap("Botones/instrucciones2.bmp",NULL);
    }else{
        boton2 = load_bitmap("Botones/instrucciones1.bmp",NULL);
    }

    if((mouse_x>=203 && mouse_x<= 482)&& (mouse_y>=229 && mouse_y<=265 )){
        boton3 = load_bitmap("Botones/salir2.bmp",NULL);
    }else{
        boton3 = load_bitmap("Botones/salir1.bmp",NULL);
    }

     if((mouse_x>=203 && mouse_x<= 482)&& (mouse_y>=279 && mouse_y<=315 )){
        boton4 = load_bitmap("Botones/scores2.bmp",NULL);
    }else{
        boton4 = load_bitmap("Botones/scores1.bmp",NULL);
    }

    blit(boton1,b1Buff,0,0,0,0,330,50);
    draw_sprite(buffer,b1Buff,180,120);

    blit(boton2,b2Buff,0,0,0,0,330,50);
    draw_sprite(buffer,b2Buff,180,170);

    blit(boton3,b3Buff,0,0,0,0,330,50);
    draw_sprite(buffer,b3Buff,180,220);

    blit(boton4,b4Buff,0,0,0,0,330,50);
    draw_sprite(buffer,b4Buff,180,270);


}

void regresaButton(){
    if((mouse_x>=20 && mouse_x<= 227)&& (mouse_y>=290 && mouse_y<=312 )){
        buttonR1 = load_bitmap("Botones/regresar2.bmp",NULL);
    }else{
        buttonR1 = load_bitmap("Botones/regresar1.bmp",NULL);
    }
    crib_x=5;
    crib_y=290;
    blit(buttonR1,br1Buff,0,0,0,0,250,40);
    draw_sprite(buffer,br1Buff,crib_x,crib_y);
    cout<<"mouse x:"<<mouse_x<<endl;
    cout<<"mouse y: "<<mouse_y<<endl;

    if((mouse_b & 1) && ((mouse_x>=20 && mouse_x<= 227)&& (mouse_y>=290 && mouse_y<=312 ))){
        cambioPantalla = 1;
    }
}
void actions(){
    if((mouse_b & 1) && ((mouse_x>=203 && mouse_x<= 482)&& (mouse_y>=129 && mouse_y<=165 ))){
        cambioPantalla = 2;
    }
    if((mouse_b & 1) && ((mouse_x>=203 && mouse_x<= 482)&& (mouse_y>=179 && mouse_y<=215 )))
        cambioPantalla = 3;
    if((mouse_b & 1) && ((mouse_x>=203 && mouse_x<= 482)&& (mouse_y>=229 && mouse_y<=265 )))
        cambioPantalla = 6;
    if((mouse_b & 1) &&((mouse_x>=203 && mouse_x<= 482)&& (mouse_y>=279 && mouse_y<=315 )))
        cambioPantalla = 6;
}

void pointerAnimation(){
     if(frames%1==0){
        blit(birds_left,buffWbLeft,contWbLeft*32,0,0,0,32,32);
        draw_sprite(buffer,buffWbLeft,mouse_x,mouse_y);
        contWbLeft++;

    }
    if(contWbLeft>4){
        contWbLeft=0;
    }
}

void menuInicial(){
    fondoMenu = load_bitmap("fondoMenu.bmp",NULL);
    blit(fondoMenu,buffer,0,0,0,0,700,350);

    switch (contTitulos){
    case 1:
        aux = load_bitmap("Botones/titulo1.bmp",NULL);
        break;
    case 2:
        aux = load_bitmap("Botones/titulo2.bmp",NULL);
        break;
    case 3:
        aux = load_bitmap("Botones/titulo3.bmp",NULL);
        break;
    }
    if(frames%1==0){
        blit(aux,buffTitulo,0,0,0,0,297,85);
        draw_sprite(buffer,buffTitulo,180,5);
        contTitulos++;
    }

    buttons();
    actions();
    pointerAnimation();

    if(contTitulos>3)
        contTitulos=1;
}

void instrucciones(){
    fondoInstrucciones = load_bitmap("fondoInstrucciones.bmp",NULL);
    blit(fondoInstrucciones,buffer,0,0,0,0,700,350);

    switch (contIns){
    case 1:
        auxIns = load_bitmap("Botones/instruccionesT1.bmp",NULL);
        break;
    case 2:
        auxIns = load_bitmap("Botones/instruccionesT2.bmp",NULL);
        break;
    }
    if(frames%1==0){
        blit(auxIns,buffInsT,0,0,0,0,330,50);
        draw_sprite(buffer,buffInsT,180,5);
        contIns++;
    }
    regresaButton();
    pointerAnimation();
    if(contIns>2)
        contIns=1;
}

void winScreen(){
    fondoGane = load_bitmap("fondoGane.bmp",NULL);
    blit(fondoGane,buffer,0,0,0,0,700,350);

    if(frames%1==0){
        blit(explosiones1,buffGane,contGane*256,0,0,0,256,256);
        draw_sprite(buffer,buffGane,500,5);
        contGane++;

    }
    if(contGane>7){
        contGane=0;
    }
}

void loseScreen(){
    fondoPerdi = load_bitmap("fondoPerdi.bmp",NULL);
    blit (fondoPerdi,buffer,0,0,0,0,700,350);

}

int main()
{
// Inicializacion allegro
   if (allegro_init() != 0)
      return 1;
   install_keyboard();
   install_timer();
   install_mouse();
   //install_sound();

// Configuracion modo grafico
   set_color_depth(32);
   if (set_gfx_mode(GFX_AUTODETECT_WINDOWED, 700, 350, 0, 0) != 0) {
      if (set_gfx_mode(GFX_SAFE, 700, 350, 0, 0) != 0) {
         set_gfx_mode(GFX_TEXT, 0, 0, 0, 0);
         allegro_message("Error modo grafico\n%s\n",
                 allegro_error);
         return 1;
      }
   }

//inicializando bitmaps
    buffer = create_bitmap(700,350);
    buffer2 = create_bitmap(700,350);
    buffTitulo = create_bitmap(297,85);
    buffInsT = create_bitmap(330,50);
    buffGane = create_bitmap(256,256);
    b1Buff = create_bitmap(330,50);
    b2Buff = create_bitmap(330,50);
    b3Buff = create_bitmap(330,50);
    b4Buff = create_bitmap(330,50);
    br1Buff = create_bitmap(250,40);
    buffWbLeft = create_bitmap(32,32);
    fondo  = load_bitmap("fondo.bmp",NULL);
    shooter = load_bitmap("shooter.bmp",NULL);
    birds_left = load_bitmap("birds_left.bmp",NULL);
    explosiones1 = load_bitmap("explosiones1.bmp",NULL);
    clear_to_color(buffer2,makecol(255,0,255));
    //show_mouse(screen);
    //set_mouse_sprite("cursor.bmp");
    bool salir = false;
    win=false;
    lose=false;
    cambioPantalla=1;

//loop juego
    while(!key[KEY_ESC] && !salir){
        switch (cambioPantalla){
        case 1:
            menuInicial();
            break;
        case 2:
            pantallaJuego();
            break;
        case 3:
            instrucciones();
            break;
        case 4:
            winScreen();
            break;
        case 5:
            loseScreen();
            break;
        case 6:
            allegro_exit();
            exit(0);
            break;
        }
        if(win==true)
            cambioPantalla=3;
        if(lose==true)
            cambioPantalla=4;

        blit(buffer,screen,0,0,0,0,700,350);
        frames++;
        rest(20);
    }
        destroy_bitmap(buffer);
        destroy_bitmap(buffer2);
        destroy_bitmap(fondo);
        destroy_bitmap(shooter);
        return 0;


}
END_OF_MAIN();
