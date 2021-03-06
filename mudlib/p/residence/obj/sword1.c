// sword.c
#include <weapon.h> 
#include <ansi.h>
inherit SWORD; 
void create()
{
        set_name(RED"红缨剑"NOR, ({ "sword" }) );
        set_weight(4000);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "把");
                set("long", "这柄剑完全是遵照干将莫邪和徐夫人遗留下来的标准规格铸造的。\n尺寸的长短、剑柄的宽度、剑锷的形式，甚至连剑鞘所用的皮革和铜饰，都带着浓厚的古风，沉稳朴实、深藏不露，就像它的主人一样。\n");
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
        dam = (int) me->query("max_sen");
        victim->receive_damage("sen",dam/10,me);
        return RED"红缨剑轻灵缠绕，剑上红缨飞舞出慑人的杀气！\n" NOR;
}   