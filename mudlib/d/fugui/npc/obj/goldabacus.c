#include <ansi.h>
#include <weapon.h>
inherit HAMMER;
#include <command.h> 
void create()
{
        set_name(HIY"金算盘"NOR, ({ "abacus","gold abacus" }) );
        set_weight(90000);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "把");
                set("long",
                      
"一块金灿灿的算盘，掂在手里沉甸甸的，肯定值不少银子。\n"
);
                set("value", 120000);
                set("lore",1);
                set("material", "steel");
                set("wield_msg", "$N「啪」地一声拿出一把$n握在手中。\n");
                set("unequip_msg", "$N将手中的$n拨弄了几下，挂回腰后。\n");
        }
        ::init_hammer(50); 
} 
mixed hit_ob(object me, object victim, int damage_bonus)
{
        int dam;
        dam = (int) me->query("force_factor")/10;
        victim->receive_damage("gin",dam);
//      GO_CMD->do_flee(victim);
    return HIR"金算盘哗哗作响，$n心烦意乱，无心恋战。\n"NOR;
}     
