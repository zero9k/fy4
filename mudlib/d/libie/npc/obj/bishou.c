 // sword.c : an example weapon
#include <weapon.h>
#include <ansi.h>
inherit DAGGER; 
void create()
{
        set_name(YEL"穷图匕"NOR, ({ "over dagger" }) );
        set_weight(7000);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "把");
                set("long", "刺客最多用的武器。\n");
                set("value", 400);
                set("material", "steel");
                set("wield_msg", "$N摸出一把$n握在手中。\n");
                set("unwield_msg", "$N将手中的$n藏回怀内。\n");
        }
        ::init_dagger(91);
}   
