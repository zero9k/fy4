#include <ansi.h>
#include <weapon.h>  
mixed hit_ob(object me,object victim){       
        
        string my_attr = me->query("attribute_mark");
        string attr = (string) this_object()->query("attribute");            
        int dam =1;
        if (my_attr !=  attr) return 0;
        if (random(3)) return 0;
        if(attr == "fire") {
                    dam = me->query("force")/4 ;
                    if (victim->query("attribute_mark")== "gold") dam *= 3; 
                    victim->receive_damage("kee",dam, me);
                    return HIR"$N手中"NOR+ this_object()->name() + HIR "喷射出绚丽的红色火焰，席卷了$n全身！\n"NOR;
        } else if(attr == "water"){
                    dam = me->query("mana")/3 ;
                    if (victim->query("attribute_mark")== "fire") dam *= 2; 
                    victim->receive_damage("sen",dam, me);
                    return HIW"$N手中"NOR+ this_object()->name() + HIW "透出丝丝寒气席卷了$n全身！\n"NOR;
        } else if(attr == "wood"){
                    dam = me->query("atman")/2 ;
                    if (victim->query("attribute_mark")== "earth") dam *= 2; 
                    victim->receive_damage("gin",dam, me);
                    return HIC"$N手中"NOR+ this_object()->name() + HIC "上忽然聚起一团青雾，射入$n身体！\n"NOR;
        } else if(attr == "gold"){
                    dam = me->query_str() * 10 ;
                    if (victim->query("attribute_mark")== "wood") dam *= 3; 
                    victim->receive_damage("kee",dam, me);
                    return HIY"$N手中"NOR+ this_object()->name() + HIY "发出锐不可当的森森气劲，割过$n全身！\n"NOR;
        } else if(attr == "earth"){
                    dam = me->query("kee")/10 ;
                    if (victim->query("attribute_mark")== "water") dam *= 2; 
                    victim->receive_damage("kee",dam, me);
                    return NOR MAG"$N手中"NOR+ this_object()->name() +NOR MAG "生出后厚重如山的力道，压得$n喘不过气来！\n"NOR;
        }
        return 0; 
} 
