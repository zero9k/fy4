// sword.c
#include <weapon.h> 
#include <ansi.h>
inherit SWORD; 
void create()
{
        set_name(HIY"轻侯剑"NOR, ({ "sword" }) );
        set_weight(4000);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "把");
                set("long", "四尺九寸七分长的剑，重叁十叁斤叁两叁钱，以白金?剑锷，黄金?剑匣。\n上面所镶的珠玉，价值在十五万两以上，华丽辉煌，无与伦比，剑未出匣，就已经足够摄人心魄。\n");
                set("value", 400000);
                set("material", "steel");
                set("rigidity", 80);
                set("wield_msg", "$N从腰中抽出一把$n握在手中。\n");
                set("unwield_msg", "$N将手中的$n插入腰间。\n");
        }
        ::init_sword(100);
}

mixed hit_ob(object me, object victim, int damage_bonus)
{
        int dam;
        dam = (int) me->query("max_gin");
        victim->receive_damage("sen",dam/10,me);
        return HIY"轻侯剑上忽然金光激射，犹如神龙破空，刺得$n睁不开眼！\n" NOR;
}   