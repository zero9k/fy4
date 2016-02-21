 // TIE@FY3 ALL RIGHTS RESERVED
#include <ansi.h>
inherit ROOM;
void create()
{
        set("short", "苦竹溪");
        set("long", @LONG
沿途盛产苦竹，溪水从竹林底穿过，流到这里汇成了一眼小泉，泉水带有淡淡
的苦涩味，但是良药苦口，苦竹更是入药的上品，所以知情人甚爱饮此泉水，泉水
对于解乏提神极有帮助。再往前，一堵峭壁挡住了去路。
LONG
        );
        set("exits", ([ 
  "southup" : __DIR__"zhulin",
]));
        set("objects", ([
                __DIR__"npc/snake" : 2,
       ]) );
        set("item_desc", ([
                "苦竹溪": "你可以试着从溪（ｘｉ）中喝（ｄｒｉｎｋ）一口。\n",
                "kuzhuxi": "你可以试着从溪（ｘｉ）中喝（ｄｒｉｎｋ）一口。\n"
        ]) );
        set("outdoors", "huangshan");
    set("coor/x",-560);
    set("coor/y",-465);
        set("coor/z",10);
        setup();
}
void init(){
        add_action("do_drink","drink");
        add_action("climbing", "climb");
}
int do_drink(string arg)
{
        object me;
        me=this_player();
        if(!arg || arg != "xi") return 0;
        if(me->query("water") >= me->max_water_capacity())
                return notify_fail("你似乎并不渴。\n");
        message_vision("$N弯下腰，在苦竹溪中喝了一大口苦水！\n",me);
   me->add("water",50);
        me->apply_condition("kuzhu",3+random(5));
        return 1;
} 
int climbing(string arg)
{
        object obj, me;
        int i;
        
        me = this_player();
        i = me->query_skill("move");
    if(!arg || arg=="") return notify_fail("你要爬什么？\n");
    if( arg == "valley" || arg == "up" || arg == "峭壁"){
                me->start_busy(2);
                if( i >= 120 )  {  
                message_vision("$N抓着突出的石角，慢慢的顺着峭壁爬了上去。\n", me);
            call_out("fliping",2,me);
                } else { 
                        if( random(10) > 1) {
                                message_vision("$N抓着突出的石角，慢慢的顺着峭壁爬了上去。\n", me);
                                call_out("falling", 2 , me);
                        } else {
                        message_vision("$N抓着突出的石角，慢慢的顺着峭壁爬了上去。\n", me);
                        call_out("fliping",2,me);
                        }
                }       
    } else {
        write("你不可以爬"+arg+"\n");
    }
        return 1;
}
int fliping(object me)
{
        if( !me->is_ghost()) {   
        me->move(__DIR__"huangshan");
        message_vision("$N顺着谷壁爬了上来。\n", me);
        }
        return 1;
} 
void falling(object me) {
   tell_object(me, "突然间你脚下一滑，整个人向下坠去！\n");
        message_vision("伴随着“阿～～～～“的一声，$N重重的从崖上摔了下来。\n", me);
    me->receive_wound("kee", random(50));
    me->receive_wound("gin", random(50));
    me->receive_wound("sen", random(50));
}
              
