 //silencer@fy4
#include <ansi.h>
#include <combat.h>
inherit SSERVER; 
int perform(object me, object target)
{
        string msg,temp,temp1;
        int extra,num,num1,lvl;
        int myexp,yourexp, exp_bonus;
        object weapon,shadow,hisweapon,newweapon;
        object *enemy;
        int cond;
        
        if(me->query("class")!="beggar" && userp(me))
                return notify_fail("［引字诀］只传授给丐帮弟子！\n");
        
        lvl = (int) me->query_skill("dagou-stick",1);
        if(lvl < 80)
                return notify_fail("你的打狗棒法还不够熟练！\n");       
        
        if (me->query_skill_mapped("force") != "huntunforce")
                return notify_fail("引字诀需要混沌心法的配合。\n");
        
        if (me->query("force")<50)
                return notify_fail("你的内力不够。\n");
        
        if( !target ) target = offensive_target(me);
        if( !target
        ||      !target->is_character()
        ||      !me->is_fighting(target) )
                return notify_fail("［引字诀］只能对战斗中的对手使用。\n"); 
        if (userp(me))  me->add("force", -50);
        weapon = me->query_temp("weapon");
        myexp=me->query("combat_exp");
                
        yourexp=target->query("combat_exp");    
        msg = HIY +"\n$N"+HIY"棒法陡变，使出打狗棒法中的“"+NOR CYN"引"+HIY"”字诀，三根手指捉住棒腰，将"+weapon->name()+HIY"舞\n成个圆圈，倏然疾翻，顺势将$n"+HIY"的劲力引向$n。\n" NOR;
        message_vision(msg,me,target);
        if ((myexp*3/4+random(myexp)*4>yourexp ||!userp(me))&& !target->query_temp("is_unconcious")) {
                seteuid(getuid());
           if (!userp(target)) {
                        sscanf(file_name(target),"%s#%d",temp,num);
                        shadow=new(temp);
                } else  {
                                shadow=new("/d/fy/npc/shadefigure");
                                shadow->changeshape(target);
                                if(hisweapon=target->query_temp("weapon")){
                                        sscanf(file_name(hisweapon),"%s#%d",temp1,num1);
                                        newweapon=new(temp1);
                                        newweapon->move(shadow);
                                        newweapon->wield();
                                }
                }       
                shadow->set("owner",me);
                shadow->set("possessed",me);
                shadow->move(environment(me));
                if (!target->query_temp("weapon"))
                if (newweapon=shadow->query_temp("weapon"))
                        newweapon->unequip();
                shadow->set("kee",target->query("kee"));                        
                shadow->set("sen",target->query("sen"));
                shadow->set("gin",target->query("gin"));
                shadow->set("eff_kee",target->query("eff_kee"));
                shadow->set("eff_gin",target->query("eff_gin"));
                shadow->set("eff_sen",target->query("eff_sen"));
                shadow->set("max_kee",target->query("max_kee"));
                shadow->set("max_sen",target->query("max_sen"));
                shadow->set("max_gin",target->query("max_gin"));
                shadow->set("name",target->query("name"));
                
                shadow->add_killer(target->query("id"));        
                shadow->add_temp("apply/attack", lvl);
                shadow->add_temp("apply/damage", lvl*2);
                COMBAT_D->do_attack(shadow,target,msg);
                shadow->add_temp("apply/attack", -lvl);
                shadow->add_temp("apply/damage", -lvl*2);
                if (target->query_temp("damaged_during_attack"))
                        target->set_temp("last_damage_from",me);
                if (me->is_killing(target->query("id"))) cond=1;
                destruct(shadow);
           }
        if (cond) 
                me->add_killer(target->query("id"));            
        me->add_enemy(target);
        me->start_busy(1+random(2));
        return 1;
}      
