 // tie@fengyun
#include <ansi.h>
#include <combat.h>
inherit SSERVER;
int perform(object me, object target)
{
        string msg;
        int extra, level, dam, n, t;
        object weapon;

        if (me->query("class")!="lama") return notify_fail("［佛法至尊］只能由大昭寺的高僧发动。\n");
        if( !target ) target = offensive_target(me);
        if( !target
        ||      !target->is_character()
        ||      !me->is_fighting(target) )
                return notify_fail("［佛法至尊］只能对战斗中的对手使用。\n");
        weapon = me->query_temp("weapon");
        
        extra = (int)me->query_skill("lamaism",1);
        level = (int)me->query_skill("lamastaff",1);
		dam = extra/2 + level/2;
		n = 1;
		t = 2;
		if( level < 50 ) return notify_fail("你的密宗杖法不够高深！\n");
        if( extra > 140 ) n = 2;
                        
        msg = HIR"$N紧闭双眼，默念佛法。。。\n$N突然睁开双眼，大喝道：以杀止杀，佛法至尊！\n"NOR;
        message_vision(msg, me, target);
		if(random((int)target->query("combat_exp")) < (int)me->query("combat_exp")*2/3) {
                message_vision(HIB"$N心头一震，不觉心惊肉跳！\n",target);
				target->receive_damage("sen", extra, me);
				if (!target->is_busy()) 
                            target->start_busy(n);
		}
		else{
				message_vision(CYN"但是$N并不为所动！\n"NOR,target);
		}

        me->add_temp("apply/attack", level/2);
        me->add_temp("apply/damage", dam/2);
        msg = HIR  "$N将手中"+ weapon->name() +HIR"抛向天空，双掌相合，口中念念有词。。。\n"+HIB"$N的"+ weapon->name() +HIB"狠狠砸向$n！"NOR;
                COMBAT_D->do_attack(me,target, TYPE_PERFORM,msg);
        me->add_temp("apply/attack", -level/2);
        me->add_temp("apply/damage", -dam/2);

        if ((int)me->query_skill("lamastaff",1) > 80) {       
				me->add_temp("apply/attack", level/2);
				me->add_temp("apply/damage", dam);
				msg = HIB  "$N的"+ weapon->name() +HIB"盘旋了一圈，横扫$n！"NOR;
                COMBAT_D->do_attack(me,target, TYPE_PERFORM,msg);
				me->add_temp("apply/attack", -level/2);
				me->add_temp("apply/damage", -dam);
		}

				
		if ((int)me->query_skill("lamastaff",1) > 140) {       
				me->add_temp("apply/attack", level);
				me->add_temp("apply/damage", dam);
				msg = HIB "$N的"+ weapon->name() +HIB"盘旋了一圈，反戳$n！"NOR;
                COMBAT_D->do_attack(me,target, TYPE_PERFORM,msg);
				me->add_temp("apply/attack", -level);
				me->add_temp("apply/damage", -dam);
				t = 3;
		}

		if ((int)me->query_skill("lamastaff",1) > 180) {       
				me->add_temp("apply/attack", level);
				me->add_temp("apply/damage", dam*2);
				msg = HIB "$N的"+ weapon->name() +HIB"飞速旋转，旋风般飞向$n！"NOR;
                COMBAT_D->do_attack(me,target, TYPE_PERFORM,msg);
				me->add_temp("apply/attack", -level);
				me->add_temp("apply/damage", -dam*2);
				t = 3;
		}
		if (me->query_busy()< t) 
				me->start_busy(t);
		return 1;
}     

