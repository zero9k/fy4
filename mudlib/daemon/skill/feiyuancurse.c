 //feiyuancurse.c
inherit SKILL; 
void setup() { 
        set("name", "非冤布毒术"); 
        set("usage/herb", 1); 
        set("practice_damage", 40); 
        set("learn_bonus", 0);
        set("practice_bonus", -50); 
        set("skill_class", "quanli"); 
        set("black_white_ness", -50);
  }       
int valid_learn(object me)  
{ 
    if((int)me->query_skill("force", 1) < 100) { 
        return notify_fail("你的内功心法火候不足，无法练非冤布毒术。\n"); 
        } 
        return 1; 
} 
        
int practice_skill(object me)
{
        if (me->query_skill("feiyuancurse",1) > 120)
                return notify_fail("练习已经不能加深你的领悟，只能通过学习来提高了。\n");
        if ((int)me->query("force") < 20) {
                return notify_fail("你的内力不够练非冤布毒术。\n");
        }
        if(!::practice_skill(me)) {
                return 0;
        }
        me->add("force", -15);
        return 1;
}     
