#include <weapon.h>
#include <ansi.h>
inherit STAFF; 
void create()
{
        set_name(HBBLU"幡旗"NOR, ({ "fanqi" }) );
        set_weight(7000);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "把");
                set("long", "这是一面招牌，上面写着：有病治病，无病安心。\n");
                set("value", 4000);
                set("material", "steel");
                set("wield_msg", "$N「唰」地一声抽出$n把在手中。\n");
                set("unwield_msg", "$N将手中的$n插在地上。\n");
        }
        ::init_staff(105);
}  
