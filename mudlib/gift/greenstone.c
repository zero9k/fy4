#include <ansi.h>;
inherit ITEM; 
void create()
{
        set_name(HIG"绿石头"NOR, ({"green stone", "stone"}));
    set_weight(200);
        if( clonep() )
                set_default_object(__FILE__);
        else {
            set("unit", "块");
            set("long", "这是一块罕见的绿色石头。\n");
                set("value", 20000);
                set("inset", 1);
                set("level",1);
        }
        ::init_item();
} 