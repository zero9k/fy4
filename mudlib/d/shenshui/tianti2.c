 // TIE@FY3 ALL RIGHTS RESERVED
//XXDER
#include <room.h>
inherit ROOM;
void create()
{
        object con,item;
        set("short", "迷雾天梯");
        set("long", @LONG
一路走来，仔细观察，两边草丛之中居然有许多森森白骨，更有断刃残
剑，显然都是些武林中人，只是为何倒毙这里，令人匪夷所思。一道精巧的
青石拱门横跨路上，上面横书＂一入此门，再世为人＂，整个拱门显得十分
鬼异，你不由得心惊胆颤。
LONG
        );
   set("exits", ([ 
      "east" : __DIR__"valley",
      "southdown" : __DIR__"tianti1",
   ]));
   set("objects", ([
      __DIR__"obj/grass": 1,
//      __DIR__"obj/bone": 1,
   ]) );
        set("outdoors","shenshui");
        set("coor/x",160);
        set("coor/y",12230);
        set("coor/z",20);
        setup();
//        san = present("grass", this_object());
//        replace_program(ROOM);
} 
void reset()
{
   object *inv;
   object item, grass;
   ::reset(); 
   grass = present("grass", this_object());
   inv = all_inventory(grass);
   if( !sizeof(inv)) {
      item = new(__DIR__"obj/sword");
      item->move(grass);
   }
}         
