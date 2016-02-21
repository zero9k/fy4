 // tie@fengyun
#include <ansi.h>
#include <combat.h>
inherit SSERVER;
int perform(object me, object target)
{
        string msg;
        int myexp,yourexp,lvl,extra,skill; 
        extra=me->query_skill("dabei-strike",1);
        skill=me->query_skill("dabei-strike",1);
        if(me->query("class")!="bonze"&&me->query("class")!="shaolin")
                skill/=5;
        if(skill<20)
                return notify_fail("你大慈大悲千叶式的修为还不够高。\n"); 
        if( !target ) target = offensive_target(me);
        if( !target
        ||      !target->is_character()
        ||      !me->is_fighting(target) )
                return notify_fail("［千手千变］只能对战斗中的对手使用。\n");
        if(target->is_busy())
                return notify_fail(target->name()+"已经手忙脚乱了！\n");        
        if(me->query("class")!="bonze"&&me->query("class")!="shaolin")
                extra/=5;                
        myexp = (int) me->query("combat_exp");
        yourexp = (int) target->query("combat_exp");
        if (target->query("boss")|| target->query("big_boss")) yourexp=yourexp*8;
//      (200/2+1.2x160) =292/40+1 = 8
        lvl = (int) me->query_skill("unarmed") / 40 + 1;
        if(me->query("class")!="bonze"&& me->query("class")!="shaolin") lvl=lvl/2+1;
        msg = HIR "$N使出大悲千叶掌法中的［千手千变］，幻出无数掌影击向$n！" NOR;
        if( random(myexp * lvl+yourexp)- lvl*lvl < myexp*lvl )
        {
                message_vision(msg + "\n", me, target);
                msg = "结果$n被$N攻了个手忙脚乱！\n";
                message_vision(msg, me, target);
                target->start_busy(2);
                me->start_busy(1);
        }
        else
        {
                me->add_temp("apply/attack",extra/2);
                COMBAT_D->do_attack(me,target, TYPE_PERFORM,msg);
           me->add_temp("apply/attack",-extra/2);
                if (me->query_busy()<2) me->start_busy(2);
        }
        return 1;
}
