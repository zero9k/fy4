#include <ansi.h>
inherit NPC;
inherit F_PAWNOWNER;
inherit F_VENDOR;
void create()
{
        set_name("狐狸精", ({ "foxgirl" }) );
        set("gender", "女性" );
        set("class","huashan");
        set("age", 29);
        set("title", "狐记当铺 老板娘");
        set("long","
狐狸精又名母狐狸，自然是老狐狸的夫人，老狐狸出了门，
狐狸窝当然交给母狐狸管理，她拥有天仙一样的容貌，鬼魅
一样的身影，没有人知道她内心真正的想法。想和狐狸精斗的
人，不管武功多高，都是一去不返。梦一般，谜一
样的狐狸精，迷死人不偿命的狐狸精。\n");
        set("combat_exp", 50000);
        set("attitude", "friendly");
        set("per",30);
        set("str",4);
        set("no_arrest",1);
        set_skill("unarmed",600);
        set("richness",100000);
        set_skill("dodge",200);
        set_skill("zhaixin-claw",50);
        map_skill("unarmed","zhaixin-claw");
        set("chat_chance_combat", 30);
        set("chat_msg_combat", ({
                (: perform_action, "unarmed.zhaixin" :),
        }) );
        
        setup();
        carry_object("/obj/armor/skirt", 
                        ([      "name"  :       HIY "五" + HIR "彩"NOR + "紧身裙",
                                "long"  :       "一件五彩丝编成的紧身裙\n",
                                "armor_prop/armor" :    3  ])   
                        )->wear();
} 
void init()
{  
        object ob;
        ::init();
        if ( interactive(ob = this_player()) && !is_fighting() ) 
           {
             remove_call_out("greeting");
             call_out("greeting", 1, ob);
           }
        add_action("do_value", "value");
        add_action("do_pawn", "pawn");
        add_action("do_sell", "sell");
        add_action("do_redeem", "redeem");
        add_action("do_vendor_list","list");
} 
void greeting(object ob)
{
        if ( !ob || environment(ob) != environment() ) return;
        if ( ob->query("gender") == "男性")
           {
             switch( random(3) ) 
                {
                  case 0:
                  message_vision("$N嗲声嗲气地说道：哎呦呦呦呦．．．这位"+RANK_D->query_respect(ob)+
"，您想典当些什么贵重物品？\n",this_object(),ob);       
                  break; 
                  case 1:
                  message_vision("$N上前拉住$n的手，笑咪咪地说道：这位"+RANK_D->query_respect(ob)+
"，您好象比上次来这儿时更高大威猛，英俊潇洒了！！\n",this_object(),ob);
                  break;
                  
                }
           }
        else
           {
             switch( random(3) ) 
                {
                  case 0:
                  message_vision("$N上前轻抚$n的粉脸，说道：这位"+RANK_D->query_respect(ob)+
"，您可真标致！嫉妒死我了！\n",this_object(),ob);
                  break;
             
                  case 1:
                  message_vision("$N上前拉住$n的手，笑咪咪地说道：这位"+RANK_D->query_respect(ob)+
"，您想典当些什么贵重物品？\n",this_object(),ob);
                  break;
                }
           }            
}      
