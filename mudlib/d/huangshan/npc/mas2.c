 inherit NPC;
inherit F_MASTER;
#include <ansi.h>
void smart_fight(); 
void create()
{
    set_name("柳无眉", ({ "master liu", "master","liu" }) );
    set("gender", "女性" );
    set("nickname", HIG"拥翠山庄少夫人"NOR);
    set("apprentice_available", 50);
    create_family("黄山派", 3, "掌门");
    set("long",
        "柳无眉黄山派掌门夫人\n"
        );
    set("age", 26);
    set("int", 30);
    set("per", 30);
    set("cor",  50);
    set("reward_npc", 1);
    set("difficulty", 30);  
       set("ill_boss",5);
    set("chat_chance", 1);
    set("chat_msg", ({
        name()+"嘀咕道：噫．．我的温玉怎么不见了？\n",
            }) );
    set("max_force", 2000);
    set("force", 2000);
    set("force_factor", 120);
    set("resistance/sen",80); 
    set("combat_exp", 6000000);
    
    set_skill("unarmed", 160);
    set_skill("sword", 180);
    set_skill("force", 180);
    set_skill("move", 160);
    set_skill("literate", 150);
    set_skill("dodge", 200);
    set_skill("perception", 200);
    set_skill("parry",160);
    set_skill("yunwu-strike", 160);
    set_skill("siqi-sword", 200);
    set_skill("xianjing", 250);
    set_skill("liuquan-steps", 200); 
    map_skill("unarmed", "meihua-shou");
    map_skill("sword", "siqi-sword");
    map_skill("force", "xianjing");
    map_skill("dodge", "liuquan-steps");
    map_skill("move","liuquan-steps");
    map_skill("parry","siqi-sword");
        
    set("chat_chance_combat", 100);
        set("chat_msg_combat", ({
               (: smart_fight() :),
        }) );
    
    set("ranks",({"弟子","小侠","少侠","大侠","奇侠","长老","元老","副掌门"}));
    setup();
    carry_object(__DIR__"obj/yellowcloth")->wear();
    carry_object(__DIR__"obj/yusword")->wield();
}
void reset()
{
        delete_temp("learned");
        set("apprentice_available", 20);
} 
void init()
{ 
        object ob;
        ::init();
        if( interactive(ob = this_player()) ) {
                remove_call_out("punish_betray");
                call_out("punish_betray",2 , ob);
        }
}
/*void punish_betray(object ob)
{
        if( ( ob->query("once_huangshan")) && ( (ob->query("class"))!= "huangshan"))
          {      
                tell_object(ob, YEL"\n柳无眉对你冷笑道：“你既然判出本门，就不配再有本门的武功！”\n"NOR);              
                message("vision", "柳无眉对"+ ob->name() +"冷笑道：“"+ ob->name() + "！ 你既然判出本门，就不配再有本门的武功！\n", environment(ob), ob);
           tell_object(ob, HIW"柳无眉手一扬，一支牛毛般细小的飞针射入你手臂！\n"NOR);              
                message("vision", HIW"柳无眉对着"+ ob->name() +"手一扬，射出一支牛毛般细小的飞针！\n"NOR, environment(ob), ob);
                
                if (ob->query_skill("liuquan-steps",1)) ob->delete_skill("liuquan-steps",0);
                if (ob->query_skill("qiusheng-blade",1)) ob->delete_skill("qiusheng-blade",0);
                if (ob->query_skill("yunwu-strike",1)) ob->delete_skill("yunwu-strike",0);
                if (ob->query_skill("siqi-sword",1)) ob->delete_skill("siqi-sword",0);
                tell_object(ob, HIR"你只觉血脉一阵逆流，武功全失！！\n"NOR);
                ob->delete("once_huangshan");
          }
} */ 
void attempt_apprentice(object ob)
{
    if( query("apprentice_available") ) {
        if( find_call_out("do_recruit") != -1 )
            command("say 慢著，一个一个来。");
        else
            call_out("do_recruit", 2, ob);
    } else {
        command("say 本庄主今天已经收了二十个弟子，不想再收徒了。");
    }
}
void do_recruit(object ob)
{
		  if(ob->query_skill("siqi-sword")){
                command("hmm");
                command("say 江湖虽然险恶，你这身功夫已经足够应付，好自为之吧。");
                return;
                }
    if( (string)ob->query("gender") != "女性" )
    {      command("say 我只收女弟子，你还是去拜我的外子吧！");
    }
    else { 
        command("smile");
        command("say 好徒儿，还不来见过师父？");
        command("recruit " + ob->query("id") );
    }
}
int recruit_apprentice(object ob)
{
    if( ::recruit_apprentice(ob) )
        ob->set("class", "huangshan");
    add("apprentice_availavble", -1);
}
int accept_fight(object me)
{
                return 0;
} 
int accept_object(object who, object ob)
{
        if(ob->query("id") == "old jade")
        {
        command("smile");
        command("thank "+who->query("id"));
        if((int)ob->query("max_cure") < 5)
        call_out("give_pena",3,who);
        else
        call_out("give_reward",3,who);
        return 1;
        } 
}
int give_reward(object who)
{
if(environment() != environment(who)) return 1;
if(!who->query("m_success/找玉石"))
        {
                who->set("m_success/找玉石",1);
                who->add("score",700); 
        }
return 1;
} 
int give_pena(object who)
{
if(environment() != environment(who)) return 1;
command("say 你竟然敢偷用本夫人的玉石？！！\n");
kill_ob(who);
who->kill_ob(this_object());
return 1;
}  
smart_fight()
{
        int i;
        object *enemy, who,count,j;
        who = this_object();
        enemy = this_object()->query_enemy();
        i = sizeof(enemy);
        if (who->query("kee")<8000) {
                count=0;
                for (j=0;j<sizeof(enemy);j++) {
                        if (enemy[j]->is_zombie()) count++;
                }
                if (count>=3)
                        command("perform zombie-wp1");
        }
        if (!random(3)) who->perform_action("sword.siqi");
        return;
}       
