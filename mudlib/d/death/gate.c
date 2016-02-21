 // TIE@FY3
#include <ansi.h>
inherit ROOM;
void create()
{
        set("short", "鬼门关");
        set("long", @LONG
猛一惊醒，不觉身在鬼门关，高大的城墙边渭水环绕，阴气森森，几
个面目狰狞的牛头，马面手持武器把守城门，勾死人手持铁链正在拖拽着
几个人影走了进去．．．．．．．，城门楼上高悬一幅牌匾：
 
                        鬼门关
LONG
        );
        set("no_fight",1);
        set("exits", ([
                "south" : __DIR__"naihe",
                "east" : __DIR__"aihe2",
        ]) );
        set("objects", ([
                __DIR__"npc/niutou":1,
                __DIR__"npc/mamian":1,
                __DIR__"npc/panguan" : 1,
        ]) );
        set("no_magic",1);
        set("coor/x",-1020);
        set("coor/y",0);
        set("coor/z",-100);
        setup();
        replace_program(ROOM);
} 
