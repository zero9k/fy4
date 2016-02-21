 // weitianpeng.c
#include <ansi.h> 
inherit NPC; 
void create()
{
        set_name("孙秀青", ({ "sun xiuqin","sun" }) );
        set("gender", "女性" );
        set("title", "峨嵋派 侠女" );
        set("nickname", HIR"三英四秀之"NOR );
        set("long",
"风姿绰约，一把佩剑令她看上去愈发英气勃勃，不让须眉。\n"
                );
        set("attitude", "peaceful");
        set("age", 27);
        set("cps", 40);
        set("int", 50);
        set("per", 30);
        set("cor", 40);
        set("agi", 30);
        set("combat_exp", 100000);
        
        set("force", 500);
        set("max_force", 500);
        set("mana", 1000);
        set("max_mana", 1000);
        set("force_factor", 10);
        set("inquiry",  ([
                "叶孤城" : "叶城主的飞仙剑法想必有独步天下之处，师傅也很是佩服啊。\n",
                "master ye" : "叶城主的飞仙剑法想必有独步天下之处，师傅也很是佩服啊。\n",
                  "西门吹雪" :"唉，西门公子能否赢得了叶城主？这紫禁之战真让人挂怀。。\n",
                  "master ximen" :"唉，西门公子能否赢得了叶城主？这紫禁之战真让人挂怀。。\n",
        ])                      );
       set_temp("apply/armor",50);
        set_temp("apply/attack", 50);
        set("chat_chance", 1);
        set("chat_msg", ({
                "孙秀青眉头微皱，轻轻理了理被海风吹散的长发。。\n",
                }) ); 
        set_skill("sword", 100);
        set_skill("dodge", 100);
        set_skill("parry", 100);
        set_skill("move", 100);
        set_skill("sky-sword", 10);
        set_skill("liuquan-steps", 10);
        map_skill("dodge", "liuquan-steps");                
        map_skill("move", "liuquan-steps");                
        map_skill("sword", "sky-sword");
        map_skill("parry", "sky-sword");
                
        setup(); 
        carry_object("/obj/weapon/sword")->wield();
        add_money("gold",1);
        carry_object("/d/fugui/npc/obj/w_skirt3")->wear();
}    
