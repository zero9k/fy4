 inherit ROOM;
#include <ansi.h> 
void create() 
{
        set("short", "小巷尽头");
        set("long", @LONG
小巷尽头是一排木板盖的屋子，仿佛已被风吹得摇晃起来。最后的两间门口墙
上贴着一张已抹上浆糊的红纸，红纸上写着：“吉屋招租，雅房一间，床铺新，供
早膳。月租纹银十二两整，先付，限单身无孩。”
LONG
        );
        set("exits", ([ 
        "north" : __DIR__"smallroad3",
        "west" : __DIR__"cabin4",
        ]));
        set("objects", ([
        ]) );
        set("outdoors", "biancheng");
        set("coor/x",-1150);
        set("coor/y",140);
        set("coor/z",0);
        setup();
        replace_program(ROOM);
}      
