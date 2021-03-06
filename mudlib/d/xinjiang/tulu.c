 /* Copyright (C) 1998 Apstone, Inc. */
inherit ROOM;
#include <ansi.h>

void create()
{
        set("short", "土路");
        set("long", @LONG
荒原上的一段蜿蜒曲折的土路，伴随一条默默的溪流（ＲＩＶＥＲ），
清澈的溪水，使人感到一股清新气息。周围群山起伏，碧水蜿蜒，风光秀丽。
LONG
        );
        set("exits", ([ 
  "northup" : __DIR__"hongshan",
  "south" : __DIR__"beimen",
]));
        set("objects", ([
        //__DIR__"npc/baiyi" : 1,
        "/d/zangbei/npc/xuedahan" : 1,
                        ]) );
        set("item_desc", ([
                "river": "水流湍急，但是不深，你可以试着涉过去(wade)。\n",
                "溪流": "水流湍急，但是不深，你可以试着涉过去(wade)。\n" 
        ]) );
        //set("no_pk",1);
        
        
        set("outdoors", "xinjiang");
        set("resource/water",1);
        set("liquid/name","清澈的溪水");
        set("liquid/container", "溪流");
        set("coor/x",-1120);
        set("coor/y",2120);
        set("coor/z",0);
        setup();
} 

void init() {
        add_action("do_wade","wade");
}  
int do_wade(string arg) {
        
        object me;
        
        me=this_player();

        if (!arg || arg == "小河" || arg== "river") {
                if (me->query_temp("zangbei/wade_1"))
                   return notify_fail("你已经在河水中央了。\n");
                message_vision("$N脱下靴子走入河水中，艰难地向对岸涉去。\n\n",me);
                call_out("pass_river",6,me);
                me->start_busy(3);
                me->set_temp("zangbei/wade_1",1);
                return 1;
        }
        tell_object(me,"你要做什么？\n");
        return 1;
}  
int pass_river(object me) {
        object room;
        if (!objectp(me) || me->is_ghost()) return 0;
        room=find_object("/d/zangbei/bank");
        if (!objectp(room)) room=load_object("/d/zangbei/bank");
        tell_object(me,HIG"你终于走到了赤土河的对岸。\n"NOR);
        message("vision",HIG""+me->name()+"水淋淋地从河里走了上来。\n"NOR,room);
        me->move(room);
        me->delete_temp("zangbei/wade_1");
        return 1;
}      

