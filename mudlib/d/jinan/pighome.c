 // pighome.c
#include <room.h>
inherit ROOM;
void create()
{
  set("short","拱猪大院");
  set("long",@LONG
这是济南城的拱猪大院，这里能听到阵阵的吆喝、争吵声，向西
是济南城的大街，向上就是拱猪房。
LONG
  );
  set("exits",([
         "westup":__DIR__"street3",
         "up":__DIR__"proom",
               ]));
//    set("throw_exit","westup");
    set("no_magic",1);
    set("NONPC",1);
        set("coor/x",50);
        set("coor/y",1930);
        set("coor/z",0);
        setup();
    replace_program(ROOM); 
}        
