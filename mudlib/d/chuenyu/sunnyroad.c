 // Room: /d/chuenyu/foot_b_mtn.c
inherit ROOM; 
void create()
{
        set("short", "山脚乡田");
        set("long", @LONG
你的两侧是茂盛的稻田，还有一条清澈见底的小溪。许多乡民在田里
辛苦的忙碌着。再北面是黑松山。眺望山顶，你似乎可以看到一个颇具规
模的城堡。城堡的最顶端插着一面大旗，大旗上绣着两个斗大的金字：淳于。
LONG
        );
        set("exits", ([ 
  "south" : __DIR__"dustyroad2",
])); 
        set("objects", ([
               __DIR__"xiaojuan" : 1,
        ]) );
        set("no_fight",1);
        set("no_magic",1);
        set("outdoors", "chuenyu");
        set("coor/x",100);
        set("coor/y",130);
        set("coor/z",0);
        setup();
} 
void reset()
{
        object room;
        ::reset();
        if( room = find_object(__DIR__"sunnyroad"))
                if(room->query("exits/north"))
                        room->delete("exits/north");
}
int valid_leave(object me, string dir)
{
        if( query("exits/north"))
        call_out("close_path",10);
        return 1;       
} 
int close_path()
{
this_object()->reset();
return 1;
}    
