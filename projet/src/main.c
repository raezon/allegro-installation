#include <stdio.h>
#include <allegro5/allegro.h>
#include <allegro5/allegro_native_dialog.h>


int main()
{
  al_init();
  al_show_native_message_box(NULL,"ALLEGRO","Hello le bazar de Monos",NULL,NULL,0);
  
  
  return 0;
  
}