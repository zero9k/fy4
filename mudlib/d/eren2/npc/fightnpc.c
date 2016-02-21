#include <ansi.h>
#include <command.h>
#include <condition.h> 
inherit __DIR__"smart_npc"; 
void create()
{ 
        set("age",30+random(20));
        set("combat_exp", 6500000);
        set("dungeon_npc","test");
                
        set("max_atman", 1000);
        set("atman", 1000);
        set("max_mana", 1000);
        set("mana", 1000);
        set("max_force",2000);
        set("force",2000);
        set("force_factor",130); 
        set("str",42);
        set("cor", 40);
        set("cps", 40);
        set("agi",40);
        
        
        set("no_fly",1);
        
        set("resistance/gin",50);
        set("resistance/kee",50);
        set("resistance/sen",50);
        
        
//      setting up special NPC function: healer, defense, zombie-killer
//      defense_type: 1. xiaohun-sword; 2.xiaohun-whip;3 yue-strike;4 lingxi-zhi; 
        
        set("defense_type",random(4)+1);        
        set("zombie-killer",1);
        set("officer-killer",1); 
        set("chat_chance_combat", 100);
        set("chat_msg_combat", ({
                (: auto_smart_fight() :),    
        }) );
    
        CHAR_D->setup_char(this_object());
        auto_npc_setup("fighter",300,200,1,"/obj/weapon/","fighter_w","shortsong");
        setup();
        set_name("智能长老三代",({"fighter"}));
        set("title",YEL"探花楼"NOR);
        set("long", "这是探花楼用来愉悦客人的幻象，一般他都是傻站着被你杀。\n");
        
        carry_object("/obj/armor/cloth")->wear();
}       
