 // sfy changed
#include <ansi.h>
#include <combat.h>
inherit SSERVER;
int perform(object me, object target)
{
        string msg;
        int skl_me, skl_you, extra_me, extra_you,i,j, dmg;
        int FLAG=0;
        object you,ob,*obs;
        if( !target ) target = offensive_target(me);
        if( !target
        ||      !target->is_character()
        ||      !me->is_fighting(target) )
                return notify_fail("［一指定乾坤］只能对战斗中的对手使用。\n");
		dmg = me->query_skill("tenderzhi",1) + me->query_skill("xuanxinjue",1);
		if(me->query("kee")<= dmg)
			return notify_fail("你的身体状况太虚弱，不能运气出指。\n");
        if(pointerp(obs=me->query_team()) )
        {
        FLAG=1;
        for(i=0;i<sizeof(obs);i++)
        {
        if(obs[i] == me) continue;
        if(!obs[i]) {FLAG=0;continue;}
        if(environment(obs[i]) != environment(me)) {FLAG=0;continue;}
        if(!obs[i]->query_skill("yiyangzhi")) {FLAG=0;continue;}
        if(objectp(ob=obs[i]->query_temp("weapon"))) {FLAG=0;continue;}
        if(obs[i]->query_skill_mapped("unarmed") != "yiyangzhi") {FLAG=0;continue;}
        }       
        if(sizeof(obs) !=2) FLAG=0;
        }
        skl_me=(int)me->query_skill("unarmed");
        extra_me=(int)me->query_temp("apply/damage")+(int)me->query_str()*(int)me->query_str()/10;
        if(FLAG)
        {
                if(obs[0]==me) you=obs[1]; else you=obs[0];
        skl_you=(int)you->query_skill("unarmed");
        extra_you=(int)you->query_temp("apply/damage")+(int)you->query_str()*(int)you->query_str();
        msg = HIG+"$N施展出阴柔的柔虹指，"+ HIR + you->name()+"施展出刚阳的一阳指，\n"+ HIY +
        "无数指影夹杂着阴冷炽热的指风，点向$n的全身！\n\n" + NOR;
        me->add_temp("apply/attack",(skl_you+skl_me)/5);
        me->add_temp("apply/damage",(extra_you+extra_me * 3));
        COMBAT_D->do_attack(me,target, TYPE_PERFORM,msg);
        me->add_temp("apply/attack",-(skl_you+skl_me)/5);
        me->add_temp("apply/damage",-(extra_you+extra_me * 3));
        you->kill_ob(target);
        }
        else
        {
        msg = HIG"$N"HIG"施展出阴柔的柔虹指，"HIY"无数指影夹杂着阴冷的指风，点向$n"HIY"的全身！\n"NOR;
        me->add_temp("apply/attack",skl_me);
        me->add_temp("apply/damage",extra_me);
        COMBAT_D->do_attack(me,target,TYPE_PERFORM,msg);
        me->add_temp("apply/attack",-skl_me);
        me->add_temp("apply/damage",-extra_me);
        
	if(me->query_temp("xuanxinaomiao"))
 	{
        msg = HIM"$N"HIM"只觉内力大盛，指尖连点，"HIY"无数指影夹杂着漫天的真气，点向$n"HIY"的全身！\n"NOR;
        me->add_temp("apply/attack",skl_me*3);
        me->add_temp("apply/damage",extra_me*2);
        COMBAT_D->do_attack(me,target,TYPE_PERFORM,msg);
        me->add_temp("apply/attack",-skl_me*3);
        me->add_temp("apply/damage",-extra_me*2);
	}
	if(me->query_skill("tenderzhi",1)>150)
		if(me->query_skill("xuanxinjue",1)>150)
					if(me->query_temp("xuanxinaomiao"))
	{
		if(me->query_skill("tenderzhi",1)>200) skl_me= skl_me * 2;
		if(me->query_skill("xuanxinjue",1)>220) extra_me = extra_me*2;
		msg = HIR"$N"HIR"真气澎湃，指尖竟然被逼出一滴鲜血，"HIY"玄心奥妙决的光芒与鲜血混在一起，爆出一团血雾，撒向$n"HIY"的全身！\n"NOR;
        me->add_temp("apply/attack",skl_me*3);
        me->add_temp("apply/damage",extra_me*5);
        COMBAT_D->do_attack(me,target,TYPE_PERFORM,msg);
        me->add_temp("apply/attack",-skl_me*3);
        me->add_temp("apply/damage",-extra_me*5);
		me->receive_damage("kee", dmg);
	} 
}      
        me->start_busy(2);
        return 1;
} 
