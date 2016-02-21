 inherit NPC;
#include <ansi.h>
void smart_fight( object who); 
void create()
{
        set_name(HIR"红莲花"NOR, ({ "hong lianhua" }) );
        set("gender", "男性");
        set("age", 18);
        set("long",
"一个乾枯瘦小，却长着两只大眼睛的少年乞丐，手里拿着根竹竿，正瞧着你笑。\n"
);
        set("inquiry", ([
        ]) );
      
        set("chat_chance", 1);
        set("chat_msg", ({
                "红莲花喃喃道：“这里面一定有一个大阴谋，是什么呢？”\n",
        }) );
          
        set("attitude", "friendly");
        set("title","少年乞丐");
        set("score", random(50000));
        set("reward_npc", 1);
        set("difficulty",15);
        set("class","beggar");
        
        set("combat_exp", 4000000);        
        set("int", 30);
        set("cps", 50);
        set("spi", 30);
        set("fle",50);
        set("str",40);
        
        set("force", 1000);
        set("max_force",1000);
        set("force_factor", 90);
        set("atman", 100);
        set("max_atman", 100);
        set("mana", 500);
        set("max_mana", 500);
        
        set("resistance/gin",40);
        set("resistance/kee",40);
        set("resistance/sen",40);
        
        set("chat_chance_combat", 10);
        set("chat_msg_combat", ({
                (: smart_fight(this_object()) :),
        }) ); 
          
        set_skill("move", 200);
        set_skill("force", 200);
        set_skill("unarmed", 160);
        set_skill("parry", 150);
        set_skill("dodge", 150);
        set_skill("staff",150);
                        
        set_skill("qidaoforce", 150);
        set_skill("doggiesteps",200);
        set_skill("dragonstrike",170);
        set_skill("dagou-stick",170);
        
        map_skill("unarmed","dragonstrike");
        map_skill("force", "qidaoforce");
        map_skill("dodge","doggiesteps");
        map_skill("move","doggiesteps");
        map_skill("parry","dagou-stick");
        map_skill("staff","dagou-stick");
        
        setup(); 
        add_money("gold", random(8));
        carry_object(__DIR__"obj/bamboo_staff")->wield();
        carry_object("/obj/armor/cloth")->wear();
        if (!random(10)) carry_object(__DIR__"obj/staffbook");
} 
 
void smart_fight(object who)
{
        int i;
        object *enemy;
   enemy = this_object()->query_enemy();
        i = sizeof(enemy);
        if (i>1) {
                who->perform_action("staff.tianxiawugou");
                return;
        }
        who->perform_action("staff.banzijue");  
        return;
}   
