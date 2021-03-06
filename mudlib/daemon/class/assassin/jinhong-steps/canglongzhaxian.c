 // silencer@fengyun 苍龙乍现 命中时，NPC, players 不能 pfm,
#include <ansi.h>
#include <combat.h>
inherit SSERVER; 
int perform(object me, object target)
{
        string msg;
        int extra, my_exp,your_exp, lvl, duration;
        if (me->query("class")!="assassin")
                return notify_fail ("［苍龙乍现］只有金钱帮弟子能使用。\n");
        lvl= me->query_skill("jinhong-steps",1);
        if (lvl<80)
                return notify_fail("你的金虹步法还不够熟练\n");         
        
        if( !target ) target = offensive_target(me);
        if( !target
        ||      !target->is_character()
        ||      !me->is_fighting(target) )
                return notify_fail("［苍龙乍现］只能对战斗中的对手使用。\n");
        
        extra = me->query_skill("jinhong-steps",1);
        me->add_temp("apply/attack", extra);    
        msg = HIR  "$N"+HIR"脚下一转，突然身形飞起，双脚如矫龙般腾空一卷，猛地向$n"+HIR"踢出！" NOR;
        COMBAT_D->do_attack(me,target, TYPE_PERFORM,msg,"瘀伤");
        me->add_temp("apply/attack", -extra);
        
        if (me->query_busy()<2) 
                me->start_busy(2);
        if (me->query_skill("jinhong-steps",1)>164 && random(201)>190
                &&!target->query("big_boss") && !target->query("boss") ) {
                target->set("kee",target->query("kee")/2);
                message_vision(RED"$n"+RED"一声惨叫，被$N"+RED"踢得狂喷鲜血。\n\n"NOR,me,target);
        }               
        
        my_exp=me->query("combat_exp");
        your_exp=target->query("combat_exp");
        
        if (your_exp>5000000) your_exp = your_exp*3/2;
                
        // lvl = 160/30 = 5+1 = random(6)
   lvl=lvl/30;
        if (lvl<1) lvl=1;
                        
        if ((lvl+1)*random(my_exp)>your_exp) {  
                if (!target->query_temp("till_death/lockup")) {
                        message_vision(HIW"$N"+HIW"凌厉的腿风扫过，$n"+HIW"只觉胸闷气滞，一口真气竟提不上来。\n"NOR,me,target);
                        target->set_temp("till_death/lockup",1);
                        duration = 10+ random(lvl*2);
                        if (your_exp>=5000000)  duration = 6+random(lvl);
                        if (target->query("big_boss") || target->query("boss")) duration = random(4);
                        target->start_call_out( (: call_other, __FILE__, "remove_effect",target:),duration );           
                }
                if (me->query_skill("jinhong-steps",1)>149 && !target->is_busy()) {
                                        target->start_busy(2);
                                        message_vision(HIY"$N"+HIY"脚步踉跄，双手捂着前胸,似站立不稳。\n"NOR,target);
                } else if (me->query_skill("jinhong-steps",1)>99 && !target->is_busy()) {
                                                target->start_busy(1);
                        message_vision(HIY"$N"+HIY"脚步踉跄，双手捂着前胸,似站立不稳。\n"NOR,target);   
                }
        }
        
        return 1;
}  
void remove_effect(object target)
{
        target->delete_temp("till_death/lockup");
        tell_object(target,HIG"你深吸一口气，真气流转如常。\n"NOR);
}     
