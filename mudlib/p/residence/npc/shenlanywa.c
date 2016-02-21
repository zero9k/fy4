 // banker.c
#include <ansi.h>
inherit NPC;
inherit F_BANKPAWNOWNER;
inherit F_VENDOR;
string ask_me(object who); 
void create()
{
        set_name("无名", ({ "waiter", "mentong" }) );
        set("title", "带剑人");
        set("gender", "男性" );
        set("age", 22);
        set("richness",1000000);
        set("str", 80);
        set("cor", 70);
        set("cps", 60);
        set("int", 50);
        set("per", 40);
        set("con", 30);
        set("spi", 20);
        set("kar", 10);
        set("long",
"只见这人影面目灰白，死眉死眼，彷佛毫无生趣，心头不觉一凛。\n"
                );
        set("chat_chance", 2);
        set("chat_msg", ({
                "无名掏出宝剑在溪边磨了磨。\n",
                }) );
        set("combat_exp", 90000000);
        set("fly_target",1);
        set("attitude", "friendly");
        set("env/wimpy", 70);
        set("max_atman", 1000);
        set("atman", 1000);             
        set("atman_factor", 3);
        set("max_force", 1000);
        set("force", 1000);
        set("force_factor", 3);
        set("max_mana", 1000);
        set("mana", 1000);
   set("mana_factor", 3);
//      set("price_index",0);
        set_skill("parry", 200);
        set_skill("sword", 200);
        set_skill("dodge", 200);
        set_skill("force", 200);
        set_skill("taiji-sword", 100);
        map_skill("sword","taiji-sword");
        map_skill("parry","taiji-sword");

        setup();
        carry_object("/obj/armor/cloth")->wear();
        carry_object("/p/residence/npc/obj/lusword")->wield();
  
} 
void init()
{
        ::init();
        
        add_action("do_value", "value");
        add_action("do_pawn", "pawn");
        add_action("do_sell", "sell");
        add_action("do_redeem", "redeem");
        add_action("do_vendor_list","list");
        add_action("do_loan","loan");
        add_action("do_convert", "convert");
        add_action("do_deposit", "deposit");
        add_action("do_balance", "balance");
        add_action("do_withdraw", "withdraw");
} 
int accept_fight(object me)
{
        command("say 不认好歹！！！");
        command("grin");
        kill_ob(me);
        return 1;
}
       
