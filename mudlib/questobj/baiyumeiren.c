#include <ansi.h>
inherit ITEM;
void create()
{
    set_name(WHT"白玉美人"NOR, ({ "yumeiren" }) );
    set_weight(50);
    if( clonep() )
            set_default_object(__FILE__);
    else {
            set("unit", "尊");
            set("material", "stone");
            set("long", WHT"一个妙手雕成，晶莹而滑润的白玉美人，看来仿佛九天仙子，不食\n人间烟火，盗帅楚留香因为觉得象极了苏蓉蓉，尤其是那同样温婉\n清澈的一泓秋水，踏月京城，盗得送与了蓉儿．\n"NOR);
        set("no_drop", 1);
        set("no_sell", 1);
        set("no_give", 1);
        set("no_put", 1);

                set("skill", ([
                        "name":         "charm",
                        "exp_required": 100000,
                        "sen_cost":     100,
                        "difficulty":   100,
                        "max_skill":    50
                        ]) );
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
