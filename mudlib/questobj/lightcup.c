 // Copyright (C) 1995, by Tie Yu and Daniel Yu. All rights reserved.
// This software can not be used, copied, or modified in any form without
// the written permission from authors.
inherit ITEM;
#include <ansi.h>
inherit F_LIQUID;
void create()
{
    set_name(HIB "夜光杯" NOR,({"yeguangbei"}));
    set_weight(300);
        if( clonep() )
                set_default_object(__FILE__);
        else {
        set("long", "一个盛满了鲜红如血的葡萄美酒的夜光杯。\n");
                set("unit", "个");
        set("no_drop", 1);
        set("no_sell", 1);
        set("no_give", 1);
        set("no_put", 1);
        set("value", 0);
        set("max_liquid", 10);
        } 
        // The liquid contained in the container is independent, we set a copy
        // in each cloned copy.
        set("liquid", ([
        "type": "alcohol",
        "name": "葡萄美酒",
                "remaining": 5,
        "drunk_apply": 20,
        ]) );
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
