 // silencer
#include <armor.h>
#include <ansi.h> 
inherit HEAD; 
void create()
{
        set_name(HIG"天神羽帽"NOR, ({ "wizard hat","hat"}) );
        set_weight(1);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "顶");
                set("material", "cloth");
                set("armor_prop/armor", 20);
                set("armor_prop/personality", -10);
                set("armor_prop/dodge",100);
                set("armor_prop/spells",100);
                set("wear_msg", "$N轻轻地把$n戴在头上。\n");
                set("unwield_msg", "$N轻轻地把$n从头上除了下来。\n");
                set("no_drop",1);
        }
        ::init_head(20);
}  
int query_autoload() { return 1; }     
