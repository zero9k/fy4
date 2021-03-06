 // TIE@FY3
inherit SKILL;
#include <ansi.h>  
void setup() {
        set("name", "降龙十八掌");
        set("usage/unarmed", 1);
        set("usage/parry", 1);
        set("practice_damage", 20);
//      set("effective_level", 130);
        set("learn_bonus", -20);
        set("practice_bonus", -150);
        set("practice_limit",140);
        set("black_white_ness", 0);
        set("skill_class", "beggar"); 
        set("parry_msg", ({
        "$n双掌微分，使出一招「神龙摆尾」，「啪」的一声将$N的$w划开。\n",
        "$n略一转身，一招「见龙在田」拍向$N拿着$w的手。\n",
        "$n使出「粘」字诀，双掌一划，引偏了$N的$w。\n",
        }) ); 
        set("unarmed_parry_msg", ({
        "$n步走阴阳，一招「震惊百里」虚空拍出三掌，逼得$N撤招自保。\n",
        "$n施展出「神龙摆尾」，轻描淡写的化解了$N的攻势。\n",
        }) );   
        action = ({
([      "action": "$N双掌平平提到胸前，神色沉重的缓缓施出「亢龙有悔」推向$n的$l",
        "dodge": 30,
        "parry": 10,
        "force": 400,
        "damage_type": "瘀伤"
]),
([      "action": "$N突然身形飞起，双掌居高临下一招「飞龙在天」拍向$n的$l",
        "dodge": 15,
        "parry": 20,
        "force": 800,
        "damage_type": "瘀伤"
]),
([      "action": "$N右掌一招「见龙在田」，迅捷无比地劈向$n的$l",
        "dodge": 10,
        "parry": 10,
        "force": 720,
   "damage_type": "瘀伤"
]),
([      "action": "$N双掌施出一招「鸿渐于陆」，隐隐带着风声拍向$n的$l",
        "dodge": 15,
        "parry": 10,
        "force": 900,
        "damage_type": "瘀伤"
]),
([      "action": "$N左掌聚成拳状，右掌一招「潜龙勿用」缓缓推向$n的$l",
        "dodge": 10,
        "parry": 10,
        "force": 500,
        "damage_type": "瘀伤"
]),
([      "action": "$N施出一招「利涉大川」，右掌插腰，左掌劈向$n的$l",
        "dodge": 10,
        "parry": 20,
        "force": 500,
        "damage_type": "瘀伤"
]),
([      "action": "$N使出「突如其来」，右掌从不可能的角度向$n的$l推出",
        "dodge": 0,
        "parry": 10,
        "force": 500,
        "damage_type": "瘀伤"
]),
([      "action": "$N大吼一声，双掌使出「震惊百里」，不顾一切般击向$n",
        "dodge": 25,
        "parry": 10,
        "force": 700,
        "damage_type": "瘀伤"
]),
([      "action": "$N使出「或跃在渊」，向$n的$l连拍数掌",
        "dodge": 20,
        "parry": 20,
        "force": 300,
        "damage_type": "瘀伤"
]),
([      "action": "$N身形滑动，双掌使一招「双龙取水」一前一后按向$n的$l",
        "dodge": 10,
   "parry": 20,
        "force": 460,
        "damage_type": "瘀伤"
]),
([      "action": "$N使出「鱼跃于渊」，身形飞起，双掌并在一起向$n的$l劈下",
        "dodge": 20,
        "parry": 30,
        "force": 900,
        "damage_type": "瘀伤"
]),
([      "action": "$N双掌立起，使出「时乘六龙」向$n连砍六下",
        "dodge": 20,
        "parry": 20,
        "force": 870,
        "damage_type": "瘀伤"
]),
([      "action": "$N使出「密云不雨」，左掌封住$n的退路，右掌斜斜地劈向$l",
        "dodge": 15,
        "parry": 20,
        "force": 220,
        "damage_type": "瘀伤"
]),
([      "action": "$N使出「损则有孚」，双掌软绵绵地拍向$n的$l",
        "dodge": 25,
        "parry": 10,
        "force": 350,
        "damage_type": "瘀伤"
]),
([      "action": "$N脚下一转，突然欺到$n身前，一招「龙战于野」拍向$n的$l",
        "dodge": 20,
        "parry": 40,
        "force": 630,
        "damage_type": "瘀伤"
]),
([      "action": "$N门户大开，一招「履霜冰至」向$n的$l劈去",
        "dodge": 25,
        "parry": 1,
        "force": 420,
        "damage_type": "瘀伤"
]),
([ "action": "$N使出「羝羊触蕃」，双掌由下往上击向$n的$l",
        "dodge": 15,
        "parry": 40,
        "force": 600,
        "damage_type": "瘀伤"
]),
([      "action": "$N左掌护胸，右掌使一招「神龙摆尾」上下晃动着击向$n的$l",
        "dodge": 10,
        "parry": 40,
        "force": 620,
        "damage_type": "瘀伤"
]),
}); 
} 
int valid_learn(object me)
{
        if(!::valid_learn(me)) {
                return 0;
        }
        if ((int)me->query("max_force") < 100)
                return notify_fail("你的内力太弱，无法练降龙十八掌。\n");
        return 1;
} 
int practice_skill(object me)
{
        if ((int)me->query("force") < 20) {
                return notify_fail("你的内力不够练降龙十八掌。\n");
        }
        if(!::practice_skill(me)) {
                return 0;
        }
        me->add("force", -10);
        return 1;
} 
mixed hit_ob(object me, object victim, int damage_bonus)
{
        int badint=0;
        if( damage_bonus < 500 ) return 0;
        badint = victim->query_skill("iron-cloth") + victim->query_temp("apply/iron-cloth")*2;
        if (victim->query_skill_mapped("iron-cloth") == "jin-gang"
           ||victim->query_skill_mapped("iron-cloth") == "spring-water"
                ||victim->query_skill_mapped("iron-cloth") == "henglian"
                ||victim->query_skill_mapped("iron-cloth") == "yijinjing"
                ||victim->query_skill_mapped("iron-cloth") == "xisui"
                ) {
                if(badint) {
                        victim->receive_wound("kee",badint);
                        switch(random(3)) {
                                case 0: return "$N隔山打牛，“喀啦”一声轻响，竟似是骨碎的声音！\n";
                                case 1: return "$N劲力暗吐，$n的$l发出“喀”地一声爆响！\n";
                                case 2: return "只听见$n的$l“喀”地一声 ．．．\n";
                                }
                }
        }
}  
int effective_level()
{
        object me;
        int skill,n;
        
        skill=this_player()->query_skill("dragonstrike",1);
        if (skill<=170) return 130;
        if (skill>=190) return 170;
        
        n=(skill-170)/5*10+130;
        return n;
} 
int learn_bonus() {
        
        int skill;
        skill = this_player()->query_skill("dragonstrike",1);
        if (skill<=170) return -20;
                else return -400;
}      
