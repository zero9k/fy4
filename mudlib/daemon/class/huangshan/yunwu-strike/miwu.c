 // tie@fengyun
#include <ansi.h>
#include <combat.h>
inherit SSERVER;
int perform(object me, object target)
{
        string msg;
        int myexp,yourexp,lvl,skill;
        if( !target ) target = offensive_target(me);
        if( !target
        ||      !target->is_character()
        ||      !me->is_fighting(target) )
                return notify_fail("［十里迷雾］只能对战斗中的对手使用。\n");
                
         if(target->is_busy())
             return notify_fail(target->name()+"已经手忙脚乱了！\n");
                
                skill=(int) me->query_skill("yunwu-strike",1);
                lvl = (int) me->query_skill("unarmed",1)  ;
               myexp = (int) me->query("combat_exp");
        yourexp = (int) target->query("combat_exp") ;
           if (me->query("class")!="huangshan") skill /= 48;
        if (yourexp > 20000000 ) yourexp= yourexp * (lvl/skill);
        if (me->query("class")!="huangshan") lvl = lvl * 5;

        msg = HIY "$N使出云雾掌法中的［十里迷雾］，双掌挥舞，掌影密布，层层击向$n！" NOR;
        if( (random(skill)*3+skill/2+skill) * myexp > (random(lvl)+lvl) * yourexp )
        {
                message_vision(msg + "\n", me, target);
                msg = "结果$n被$N攻了个手忙脚乱！\n";
                message_vision(msg, me, target);
                if (me->query("class")!="huangshan")
                {
                    if ( (lvl/30)>=5 ) target->start_busy(5);
                    else target->start_busy(lvl/40);
                 }
                 else {
                    if ( (lvl/50)>=4 ) target->start_busy(7);
                    else target->start_busy(3+lvl/50);
                    }
        }
        else
                        COMBAT_D->do_attack(me,target, TYPE_PERFORM,msg);
                        me->start_busy(2);
        return 1;
}      
