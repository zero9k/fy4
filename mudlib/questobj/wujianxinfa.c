#include <ansi.h>
inherit ITEM;
void create()
{
    set_name(HIW"无剑心法"NOR, ({ "wujianxinfa" }) );
    set_weight(1);
    if( clonep() )
            set_default_object(__FILE__);
    else {
            set("unit", "个");
            set("material", "stone");
            set("long", "一本破旧，字迹模糊的书。\n");

            set("skill", ([
                        "name":         "doomsword",             
                        "exp_required": 50000,                          
                        "sen_cost":     50,                     
                        "difficulty":   50,                     
                        "max_skill":    50              
                        ]) );
          } 
    ::init_item();
} 
/*void owner_is_killed(object killer)
{
        message_vision("有样东西从尸体里跌落$N的怀中！\n\n",killer);
        this_object()->move(killer);
}*/
