 // a skeleton for user rooms
#define X_COOR 0
#define Y_COOR 2040
#define Z_COOR 30
#define R_FLAG 2561
#define OWNER "baby"
#define CLASS "三清宫"
inherit ROOM;
void create()
{
set("short", "威廉古堡");
set("long", @LONG
藤蔓植物爬满了伯爵的坟墓 
古堡里一片荒芜长满杂草的泥土 
不会骑扫把的胖女巫用拉丁文念咒语啦啦呜 
她养的黑猫笑起来像哭啦啦啦呜用水晶球替人占卜   
她说下午三点阳光射进教堂的角度 
能知道你前世是狼人还是蝙蝠 
古堡主人威廉二世满脸的落腮胡 
习惯在吸完血后开始打呼   
管家是一只会说法语举止优雅的猪 
吸血前会念约翰福音做为弥补 
拥有一双蓝色眼睛的凯萨琳公主 
专吃有ＡＢ血型的公老鼠   
恍恍惚惚是谁的脚步 
银制茶壶装蟑螂蜘蛛 
辛辛苦苦全家怕日出 
白色蜡烛温暖了空屋   
恍恍惚惚是谁的脚步 
客厅壁炉零下的温度 
辛辛苦苦从不开窗户 
小小恐怖吸血鬼家族 
LONG
);
        set("exits", ([
"east" : "/p/residence/recall1014842649.c",
]));
set("objects", ([
       ]) );
        set("coor/x",X_COOR);
   set("coor/y",Y_COOR);
        set("coor/z",Z_COOR);
        set("room_flag",R_FLAG);
        set("owner", OWNER);
        set("class", CLASS);
        setup();
}
void init()
{
        int flag;
        flag = (int) query("room_flag");
        if(flag & 1) set("valid_startroom",1);
        if(flag & 2) set("NONPC",1);
        if(flag & 4) set("no_fight",1);
        if(flag & 8) set("no_magic",1);
        if(flag & 16) set("outdoors","residence");
        add_action("do_invite","invite");
        add_action("do_setowner","setowner");
        add_action("do_list","list");
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
    
