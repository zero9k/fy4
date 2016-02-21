 // void_sense.c
#include <ansi.h> 
inherit SSERVER; 
int conjure(object me, object target)
{
        int skill;
        int my_exp,his_exp;
        if(me->query("class")!="bonze")
                return notify_fail("只有兴国禅寺的弟子才可以使用空识神通！\n");
        if( !target ) target = offensive_target(me);
        if( !target
        ||      !target->is_character()
        ||      !me->is_fighting(target) )
                return notify_fail("［空识神通］只能对战斗中的对手使用。\n");
        if( (int)target->query_temp("voidsense") ) 
                return notify_fail("敌人已经中招了，还不抓紧时机攻击？\n");
        if( me->query("atman") < 150 )
                return notify_fail("你的灵力不够！\n");
        if( me->query("gin") <= 150 )
                return notify_fail("你的精不够！\n");
        if((int) me->query_skill("essencemagic",1) < 60)
                return notify_fail("你的八识神通不够高深！");
        me->add("atman", -100);
        me->receive_damage("gin", 100);
        message_vision(HIY "$N双手合十，垂眉俯首，低声吟诵 ...\n" NOR, me);
        
        skill= (int) me->query_skill("essencemagic",1);
        my_exp=(int)me->query("combat_exp");
        his_exp=(int)target->query("combat_exp");
        
        
        if (target->query("dungeon_npc") || target->query("quality")) his_exp = his_exp*2;
                else if (his_exp>5000000 || userp(target)) his_exp=his_exp*2;
        
        if(his_exp < my_exp*3/4+random(my_exp/20*skill))        
        {
                message_vision(HIW"$N心头一颤，只觉繁华世事皆为过眼烟云，身形不由凝滞下来。\n"NOR, target);
                target->add_temp("apply/dodge", -skill);
                if (userp(target)) target->add_temp("apply/parry", -skill);
                target->add_temp("apply/attack",-skill);
				target->set_temp("voidsense", 1);
                target->start_call_out( (: call_other, __FILE__, "remove_effect", target, skill :), skill/4);
                return 1;
        }
        message_vision(HIR"$N大喝一声：“米粒之珠，也放光华？“\n"NOR, target);
        message_vision(YEL"$N面如土色，不自觉地微微颤动。\n"NOR,me);
        me->start_busy(1);
        return 1;
} 
void remove_effect(object target, int amount)
{
        target->add_temp("apply/dodge", amount);
        if (userp(target)) target->add_temp("apply/parry", amount);
        target->add_temp("apply/attack", amount);
        target->delete_temp("voidsense");
         message_vision( HIR"$N浑身一凛，恍若大梦初醒。\n" NOR, target);
}
 
    
    
       
