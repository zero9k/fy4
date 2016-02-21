#include <ansi.h>
inherit F_CLEAN_UP;
void remove_effect(object me, int amount); 
int exert(object me, object target, int amount)
{
        int skill;
        skill = me->query_skill("manjianghong",1); 

		if(skill < 50) 
                return notify_fail("你的满江红心法太差了！\n");
        if( target != me ) 
                return notify_fail("你只能提升自己的勇气。\n");
        if( (int)me->query("force") < 200 )   
                return  notify_fail("你的内力不够。\n");
        if( (int)me->query_temp("manjianghong/cor") ) 
                return  notify_fail("你现在慷慨激昂！\n");
        
        me->add("force", -200);
        message_vision(HIR "$N凝视远方，慷慨地吟唱：抬望眼、仰天长啸，壮怀激烈！\n" NOR, me);
        me->add_temp("apply/courage", skill/5);
        me->set_temp("manjianghong/cor", 1);
        me->start_call_out( (: call_other, __FILE__, "remove_effect", me, skill/5 :), skill/2);
        me->start_busy(1);
        return 1;
} 
void remove_effect(object me, int amount)
{
        me->add_temp("apply/courage", - amount);
        me->delete_temp("manjianghong/cor");
        tell_object(me, "你的心情恢复了平静。\n");
}
      
