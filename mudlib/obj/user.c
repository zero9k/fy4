 // user.c
// Copyright (C) 1995 - 2001, by FengYun Workshop. All rights reserved.
// This software can not be used, copied, or modified in any form without
// the written permission from authors.
// 
// Last modification:
//              - 07/22/2001 by Daniel Q. Yu.
//                      * Move some code in move function here.
//              - 08/16/2001 by Daniel Q. Yu.
//                      * Add autosave for each user.
// ^_^
//              - 12/30/2001 by Justdoit
//                      *Try to fix the connection error when player login.  
#include <origin.h>
#include <user.h>
#include <room.h>
#include <ansi.h> 
inherit CHARACTER;
inherit F_MASTER;
inherit F_AUTOLOAD;
inherit F_SAVE; 
static int last_age_set; 
void autosave(); 
void create() {
        ::create();
        set_name("使用者物件", ({ "user object", "user", "object" }) );
} 
void terminal_type(string term_type)
{
        set_temp("terminal_type", term_type);
        message("system", "终端机型态设定为 " + term_type + "。\n", this_object());
} 
void reset()
{
        if( (int)query("potential") - (int)query("learned_points") < 100 )
                add("potential", 1);
        if( (int)query("thief") > 0 )
                add("thief", -1 );
} 
// This is used by F_SAVE to determine the filename to save our data.
string query_save_file()
{
        string id; 
        id = geteuid();
        if( !id ) id = getuid();
        if( !stringp(id) ) return 0;
        return sprintf(DATA_DIR "user/%c/%s/%s", id[0],id, id);
} 
int save()
{
        int res; 
        save_autoload();
        res = ::save();
        clean_up_autoload(); // To save memory
        return res;
} 
void autosave() {
        tell_object(this_object(), HIR "\n 自动存档．．．");
        save();
        tell_object(this_object(), HIG "．．．存档完毕 \n" NOR); 
        EVENT_D->add_event(time() + 1800 + random(1800), this_object(), (: autosave :));
} 
// This function updates player's age, called by heart_beat()
void update_age()
{
        // Update the time we spend on mudding, using method from TMI-2 mudlib.
        if( !last_age_set ) last_age_set = time();
        add("mud_age", time() - last_age_set);
        last_age_set = time();
        set("age", 10+(int)query("age_modify") + ((int)query("mud_age") / 172800));
} 
void setup()
{
        // We want set age first before new player got initialized with
        // random age.
        update_age(); 
        ::setup();
        restore_autoload();
} 
private void user_dump(int type)
{
        switch(type)
        {
        case DUMP_NET_DEAD:
                        if (environment())
                        {
                                tell_room( environment(), query("name") + "断线超过 "+ 
                                NET_DEAD_TIMEOUT/10 + " 分钟，自动退出这个世界。\n");
                        }
                        catch(command("quit"));
                        if (this_object())
                        {
                                // command quit failed.
                                seteuid(getuid());
                                destruct(this_object());
                        }
                        break;
        case DUMP_IDLE:
                        if(!wizardp(this_object()))
                        {
                                tell_object( this_object(), "对不起，您已经发呆超过 " +
                                IDLE_TIMEOUT/10 + " 分钟了，请下次再来。\n");
                                if (environment())
                                {
                                        tell_room( environment(), "一阵风吹来，将发呆中的" + query("name") +
                                                "化为一堆飞灰，消失了。\n", ({this_object()}));
                                }
                                command("quit");
                                if (this_object())
                                {
                                        // command quit failed.
                                        seteuid(getuid());
                                        destruct(this_object());
                                }
                        }
                        break;
        default:
                return;
        }
} 
// net_dead: called by the gamedriver when an interactive player loses
// his/her network connection to the mud.
private void net_dead()
{
        object link_ob; 
        set_heart_beat(0);
        if( objectp(link_ob = query_temp("link_ob")) )
                destruct(link_ob); 
        // Stop fighting, we'll be back soon.
        // To prevent bugs , commented it out! Tie
        // remove_all_enemy(); 
        set_temp("netdead", 1);
        if( userp(this_object()) )
        {
                call_out("user_dump", NET_DEAD_TIMEOUT, DUMP_NET_DEAD);
                tell_room(environment(), query("name") + "断线了。\n", this_object());
                CHANNEL_D->do_sys_channel("sys", sprintf(
                        "%s(%s)断线了。",query("name"),query("id")));
        }
        else command("quit"); // What is this???
} 
// reconnect: called by the LOGIN_D when a netdead player reconnects.
void reconnect()
{
        set_heart_beat(1);
        set_temp("netdead",0);
        remove_call_out("user_dump");
        tell_object(this_object(), "重新连线完毕。\n");
} 
varargs int move(mixed dest, int silently) {
        object *inv;
        string str, *dirs;
        int result, i;
        mapping exits;
        
        result = ::move(dest, silently);
        if(result && interactive(this_object()) 
                        && living(this_object())
                        && !silently) {
                if(query("env/brief")) {
                   tell_object(this_object(), environment()->query("short") + "\n");
                } else if(query("env/brief2")) {
                        str = environment()->query("short") + "\n";
                        inv = all_inventory(environment());
                        for(i=0; i<sizeof(inv); i++) {
                                if(inv[i]==this_object()) {
                                        continue;
                                }
                                if(inv[i]->query("no_shown")) {
                                        continue;
                                }
                                if(!this_object()->visible(inv[i])) {
                                        continue;
                                }
                                str += "  " + inv[i]->short() + "\n";
                        }
                        tell_object(this_object(), str);
                } else if(query("env/brief3")) {
                        str = environment()->query("short")+(wizardp(this_object())?
                        sprintf(" - %s - (%d,%d,%d)\n",file_name(environment()),
                                        environment()->query("coor/x"),
                                        environment()->query("coor/y"),
                                        environment()->query("coor/z")):"\n");
                        if(mapp(exits = environment()->query("exits"))) {
                                dirs = keys(exits);
                                for(i=0; i<sizeof(dirs); i++) {
                                        if((int)environment()->query_door(dirs[i], "status") & DOOR_CLOSED) {
                                                dirs[i] = 0;
                                        }
                                }
                                dirs -= ({ 0 });
                                if(sizeof(dirs)==0) {
                                        str += "    这里没有任何明显的出路。\n";
                                } else if(sizeof(dirs)==1) {
                                        str += "    这里唯一的出口是 " + BOLD + dirs[0] + NOR + "。\n";
                                } else {
                                        str += sprintf("    这里明显的出口是 " + BOLD + "%s" + NOR
                                                        + " 和 " + BOLD + "%s" + NOR + "。\n",
                                                        implode(dirs[0..sizeof(dirs)-2], "、"),
                                                        dirs[sizeof(dirs)-1]);
                           }
                        } else {
                                str += "    这里没有任何明显的出路。\n";
                        }
                        inv = all_inventory(environment());
                        for(i=0; i<sizeof(inv); i++) {
                                if(inv[i]==this_object()) continue;
                                if(inv[i]->query("no_shown")) continue;
                                if(!this_object()->visible(inv[i]) ) continue;
                                str += "  " + inv[i]->short() + "\n";
                        }
                        tell_object(this_object(), str);
                } else {
                        command("look");
                }
        }
        return result;
} 
void receive_message(string cl, string msg) {
        if(this_object()->query_temp("char_encoding") == "big5") {
                msg = ENCODE_D->gbTobig5(msg);
        }
        ::receive_message(cl, msg);
} 
string process_input(string str) {
        if(this_object()->query_temp("char_encoding") == "big5") {
                str = ENCODE_D->big5Togb(str);
        }
        return ::process_input(str);
}       
