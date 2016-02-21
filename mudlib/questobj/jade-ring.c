#include <armor.h>
#include <ansi.h>
inherit FINGER; 
void create()
{
        set_name(HIC "觇玉戒指" NOR, ({ "jade-ring"}) );
        set_weight(1);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("long", "一个翠绿欲滴的玉戒指。\n");
                set("unit", "个");
                set("value", 100000);
        set("no_drop", 1);
        set("no_sell", 1);
        set("no_give", 1);
        set("no_put", 1);
                set("armor_prop/armor", 0);
                set("armor_prop/personality", 3);
                set("wear_msg", "$N轻轻地把一个$n戴在手指上。\n");
                set("unwield_msg", "$N轻轻地把$n从手指上除了下来。\n");  
        }
        ::init_finger();
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
