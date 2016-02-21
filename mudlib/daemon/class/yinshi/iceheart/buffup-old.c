 // silencer@fy
inherit SSERVER;
#include <ansi.h> 
int exert(object me, object target, int amount)
{
        int force, lvl, duration;
        int my_exp,your_exp;
        object obj;
        int kee_record; 
//      if(me->query("class")!="yinshi")
//              return notify_fail("只有帝王谷的弟子才能施寒心诀！\n");
        lvl = me->query_skill("iceheart",1);
        if( lvl < 50) 
                return notify_fail("你的冰心诀不够娴熟。\n");
        
        duration = 2+(lvl-50)/10;
        if(me->query("class")!="yinshi")
                duration= duration / 2; 
        force =(int) me->query("force") - (int) me->query("max_force");
        if( force <=lvl*3) return notify_fail("你的真气不足。\n");
        
        if (target == me)
        {       
        if   (me->query_temp("till_death/buffed_kee")==1)
                        return notify_fail("你已经在运功中了。\n");
        
        kee_record=me->query("max_kee");
        me->set_temp("buffed_kee_record",kee_record);   
        message_vision(HIW"$N深深吸了口气，运起冰心诀中至高的“寒心诀“。\n"NOR, me);   
        me->add("force", -lvl*2 );
        me->apply_condition("buffed",duration);
        }       
        else
        {
                if(!objectp(obj = present(target, environment(me))))
                        return notify_fail("这里没有这个人。\n");
                if( !obj->is_character() || obj->is_corpse() )
                        return notify_fail("看清楚一点，那并不是活物。\n");
                if   (target->query_temp("till_death/buffed_kee")==1)
                        return notify_fail("对方已经在运功中了。\n");   
           my_exp=me->query("combat_exp");
                your_exp=target->query("combat_exp");
                if (my_exp>your_exp*3 || my_exp<your_exp/3)
                        return notify_fail("你们之间功力相差太远了,内力无法传递.\n");
                message_vision(HIW"$N两掌抵在$n背心，内力源源不绝地从掌心传了过去．．．\n"NOR, me,target);
                me->add("force", -lvl*3  );
                target->apply_condition("buffed",duration);
                }
        me->start_busy(3);
        return 1;
}
       
