 inherit NPC;
void use_poison(); 
void create()
{
        set_name("����", ({ "cor" }) );
        set("race", "Ұ��");
        set("age", 4);
        set("yes_carry", 1);
        set("long", "һ��ˮͰ��ֵ����㡣\n"); 
        set("limbs", ({ "ͷ��", "����", "β��", "�۾�" }) );
        set("verbs", ({ "bite" }) );
        set("attitude", "aggressive");
        set_skill("dodge", 50);
        set_skill("move",300);
        set("combat_exp", 9999);
        set("bellicosity", 300 );
        set("chat_chance", 20);
        add_temp("apply/damage",10+random(10));
        setup();
}
/*
void use_poison()
{
        object *enemy, ob;
        string msg; 
        enemy = query_enemy();
        if( sizeof(enemy) ) ob = enemy[random(sizeof(enemy))]; 
        tell_object(ob,
"��������Ͼ�ʹ������һ��������������ӡ�ۡ�\n");
        if( random(query("combat_exp")) > (int)ob->query("combat_exp") )
                ob->apply_condition("snake_poison", 
                (int)this_player()->query_condition("snake_poison")
                + random(3)+3);
}
*/
void init()
{
        object ob;
        ::init();
        if( interactive(ob = this_player()) ) {
                kill_ob(ob);
        }
} 
