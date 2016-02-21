 //Created by justdoit at May 2001
//All Rights Reserved ^_^ 
inherit NPC;
#include <ansi.h>
void create()
{
        set_name("老掌柜", ({ "old zhanggui", "zhanggui" }) );
        set("gender", "男性" );
        set("age", 69);
        set("long","这位船行的老掌柜正在忙着噼哩啪啦打着算盘算账。\n");
        set("combat_exp", 500000);
        set("attitude", "friendly");
        set("per",30);
        set_skill("unarmed",200);
        set_skill("dodge",200);
        setup();
        carry_object("/obj/armor/cloth")->wear();
} 
void init()
{       
        object ob;
        ::init();
        if ( interactive(ob = this_player()) && !is_fighting() ) 
           {
             remove_call_out("greeting");
             call_out("greeting", 1, ob);
           }
} 
void greeting(object ob)
{
        if( !ob || environment(ob) != environment() ) return;
        switch( random(10) ) 
              {
                case 0:
                message_vision("$N用他的老花眼看了$n一眼，说道：欢迎这位"+RANK_D->query_respect(ob)+
                               "光临本船行！\n",this_object(),ob);
                break;
                
                case 1:
                message_vision("$N轻轻捶了捶发酸的肩膀说道：这位"+RANK_D->query_respect(ob)+
                          "想要租什么样式的船？\n",this_object(),ob);
                break;
                
                case 2:
                message_vision("$N说道：如要询问租船的价格，请参看本店的价格牌．．．\n",this_object(),ob);
              }
} 
int accept_object(object who, object ob)
{
        int val;
        object paper; 
//        message_vision(CYN"$N说：风浪太大，航船暂停。\n"NOR,this_object());
//        return 0;
      val = ob->value();
    if ( val < 5000 ) 
           {
         message_vision("$N皱了下眉头道：这位客官，钱不够啊。\n",this_object());
             return 1;
           }
        paper = new(__DIR__"obj/contract");
    if ( val>=5000 && val < 500000 ) paper->set("shiptype", 0);
    else if ( val >=500000 && val < 5000000 ) paper->set("shiptype", 1);
    else if ( val >=5000000) paper->set("shiptype", 2);
        paper->set("employer",who->query("name"));      
        paper->move(who);
        say( "老掌柜说道：多谢这位" + RANK_D->query_respect(who) +
             "光顾本船行，请拿这张租约到码头给老狐狸。\n");
        return 1;
}      
