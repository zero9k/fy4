 // lifeheal.c
#include <ansi.h>
#include <combat.h>
inherit SSERVER; 
int exert(object me, object target, int amount)
{
        int level,i, n,add;
        object *enemy, *mem;
        
        if(me->query("class")!="bonze")
                return notify_fail("只有兴国禅寺的弟子才能用此心法！\n");
        level=me->query_skill("lotusforce",1)/50+1;
        if (level<2) 
                return notify_fail("你的莲华心法太差了。\n");
        if( !target )                                                                           
                target=me;
        
        mem = me->query_team();
        if (!mem && target!=me)
                 return notify_fail("你只能给同一队伍中的人疗伤。\n");
        
        if (target!=me) {
        for(i=0;i<sizeof(mem);i++) {
                if (target!=mem[i]) n=n+1;
                }
        if (n>=sizeof(mem)) 
                return notify_fail("你只能给同一队伍中的人疗伤。\n");
        }
                
        
        if( (int)me->query("force") < 250 )
                return notify_fail("你的真气不够。\n");
        me->add("force", -250);
        me->set("force_factor", 0);     
        if (target!=me)
        message_vision(HIY "$N运起内功，将手掌贴在$n背心，缓缓地将真气输入$n体内....\n\n"NOR,me,target);
        else
        message_vision(HIY "$N运起内功，缓缓地将真气在体内流转....\n\n"NOR,me);
        call_out("heal_him", 4, me, target, level);
        me->start_busy(1);
   if( target->is_fighting()) {
                enemy = target->query_enemy();
                for (i=0;i<sizeof(enemy);i++) {
                        me->kill_ob(enemy[i]);  
                        enemy[i]->kill_ob(me);
                }       
        }       
        return 1;
}  
int heal_him(object me, object target, int level)
{
        int amount;
//      amount=target->query("max_kee")/20*level;
        amount=1000;
        if (!present(target,environment(me))) {
                tell_object(me,"你要救治的人已经不在这里了。\n");
                return notify_fail("");
                }
        if (target!=me)
        message_vision(HIY"过了不久，$N额头上冒出豆大的汗珠，$n吐出一口瘀血，脸色看起来红润多了。\n"NOR,me,target);
        else 
        message_vision(HIY"过了不久，$N吐出一口瘀血，脸色看起来红润多了。\n"NOR,me);
        target->receive_curing("kee", amount);
        if (target->query("kee")+ amount<target->query("max_kee"))
                target->add("kee",amount);
                else target->set("kee",target->query("max_kee"));       
}   
