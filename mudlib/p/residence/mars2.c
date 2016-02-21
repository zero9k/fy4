 // a skeleton for user rooms
#include <ansi.h>
#include <room.h>
#define X_COOR 20
#define Y_COOR 2040
#define Z_COOR 40
/* #define R_FLAG 18
#define OWNER "mars"
#define CLASS "峨嵋派"  */
inherit ROOM; 
void create()
{
set("short", WHT"怡然厅"NOR);
set("long", @LONG
大厅布置的简单别致，大厅两旁各安置着两张红木椅子和茶几
正前方挂着此居主人当年纵横天下所用的刀剑，刀剑下方安置着
香坛，里面燃放着香料，幽幽的香味让大厅显得格外的宁静和舒
适。
LONG
);
        set("exits", ([
"west" : __DIR__"mars3",
"east" : __DIR__"mars4",
"south" : __DIR__"mars1",

]));
set("objects", ([

       ]) );
           set("item_desc", ([
                "door": "一扇清雅的木门，造型别致，似乎可以打开(open)。\n",
                "木门": "一扇清雅的木门，造型别致，似乎可以打开(open)。\n",
        ]) );
        create_door("south", "木门", "north", DOOR_CLOSED);
        set("coor/x",X_COOR);
   	set("coor/y",Y_COOR);
        set("coor/z",Z_COOR);
/*        set("room_flag",R_FLAG);
        set("owner", OWNER);
        set("class", CLASS); */
        set("indoors","residence");
        setup();
}
/* void init()
{
       int flag;
        flag = (int) query("room_flag");
        if(flag & 1) set("valid_startroom",1);
        if(flag & 2) set("NONPC",1);
        if(flag & 4) set("no_fight",1);
        if(flag & 8) set("no_magic",1);
        if(flag & 16) set("indoors","residence");  
        add_action("do_invite","invite");
        add_action("do_setowner","setowner");  
        add_action("do_list","list");
                //add_action("do_sleep", "sleep");
}
int valid_enter(object me)
{
        int flag;
// means no enter at the beginning.
        int enter = 0;
    flag = (int) query("room_flag");
// always let owner go in:
        if((string)me->query("id") == (string)query("owner"))
        enter = 1;
        if(flag & 16)
        enter = 1;
        if(flag & 512)
        if((string)me->query("id") == (string)query("owner"))
        enter = 1;
        if(flag & 1024)
        if((string)me->query("class") == (string)query("class"))
        enter = 1;
        if(flag & 2048) 
        {
                if(strlen(query("invite")) && strsrch((string)query("invite"),"["+(string)me->query("id")+"]") != -1)
           enter = 1;
        }
//      write(sprintf("%d", enter));    
        return enter;
}
int do_list()
{
        object me;
        string *list,invitelist;
        me = this_player();
        if((string)me->query("id") != (string)query("owner"))
        return 0;
        invitelist = query("invite");
        if (strlen(invitelist))
        {
                list = explode("]"+invitelist+"[", "][");
                write("你邀请了下列玩家到你的房间:\n");
                for(int i=0;i<sizeof(list);i++)
                        write(list[i]+"\n");
        }else
                write("你没有邀请任何人到你的房间。\n");
        return 1;
} 
int do_invite(string arg)
{
        object me;
        string invitelist;
        me= this_player();
        if((string)me->query("id") != (string)query("owner"))
        return 0;
        if( !arg )
        {
                write("你要邀请谁? \n");
                return 1;
        }
        invitelist = (string)query("invite");
        if(strlen(invitelist) && strsrch(invitelist,"["+arg+"]") != -1)
        {
                //if the person has already been invited, remove it from invite list.
                invitelist = replace_string(invitelist,"["+arg+"]","");
           set("invite",invitelist);
                write("你将"+arg+"从你的邀请名单中除去。\n");
        }else
        {
                //invite the person.
                if( find_player(arg))
                {
                        if(!strlen(invitelist))
                                set("invite","["+arg+"]");
                        else
                                set("invite",invitelist+"["+arg+"]");
                        write("你邀请"+arg+"来你的房间。\n");
                }else
                {
                        write("咦... 有这个人吗?\n");
                }
        }
        return 1;
} 
int do_setowner(string arg)
{
        string oldowner;
        oldowner = (string)query("owner");
        set("owner",arg);
        write("你将房间的主人暂时设为"+arg+"。\n");
        call_out("set_back",60, oldowner);
        return 1;
} 
int set_back(string oldowner)
{
        set("owner", oldowner);
        return 1;
}
    
*/