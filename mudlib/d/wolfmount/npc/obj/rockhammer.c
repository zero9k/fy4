 // hammer.c
#include <weapon.h> 
inherit HAMMER; 
void create()
{
    set_name("搏浪锤", ({ "war hammer","hammer" }) );
    set_weight(150000);
    if( clonep() )
        set_default_object(__FILE__);
    else {
        set("unit", "把");
        set("long", "这是一柄重约一百八十斤的巨锤。\n");
        set("value", 10000);
        set("material", "iron");
        set("wield_msg", "$N舌绽惊雷，怒喝中霍然拎出一把$n，掂了掂份量，握在手中。\n");
        set("unwield_msg", "$N放下手中的$n。\n");
    }
    
    ::init_hammer(160);
}  
