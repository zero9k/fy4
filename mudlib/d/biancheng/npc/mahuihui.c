#include <ansi.h>

//inherit "/d/taiping/npc/smart_npc"; 
inherit NPC;
inherit F_VENDOR; 


void create()
{
        set_name("马回回",({"ma huihui","huihui"}));
        set("title","关外第一摔跤好手");
        set("long","马回回总是满面红光，精神抖擞。据说能将牛肉烹调得像嫩鸡、像肥鸭、像野味，有时甚至嫩得像豆腐。\n");
        
        set("gender","男性");
        set("attitude", "friendly");
        set("group","citizen");
        
        set("combat_exp",1000000);  
        set("age",42);
                
        set("int",40);
        set("cor",40);
        set("cps",40);
        
        set_skill("unarmed",220);
        set_skill("shuaijiao",200);
        set_skill("dodge",150);
        set_skill("parry",160);
        set_skill("force",180);
        set_skill("move",200); 
        
        map_skill("unarmed","shuaijiao"); 
                
        set("max_force",200+random(500));
        set("force",query("max_force"));
        set("force_factor",300);
        
        
        set("inquiry", ([
                
        ])); 
//      set("death_msg",CYN"\n$N说：“你的心真狠，连穷人都不放过。”\n"NOR);    
        set("chat_chance_combat", 100);
/*        set("chat_msg_combat", ({
             (: auto_smart_fight(20) :),
        }) );  */
        set("vendor_goods", ([
                __DIR__"obj/cow1":15,
                __DIR__"obj/cow2":20,
                __DIR__"obj/cow3":15,
                __DIR__"obj/cow4":20,
        ]) );

                  
        
        setup();
        carry_object("/obj/armor/cloth")->wear();    
}       
void init()
{
        add_action("do_vendor_list", "list");
}  