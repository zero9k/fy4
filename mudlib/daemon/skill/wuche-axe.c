 // TIE@FY3
inherit SKILL;
void setup(){
        set("name", "悟彻波风斧法");
        set("usage/axe", 1);
        set("usage/parry", 1);
        set("practice_damage", 30);
        set("effective_level", 250);
        set("practice_limit",150);
        set("learn_bonus", -1000);
        set("practice_bonus", -5);
        set("skill_class", "shaolin");
        
        set("parry_msg", ({
        "结果$n一招「禅心落寞」，挥动手中$v格开了$N的$w。\n",
        "结果$n手中$v一分，一招「入魔入佛」，斜劈$N的$w。\n",
        "结果$n手中$v抡动如飞，一招「洪波万里」，荡开$N的$w。\n",
        "结果$n手中$v飞速旋转，一招「不解成舟」，反扫$N的$w。\n",
        }) ); 
        set("unarmed_parry_msg", ({
        "$n手中的$v舞动如飞，一招「不动不摇」，封住了$N的攻势。\n",
        "$n身影晃动，一招「千潭月朗」，反砍$N的下盘。\n",
        "$n身形一矮，一招「满地蒿蓬」，躲过$N的攻势。\n",
        "$n手中的$v自上而下，一招「始堪耕地」，反劈$N的要害。\n",
        }) );   
        action = ({
        ([      "action":               
"$N手中$w抡开，挟着呼呼风声，一招「树喧每每」，直取$n的各处要害！",
                "dodge":                -150,
                "parry":                -200,
                "post_action":  "bash_weapon",
                "damage_type":  "割伤"
        ]),
        ([      "action":               
"$N纵身一跃，手中$w斧风呼啸，一招「月现长空」，横空向$n$l劈去！",
                "dodge":                -160,
                "parry":                -210,
                "post_action":  "bash_weapon",
                "damage_type":  "割伤"
        ]),
        ([      "action":               
"$N手中$w接连劈出，，一招「渊源不尽」，旋风般砍向$n$l！",
                "dodge":                -150,
                "parry":                -150,
                "post_action":  "bash_weapon",
                "damage_type":  "割伤"
        ]),
        ([      "action":               
"$N使出一招「万派朝宗」，手中$w舞动，身随斧势，化作一溜烟尘，滚滚奔向$n的$l！",
                "dodge":                -140,
                "parry":                -240,
                "post_action":  "bash_weapon",
                "damage_type":  "割伤"
        ]),
        });
}
int valid_learn(object me)
{
        if(!::valid_learn(me)){
                return 0;
        }
        if( (int)me->query("str") + (int)me->query("max_force") / 10 < 15 ){
            return notify_fail("你的膂力还不够，也许该练一练内力来增强力量。\n");
        }
        return 1;
} 
int practice_skill(object me)
{
        if (me->query_skill("wuche-axe",1)>161)
                return notify_fail("高级的悟彻波风斧法只能学的。\n");
        
        if( (int)me->query("force") < 10 ){
            return notify_fail("你的内力不够了，休息一下再练吧。\n");
        }
        if(!::practice_skill(me)){
                return 0;
        }
        me->add("force", -10);
        return 1;
}      
