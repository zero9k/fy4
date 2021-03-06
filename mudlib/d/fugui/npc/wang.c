 inherit NPC;
inherit F_MASTER;
#include <ansi.h> 
void smart_fight();
void smart_busy();
void smart_attack(); 
int leave();
void create()
{
        set_name("王动", ({ "master wang", "master", "wang" }) );
        set("nickname", HIR"一飞冲天 鹰中王"NOR);
        set("gender", "男性" );
        set("apprentice_available", 10);
        set("class","fugui");
        set("reward_npc", 1);
        set("difficulty", 10);
        set("age", 36);
        set("int", 40);
        set("spi", 25);
        set("cor", 20);
        set("per", 40);
        set("attitude","heroism");
        set("max_force", 1000);
        set("force", 1000);
        set("force_factor",40); 
        set("long",
"他长得本不算难看，只不过显得面黄肌瘦，连说话都是有气无力的样\n子，象是已饿了好几天。直挺挺躺在床上,但并没有睡着，眼睛反而\n睁得很大。\n"
        );
        set("chat_chance", 2);
        set("chat_msg", ({
                "王动喃喃自语：郭大路那犟牛到底跑到哪里去了？\n",
        }) );
        set("inquiry",  ([
                "郭大路" : "哎...那头犟牛.....\n",
                "红娘子" : "哎....\n",
                "leave": (: leave :),
                ])                      ); 
        create_family("富贵山庄", 7, "庄主");
        set("combat_exp", 4000000);
        set("rank_nogen",1);
   
        set("chat_chance_combat", 50);
        set("chat_msg_combat", ({
                (: smart_fight() :),    
        }) ); 
                set_skill("perception",200);
        set_skill("move", 220);
        set_skill("henglian", 200);
        set_skill("parry", 180);
        set_skill("dodge", 250);
        set_skill("force", 200);
        set_skill("unarmed", 160);
        set_skill("skyforce",160);
        set_skill("literate", 150);
        set_skill("iron-cloth", 180);
        set_skill("spear", 200);
        set_skill("xuezhan-spear",180);
        set_skill("hawk-steps",220);
        set_skill("eagle-claw",280);
        
        map_skill("force", "skyforce");
        map_skill("parry","xuezhan-spear");
        map_skill("iron-cloth","henglian");
        map_skill("spear","xuezhan-spear");
        map_skill("dodge","hawk-steps");
        map_skill("move","hawk-steps"); 
        map_skill("unarmed","eagle-claw");      
        
        set_temp("apply/iron-cloth",110);
        
        set("ranks",({ "弟子","领班","小管家","管家","大管家",
                        CYN"总管"NOR,CYN"大总管"NOR,HIC"副庄主"NOR }));
        setup();
        carry_object(__DIR__"obj/oldcloth")->wear();
        carry_object(__DIR__"obj/spear");
} 
void reset()
{
                set("apprentice_available", 5);
} 
void attempt_apprentice(object ob)
{
        if( query("apprentice_available") ) 
        {
                if( find_call_out("do_recruit") != -1 )
                        command("say 慢著，一个一个来。");
                else
                        call_out("do_recruit", 2, ob);
        } 
        else 
        {
                command("say 我这个富贵山庄穷得很，已经收够了弟子，不能再收了。");
        }
} 
void do_recruit(object me)
{
        if( (string)me->query("gender") != "男性" )
          {
                command("say 我只收男弟子，你还是另谋高就吧！");
                return 0;
          }
        if(!me->query_temp("marks/青瓷瓶") && !me->query_temp("marks/金链子"))
          {
                switch ( random(2) )
                  {
                        case 0:
                                command("sigh\n");
                                command("say 如今我大难当头，这倒也罢了，可却拖累了我那林兄弟，\n身中奇毒，至今尚在昏迷之中，生死难料，哪能再连累小兄弟你啊．\n");
                                break;
                        case 1:
                                command("say 大路不见了，还是等知道了大路的消息再谈此事吧.\n");
                                break;
                  }
          }
        else 
          {
                if (me->query("combat_exp")<300000) {
                    command ("say 你技艺不精，强练我王动的霸道功夫，有害无益，还是练好本事再来我富贵山庄吧。\n");
                        return 0;
                }
                   command("say 你帮我了却心头大事，我就收你为徒吧！\n");
                me->set("class","fugui");
                command("recruit " + me->query("id") );
          }
}
                
int recruit_apprentice(object ob)
{
        if( ::recruit_apprentice(ob) )
                ob->set("class", "fugui");
                ob->add("betrayer",-1);
                ob->add("score",-5000);
        if(ob->query("betrayer") < 0) ob->set("betrayer",0);
        add("apprentice_availavble", -1);
} 
void killed_enemy(object who)
{
        command("say 何必自寻死路呢？\n");
} 
int accept_fight(object me)
{
        command("say 想打架？留着的力气帮我打扫一下院子吧！");
        command("sleep");
        return 0;
} 
void init()
{
        ::init();
        add_action("do_killing", "kill");
} 
int do_killing(string arg)
{       
        object player, victim, weapon;
        string name;
        if(!arg) return 0;
        player = this_player();
        if( objectp(victim = present(arg, environment(this_object()))) && living(victim))
        {
                name = victim->name();
                if( name == "王动")
                {
                        if (weapon = present("silver spear", this_object())) {
                                message_vision("$N皱皱眉头。\n", this_object());
                           message_vision("$N不知从哪里摸出一只亮银枪。\n", this_object());
                                weapon->wield();
                                call_out("do_unwie", 3);
                                }
                        return 0;
                }
                return 0;
        }
        return 0;               
} 
int do_unwie()
{
        if( !this_object()->is_fighting())
        {
                command("unwield spear");
                message_vision("$N揉揉眼、打个哈欠，立刻躺倒在床上。。。。\n", this_object());
                return 1;
        }
        else
                call_out("do_unwie", 3);
} 
int accept_object(object me, object ob)
{
        if(ob->query("name") == HIY"金链子"NOR)
        {
                command("touch " + me->query("id"));
                command("say 终于知道大路的消息了！\n");
                command("say 这位" + RANK_D->query_respect(me)+ "，大恩不言谢，只要你愿意，以后你就是我富贵山庄的人了.\n");
                me->set_temp("marks/金链子",1);
                return 1;
        }
        else
                tell_object(me,"王动说道：这不是我想要的。\n");
                return 0;      
} 
int leave() {
        if (this_player()->query("class")!="fugui") return 0;
        message_vision(CYN"$N笑笑，“这儿太穷，留不住人了。“\n"NOR, this_object());
        message_vision(CYN"$N说：人各有志，我不勉强，只是我的横练心诀你大概没机会体会了。\n"NOR,this_object());
        return 1;
} 
smart_fight()
{
        int i;
        object *enemy;
        enemy = this_object()->query_enemy();
        i = sizeof(enemy);
        while(i--) {
                if( enemy[i] && living(enemy[i]) ) {
                        if (!enemy[i]->is_busy()
                                && enemy[i]->query("combat_exp")<this_object()->query("combat_exp")) {
                                this_object()->smart_busy();
                        }
                        {
                                this_object()->smart_attack();
                        } 
                }
        }
} 
smart_busy() {
        this_object()->perform_action("dodge.yingjichangkong");
}
smart_attack() {
        this_object()->perform_action("spear.bafangfengyu");    
        }      
