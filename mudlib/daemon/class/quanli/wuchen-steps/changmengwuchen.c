 // tie@fengyun
#include <ansi.h> 
#include <combat.h> 
inherit SSERVER; 
int perform(object me, object target) 
{ 
        string msg; 
        int extra; 
        extra = me->query_skill("wuchen-steps",1); 
        if ( extra < 50) return notify_fail("你的［无尘步法］还不够纯熟！\n"); 
        if( !target ) target = offensive_target(me); 
        if( !target 
        ||      !target->is_character() 
        ||      !me->is_fighting(target) ) 
                return notify_fail("［长梦无尘］只能对战斗中的对手使用。\n"); 
        if(target->is_busy()) 
                return notify_fail(target->name()+"已经忙乱失措！\n"); 
 
        message_vision( HIY "$N"+HIY"脚踏八方，目视四周，如入无人之境！\n" NOR ,me,target); 
 
        if(random((int)target->query("combat_exp")) < (int)me->query("combat_exp")/5) 
 
        { 
        message_vision( HIY "结果$N"+HIY"被迷得不知方向！\n" NOR,target); 
        target->start_busy(2); 
        } 
 
        else{ 
        message_vision( HIW "可惜$n"+HIW"看出了$N"+HIW"的无尘步，$N只好中途撤招！\n" NOR,me,target); 
        me->start_busy(1);
        } 
        return 1; 
} 
