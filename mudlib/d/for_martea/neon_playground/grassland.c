#include <ansi.h>
inherit ROOM;
void create()
{
    set("short", HIG"常青草地"NOR);
    set("long", @LONG
一片四季常绿的草地。
绿油油的细草，柔软得很像是情人的头发。草地绵延伸向远方一片果树林。
LONG
        );
        set("exits", ([ 
        "south" : __DIR__"shanpo",
        "south" : __DIR__"kezhan",
        "west" : __DIR__"smallyard",
        ]));
        set("outdoors","neon_playground");
        set("coor/x",0);
        set("coor/y",30040);
        set("coor/z",0);
        setup();
}     
