 // TIE@FY3
#include <ansi.h>
inherit SSERVER;
int cast(object me, object target)
{
        string msg;
        int lvl, ap, dp; 
        if((int)me->query_skill("spells") < 80 )
             return notify_fail("你的法术不够高！\n");
  
//   if(!me->is_fighting())
//              return notify_fail("七星法中的［捍星诀］只可以在战斗中施展！\n"); 
        
        if( !target ) target = me;
                else if(me!=target)
                        return notify_fail("七星法中的［捍星诀］只可以用在自己的身上。\n");
    
        if(target->query_temp("timer/flex"))
                return notify_fail("你的韧性已经得到提升了。\n"); 
        if((int)me->query("mana") < 150 )
                return notify_fail("你的法力不够！\n"); 
        me->add("mana", -150);
    
        msg = HIC "$N口中念念有词，一道光芒从$N头顶射出，缭绕在$N周围！\n\n" ; 
        msg +="光芒化成一身软甲，保护住$N的全身！\n";
        lvl = (int)me->query_skill("spells") * 2;
        target->set_temp("timer/flex",1);
        target->add_temp("apply/flexibility",lvl/6);
        seteuid(ROOT_UID);
        target->start_call_out( (: call_other, __FILE__, "remove_hanxing",target, lvl :),random(lvl/3)+lvl/3);
        message_vision(msg+NOR,me);
        me->start_busy(1);
        return 1;
} 
void remove_hanxing(object me, int lvl)
{
    me->delete_temp("timer/flex");
    me->add_temp("apply/flexibility",-lvl/6);
    message_vision(HIY "\n\n$N周身的光甲发出耀眼的一闪就消失了。\n\n" NOR, me);
}  
