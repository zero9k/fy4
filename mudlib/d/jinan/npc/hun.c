 // TIE@FY3
#include <ansi.h>
inherit NPC;
void create()
{
        set_name( "冷秋魂", ({ "leng qiuhun", "qiuhun" }) );
        set("long", "
朱砂帮的掌门大弟子，杀手书生西门千的徒弟。
\n");
        set("attitude", "friendly");
        set("title", HIM "粉面孟尝"NOR);
        set("max_gin", 500);
        set("max_kee", 500);
        set("max_sen", 500);
        set("age", 17);
        set("gender", "男性" );  
        set("str", 35);
        set("cor", 30);
        set("cps", 25);
        set("per", 40);
        set("combat_exp", 50000);
        set("chat_chance", 10);
        set("chat_msg", ({
"冷秋魂喃喃道：令师一收到那信就一去不返，莫非有什么不测？\n",
"冷秋魂向你问道：可否见到西门他老人家？\n"
        }) ); 
        set_skill("unarmed", 100+random(200));
        setup();
        carry_object("/obj/armor/cloth")->wear();
        add_money("coin", 5); 
}    
