#include <ansi.h>
inherit QUESTNPC;
#include <ansi.h>
void crazy();
void create()
{
        set_name("傅红雪", ({ "fu hongxue","fu" }) );
        set("gender", "男性");
        set("age",26);
        set("nickname", HIC"天涯·明月·刀"NOR);
        set("title", "边城浪子");
        set("combat_exp", 50000000);
        set("long",
                "他脸上的轮廓英俊而突出，但却像是远山上的冰雪塑成的。\n",
        );
        set("cor",40);
//        set("quest_npc",1);
	set("organization/性质","邪");
	set("npc_difficulty",6);
//	set("no_busy",6);
	set("attitude", "peaceful");
        set("str",100);
        set("cps",31);
        set("max_force",4000);
        set("force",4000);
        set("force_factor",80);
        set("max_kee",100000);
        set("max_gin",80000);
        set("max_sen",80000);
        set_skill("force",200);
        set_skill("demon-force",200);
        set_skill("parry", 200);
        set_skill("blade",200);
        set_skill("dodge",300);
        set_skill("demon-steps",200);
        set_skill("demon-blade",200);
        map_skill("dodge","demon-steps");
        map_skill("blade","demon-blade");
        map_skill("parry","demon-blade");
        map_skill("force","demon-force");
        set("chat_chance", 90);
        set("arrive_msg","走了过来，左脚先迈出一步，右脚才慢慢的拖上去");
        set("leave_msg","走去，左脚先迈出一步，右脚才慢慢的拖上去");
        set("chat_msg", ({
        (: random_move :),
        (: random_move :),
        (: random_move :),
        (: crazy :),
         "傅红雪脸上露出了极其痛苦的表情，喃喃自语道“报仇，报仇！！”\n",
        }) );    
        set("chat_chance_combat", 90);
        set("chat_msg_combat", ({
                (: perform_action,"dodge.lianhuanbabu"  :),
          	(:perform_action,"blade.tiandirenmo" :),
        }) );
        setup();
        carry_object("/obj/armor/cloth")->wear();
        carry_object(__DIR__"obj/blackblade")->wield();
}

void init()
{
	object ob;
        ::init();
        if( userp(ob = this_player()))
        if( (string)ob->name() == "翠浓" )
        {
                remove_call_out("greeting");
                call_out("greeting", 1, ob);
        }
}

void remove_effect(int exp);
//可以巧杀他，不能用busy
void crazy()
{       int exp;
        if (!random(50))
        {
                message_vision("傅红雪的脸忽然扭曲变形，口中吐出白沫。浑身上下都开始痉挛。他眼中露出了无比痛苦的表情，
他似乎想说什么，却一个字也说不出来。。。。。。",this_object());
                exp=this_object()->query("combat_exp");
                this_object()->delete("no_busy");
        	this_object()->start_busy(30);
                this_object()->set("combat_exp",25000000);
                call_out("remove_effect",30,exp);
                return;
        }
        return;
} 
void remove_effect(int exp)
{
        message_vision("傅红雪的癫痫终于发作完了。\n",this_object());
        this_object()->stop_busy();
        this_object()->set("no_busy",6);
        this_object()->set("combat_exp",exp);
}    
int accept_fight(object me)
{
	command("heng");
        command("say 我的刀不是拿来看的。");
        return 0;
}

void greeting(object me)
{
	int exp;
        if(!me ||environment(me)!=environment())
                return ;
	        message_vision("傅红雪用奇怪的表情看着翠浓，他的脸忽然扭曲变形，眼中露出了无比痛苦的表情，好像
想起了什么痛苦的事情，他似乎想说什么，却又说不出一句话。\n只见他口中吐出白沫，浑身上下都开始痉挛。。。。。。\n",this_object());
                exp=this_object()->query("combat_exp");
                this_object()->delete("no_busy");
        	this_object()->start_busy(15);
                this_object()->set("combat_exp",25000000);
                call_out("remove_effect",30,exp);
                return;
        return ;
}  