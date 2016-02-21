#include <ansi.h>
#include <weapon.h> 
inherit HAMMER; 
void create()
{
        set_name( HIB"搏浪锤"NOR, ({ "wave-hammer" }) );
        set_weight(200000);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "个");
                set("long","这是一把样式古拙的大铁锤，重约一百八十斤。 \n");
                set("material", "gold");

        set("no_drop", 1);
        set("no_sell", 1);
        set("no_put", 1);
        set("no_give", 1);
                set("rigidity", 200000); 
                set("wield_msg", "$N舌绽惊雷，怒喝中霍然拎出一把$n，掂了掂份量，握在手中。\n");
                set("unwield_msg", "$N缓缓放下手中的$n。\n");
        }
        ::init_hammer(150);
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

mixed hit_ob(object me, object victim, int damage_bonus)
{
        int dam;
        dam = (int) me->query("max_sen");
        victim->receive_damage("sen",dam/10,me);
        return HIB"搏浪锤呼呼破风，犹如海潮咆哮，吓得$n一愣一愣！\n" NOR;
}   