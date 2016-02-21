 inherit NPC;
inherit F_VENDOR;
#include <ansi.h>
void create()
{
        set_name("芳儿", ({ "fang" }) );
        set("gender", "女性" );
        set("age", 29);
        set("title", HIY "千"+ HIR "面" + HIM "娘" + HIC"子"NOR);
        set("long",
                "这位年轻风骚的老板正对你狂抛媚眼儿。\n");
        set("combat_exp", 50000);
        set("attitude", "friendly");
        set("per",30);
        set("vendor_goods", ([
                __DIR__"obj/yanzhi":10,
                __DIR__"obj/bao":10,
                __DIR__"obj/huabag":10,
                __DIR__"obj/pozhi":10,
        ]) );
        set_skill("unarmed",200);
        set_skill("dodge",200);
        setup();
        carry_object(__DIR__"obj/wch_skirt")->wear();
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
void greeting(object ob)
{
        if( !ob || environment(ob) != environment() ) return;
        switch( random(5) ) {
                case 0:
message_vision("$N笑着说道：这儿什么都有，买些回去给你的心上人吧。\n",this_object(),ob);
                        break;
                case 1:
message_vision("$N笑咪咪地说道：这位"+RANK_D->query_respect(ob)+
"要买什么？\n",this_object(),ob);
                        break;
                case 2:
message_vision("$N用一种奇异的眼神望着$n。\n",this_object(),ob);
        }
} 
int accept_object(object who, object ob)
{
        string tmpname;
        string err;
        object newmask;
        object rope,*obj;
        int i;
        string gender, name, id;
        string newfile;
        if(ob->query("skull")){
                if(!who->query("m_success/武当掌门的秘密")) {
                        return 0;
                }
                /*obj = all_inventory(ob);
                for(i=sizeof(obj)-1;i>=0;i--)  {
                        if(obj[i]->query("silk")) {
 give out a mask
                              destruct(object[i]);*/
                         else {       newmask = new(__DIR__"obj/headmask");
                                newmask->move(who);
                        message_vision("$N悄悄的塞给$n一样东西。\n",this_object(), who);
                                return 1;
                        }
                }
               // command("say 你给我这个有什么用？我需要用五彩绳子烧成的灰才可以从这头骨作出面具。\n");
                //return 0;
                
        
        if(ob->name() != "皱皱的破纸片") return 0;
        tmpname = "/open/tempmask"+sprintf("%d",time());
        message_vision("$N对着$n表情僵硬的笑了笑．．．\n",this_object(),who);
   gender = (string)ob->query("targetgender");
        name = (string)ob->query("targetname");
        id = (string)ob->query("targetid");
        if( !stringp(id) ) return 0;
        if( !find_living(id)) return 0;
        if( !stringp(gender)) return 0;
        if( !stringp(name) ) return 0;
        if ((string)gender != "男性" && (string)gender != "女性")
                return 0;
        id = capitalize(id);
        newfile = read_file("/obj/item/orig_mask.o");
        if( !newfile) return 0;
        seteuid(ROOT_UID);
        newfile = replace_string( newfile, "男性", gender);
        newfile = replace_string( newfile, "maskman", id);
        newfile = replace_string( newfile, "蒙面人", name);
        if( !newfile) return 0;
        tmpname = tmpname + who->query("id") + ".c";
        if( !write_file(tmpname, newfile, 1))
//      if(!write_file(tmpname, newfile, 1))
                return 0;
        newmask = new(tmpname);
        if (! rm( tmpname))
                {
                destruct(newmask);
                return 0;
                }
        if( !newmask) return 0;
        newmask->move(who);
        message_vision("$N悄悄的塞给$n一样东西。\n",this_object(), who);
        seteuid(getuid());
                return 1;
} 
void reset()
{
        set("vendor_goods", ([
                __DIR__"obj/yanzhi":10,
                __DIR__"obj/bao":10,
                __DIR__"obj/huabag":10,
                                __DIR__"obj/pozhi":10,
   ]) );
}
           
