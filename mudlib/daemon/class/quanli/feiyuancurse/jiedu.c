 // recover.c
inherit SSERVER;
#include <ansi.h>
#include <condition.h> 
int perform(object me, object target) 
{ 
        int force, lvl, extra; 
        if( target != me ) return notify_fail("你只能用真气将自己体内毒素逼出。\n"); 
        force =(int) me->query("force"); 
        if( force < 100) return notify_fail("你的真气不足。\n"); 
        lvl = me->query_skill("herb",1); 
		extra = me->query_skill("feiyuancurse",1);
        if( lvl < 50) return notify_fail("你的［药道］不够熟练，还不能为自己解毒！\n"); 
        if( extra < 50) return notify_fail("你的［非冤布毒术］不够熟练，还不能为自己解毒！\n"); 
 
        me->add("force", -100); 
        message_vision(WHT"$N运功抗毒，准备把毒逼出体外．．．\n"NOR, me); 
        me->start_busy(1);
        if (random(lvl) < 20) 
        { 
                return notify_fail(YEL"但是失败了。\n"NOR); 
        } 
        else 
        { 
        me->clear_condition();   
                write(HIG"你成功地逼出体内的巨毒！\n"NOR); 
        return 1; 
        } 
} 
     
