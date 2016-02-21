#include <ansi.h>
#include <combat.h>
inherit SSERVER;
int perform(object me, object target)
{

 string msg,sk;
 object weapon; 
 int skill,ap,dp,tf,kee; 
 if (me->query("class")!="huashan")
                return notify_fail ("［破残式］只有华山弟子能使用。\n");
 if( !target ) target = offensive_target(me);
        if( !target
        ||      !target->is_character()
        ||      !me->is_fighting(target) )
                return notify_fail("［破残式］只能对战斗中的对手使用。\n");
 skill = (int)me->query_skill("dugu-sword",1);
 // no pocan in fy4 -neon
 if( skill < 180 && userp(me))
  return notify_fail("你的独孤九剑等级不够, 不能使用「破残式」！\n");
  if( me->query("force") < 500 )
  return notify_fail("你的内力不够，无法运用「破残式」！\n");
 msg = HIW "$N神功妙悟，独孤九剑「破残式」以惊天之势向$n攻出。 \n";
//  if(userp(me)) me->delete("force");
 ap =  (int) me->query("combat_exp")* skill/10;
 dp = (int) target->query("combat_exp");
 if(random(ap+dp) > dp) {
  if(userp(target)){
  	weapon = target->query_temp("weapon");
   	if(!weapon) sk= "unarmed";
   	else sk= weapon->query("skill_type");
   	tf = target->query_skill(sk,1);
   	
   	if(tf>=3) target->set_skill(sk,tf-2);   
   //如果玩家没有学任何skills,那么就会晕倒   add by xiaolang 
   	else {
   		message_vision(WHT"$N禁不起如此狂风暴雨般的攻击，竟然心力俱碎，晕了过去......\n"NOR,target);
   		target->unconcious();
   	} 
   	if(userp(me)) me->delete("force");    //成功才delete force
  }
 msg += "$n大惊失色，心惊胆寒，但已经太迟了！\n" NOR;
 target->start_busy(2);
 } else {
 msg += "可是$n看破了$N的剑路，就地一滚，十分狼狈的躲过这一招。\n"NOR;
 me->start_busy(2);
 me->add("force",-100);
 }
 message_vision(msg, me, target);
 return 1;
}       
