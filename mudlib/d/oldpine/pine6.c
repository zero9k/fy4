 // Room: /d/oldpine/pine1.c
inherit ROOM;
string *names=({
        __DIR__"pine1",
        __DIR__"pine2",
        __DIR__"pine5",
        __DIR__"pine3",
} );  
void create()
{
        set("short", "松树林");
        set("long", @LONG
你现在正站在一个松树林里，嗯....这是一个松树林....你所知就
这麽多，茂密的松树遮蔽了整个天空，使你连方向都弄不清楚，最好在
天黑之前赶紧找条道路出去吧。
LONG
        );
        set("outdoors", "oldpine"); 
        set("coor/x",560);
        set("coor/y",2340);
        set("coor/z",90);
        setup();
} 
void reset()
{
        int i,j;
        string temp;
        ::reset();
        for (i=0;i<=3;i++)
        {
                j=random(4);
                temp=names[j];
                names[j]=names[i];
                names[i]=names[j];
                names[i]=temp;
        }
        set("exits", ([
                "north" : names[0],
                "south" : names[1],
                "east" : names[2],
           "west" : names[3],
        ]));
} 
int valid_leave(object me, string dir)
{
        write("你实在弄不清楚方向....");
        switch(dir) {
                case "north":   write("北边....北边是哪里呢？....");    break;
                case "east":    write("东边....东边....");      break;
                case "south":   write("南边....哪里是南边？....");      break;
                case "west":    write("西边....嗯....");        break;
                default:
                        write("该往哪里走呢....");
        }
        write("就是这个方向吧。\n");
        return 1;
}
