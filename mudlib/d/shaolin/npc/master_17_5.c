 // Copyright (C) 1995, by Tie Yu and Daniel Yu. All rights reserved.
// This software can not be used, copied, or modified in any form without
// the written permission from authors.
inherit NPC;
inherit F_MASTER;
#include <ansi.h>
void create()
{
    set_name("心树", ({ "master shu", "master"}) );
    set("vendetta_mark","shaolin");
    set("gender", "男性" );
        set("reward_npc", 1);
        set("difficulty", 10);
    set("age", 64);
    set("per", 35);
    set("agi",30);
    set("int",10);
//    set("str",40+random(40));
//        set("force_factor",30);
    set("attitude","friendly");
    set("max_force", 1500);
    set("force", 1500);
    set("long", "少林寺七大高手之一。\n");
    create_family("少林寺", 17, "大师");
    set("student_title","长老");
    set("combat_exp", 6000000);
    set_skill("move", 200);
    set_skill("dodge", 200);
    set_skill("force", 200);
    set_skill("literate", 150);
    set_skill("zen",175);
    set_skill("chanting",200);
    setup();
    carry_object(__DIR__"obj/monk_cloth")->wear(); 
} 
void attempt_apprentice(object me)
{
    if(me->query_temp("won_master_yi")||me->query_temp("won_master_17"))
    {
        if (me->query("combat_exp")<1200000) {
           command("say 徒儿，我的功夫你还没练完吧！\n");  
                return 0;
                } 
        command("smile");
        command("recruit " + me->query("id") );
                me->delete_temp("won_master_yi");
        me->delete_temp("won_master_17");
        return;
    }
    else
    {
        command("shake");
    }
} 
int accept_fight(object me)
{
    if((me->query("family/family_name") == query("family/family_name") &&
        me->query("family/master_id") == query("id")) || me->query_temp("won_master_17"))
    {
        command("say 好，你赢了我，你就可以去找少林中更高深的师傅了！\n");
        return 1;
    }
    else
    {
        command("say 阿弥陀佛！贫僧武功低微，施主不要开这种玩笑。\n");
        return 0;
    }
}
void win_enemy(object loser)
{
    command("say 阿弥陀佛！徒儿还要努力呀！\n");
}
void lose_enemy(object winner)
{
    command("say 阿弥陀佛！你可以去找别的师傅去深造了。\n");
    winner->set_temp("won_master_17",1);
} 
void recruit_apprentice(object ob)
{
    if( ::recruit_apprentice(ob) )
        ob->set("class", "shaolin");
} 
void init()
{       
        ::init();
        add_action("do_killing", "kill"); 
} 
int do_killing(string arg)
{
    object player, victim;
    string id,id_class;
    player = this_player();
    if(!arg || arg == "") return 0;
    victim = present(arg, environment(player));
        if(!objectp(victim))
                return notify_fail("这里没有这个人。\n");
    if(living(victim))
    {
        id_class=victim->query("class");
        id=victim->query("id");
        if(id_class == "shaolin"&& userp(victim)&&player!=victim)
        {
            message_vision(HIW
"$N对$n喝道：阿弥陀佛,佛门清静之地,岂可妄起杀心?施主请恕老衲得罪了！\n"NOR, this_object(),player);
            this_object()->kill_ob(player);
            player->kill_ob(this_object());
            if (!player->is_busy()) player->start_busy(2);
            return 0;
        } 
    }
    return 0;
}
