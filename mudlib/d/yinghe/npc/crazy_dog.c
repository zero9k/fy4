 // crazy_dog.c
inherit NPC; 
void create()
{
        set_name("�蹷", ({ "crazy dog", "dog" }) );
        set("race", "Ұ��");
        set("age", 4);
        set("long", "һֻ�����������Ұ����һ˫�۾�����ݺݵص����㡣\n");
        set("attitude", "aggressive");
        
        set("str", 26);
        set("cor", 30); 
        set("limbs", ({ "ͷ��", "����", "ǰ��", "���", "β��" }) );
        set("verbs", ({ "bite", "claw" }) ); 
        set("combat_exp", 100); 
        set("chat_chance", 6);
        set("chat_msg", ({
                (: random_move :),
        }) );
        
        set("chat_msg_combat", ({
                (: random_move :),
                "�蹷�����ͽУ�������������������������\n",
                "�蹷ͻȻ����������������ҧ��ȴ��֪������ҧ˭��\n"
        }) );
                
        set_temp("apply/attack", 15);
        set_temp("apply/damage", 6);
        set_temp("apply/armor", 2); 
        setup();
}
