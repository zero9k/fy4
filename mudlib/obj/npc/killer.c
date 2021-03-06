 //written by Cheng Bao
// gangster.c 
inherit NPC;
void goaway();
void create()
{
        set_name("杀手", ({ "killer" }) );
        set("gender", "男性" );
        set("age", 27);
        set("str", 40);
        set("int", 12);
        set("per", 10);
        set("long", @LONG
这个杀手蒙着面，你无法看清他的长相，但是从那冷酷的眼神能看出他是一个
非常干练、训练有素的杀手。
LONG
);
        set("attitude", "heroism");
        set("bellicosity", 1500 ); 
        set("combat_exp", 10000); 
        set("chat_chance", 50);
        set("chat_msg", ({
                        (: goaway :),
        }) );  
        set("chat_chance_combat", 1);
        set("chat_msg_combat", ({
              "杀手显得很有组织，明显是有目的的。\n",
              "杀手高喊：先杀联络人员！！！\n",
        }) ); 
        set("force",5000);
        set("force_factor",80);
        set_skill("unarmed", 200);
        set_skill("blade", 160);
        set_skill("dodge", 140);
        set_skill("parry", 150);
        set_skill("move",100);
        set_skill("fall-steps",100);
        set_skill("shortsong-blade",120);
        map_skill("dodge","fall-steps");
        map_skill("move","fall-steps");
        map_skill("blade","shortsong-blade");
        map_skill("parry","shortsong-blade");
        set("chat_chance_combat", 60);
    	set("chat_msg_combat", ({
//        	(: perform_action, "blade.duangechangmeng" :),
            }) );

        setup();
        add_money("coin", 10); 
        carry_object("/obj/weapon/blade")->wield();
        carry_object("/obj/armor/cloth")->wear();
} 
void goaway()
{
        object ob;
        if (ob=present("importman",environment()) )
        {
                command("heng");
                kill_ob(ob);
                ob->kill_ob(this_object());
                return; 
        }
                
        message_vision("$N一声唿哨，消失得无影无踪！\n",this_object());
        destruct(this_object());
}  
