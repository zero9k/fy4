 inherit NPC;
void create()
{
        set_name("护寺藏尼", ({ "zang ni", "ni"}) );
        set("gender", "女性" );
        set("age", 25);
        set("str", 20);
        set("long", @LONG
一个大昭寺的藏尼。
LONG
);
        set("attitude", "peaceful"); 
        set("combat_exp", 6000);
        create_family("大昭寺", random(4)+22, "弟子");
        set_skill("unarmed", 50+random(10));
        set_skill("bloodystrike", random(50)+20);
        set_skill("force", 40);
        set("chat_chance_combat", 30);
        set("chat_msg_combat", ({
                (: perform_action, "unarmed.fefawubian" :),
        }) );  
        map_skill("unarmed", "bloodystrike");
        set_skill("iron-cloth", 40+random(10));
        set("chat_chance", 1);
        set("chat_msg", ({
                (: random_move :),
        }) ); 
        setup(); 
        carry_object(__DIR__"obj/redcloth2")->wear();
}       
