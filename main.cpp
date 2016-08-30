//#include <stdio.h>
#include <iostream>
#include <cstdlib>
#include <math.h>
#include "allegro5/allegro.h"
#include <allegro5/allegro_primitives.h>
#include "allegro5/allegro_image.h"
#include "allegroStart.h"
#include <stdio.h>      /* printf */
#include <math.h>       /* sin */
#include <string>

#define PI 3.14159265

using namespace std;

allegroStart mA(800,600);
ALLEGRO_DISPLAY *okno = mA.openWindow();
ALLEGRO_BITMAP  *bitmapa = mA.openBitmap(800,600);
ALLEGRO_KEYBOARD_STATE klawisz;
ALLEGRO_LOCKED_REGION *lr;
unsigned char *ptr;

//void *__gxx_personality_v0;


int main()
{
    float x1=0,y1=0,x2=0,y2=0;
    float alfa1=0, r1=20;
    float alfa2=0, r2=40;
	bitmapa = al_load_bitmap("fotka.bmp");


    while( !al_key_down( & klawisz, ALLEGRO_KEY_ESCAPE ) )    {

        lr = al_lock_bitmap(bitmapa, ALLEGRO_PIXEL_FORMAT_ABGR_8888, ALLEGRO_LOCK_READWRITE);
        ptr = (unsigned char *)lr->data;

        al_clear_to_color(al_map_rgb(0,0,0));
        al_draw_bitmap(bitmapa,0,0,0);
        al_draw_tinted_bitmap(bitmapa,al_map_rgba(255,255,255,160),x1,y1,0);
        al_draw_tinted_bitmap(bitmapa,al_map_rgba(255,255,255,200),x2,y2,0);
        al_unlock_bitmap(bitmapa);

//        x++;
//        cout <<alfa1<<endl;
//        if (x>250) x=50;
        alfa1+=3;
        x1 = sin (alfa1*PI/180)*r1;
        y1 = cos (alfa1*PI/180)*r1;
        alfa2+=3;
        x2 = sin (alfa2*PI/180)*r2;
        y2 = cos (alfa2*PI/180)*r2;

        al_flip_display();
        al_get_keyboard_state( & klawisz );
        al_rest(0.004);
        }

	return 0;
}


