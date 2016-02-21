#include <ansi.h>
inherit F_CLEAN_UP; 
int exert(object me,object target,int amount)
{
        object *ob;
        int i, extra; 
        if(me->query("class")!="legend"&& userp(me))
                return notify_fail("只有铁雪山庄的弟子才能够使用聚气或蝶梦。\n"); 
        if(me->query_temp("qidaoforce_juqi"))
                return notify_fail("你已经在施展类似的武功了。\n");
        
        if( (int)me->query("force") < 600 )
                return notify_fail("你的内力不够。\n");
        extra = me->query_skill("force");
      
        me->add("force", -600);
        
        
        if(me->query("family/master_id")=="master xuerui") {
                message_vision(HIG"$N双臂轻舒，如蝶翼般轻轻展开，晶莹的玉色光芒从身侧缓缓扩散而出。。。\n"NOR,me);
                me->add_temp("qidaoforce_diemeng",extra/10+random(extra/5));
        } else 
                message_vision(HIW"$N运劲将内力凝聚，全身上下升起了一团若有若无的白气。。。\n"NOR,me);
        
        extra= extra+random(extra);
//      320+ random(320);
        me->add_temp("qidaoforce_juqi",extra);
        call_out("remove_effect",extra/5,me,extra);
        return 1;
} 
int remove_effect(object me,int extra)
{
        if(!me) return 0;
        me->delete_temp("qidaoforce_juqi");
        me->delete_temp("qidaoforce_diemeng");
        if(me->query("family/master_id")=="master xuerui") 
                tell_object(me,"你"+HIG"蝶梦"NOR+"的效果已经消失了。\n");
                else 
                        tell_object(me,"你"+HIW"聚气"NOR+"的效果已经消失了。\n");
        return 1;
}
