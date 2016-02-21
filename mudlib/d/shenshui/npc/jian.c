 // XXDER
inherit NPC;
void create()
{
        set_name("剑儿" , ({ "jian er", "girl" }) );
        set("long", "一位浓眉大眼的女孩。\n");
        set("attitude", "friendly");
        set("class","shenshui");
        set("max_gin", 500);
        set("max_kee", 500);
        set("max_sen", 500);
        set("age", 16);
        set("gender", "女性" );
        set("title", "神水宫弟子");
        set("combat_exp", 50000);
        set_skill("unarmed", 50);
        set_skill("throwing", 85);
        set_skill("force", 90);
        set_skill("parry", 67);
        set_skill("dodge", 89);
        set_skill("literate", 50);
        set_skill("perception", 68); 
        set_skill("nine-moon-steps", 68);
        set_skill("nine-moon-claw", 65);
        set_skill("nine-moon-force", 60);
        set_skill("nine-moon-sword", 80); 
        map_skill("dodge", "nine-moon-steps");
        map_skill("unarmed", "nine-moon-claw");
        map_skill("force", "nine-moon-force");
        map_skill("sword", "nine-moon-sword");
        
        set("chat_chance_combat", 50);
        set("chat_msg_combat", ({
                (: perform_action, "dodge.lianhuanbu" :),
                (: perform_action, "dodge.lianhuanbu" :),
                (: perform_action, "unarmed.suicidal" :),
                (: perform_action, "dodge.lianhuanbu" :),
                
        }) );
        setup();
   carry_object(__DIR__"obj/cloth")->wear();
        carry_object("/obj/weapon/sword")->wield();
} 
void init()
{
        object me;
        me = this_player();
        if(interactive(me) && me->query("gender") == "男性" && !me->query_temp("marks/guest"))
        call_out("chase_him", 1,me );  
} 
int chase_him(object me)
{
        message_vision("$N向$n喝道：大胆狂徒，竟敢擅闯神水宫！\n",this_object(),me);
        set_leader(me);
        kill_ob(me);
        me->kill_ob(this_object());
        return 1;
}      
