 // Copyright (C) 1995, by Tie Yu and Daniel Yu. All rights reserved.
// This software can not be used, copied, or modified in any form without
// the written permission from authors.
#include <ansi.h>
inherit ITEM; 
void create()
{
    set_name(HIW"玉羊脂精"NOR, ({ "white jade", "jade"}) );
        set_weight(1);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "块");
                set("long", "一块通体纯白的玉石，乃千年所化之玉石精英。\n");
                set("value", 20000);
        }
        ::init_item();
}    
