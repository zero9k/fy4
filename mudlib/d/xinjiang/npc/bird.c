 // dog.c
inherit NPC; 
void create()
{
        set_name("��ȸ", ({ "bird" }) );
        set("race", "Ұ��");
        set("age", 1);
        set("long", "����������һֻС��ȸ��\n");
        
        set("limbs", ({ "ͷ��", "����", "���", "β��" }) );
        set("verbs", ({ "bite", "claw" }) ); 
        set("chat_chance", 10);
        set("chat_msg", ({
                (: this_object(), "random_move" :),
                "���ҡ�\n",
                "������\n",
        }));
        set("arrive_msg","���˹���");
        set("leave_msg","�ɿ���");
        set_temp("apply/dodge", 100);
        set_temp("apply/attack", 10);
        set_temp("apply/armor", 3); 
        setup();
}       
