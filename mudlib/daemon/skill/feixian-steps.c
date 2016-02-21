 // feixian-steps.c
#include <ansi.h>
inherit SKILL;
void setup() {
        set("name", "飞仙步法");
        set("usage/dodge", 1);
        set("usage/move", 1);   
        set("effective_level", 220);
        set("black_white_ness", 10);
        set("skill_class", "baiyun");
        set("dodge_msg", ({
                "$n一招「天玑离枢」轻轻巧巧地避了开去。\n",
                "只见$n身影一晃，一式「天璇乱步」早已避在七尺之外。\n",
                "$n使出「倒转天权」，轻轻松松地闪过。\n",
                "$n左足一点，一招「逐影天枢」腾空而起，避了开去。\n",
                "可是$n使一招「风动玉衡」，身子轻轻飘了开去。\n",
                "$n身影微动，已经藉一招「开阳薄雾」轻轻闪过。\n",
                "但是$n一招「瑶光音迟」使出，早已绕到$N身後！\n"
        }) ); 
} 
int valid_learn(object me)
{
        if( (int)me->query("max_force") < 50 ) {
                return notify_fail("你的内力不够，没有办法练飞仙步法。\n");
        }
        return 1;
} 
int practice_skill(object me)
{ 
        if((int)me->query("force") < 3 ) {
                return notify_fail("你的气或内力不够，不能练倒飞仙步法。\n");
        }
        if(!::practice_skill(me)) {
                return 0;
        }
        me->add("force", -3);
        return 1;
}  
mixed dodge_ob(object victim, object me)
{       int busy_time;
   int skill;
        int my_exp, your_exp;
        
        my_exp=me->query("combat_exp");
        your_exp=victim->query("combat_exp");
        
        skill=me->query_skill("chess",1);
        
        if (random(skill) + skill/3 > 88 && me->is_busy()) {
                message_vision(HIY"$N大局在握，步走斜飞，棋艺的［成算篇］历历在目，身形骤然轻巧起来。\n"NOR, me);       
                me->stop_busy();
        }
        
        return 0;
}        
