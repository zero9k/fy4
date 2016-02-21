#include <ansi.h>
inherit SSERVER;
int perform(object me, object target)
{
    string msg;
    int your_exp,n;
    if( !target ) target = offensive_target(me);
    if( !target
        ||!target->is_character()
        ||!me->is_fighting(target) )
        return notify_fail("［粘字诀］只能对战斗中的对手使用。\n"); 
    if( target->is_busy() )
        return notify_fail(target->name() + "目前正自顾不暇，放胆攻击吧！\n");
    
    msg = "$N"+CYN"使出三才剑法中的「粘」字诀，企图减缓"NOR+"$n"+CYN"的攻势，";
    me->start_busy(1);
    
    if (me->query("class")=="wudang" || me->query("combat_exp")<500000) your_exp =  (int)target->query("combat_exp")/3; 
        else  your_exp = (int)target->query("combat_exp")/2; 
    
    if(random(me->query("combat_exp")+me->query("combat_exp")/3) > your_exp)
    {
        msg += "结果$p"+CYN"被$P"+CYN"攻了个措手不及！\n" NOR;
        message_vision(msg, me, target);
        n= random(me->query_skill("three-sword", 1) / 40) + 2;
        if (n>3) n=3;
        if (me->query("class")=="wudang") target->start_busy(n);
                else target->start_busy(2);
    } else {
        msg += "可是$p"+CYN"看破了$P"+CYN"的企图，并没有上当。\n" NOR;
        message_vision(msg, me, target);
    }
    return 1;
}   
