 inherit NPC;
#include <ansi.h>
void smart_fight(); 
void create()
{
        set_name("严独鹤", ({ "yan duhe"}) );
        set("gender", "男性" );
        set("title",HIR"南方总管"NOR);
        set("age", 60+random(10));
                
        set("long",
                "他是个高大严肃的人，腰杆依旧挺直钢针般的须发也是漆黑的，只不过脸上\n的皱纹已很多，很深。\n你只有在看见他的脸时，才会觉得他已是老人。\n"
                );
        set("class","yinghe");
        set("combat_exp", 5500000);
        set("score", 900);
        
        set("fle",50);
        set("cor",40);
        set("cps",30);
        set("str",40);
        set("per",15);
        
        set("force",1500);
        set("max_force",1500);
        set("force_factor",100);
        set("atman",1500);
        set("max_atman",1500);
        set("mana",1500);
        set("max_mana",1500);
                
        set("no_busy",6);
        
        set("resistance/kee",30);
        set("resistance/gin",30+random(40));
        set("resistance/sen",30);
        
        set("chat_chance", 1);
        set("chat_msg", ({
                "严独鹤手握着剑柄，只觉得自己的手比剑柄还冷，不但手冷．他的心也是冷的。\n",
                }) );
        
        set_skill("perception",200);
        set_skill("iron-cloth", 200);
        set_skill("unarmed", 200);
        set_skill("dragonstrike", 200);
        set_skill("force", 200);
        set_skill("lingxi-zhi", 150);
        set_skill("spells",200);
        set_skill("parry",200);
        set_skill("kwan-yin-spells",200);
        set_skill("jin-gang",150);
        set_skill("move",400);
                
        map_skill("iron-cloth","jin-gang");
        map_skill("spells","kwan-yin-spells");
        map_skill("unarmed", "lingxi-zhi");
        map_skill("force", "bolomiduo");
        
        add_temp("apply/iron-cloth", 200);
         
        setup();
        set("max_kee", 500000);
        set("eff_kee", 9000);
        
        carry_object(__DIR__"obj/lan_cloth")->wear();
        
} 
/*
smart_fight()
{
        int j,i;
        object *enemy, who;
        who = this_object();
        enemy = this_object()->query_enemy();
        
        for(j=0;j<sizeof(enemy);j++)
        {
                if (enemy[j]->is_zombie() && random(2))
                {       who->cast_spell("ni");
                   return;
                }               
        }
        return;
}*/  
void win_enemy(object loser)
{
        say("霍天青答哈哈一笑说道：好说，好说。\n"); 
}        
