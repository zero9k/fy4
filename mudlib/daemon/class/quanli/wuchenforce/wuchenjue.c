 // wuchenjue.c
#include <ansi.h> 
#include <combat.h>
inherit F_CLEAN_UP; 
void remove_effect(object me, int amount); 
int exert(object me, object target, int amount)
{
    int skill;
    skill = me->query_skill("wuchenforce",1);

    if(skill < 60) {
         return notify_fail("你的无尘心法太差了！\n");
    }

	if ( me->query_skill_mapped("dodge") != "wuchen-steps" )
			return notify_fail("『无尘决』必须配合无尘步法使用！\n"); 
    if( target != me )
        return notify_fail("你只能用无尘决提升自己的防御力。\n");
    if( (int)me->query("force") < 80 )
        return notify_fail("你的内力不够。\n");
    if( (int)me->query_temp("stepup") )
        return notify_fail("你已经在运功中了。\n"); 
	skill = skill / 2;
    me->add("force", -80); 
    message_vision(HIY"$N默念『无尘决』，整个身体变得轻盈起来……\n" NOR, me); 
    me->add_temp("apply/dodge", skill);
    me->set_temp("stepup", 1); 
    me->start_call_out( (: call_other, __FILE__, "remove_effect", me, 
                         skill :), skill); 
    if( me->is_fighting()) me->start_busy(2); 
    return 1;
} 
void remove_effect(object me, int amount)
{
    me->add_temp("apply/dodge", - amount);
    me->delete_temp("stepup");
    tell_object(me, YEL"你的无尘决运行完毕。\n"NOR);
}
    
