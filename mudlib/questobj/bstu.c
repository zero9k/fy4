#include <ansi.h>
inherit ITEM;
void create()
{
    set_name( WHT "巴山图" NOR, ({ "bstu" }) );
    set_weight(1);
    if( clonep() )
            set_default_object(__FILE__);
    else {
            set("unit", "张");
            set("material", "paper");
            set("long", "一张详细的巴山地图，左下角写了一行小字：
风云城东十里，左三右四，子午双时．．\n");
        set("no_drop", 1);
        set("no_put", 1);
        set("no_sell", 1);
        set("no_give", 1);
          }
    ::init_item();
}   
void owner_is_killed(object killer)
{
	if(objectp(killer))
        {
        message_vision("有样东西从尸体里跌落$N的怀中！\n\n",killer);
        this_object()->move(killer);}
        else
        {destruct(this_object()); }
}
