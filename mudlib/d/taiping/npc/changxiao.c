#include <ansi.h>
#include <command.h> 
inherit "/d/taiping/npc/smart_npc"; 
void create()
{ 
        set_name("常笑",({"chang xiao","chang","xiao"}));
        set("nickname","毒剑");
        set("title",WHT"四大名捕"NOR);
        set("long", "
他面上挂着笑容，和蔼的笑容，相貌亦是一副慈祥的相貌，即使穿上了官服，他也
是显得和蔼可亲。有谁想到这样的一个人，他的心，他的剑，竟比毒蛇还狠毒？他
今年不过三十六岁，做这份工作不过十年，死在他手上的人却已过千。平均每三日，
就有一个人死在他手上。知道这些事的人，是不是仍觉得他和蔼可亲？\n");
        set("age",47);
        set("combat_exp", 9000000);
                
        set("resistance/gin",30);
        set("resistance/kee",50);
        set("resistance/sen",30);
        
//      setting up special NPC function: healer, defense, zombie-killer
//      defense_type: 1. xiaohun-sword; 2.xiaohun-whip;3 yue-strike;4 lingxi-zhi;
        
        set("defense_type",random(2)+1);        
        set("zombie-killer",1);
//      set("officer-killer",1);
//      set("dungeon_npc","check");
        
        set("nb_chat_chance", 100);
        set("nb_chat_msg_combat", ([
                10:     "\n常笑冷冷道：这儿某个人的咽喉之上立即会多出一个血洞了！\n",
        ]) ); 
        set("chat_chance_combat", 100);
        set("chat_msg_combat", ({
                (: auto_smart_fight(20) :),    
        }) );
         
        auto_npc_setup("wang",300,200,0,"/obj/weapon/","fighter_w","sharen-sword",1);
        
        setup();
   carry_object(__DIR__"obj/o_cloth2")->wear();
        carry_object(__DIR__"obj/o_sword")->wield();
}  
/*
void init() {
        
        object ob;
        ::init();
        add_action("do_answer","answer");
        if( interactive(ob = this_player()) && !is_fighting() ) {
                remove_call_out("greeting");
                call_out("greeting", 1, ob);
        }
}  
void greeting(object ob) {
        
        if( !ob || environment(ob) != environment() || ob->is_fighting()) return;
        call_out("ask_question_1",1,ob); 
}
*/
