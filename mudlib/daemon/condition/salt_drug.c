 // drunk.c
inherit F_CLEAN_UP;  
inherit __DIR__"generic_condition";
#include <ansi.h>
#include <condition.h>  
int update_condition(object me, int duration)
{
        int limit; 
        limit = (me->query("con") + (int)me->query("max_force") / 50) * 2; 
        if( duration > limit
        &&      living(me) ) {
                me->unconcious();
                return 0;
        } else if( duration > limit/2 ) {
                tell_object(me, "你觉口中又苦又咸，真的受不了了！\n");
                message("vision", me->name() + "嘴唇发白，似乎极度脱水了！\n",
                        environment(me), me);
        } 
        me->apply_condition("salt_drug", duration - 1);
        if( !duration ) return 0;
        return 1;
} 
