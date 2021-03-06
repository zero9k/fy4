 // Copyright (C) 1995, by Tie Yu and Daniel Yu. All rights reserved.
// This software can not be used, copied, or modified in any form without
// the written permission from authors.
inherit NPC;
inherit F_MASTER;
#include <ansi.h>
void create()
{
    set_name("上官金虹", ({ "master shangguan", "master", "master shang" }) );
    set("nickname", RED"龙凤双环"NOR);
    set("gender", "男性" );
    set("class", "assassin");
    set("age", 44);
    set("cor", 40);
    set("cps", 30);
    set("int", 30);
    set("per", 30);
        set("reward_npc", 1);
        set("difficulty", 30);
    set("attitude","friendly");
    set("max_force", 5000);
    set("force", 5000);
    set("force_factor",80+random(50));
    set("max_mana",2000);
    set("mana",2000); 
    set("long",
        "
一个人正站在桌子前翻阅着，不时用朱笔在卷宗上勾划，批改，嘴里偶而会露出一丝
得意的笑容。他是站着的。他认为一个人只要坐下来，就会令自己的精神松弛，一个
人的精神若松弛，就容易造成错误。
\n"
        );
    create_family("金钱帮  ", 1, "帮主");
       set("rank_nogen",0);  
    set("combat_exp", 10000000);
    set("score", 200+random(200000));
    set("agi",25);
    set("int",30);
    set("chat_chance_combat", 50);
    set("chat_msg_combat", ({
        (: perform_action, "hammer.longfengshuangfei" :),
            }) );
    set("skill_public",1);
    set_skill("move", 120);
    set_skill("parry", 160);
    set_skill("dodge", 120);
    set_skill("force", 220);
    set_skill("literate", 140);
    set_skill("jingxing",200);
    set_skill("hammer", 220);
    set_skill("flame-strike",180);
    set_skill("unarmed",160);
    set_skill("jinhong-steps",160);
    set_skill("longfenghuan",200);
    set_skill("yoga",120);
    map_skill("dodge", "jinhong-steps");
    map_skill("hammer", "longfenghuan");
    map_skill("parry", "longfenghuan");
    map_skill("force", "jingxing");
    map_skill("unarmed", "flame-strike");
     
/*    set("ranks",({"帮众","副堂主","堂主","副坛主","坛主",
                      "副舵主","舵主","护法","大护法",
                      "长老","大长老","副帮主"}));
    set("rank_levels",({ 32000,64000,128000,256000,512000,
                             1024000,1536000,2304000,3456000,
                             5187000,26244000 }));  */
    setup();
    carry_object(__DIR__"obj/whitecloth")->wear();
    carry_object(__DIR__"obj/longfenghuan")->wield();
} 
void attempt_apprentice(object me)
{
         if ( me->query("class")!="assassin") {
                message_vision("$N摇了摇头：本帮主要考虑的事很多，要拜师你还是去找荆无命吧。\n",this_object(),me);
                message_vision("$N淡淡地说：若你对本帮忠心耿耿，我以后自然会指点你一二。\n",this_object()); 
                return 0;
                }
         if ((int)me->query("combat_exp") < 1024000 ) {
                message_vision("$N对$n说道：等你当了本帮的舵主再说吧？\n",
                           this_object(),me);
                return 0;
                }
         command ("say 拜师却也免了，想学什么就说吧，我会抽空传你几招的．");
} 
/*void recruit_apprentice(object ob)
{
        if( ::recruit_apprentice(ob) )
                ob->set("class", "assassin");
}*/  
int recognize_apprentice(object ob){
        if(ob->query("class")=="assassin") {
           if( (int)ob->query("combat_exp") > 1024000 ) return 1;
           else message_vision("$N对$n说道：等你当了本帮的舵主再说吧？\n",
                        this_object(),ob);
        }
        return 0; 
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
        if(id_class == "assassin"&& userp(victim)&& player!=victim)
        {
            message_vision(HIW
"$N喝道：在我面前杀我帮的弟子，不想活了！\n"NOR, this_object());
            this_object()->kill_ob(player);
            player->kill_ob(this_object());
            if (!player->is_busy()) player->start_busy(2);
            return 0;
        } 
    }
    return 0;
}
