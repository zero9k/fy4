#include <ansi.h>
#include <combat.h>
inherit SSERVER;
int perform(object me, object target)
{
        string msg;
        int extra;
        object weapon;
        extra = me->query_skill("xuanyuan-axe",1);
        if(me->query("class")!="knight")
                return notify_fail("只有快活林弟子才能使出「九气破霄」的绝技。\n");
        if ( extra < 160) return notify_fail("你的轩辕斧法还不够纯熟！\n");
        
        
        if (userp(me) && me->query_skill_mapped("force") != "longlife-force")
                return notify_fail("轩辕斧法需要苍生诀的配和！\n");
        
        if( !target ) target = offensive_target(me);
        if( !target
        ||      !target->is_character()
        ||      !me->is_fighting(target) )
                return notify_fail("［九气破霄］只能对战斗中的对手使用。\n");
        if (me->query_temp("timer/jiuqipoxiao")+30>time())
                return notify_fail("［九气破霄］不能连续使用。\n");     
                
                
        weapon = me->query_temp("weapon");
        me->add_temp("apply/attack",extra);
		me->add_temp("apply/damage",extra);
        msg = HIY  "$N手中的"+ weapon->name()+HIY"舞动的速度愈来愈快，吼声愈来愈大\n吼声中"+weapon->name()+HIY"突然雷霆霹雳般向$n"NOR+HIY"劈出一式『九气破霄』！！！\n" NOR;
        message_vision(msg,me,target);
        msg = HIW  "电光！" NOR;
        COMBAT_D->do_attack(me,target, TYPE_PERFORM,msg);
        msg = HIW  "火石！" NOR;
        COMBAT_D->do_attack(me,target, TYPE_PERFORM,msg);
        msg = HIB  "撼三山！" NOR;
        COMBAT_D->do_attack(me,target, TYPE_PERFORM,msg);
		msg = HIB  "震五岳！" NOR;
        COMBAT_D->do_attack(me,target, TYPE_PERFORM,msg);
		msg = HIC  "破九霄！" NOR;
        COMBAT_D->do_attack(me,target, TYPE_PERFORM,msg);
        me->add_temp("apply/attack",-extra);
		me->add_temp("apply/damage",-extra);
        if (me->query_busy()<3) 
                me->start_busy(3);
        me->set_temp("timer/jiuqipoxiao",time());
        return 1;
}     
