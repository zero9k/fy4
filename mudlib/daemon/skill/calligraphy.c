 // Copyright (C) 2002, by Sinny Shi. All rights reserved.
// - revised by neon
// - This skill is a skill to enable all kinds of "pen-like" weapons - neon 
// This software can not be used, copied, or modified in any form without
// the written permission from authors.
inherit SKILL;
#include <ansi.h>
void setup(){
        set("name", "书法");
        
        set("usage/unarmed", 1);
        set("usage/parry", 1);
        //set("usage/sword", 1);
        set("effective_level", 220);
        set("practice_bonus", -10);
        set("black_white_ness", 10);
        set("skill_class", "baiyun");
        set("unarmed_parry_msg", (
        
         { "$n笔势如飞，瞬息之间「哀毒蓋深, 奈何奈何」八字令$N不知所措。 \n",
          "$n回腕轻灵，笔意圈转翔动，落落乎犹众星之列河汉，令$N眼花缭乱。 \n",
         }
        ) ); 
        action = ({
        ([      "action":               
"$N清啸一声，身形飘逸，笔势如刀割向$n，纵横之间「羲之顿首」四字写的清刚峭拔，卓尔不群。",
                "dodge":                -10,
                "parry":                10,
                "damage":               110,
                "damage_type":  "割伤"
        ]),
        ([      "action":               
"$N身形大开大阖，「先墓再罹荼毒」一气呵成，一笔一划尽是悲愤，狂风暴雨般洒向$n。",
                "dodge":                -30,
                "parry":                30,
                "damage":               140,
                "damage_type":  "刺伤"
        ]),
        ([      "action":               
"$N笔意抖变，出手迟缓凝重，似有千钧之力砸向$n的$l，写的正是「追惟酷甚」四字。",
                "dodge":                50,
                "parry":                50,
                "damage":               160,
                "damage_type":  "挫伤"
        ]),
        ([      "action":               
"$N挥洒之间在$n的$l刻下「号慕摧绝，痛贯心肝」八字，其缩也凝重，似尺蠖之屈，其
纵也险劲，如狡兔之脱。 ",
                "dodge":                270,
                "parry":                270,
                "damage":               30,
                "damage_type":  "刺伤"
        ]),
        });
}
int valid_learn(object me)
{
        if(!::valid_learn(me)){
                return 0;
        }
    if((int)me->query_skill("chess", 1) <  (int)me->query_skill("calligraphy",1) ){
        return notify_fail("你的棋艺修为不够，心浮气躁不宜学习书法。\n");
    }
    return 1;
}  
int practice_skill(object me)
{
    if((int)me->query_skill("calligraphy",1) >  100){
        return notify_fail("更深的弈道只能通过学习或研究来领悟了。\n");
    }
        if( (int)me->query("force") < 25 ){
            return notify_fail("你的内力不够了，休息一下再练吧。\n");
        }
        if(!::practice_skill(me)){
                return 0;
        }
        me->add("force", -15);
   return 1;
}  
mixed parry_ob(object victim, object me)
{       int busy_time;
        int skill;
        int my_exp, your_exp;
        
        my_exp=me->query("combat_exp");
        your_exp=victim->query("combat_exp");
        
       //if ( random(my_exp*5) < your_exp ) return 0;
        
        skill=me->query_skill("calligraphy",1);
        
        if (/*random(skill) + skill/2 > 100 && */me->is_busy()) {
                message_vision(HIG"$N提腕回手，进退井然，棋艺的［得算篇］历历在目，身形骤然轻巧起来。\n"NOR, me);       
                me->stop_busy();
        }
        
        return 0;
}         
mapping query_action(object me, object weapon)
{
        int attack_act;
        object *victims,victim;
        attack_act=random(sizeof(action));
        me->set_temp("calli_print",attack_act);
        return action[attack_act];
}  
mixed hit_ob(object me, object victim, int damage_bonus)
{
       
        int action;
        string printtype, prints;
        
        if (! random(3)) return;
                
        action = me->query_temp("calli_print"); 
        
        switch(action) {
                case 0:
                   printtype="「羲之顿首」" ;
                        break;
                case 1:
                        printtype="「先墓再罹荼毒」";
                        break;
                case 2:
                        printtype="「追惟酷甚」";
                        break;
                case 3:
                        printtype="「号慕摧绝，痛贯心肝」";
                        break;
                }
        
        me->delete_temp("calli_print");
        
        if(printtype)
        {
                prints =(string) victim->query_temp("body_print");
                if ( victim->query_temp("cali_print") <3) {
                        if (!prints)
                                prints = gender_pronoun(victim->query("gender")) + "身上不知道被谁刻下："+ printtype+ "几个字。\n";
                        else prints = prints + "横七竖八刻下的还有："+ printtype+ "几个字。\n";
                }
                else prints = gender_pronoun(victim->query("gender")) + "身上被人乱刻乱画得一团糟，勉强可以看出：" + printtype+ "几个字。\n";
                victim->set_temp("body_print", prints);
                victim->add_temp("apply/personality" , -1);
                victim->add_temp("cali_print", 1);
        }
        // -----> can add special effects here
        
        
        // <------------
        switch(random(2)) {
                case 0: return WHT"$N笔意萧然，已在$n的$l写下" + printtype + "几个字！\n"NOR;
                case 1: return WHT"$N笔力刚劲，入木三分，将" + printtype+"几个字刻在$n的$l！\n"NOR ;
        }
        
}       
int learn_skill(object me)
{
       if (me->query("class") != "baiyun") 
                return notify_fail("只有白云城弟子才可以学习书法。\n");
}
