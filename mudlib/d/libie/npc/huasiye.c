#include <ansi.h>
inherit NPC;
int answer_robery();
int answer_di();
int answer_yang();  
void create()
{
        set_name("花四爷", ({ "hua siye","hua","siye" }) );
        set("long",
                "花四爷生前是洛阳首富，生得高大、肥壮。胖嘟嘟的一张脸上透着诚恳、
热心，似乎连一点机诈都没有。但此刻，他的鬼魂的脸上却布满了戾气，
令人感到不寒而栗。\n"); 
        set("attitude", "friendly");
        set("title", "花开富贵");
        set("age",53);
        set("cps", 77);
        set("agi", 60);
        set("class","wudang");
        
        set("combat_exp", 4000000+random(500000)); 
        set("force",1000);
        set("max_force",1000);
        set("force_factor",30);
        
        set_skill("unarmed",200);
        set_skill("taiji",200);
        set_skill("parry",400);
        set_skill("dodge",400);
        set_skill("five-steps",150);
        map_skill("unarmed","taiji");
        map_skill("dodge","five-steps");
        
        set("chat_chance", 1);
        set("chat_msg", ({
"花四爷凄惨的声音在你耳边回荡：狄青麟。。我花四做厉鬼也不会放过你。。。\n"
}) ); 
        set("inquiry", ([
                "劫镖案" : (: answer_robery :),
                "robery" : (: answer_robery :),
                "杨铮" : (: answer_yang :),
                "yang" : (: answer_yang :),
                "yang zheng" : (: answer_yang :),
                "狄青麟" : (: answer_di :),
                "di" : (: answer_di :),
                "di qinglin" : (: answer_di :),
        ])); 
        set("chat_chance_combat", 50);
        set("chat_msg_combat", ({
                (: perform_action("unarmed.nianzijue") :),
        }) );  
        setup(); 
        carry_object("/obj/armor/cloth")->wear();
} 
int is_ghost() { return 1; } 
int answer_di()
{
        object me;
        string msg;
        
        me=this_player();
    msg=HIR"花四爷怨毒地说：狄青麟为人阴狠，切不可轻信于他，切记切记。\n"NOR;
        me->set("libie/离别钩_花四爷的提醒",1);
//      if (me->query(marks/离别钩二))
//              msg+=HIR"花四爷说道：“
        message_vision(msg,me);
        return 1;
} 
int answer_robery()
{}
int answer_yang()
{}
