 // banker.c
#include <ansi.h> 
inherit NPC;
inherit F_BANKPAWNOWNER;
inherit F_VENDOR;
string ask_me(object who); 
void create()
{
        set_name("小伙计", ({ "huoji" }) );
        set("title", "临时帮忙的");
        set("gender", "男性" );
        set("age", 16);
        set("richness",1000000);
        set("long",
"近来鹰记生意太好，卜鹰请来专门帮客官存银子的。\n"
                ); 
        set("combat_exp", 2000);
        set("attitude", "friendly");
        set("env/wimpy", 70);
        setup();
        carry_object("/obj/armor/cloth")->wear(); 
        add_money("coin", 1);
}
void init()
{
        ::init();
        add_action("do_deposit", "deposit");
}
