#include <ansi.h>
inherit NPC; 
void create()
{
    set_name("朱云",({"zhu yun","zhu"}));
        set("long","他很年轻，可是头发眉毛都已开始脱落，呼吸也细若游丝。\n");
        set("nickname", BLU"病入膏肓"NOR);
        set("gender","男性");
        
        set("no_arrest",1);
        set("no_heal",1);
        
        set("age",22);
        set("int",22);
        set("str",40);
        set("cor",30);
        set("per",30);
        set("cps",20);
        set("gin",3000);
        set("max_gin",2500);
        set("eff_gin",2500);
        set("gin",2500);
        
        set("max_kee",5000);
        set("eff_kee",2500);
        set("kee",2500);  
        
        set("max_sen",2500);
        set("sen",2500);    
        set("eff_sen",2500);
        
        set("combat_exp",3000000);  
        set_temp("apply/damage",200);
        set_temp("apply/armor",200);
        
        set_skill("force",200);
        set_skill("iron-cloth",200);
        set_skill("wolf-claw",200);
        set_skill("xueyeqianzong",200);
        set_skill("unarmed",200);
   set_skill("parry",150);
        set_skill("dodge",150);
         
        map_skill("dodge","xueyeqianzong");
        map_skill("unarmed","wolf-claw");
        
        set("force",10000);
        set("max_force",10000);
        set("force_factor",100);
        
        set("attitude", "friendly");
        
        set("chat_chance",1);     
        set("chat_msg",({
        "朱云皱皱眉头道：想我父天纵英才，惊才绝艳，怎可能让狼山如此混乱不堪！定是。。。\n",
        }) );
        setup();
    if (!random(5)) add_money("thousand-cash", 1);
    carry_object(__DIR__"obj/whitecloth")->wear();
    if (!random(10)) carry_object(__DIR__"obj/zhuguo");
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
int greeting(object ob)
{
 if (random(100)>20 )
        {
        if(NATURE_D->get_current_day_phase() == 1080) 
                {
                       if (present("zhuguo",this_object()))
                       {
                                                   message_vision(HIR"$N突然剧烈地咳嗽起来。\n$N叹了口气道：该是吃药的时候了。\n\n"NOR,this_object(),ob);
                                                   command("eat zhuguo");
                                              return 1; 
                       }
                                                
                }
                else 
                {
                        command("sigh");
                        say ("朱云抬头看了你一眼，忍不住又咳嗽起来。\n");
                        return 1;
                }
        }
        else
                return 0;
}
       
