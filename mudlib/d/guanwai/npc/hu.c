 // banker.c
#include <ansi.h>
inherit NPC;
inherit F_BANKPAWNOWNER;
inherit F_VENDOR;
string ask_me(object who); 
void create()
{
        set_name("胡大掌柜", ({ "hu", "hu boss" }) );
        set("title", "鹰记新老板");
        set("gender", "男性" );
        set("age", 56);
        set("richness",1000000);
        set("str", 22);
        set("cor", 30);
        set("cps", 30);
        set("int", 26);
        set("per", 53);
        set("con", 24);
        set("spi", 30);
        set("kar", 25);
        set("long",
"原先的鹰记老板卜鹰神秘失踪以后，富甲关外的吕三爷手下的胡大掌\n柜便来管这家商号。\n"
                );
        set("chat_chance", 2);
        set("chat_msg", ({
                "胡大掌柜咧着嘴冲着你嘿嘿一笑。\n",
                }) );
        set("combat_exp", 600000);
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
        set_skill("parry", 100);
        set_skill("dodge", 100);
        set_skill("force", 100);
        setup();
        carry_object("/obj/armor/cloth")->wear();
        add_money("gold", 1);
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
        command("say 咦... 要打就真打吧，光是较量多没意思？");
        command("grin");
        kill_ob(me);
        return 1;
}
       
