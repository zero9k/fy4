#include <ansi.h>
//inherit "/d/taiping/npc/smart_npc";
inherit NPC;
inherit F_VENDOR; 
int kill_him(); 
void create()
{
        set_name("胡掌柜",({"hu zhanggui","hu","zhanggui"}));
        set("title","肉铺");
        set("long","这人满脸横肉，留着一把大胡子，正是肉铺的胡掌柜。他围着一身油腻腻的围
裙，正在柜台后面切肉。胡掌柜今年四十多，两年前从内地买了个姑娘回来做
媳妇，虽说女人看上去死心塌地的，新近还怀了孩子，胡掌柜总是疑神疑鬼的
怕她哪天会不辞而别。\n");
        set("gender","男性");
        set("attitude", "friendly");
        set("group","citizen");
        
        set("combat_exp",4000000);  
        set("age",42);
                
        set("int",40);
        set("cor",40);
        set("cps",40);
        
                set("vendor_goods", ([
                "/d/guanwai/npc/obj/wineskin": 50,
               "/obj/food_item/chicken_leg" : 50,
                "/d/xinjiang/npc/obj/milk": 50,
                "/d/guanwai/npc/obj/sheep_leg":50,
        ]) );

        set_skill("unarmed",200);
        set_skill("dodge",150);
        set_skill("parry",160);
        set_skill("force",180);
        set_skill("move",200); 
                
        set("max_atman",random(1000));
        set("atman",query("max_atman"));
        set("max_mana",random(500));
        set("mana",query("max_mana"));
        set("max_force",1000+random(500));
        set("force",query("max_force"));
        set("force_factor",100);
        
        set("resistance/kee",random(30));
        set("resistance/gin",random(30));
        set("resistance/sen",random(30));
        
        set("inquiry", ([
                "强盗" : "镇外有强盗，镇内也有强盗，这日子可怎么过下去呀！\n",
                "镇外的强盗" : "还不就是龙虎寨的那些山贼么！\n",
                "镇内的强盗" : "不能说，不能说呀。。\n",
                "江湖五毒"      :               (: kill_him :),
                   "采花蜂"        :               (: kill_him :),
        ]));
        
        set("death_msg",CYN"\n$N悔恨地说：“报应，报应啊。”\n"NOR);    
        set("nb_chat_chance", 100);
        set("nb_chat_msg_combat", ([
                        10: name()+"叫道：“来人啊，强盗打劫店铺啦！”\n",
        ]) );           
        set("chat_chance_combat", 100);
        set("chat_chance",1);
        set("chat_msg",({
                "胡掌柜说：“好汉需好酒，好酒需好肉，好肉就找我老胡。”\n",
        }) );                   
        
        setup();
        carry_object("/obj/armor/cloth")->wear();    
    
}  
void init()
{       
        object ob; 
        ::init();
        if( interactive(ob = this_player()) && !is_fighting() ) {
                remove_call_out("greeting");
                call_out("greeting", 1, ob);
        }
        add_action("do_vendor_list", "list");
} 

int kill_him()
{
        object me, another;
        object ob;
        
        ob=this_object();
        me = this_player();
        if (this_object()->is_fighting()) {
                tell_object(me,"胡掌柜现在没空回答你。\n");
                return 1;
                }
        message_vision(CYN"$N脸上忽然露出种冷淡而诡秘的微笑，这种笑容本不该出现脸上的。\n"NOR,this_object());
        message_vision(CYN"$N冷冷笑着道：“既然你知道了，就不能让你再活着出去。\n",this_object());
        another = new(__DIR__"yunzhonghe");
        another->move(environment(this_object()));
        destruct(ob);
        return 1;
}  
void greeting(object ob)
{
        object hu,blade,groom;
        
        if( !ob || environment(ob) != environment() ) return;


        hu=this_object();
        if (ob->query("wanma/义助小媳妇") && !ob->query("wanma/和胡掌柜")) {
                message_vision("$N抬头朝$n一看，刷地一下从架子上抽出一把明晃晃的杀猪刀。\n",hu,ob);
                if (ob->query("gender")=="女性") {
                        command("say 女人家不学好，却教我媳妇儿乱花钱，快走快走，这儿的东西不卖给你。");
                        groom = find_object(AREA_BIANCHENG"road4");
                        if(!objectp(groom)) groom = load_object(AREA_BIANCHENG"road4");
                        ob->move(groom);
                        message_vision(HIY "\n$N被$n踢了出来！\n"NOR, ob,this_object());
                }
                else {
                        command("say 大胆，竟敢和我媳妇眉来眼去的勾搭，不教训你一下不成！");
                        if (!hu->query_temp("weapon")) {
                                blade=new(__DIR__"obj/pblade");
                                blade->move(hu);
                                command("wield blade");
                        }
                        fight_ob(ob);
                        ob->fight_ob(hu);
                        ob->set_temp("wanma/胡掌柜杀",1);
                }
        } 
}  
void win_enemy(object loser){
        object groom;
        
        command("puke");
        groom = find_object(AREA_BIANCHENG"road4");
        if(!objectp(groom)) groom = load_object(AREA_BIANCHENG"road4");
                loser->move(groom);
        message_vision(HIY "\n$N被$n踢了出来！\n"NOR, loser,this_object());
}  
void lose_enemy(object winner){
        command("say 你狠，咱们骑驴看唱本，走着瞧。\n");
        winner->delete_temp("wanma/胡掌柜杀");
}      
