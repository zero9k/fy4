 // 武穆奇兵
inherit __DIR__"generic_condition";
#include <ansi.h>
#include <condition.h>  
int update_condition(object me, int duration)
{
        me->receive_damage("gin", 80);
        me->receive_damage("kee", 100);
        me->apply_condition("wumushenbing", duration - 1);
        if( duration < 1 )
                message_vision(HIG "$N"+HIG"终于冲出了岳家军的阵法！\n"NOR, me );
        else
                message_vision(HIW "各旗阵在$N"+HIW"面前前高声叫阵，战鼓擂动，彩旗飞舞，$N"+HIW"不由得心烦意乱！\n" NOR, me );
        if( duration < 1 ) 
                return 0;
        return 1;
}    
