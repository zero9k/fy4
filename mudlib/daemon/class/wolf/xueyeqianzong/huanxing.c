 // tie@fengyun
#include <ansi.h>
#include <combat.h>
inherit SSERVER;
int perform(object me, object target)
{
        string msg;
        int extra;
        int ap,dp;
        int base;
        extra = me->query_skill("xueyeqianzong",1);
        if ( extra < 50) return notify_fail("你的［雪野潜踪］还不够纯熟！\n");
        if( !target ) target = offensive_target(me);
        if( !target
        ||      !target->is_character()
        ||      !me->is_fighting(target) )
                return notify_fail("［幻形］只能对战斗中的对手使用。\n"); 
        message_vision(HIB"$N"+HIB"忽然旋身飞转，$n"+HIB"刚一迟疑，$N"+HIB"的身影已经飞快向远方飘去。 \n"NOR,me,target);
        ap=(int)target->query("combat_exp");
        dp=(int)me->query("combat_exp"); 
        if (me->query("class")=="wolfmount") base=random(dp)+ dp*5/6+random(extra/50)*dp;
                else base = random(dp) + dp/2; 
        if(ap < base)
        {
        message_vision(HIG"$N"+HIG"茫然望着$n"+HIG"远去的身影，一时不知道该不该追击。 \n"NOR,target,me);
        me->remove_killer(target);
        target->remove_killer(me);
        me->start_busy(1);
        }
        else{
        me->start_busy(1);
        message_vision(HIR"$N"+HIR"识破了$n"+HIR"的幻形，对准$n"+HIR"发出致命一击！ \n"NOR,target,me);
        COMBAT_D->do_attack(target,me,TYPE_PERFORM,msg);        
        }
        return 1;
}     
