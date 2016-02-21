 // Room: woodroad3.c --- neon
inherit ROOM; 
void create()
{
        set("short", "楠木走廊"); 
        set("long", @LONG
这是一条长长的楠木走廊，它横架于沙草之上。长廊的木料透出金亮明橙的楠
木本色。长廊四下雕梁画柱，令人目不暇接。
LONG);
        
        set("indoors", "yinghe");
        set("exits",([
        "south":__DIR__"woodroad4",
        "northwest":__DIR__"woodroad2",
        ]) );
        //}}
        set("objects", ([
                __DIR__"npc/yingwu" : 1,
        ]));
        setup();
        replace_program(ROOM);
}      
