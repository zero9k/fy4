 // ice liumang-strike.c 
inherit SKILL; 
void setup() { 
        set("name", "流氓神拳"); 
        set("usage/unarmed", 1); 
        set("effective_level", 100);
        set("practice_limit",200);
        set("skill_class", "quanli"); 
        set("parry_msg", ({ 
        "$n一式「烈火锥」，双掌轮流下击，拳势如焰，格开了$N的$w。\n", 
                "$n腾空飞起，一式「八方雨」，双手双腿齐出，荡开了$N的$w。\n", 
        }) ); 
 
        set("unarmed_parry_msg", ({ 
                "$n故意丢个破绽，一招「秋水沉舟」，双拳反击向$N之必救。\n", 
                "$n一招「天下有雪」，全然不顾$N的攻击，双掌直向$N击去，逼得$N回招自保。\n", 
        }) ); 
 
        action = ({ 
        ([      "action":                
"$N脸上露出诡异的笑容，隐隐泛出绿色的双掌扫向$n的$l！", 
                "damage":               60, 
                "dodge":                40, 
                "parry":                50, 
 
                "damage_type":  "瘀伤" 
        ]),  
        ([      "action":                
"$N突然身形旋转起来扑向$n，双掌飞舞着拍向$n的$l！", 
                "damage":               10, 
                "dodge":                80, 
                "parry":                100, 
 
                "damage_type":  "瘀伤" 
        ]), 
        ([      "action":                
"$N将内力运至右手，一招「晴天蓝」大力抓向$n的$l！", 
                "damage":               70, 
                "dodge":                90, 
                "parry":                70, 
 
                "damage_type":  "瘀伤" 
        ]), 
        ([      "action":                
"$N双掌挟着一股腥臭之气拍向$n的$l！", 
                "damage":               50, 
                "dodge":                50, 
                "parry":                100, 
 
                "damage_type":  "瘀伤" 
        ]), 
        ([      "action":                
"$N气凝如山，一式「金戈铁马」，双拳蓄势而发，击向$n的$l！", 
                "damage":               30, 
                "dodge":                20, 
                "parry":                70, 
 
                "damage_type":  "瘀伤" 
        ]), 
        ([      "action":                
"$N身形凝重，劲发腰背，一式「木已成舟」，缓缓向$n推出！", 
                "damage":               40, 
                "dodge":                80, 
                "parry":                50,                                

                "damage_type":  "瘀伤" 
        ]), 
        ([      "action":                
"$N步伐轻灵，两臂伸舒如鞭，一式「水中捞月」，令$n无可躲闪", 
                "damage":               20, 
                "dodge":                80, 
                "parry":                60, 
 
                "damage_type":  "瘀伤" 
        ]), 
        }); 
} 
int valid_learn(object me) 
{ 
        if(!::valid_learn(me)) { 
                return 0; 
        } 
    if ((int)me->query_skill("wuchenforce", 1) < 50){ 
                return notify_fail("你的无尘心法火候不够，无法练流氓神拳。\n"); 
        }        
    if((int)me->query("str") + (int)me->query("max_force") / 100 < 35 ) { 
        return notify_fail("你的膂力还不够，也许该练一练内力来增强力量。\n"); 
        } 
    return 1; 
} 

        
