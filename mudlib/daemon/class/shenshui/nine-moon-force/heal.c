 // heal.c
#include <ansi.h> 
int exert(object me, object target, int amount)
{
        if (!me->query("marks/��������"))
                return notify_fail("�����õ��ڹ���û�����ּ��ܡ�\n"); 
        if (me->query_skill("nine-moon-force",1)<150)
                return notify_fail("��ľ����ľ�̫�\n");
                
        if (me->query_skill("qingpingforce",1)<110)
                return notify_fail("�����ƽ�ڹ�̫�\n");
        
        if( target != me ) return 
                notify_fail("��ֻ�����ڹ����Լ����ˡ�\n"); 
        if( me->is_fighting() )
                return notify_fail("ս�����˹����ˣ�������\n"); 
        if( (int)me->query("force") - (int)me->query("max_force") < 50 )
                return notify_fail("�������������\n"); 
        write( HIW "��ȫ�����ɣ���������ʼ�˹����ˡ�\n" NOR);
        message("vision",
                HIW + me->name() + "�������˹����ˣ�����һ���һ��ף����ã��³�һ����Ѫ����ɫ�������ö��ˡ�\n" NOR,
                environment(me), me); 
        me->receive_curing("kee", 20 + (int)me->query_skill("nine-moon-force")*2,1);
        me->add("force", -50);
        me->set("force_factor", 0); 
        return 1;
}   