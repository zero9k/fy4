#include <ansi.h>
inherit QUESTNPC;
void create()
{
        set_name("花满楼", ({ "hua manlou","hua" }) );
        set("gender", "男性");
        set("age", 32);
    	set("nickname",WHT"鲜花满楼"NOR);
    	set("title","花家七倌");
        set("npc_difficulty",6);
        set("organization/性质","中立");
        set("long",
"鲜花满楼。花满楼对鲜花总是有种强烈的热爱，正如他热爱所有的生命一样。
\n"
               );  
        set("attitude", "peaceful");
        set("combat_exp", 50000000);
        set("chat_chance", 10);
        set("chat_msg", ({
              "花满楼说道：“只要你肯去领略，就会发现人生本是多么可
爱，每个季节里都有很多足以让你忘记所有烦恼的赏心乐事。”\n",
"花满楼道：“我有很充足的睡眠，有很好的胃口，有这间
很舒服的屋子，有一把声音很好的古琴，这些本已足够，何
况我还有个很好的朋友。”\n",
        }) );
                set("chat_chance_combat",60);
              set("chat_msg_combat", ({
                      (:perform_action,"unarmed.xinyoulingxi":)
              })      );
        set("force", 8000);
        set("max_force", 8000);
        set("force_factor", 80);
        set("max_gin",50000);
        set("max_kee",80000);
        set("max_sen",50000);
        set("fle",30);
        set("int",41);
        set("cor",40);
        set_skill("force", 200);
        set_skill("unarmed", 200);
        set_skill("dodge", 220);
        set_skill("parry",220);
        set_skill("lingxi-zhi",300);
   	set_skill("move", 300);
   	set_skill("iron-cloth",300);
   	set_skill("fengyu-piaoxiang",300);
   	set_skill("xisui",200);
   	map_skill("iron-cloth","xisui");
        map_skill("unarmed","lingxi-zhi");
        map_skill("dodge","fengyu-piaoxiang");
        map_skill("move","fengyu-piaoxiang");
        setup();
    carry_object("/obj/armor/cloth")->wear();
} 
mixed hit_ob(object me, object victim, int damage_bonus)
{
        int myexp,hisexp;
        myexp=me->query("combat_exp");
        hisexp=victim->query("combat_exp"); 
        if (random(myexp+hisexp)>hisexp&&(!random(2)))
        {
                victim->start_busy(10+random(10));
//                victim->remove_all_killer();
        return HIR "$n只觉得一麻，要穴被制，一动都不能动了。\n" NOR;
        }
}    

int accept_fight(object me)
{
	command("sigh");
        command("say 我一个瞎子，你又何苦，战胜了我又能说明什么呢？");
        return 0;
}