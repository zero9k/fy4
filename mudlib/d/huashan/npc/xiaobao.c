 // hu.c
inherit NPC;
#include <ansi.h>
 
void create()
{
        set_name("小宝", ({ "xiao bao", "bao" }) );
        set("title", HIG"美少年"NOR);
        set("gender", "男性" );
        set("age", 23);
        set("str", 30);
        set("int", 25);
        set("cor", 30);
    set("long",
"他高大英俊，健壮，宽肩，细腰，浓眉，大眼，充满了男性的魅力。 \n"
    );
        set("combat_exp", 300000+random(300000));
        set("attitude", "friendly");
        set_skill("move",100);
        set_skill("dodge", 100);
        set_skill("force", 100);
        set_skill("unarmed", 100);
        set_skill("perception", 100);
        set("max_force", 500);
        set("chat_chance", 1);
        set("chat_msg", ({
                "小宝带着种诚恳而同情的态度说：“你最近又忙又累，吃得又少，怎么会不瘦？”\n", 
        }));
        setup();
        carry_object(__DIR__"obj/baocloth")->wear();
        carry_object("/obj/armor/boots")->wear();
}    
