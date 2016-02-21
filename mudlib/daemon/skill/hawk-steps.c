 // hawk-steps.c
inherit SKILL;
void setup() {
        set("name", "鲲鹏步法");
        set("usage/dodge", 1);
        set("usage/move", 1);
        set("effective_level", 160);
        set("black_white_ness", 10);
        set("practice_damage",  40);
        set("practice_bonus", -80);
        set("skill_class", "fugui");
        set("dodge_msg", ({
                "$n轻张双臂，使出「苍茫古木连穷巷」，轻轻巧巧地避了开去。\n",
                "只见$n身影一晃，一式「寥落寒山对虚牖」早已避在七尺之外。\n",
                "$n藉著激起的劲风,瞬间移形换位，使出「誓令疏勒出飞泉」，轻轻松松地闪过。\n",
                "$n左足一点，漂浮不定的身法恰似「不似颍川空使酒」，腾空而起，避了开去。\n",
                "可是$n使一招「贺兰山下阵如云」，意境已达形泣风动般的诡异,轻轻飘了开去。\n",
                "$n身影微动，已经藉一招「羽檄交驰日夕闻」轻轻闪过。\n",
                "$n势如风行草偃，犹如诗意「试拂铁衣如雪色」，向后疾退而去。\n",
                "$n双脚真气一提，身形变换「聊持宝剑动星文」，顿时风起叶飞，雪花盖顶，人已无影无踪。\n",
        }) );
} 
int valid_learn(object me)
{
        if( (int)me->query("max_force") < 50 )
                return notify_fail("你的内力不够，没有办法学鲲鹏步法。\n"); 
        return 1;
} 
int practice_skill(object me)
{ 
        if((int)me->query("force") < 20 ) {
                return notify_fail("你的内力不够，不能练鲲鹏步法。\n");
        }
        if(!::practice_skill(me)) {
                return 0;
        }
        me->add("force", -10);
        return 1;
}     
