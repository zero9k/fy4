 inherit F_FOOD;
inherit ITEM;
#include <ansi.h>
void create()
{
    set_name(HIR"情花"NOR , ({ "flower" }) );
        set_weight(5);
        if( clonep() )
                set_default_object(__FILE__);
        else {
  set("long", 
      HIR"一朵鲜红欲滴的花朵。\n"NOR);
        set("unit", "个");
        set("value", 0);
                set("food_remaining", 1);
                set("food_supply", 0);
                set("material", "food");
        }
        ::init_item();
}
/*int finish_eat()
{
        object me;
        int max_gin, max_kee, max_sen;
        me = this_player();
        max_gin = (int) me->query("max_gin");
    max_kee = (int) me->query("max_kee");
    max_sen = (int) me->query("max_sen");
    message_vision( HIY "$N只觉腹中暖洋洋的十分舒服，全身隐隐散发出一股清雅的香气。\n"NOR, me);
    max_gin = max_gin * 11/10;
    max_kee = max_kee * 11/10;
    max_sen = max_sen * 11/10;
        me->set("max_gin", max_gin);
        me->set("max_kee", max_kee);
        me->set("max_sen", max_sen);
        destruct(this_object());
        return 1;
}
*/ 
