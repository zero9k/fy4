 // bandit.c
#include <ansi.h>
inherit NPC;
void create() {
        set_name("土匪", ({ "tufei", "bandit"}) );
        set("long","一个满脸伤疤加横肉的家伙。\n");
        set("attitude", "aggressive");
        set("vendetta/authority",1);
        set("per", 1);
        set("intellgent",1);
        set("pursuer",1);
        set("no_return",1);
        set("combat_exp", 100000+random(4000000));
                set("bellicosity", 10000);
        set("chat_chance_combat", 50);
        set("chat_msg_combat", ({
                "山西土匪喝道：今天老子要钱又要命！！\n",
                "山西土匪笑道：贼娘的，去死吧！\n",
                                (: random_move :),
        }) );
        set("chat_chance", 60);
        set("chat_msg", ({
                (: random_move :),
        }) ); 
        set_skill("unarmed", 70+random(200));
        set_skill("axe", 70+random(200));
        set_skill("blade", 70+random(200));
        set_skill("hammer", 70+random(200));
        set_skill("sword", 70+random(200));
        set_skill("parry", 70+random(200));
        set_skill("dodge", 70+random(200));
        set_skill("move", 100+random(200)); 
        set_temp("apply/attack", 70);
        set_temp("apply/dodge", 70);
        set_temp("apply/armor", 70);
        set_temp("apply/damage", 30+random(400));
        set_temp("apply/move", 100); 
        setup();
} 
void init() {
    remove_call_out("hunting");
        if(!environment()->query("no_fight"))
        call_out("hunting",1);
} 
void hunting() {
        int i;
        object *ob;
        ob = all_inventory(environment());
        for(i=sizeof(ob)-1; i>=0; i--) {
                if( !ob[i]->is_character() || ob[i]==this_object() || !living(ob[i])) continue;
        if(ob[i]->query("vendetta/authority")) continue;
                kill_ob(ob[i]);
                ob[i]->fight(this_object());
        }
} 
void setup_bandit(string name, string armor, string weapon, string mark) {
        object armor_ob, weapon_ob;
        
        set("name", name);
        armor_ob = new(armor);
        if(objectp(armor_ob)) {
                armor_ob->move(this_object());
                armor_ob->wear();
        }
        weapon_ob = new(weapon);
        if(objectp(weapon_ob)) {
                weapon_ob->move(this_object());
                weapon_ob->wield();
        }
        set("area_mark", mark);
}   
