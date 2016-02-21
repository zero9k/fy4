 inherit F_FOOD;
inherit ITEM;
#include <ansi.h>
void create()
{
    set_name(CYN"无名花"NOR , ({ "flower" }) );
        set_weight(5);
        if( clonep() )
                set_default_object(__FILE__);
        else {
  set("long", 
      CYN"一朵不知名的小花，花呈淡淡的蓝色，清香扑鼻。\n"NOR);
        set("unit", "个");
        set("value", 0);
                set("food_remaining", 1);
                set("food_supply", 0);
                set("material", "food");
        }
        ::init_item();
}
int finish_eat()
{
        object me;
        int max_gin, max_kee, max_sen;
        me = this_player();
        if (!me->query_temp("timer/yihua") && !me->query_temp("buffup/buffed_kee")) {
        max_gin = (int) me->query("max_gin");
    max_kee = (int) me->query("max_kee");
    max_sen = (int) me->query("max_sen");
    message_vision( CYN "$N只觉腹中暖洋洋的十分舒服，七孔之间散发出一股悠扬的香气。\n"NOR, me);
    max_gin = max_gin * 11/10;
    max_kee = max_kee * 11/10;
    max_sen = max_sen * 11/10;
        me->set("max_gin", max_gin);
        me->set("max_kee", max_kee);
        me->set("max_sen", max_sen);
        me->set_temp("timer/yihua",1);
        destruct(this_object());
        return 1;
        } else 
        message_vision( CYN "$N仍然觉得腹中暖洋洋的十分舒服，但什么也没发生。\n"NOR, me);
        destruct(this_object());
        return 1;
}    
