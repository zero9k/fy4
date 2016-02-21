 // hunter.c
inherit NPC; 
void create()
{
        set_name("猎人", ({"hunter"}) );
        set("gender", "男性" );
        set("age", 36);
        set("agi",30);
        set("per", 10);
        set("str",30);
        set("long",
                "猎人正全神贯注地盯着前面的灌木丛。\n"
                );
        set("max_gin", 500);
        set("max_kee", 500);
        set("max_sen", 500);
        set("eff_gin", 500);
        set("eff_kee", 500);
        set("eff_sen", 500);
        set("gin", 500);
        set("kee", 500);
        set("sen", 500);
        set("combat_exp", 20000);
        set_skill("move", 50);
        set_skill("parry", 50);
            set_skill("dodge", 60);
        set_skill("unarmed",50);
            setup();
            carry_object(__DIR__"obj/woodaxe")->wield();
            carry_object("/obj/armor/cloth")->wear();  
}  
