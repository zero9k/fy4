inherit ROOM;
#include <ansi.h>
void create()
{
         set("short", HIG"楚儿的小木屋"NOR);
        set("long", @LONG
简单、舒适、纯天然的搭建！集天下名山的千年古木而成，汇神州
灵气于一体！尚有天上诸佛加持无上密语！无物能侵！
LONG
        );
        set("exits", ([ 
         "up" : __DIR__"fotang",
]));
     set("valid_startroom",1);
    set("item_desc" , ([ /* sizeof() == 1 */
        "up": HIW"一朵白云飘了过来，挡住了你的视线！\n"NOR,
]));
        setup();
}
int valid_leave(object me, string dir)
{
        object ob,arr;
        string idname;
       ob = this_player();
        arr = present("arrow", ob);
        idname = ob->query("id");
        if ( dir=="up" &&
             !(idname=="chuer") )
                return notify_fail(HIY"有种神奇的力量让你不能动弹！\n"NOR);
        return ::valid_leave(me, dir);
}
