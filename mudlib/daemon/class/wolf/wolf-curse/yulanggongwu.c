#include <ansi.h>
inherit SSERVER;
int curse(object me, object target)
{
        object wolfboss,wolf;
        int wolfcurse, exp;
        int count;
        
        if ((string)me->query("class") != "wolfmount")
                return notify_fail("只有狼山弟子才可以与狼共舞。\n");
        if( !me->is_fighting() )
                return notify_fail("现在不是与狼共舞的时候。\n");
        wolfcurse = (int)me->query_skill("wolf-curse",1);
        exp = (int)me->query("combat_exp");
        if(wolfcurse < 150 )
                return notify_fail("你的天狼血咒还不够熟练，不能引起狼的共鸣。\n");   
        count=3+(wolfcurse-150)/10;
        if(count>=5) count =5;
        seteuid(getuid());
        me->receive_damage("sen",random(wolfcurse/2));
        me->receive_damage("gin",random(wolfcurse/2));
        wolfboss= new("/obj/npc/wolfboss");
        wolfboss->move(environment(me));
        wolfboss->setboss(me, (wolfcurse));
        wolfboss->set("possessed", me); 
        wolfboss->set("name",WHT"幽灵狼王"NOR);
        for(int i=0;i<count;i++)
        {
        	wolf= new("/obj/npc/wolfguard");
        	wolf->move(environment(me));
        	wolf->setguard(me, (wolfcurse));
        	wolf->set("possessed", me);
        	wolf->set("boss",wolfboss);
        	wolf->set("name",WHT"幽灵狼"NOR);
        }        
        me->remove_all_killer();
        message_vision( WHT"\n$N心无杂念口中念念有词，突然之间，一只只幽灵狼王从四面八方涌现出来！！\n"NOR, me);     
        message_vision( WHT"\n\n幽灵狼"+HIR"围在$N四周，不让任何人伤害自己的主人。\n"NOR ,me);
        return 1;
} 