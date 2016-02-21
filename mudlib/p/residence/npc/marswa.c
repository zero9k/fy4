#include <ansi.h> 
inherit NPC; 
void create()
{
        set_name("冯晓晓", ({ "feng xiaoxiao","xiaoxiao" }) );
        set("gender", "女性" );
        set("title",HIG"小居侍女"NOR);
        set("long",
     "冯晓晓是现今峨嵋十八居唯一的侍女。\n"
                );
        set("attitude", "peaceful");
         set("age", 20);
        set("str", 15);
        set("cps", 15);
        set("int",30);
        set("per", 70);
        set("combat_exp", 100000);
        set("force", 200);
        set("max_force", 200);
        set("mana", 100);
        set("max_mana", 100);
        set("max_kee", 400);
        set("max_gin", 400);
        set("max_sen", 400);
        set("force_factor", 10);
        set("chat_chance", 50);
        set("chat_msg", ({
             "冯晓晓喃喃的说道：不知道今天主人喜欢吃什么样的菜肴。\n",
             (: random_move :),
        }) ); 
        setup();
        carry_object("/d/resort/npc/obj/pink_cloth")->wear();
        carry_object("/d/resort/npc/obj/shoe")->wear();
}    


void init()
{       
        object ob; 
        ::init();
        if( interactive(ob = this_player()) && !is_fighting() ) {
                remove_call_out("greeting");
                call_out("greeting", 1, ob);
        }
} 

int accept_fight(object me)
{
        command("emote 摇头道：我不喜欢打架。");
        command("shy");
        return 0;
}
       
void greeting(object ob)
{   

  message_vision("$N对着$n微微一笑。\n", this_object(),ob );
  return;
}   


