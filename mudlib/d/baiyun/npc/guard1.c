 // XXDER@FY3
inherit NPC;
void create()
{
        set_name("Ҷ��" , ({ "swords man","man" }) );
        set("long", "һ������ƮƮ��Ӣ�������İ��Ƴǽ�ʿ����\n");
        set("nickname","���ƴ����");
        set("attitude", "friendly");
        set("age", 19);
        set("gender", "����" );
        create_family("���Ƴ�", 2, "��ʿ");
        set("combat_exp", 200000+random(500000));
        set_skill("dodge", 80+random(50));
        set_skill("unarmed", 80);
        set_skill("sword", 65);
        set_skill("feixian-sword", 50);
        set_skill("force", 60);
        set_skill("feixian-steps", 50);
        set_skill("qingpingforce", 55);
        map_skill("sword", "feixian-sword");
        map_skill("dodge", "feixian-steps");
        set("chat_chance", 50);
        set("chat_msg", ({
                (: random_move :),
        }) );
        set("chat_chance_combat", 30);
        set("chat_msg_combat", ({
                (: perform_action, "dodge.tianwaifeixian" :),
        }) ); 
        setup();
        carry_object("/obj/armor/cloth")->wear();
        carry_object("/obj/weapon/sword")->wield();
}    
