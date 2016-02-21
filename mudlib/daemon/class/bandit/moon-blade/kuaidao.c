 // ice@fy4
#include <ansi.h>
#include <combat.h>
inherit SSERVER;
int perform(object me, object target)
{
        string msg;
        int extra, bonus, i, n, num;
        
        object *enemy;

        /*if ( me->query("class")!= "bandit")
			return notify_fail("只有神教弟子才能领悟魔刀精要。\n");*/
        if((int)me->query_skill("moon-blade",1) < 80)
            return notify_fail("你的圆月魔刀还不够精纯！\n");      

        enemy = me->query_enemy();

        if(!sizeof(enemy))
            return notify_fail("［快刀］只能对战斗中的对手使用。\n");
        if(target)
            return notify_fail("快刀不需要指定使用对象！！\n");
                
        msg = HIR "\n$N"+HIR"将刀横于胸前，左手中指在刀背上一弹，右手借力挥刀。。。\n"NOR;
        message_vision(msg,me);
		num = sizeof(enemy);
		n = num;
		if(n==1) n=2;
		if(n > 5) n = 5;

        extra = me->query_skill("blade") + me->query_skill("move") + n*100;
		bonus = me->query("combat_exp")/1000*extra/8000;
        if((int)me->query_skill("moon-blade",1) > 120) extra = extra + bonus;
        for(i=0;i<num;i++)
        {
			target = enemy[i];
            if(target->query("combat_exp") < random((int)me->query("combat_exp"))*10+(int)me->query("combat_exp")/3) {
                message_vision(HIW"只见一道亮光从$N"+HIW"身前划过！！\n"NOR,target);
                target->receive_wound("kee",random(extra/2)+extra/2);
                target->receive_damage("kee",extra+extra/2);
                target->set_temp("last_damage_from",me);
                COMBAT_D->report_status(target);
				COMBAT_D->win_lose_check(me,target,1);
			}
			else message_vision(HIY"但$n"+HIY"抢上半步，躲过了$N"+HIY"这一刀！\n"NOR,me,target);

		}

        if (me->query_busy()<n) 
                me->start_busy(n);
        return 1;
}  
