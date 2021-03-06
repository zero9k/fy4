 // cloud-dance.c
inherit SKILL; 
void setup() {
        set("name", "幻风飘云舞");
        set("usage/dodge", 1);
        set("usage/move", 1);
        set("effective_level", 175);
        set("learn_bonus", -500);
        set("practice_bonus", -200);
        set("black_white_ness", 0);
        set("skill_class", "huashan");
        set("dodge_msg", ({
                "$n悠悠飘开，如秋空中的一缕轻云。\n",
                "$n纤腰轻轻一折，如风舞流云避开了$N的攻势。\n",
                "$n似旋风中飘舞的羽毛，身影闪动姿态妙曼，悠闲地避开了$N的招式。\n",
                "如同冷冽的晨风中落下的梅花，$n款款向后飘开。\n",
        }) );
} 
int valid_learn(object me)
{
        if( (int)me->query("max_force") < 50 ) {
                return notify_fail("你的内力不够，没有办法学幻风飘云舞。\n");
        }
        return 1;
} 
int practice_skill(object me)
{
        return notify_fail("幻风飘云舞只能用学的。\n");
}    
