 // XXDER@FY3
inherit NPC;
#include <ansi.h>
void create()
{
    set_name("松实" , ({ "song shi","song" }) );
    set("nickname",HIY"啖松实"NOR);
    set("long", "乍一看去，这汉子敞衣赤足，眉目粗豪，但仔细打量，竟令人觉得他着实是个\n灵秀之人。\n");
        set("attitude", "friendly");
    set("age", 32);
        set("gender", "男性" );
        create_family("白云城",1, "狂生");
    set("per",40);
    set("combat_exp", 6000000);
        set("chat_chance", 1);
        set("chat_msg", ({
        "松实拈着黑子沉吟半晌，忽然双眉一轩，下了一着，轻轻吁了口气。\n",
        "松实剑眉微皱，轻叹一声：这一局劫中有劫，既有共活，又有长生，何得破解？\n",
        }) );
    set_skill("dodge", 200);
    set_skill("fall-steps", 200);
    set_skill("sky-sword", 200);
    set_skill("sword", 200);
    set_skill("unarmed", 100);
    set_skill("iron-cloth", 100);
    set_skill("henglian", 200);
    map_skill("iron-cloth","henglian");
    map_skill("sword","sky-sword");
        set("chat_chance_combat", 30);
        set("chat_msg_combat", ({
                (: perform_action, "sword.tianrenheyi" :),
        }) ); 
        setup();
    carry_object("/obj/armor/cloth")->wear();
        carry_object("/obj/weapon/sword")->wield();
}      
