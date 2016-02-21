 // tie@fengyun
#include <ansi.h>
#include <combat.h>
inherit SSERVER; 
int perform(object me, object target)
{
    string msg;
    int extra,myexp, hisexp;
    object weapon;
    extra = me->query_skill("fumostaff",1);
    if (me->query_skill("staff") < 150 || extra<100) 
                return notify_fail("你的韦陀伏魔杖法还不够纯熟！\n");
      
    if( !target ) target = offensive_target(me);
    if( !target
        ||!target->is_character()
        ||!me->is_fighting(target) )
        return notify_fail("［何去何从］只能对战斗中的对手使用。\n");
    if(target->is_busy())
                return notify_fail(target->name()+"已经手忙脚乱了！\n"); 
    if (target->query("step_less")==2) 
                return notify_fail(HIW"此人身势灵活，功力深湛，不会被此技能迷惑的。\n"NOR); 
    myexp = (int) me->query("combat_exp");
    hisexp= (int)target->query("combat_exp");
    message_vision(HIW"$N"HIW"展开韦陀伏魔杖法，忽然幻出个＂茫＂字！\n"NOR, me); 
    if (me->query("class")=="shaolin")      myexp=myexp/2+random(myexp)*11/4;
                else myexp=random(myexp)*5/2;
    
    if (extra >149 && me->query_skill("zen",1)>149 && me->query("class")=="shaolin")
			myexp = myexp+random(myexp)*11/4;
    
    if (!userp(me)) myexp=myexp/2+random(myexp)*5/2;
                
    if(hisexp < myexp)
    {
        target->start_busy(3);
        message_vision(YEL"$N"NOR YEL"一时间似乎忘了该何去何从，动作慢了下来！\n"NOR,target);
        if(!me->is_busy()) me->start_busy(1);
    }
    else
    {
        message_vision(HIR"但是$N"HIR"对$n"HIR"的举动若视无睹！\n"NOR,target,me);             
        if(me->query_busy()<2) me->start_busy(2);
    }
    return 1;
} 
