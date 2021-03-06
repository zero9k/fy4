 inherit NPC;
#include <ansi.h> 
void create()
{
        set_name("看风景的道姑", ({ "wandering taoist" }) );
        set("gender", "女性");
        set("age", 32);
        set("long",
"一个叫可尔的道姑，着一身黑色的道袍，优哉游哉地在湖畔看风景。\n"
);
        set("combat_exp", 21000);
        set("score", 200);
        set("class", "taoist");
        set("int", 30);
        set("cps", 30);
        set("spi", 30);
        set("mana", 300);
        set("max_mana", 300);
        set("mana_factor", 5); 
        set("inquiry", ([
                "三清湖": 
"在观里闷久了，出来散散心，三清湖是个好地方啊。\n",
        ]) );
        set("chat_chance_combat", 80);
        set("chat_msg_combat", ({
                (: cast_spell, "drainerbolt" :),
                (: cast_spell, "invocation" :),
        }) ); 
        create_family("三清宫", 7, "弟子"); 
        set_skill("move", 20);
        set_skill("force", 20);
        set_skill("spells", 30);
        set_skill("unarmed", 40);
        set_skill("notracesnow",30);
        set_skill("sword", 40);
        set_skill("parry", 50);
        set_skill("dodge", 30);
        set_skill("gouyee", 50);
        set_skill("necromancy", 30);    
        set_skill("snowshade-sword",30);
   
        map_skill("sword","snowshade-sword");
        map_skill("parry","snowshade-sword");
        map_skill("dodge","notracesnow");
        map_skill("spells", "necromancy"); 
        set_temp("apply/dodge", 25);
        set_temp("apply/armor", 25); 
        setup(); 
        add_money("coin", 10);
        carry_object(__DIR__"obj/sword1")->wield();
        carry_object(__DIR__"obj/tcloth")->wear(); 
}  
void init()
{       
        ::init();
        add_action("do_killing", "kill");
} 
int do_killing(string arg)
{
    object player, victim;
    player = this_player();
    if(!arg || arg == "") return 0;
    victim = present(arg, environment(player));
    if(!objectp(victim))
                return notify_fail("这里没有这个人。\n");
    if(living(victim))
    {
        if(userp(victim)&& victim!=player)
        {
            message_vision(HIW"$N对著$n喝道：难得出来散散心，竟然被你这小子坏了心绪!\n"NOR, this_object(), player);
            this_object()->kill_ob(player);
            player->kill_ob(this_object());
            player->start_busy(2);
            return 0;
        } 
    }
    return 0;
}  
