#include <ansi.h>
#include <command.h>
inherit "/d/taiping/npc/smart_npc"; 
void create()
{ 
        set_name("血奴",({"xuenu"}));
        set("title",YEL"鹦鹉楼"NOR);
        set("long", "她并不是赤裸着的。她还穿着一半衣裳——既不是上面一半，也不是下面一半。她
右边半身衣裳，穿得很整齐，左边半身却是赤裸的。她在耳上戴着珠环，有半边脸
上抹着脂粉，发上还有珠翠满头。--只有右边。她的左半身看来就像是个初生的
婴儿。她的笑容温柔如春风，美丽如春花，又像是春水般流动变幻不定。她的瞳孔
深处，却冷如春冰。");
        set("age",20);
        set("combat_exp", 9000000);
        set("attitude", "friendly");    
        
        set("no_busy",10);
        set("max_atman", 600);
        set("atman", 600);
        set("max_mana", 600);
        set("mana", 600);
        set("max_force",1500);
        set("force",1500);
        set("force_factor",130); 
        set("str",40);
        set("cor", 40);
        set("cps", 40);
        set("agi",40);
        set("fle",40);
        
        set("resistance/gin",30);
        set("resistance/kee",30);
        set("resistance/sen",30);
        
//      setting up special NPC function: healer, defense, zombie-killer
//      defense_type: 1. xiaohun-sword; 2.xiaohun-whip;3 yue-strike;4 lingxi-zhi;
        
//      set("defense_type",random(2)+1);        
//      set("zombie-killer",1);
//      set("officer-killer",1);
// set("dungeon_npc","check");
        
        CHAR_D->setup_char(this_object());
        auto_npc_setup("wang",300,200,0,"/obj/weapon/","fighter_w","nine-moon-claw",2);
        setup();
        carry_object(__DIR__"obj/redcloth")->wear();
        
} 
int accept_object(object who, object ob)
{
        if( ob->name()==HIR"红石"NOR) {
                if (!who->query("m_killer/谭天龙") && !who->query("m_killer/谭天虎")
                        && !who->query("m_killer/谭天豹") && !who->query("parrot/刺客")){             
                command("say 你从哪儿捡来的红石头？");
                return 0;
                } 
                call_out("event1",1,who,0);
                who->set("parrot/血奴表演",1);
                return 1;
        }        
        return 0;
}     
string *event1_msg=     ({
        
        WHT"\n\n  血奴的脸色骤然变了，就像是忽然被人用力抽了一鞭子。\n",
        
        WHT"  带刺的鞭子！\n"NOR, 
        GRN"  “这不是石头，这就是魔血……”她疯狂般嘶喊。她又在疯狂般大笑，美丽的脸
  上忽然起了种无法描述的变化。\n"NOR, 
        GRN"  她的脸忽然变成种令人作呕的惨绿色，柔软的嘴唇开始扭曲，温柔的眼波中露出
  狞恶的表情。\n"NOR,
        
        GRN"  她的双腿和双手关节忽然向外扭曲，结实修长的腿张开了，露出了……\n"NOR, 
        GRN"  她在用力捏弄自己的奶头，“来，快来，用力……”\n"NOR, 
        HIG"  她忽然吐了出来，吐出一种浓绿色的，带着恶臭的稠汁。\n"NOR, 
        GRN"  可是她的脸忽又变得温柔而美丽，呻吟着道：“不要，我痛……”\n"NOR, 
        GRN"  呻吟般的声音忽又变成厉吼，她的脸也突又变得可怕而狞恶。\n"NOR, 
        GRN"  这两种表情不断的在她脸上交替变幻着，喉咙里有时呻吟，有时低沉。\n"NOR, 
        GRN"  那绝不是同一个人能具有的表情，也绝不是同一个人能发得出的声音。\n"NOR, 
        WHT"  然后她忽然跳起来，她的脸突然扭转，几乎扭到背后。\n"NOR, 
   GRN"  她的背对着$N，脸也对着$N，嘴里的浓汁还在不停往外流。\n"NOR,
        
        GRN"  屋子里竟然充满恶臭，就像忽然变成了个地狱。\n"NOR, 
        RED"  墙壁图画上的血鹦鹉身边的十三只怪鸟，竟已赫然少了一只。\n"NOR,
        
        WHT"  。。。。。。。。。。\n"NOR, 
        WHT"  。。。。。。。\n"NOR,
        
        WHT"  。。。。\n"NOR, 
        GRN"  呻吟声越来越轻，越来越弱。\n"NOR, 
        GRN"  血奴扭曲的面目和四肢逐渐恢复正常，但是她的人却已完全虚脱。\n"NOR, 
        GRN"  她的鼻尖在流着汗，全身都在流着汗，瞳孔已因兴奋后的虚脱而扩散。\n"NOR, 
        GRN"  她还在不停的呻吟喘息，然后她脸上就忽然露出种甜蜜而满足的微笑。\n"NOR, 
        GRN"  她在看着$N，不停的低语道：“你真好，你真好……”\n"NOR, 
});  
void event1(object me, int count)
{
        if (environment(me)!=environment(this_object()) 
                || this_object()->is_fighting())        return;
        message_vision(event1_msg[count]+"\n",me);
        if(++count==sizeof(event1_msg))
        {
                message_vision(RED"\n\n   再看墙上的图画，围绕在血鹦鹉身旁的怪鸟，已经又变成十三只。\n\n\n"NOR,this_object(),me);
                return;
        }
        else call_out("event1",1,me,count);
        return ;
}  
/*
void init() {
        
        object ob;
        ::init();
        add_action("do_answer","answer");
        if( interactive(ob = this_player()) && !is_fighting() ) {
                remove_call_out("greeting");
                call_out("greeting", 1, ob);
        }
}   
*/
