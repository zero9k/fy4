 // -neon
#include <ansi.h>
#include <armor.h>
inherit CLOTH;
void create()
{
    set_name(HIY"金色盔甲"NOR, ({ "kui jia", "cloth" }) );
    set_weight(10000);
    if( clonep() )
        set_default_object(__FILE__);
    else {
        set("unit", "件");
        set("long", "一件金色的盔甲。\n");
        set("material", "cloth");
        set("armor_prop/armor", 27);
        set("male_only", 1);
        set("value",4000);
    }
    ::init_cloth();
}       
