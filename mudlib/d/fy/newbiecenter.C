#include <room.h>
inherit NEWBIE_HELP_ROOM; 
void create()
{
        set("short", "隧道中心");
        set("long", @LONG
一个古色古香的地下城中心，通往四方八面。黑黑的四周似乎
放着好些东西，凌乱中有点诡异。阵阵过堂风吹过，将中间的水池
掀起一些小波浪，传来幽幽的香味，那么诱惑迷人。
LONG
        );
    set("exits", ([ /* sizeof() == 4 */
                "north" : __DIR__"nnewbie4",
                "south" : __DIR__"snewbie4",
                "east" : __DIR__"enewbie4",
                "west" : __DIR__"wnewbie4",
        ]));
    set("resource/water", 1);
    set("liquid/container", "水池");    
        set("objects", ([
//        __DIR__"npc/waiter" : 1,
                        ]) ); 
        set("coor/x",0);
        set("coor/y",0);
        set("coor/z",-10);
               
        setup();
}