 // Room: woodroad.c --- neon
inherit ROOM; 
void create()
{
        set("short", "焦木走廊"); 
        set("long", @LONG
这是一条长长的木走廊，它横架于滚滚流沙之上。西面火山上透出的热浪如烤
如炙，以至于长廊的木材都被烤成焦黑的颜色。走在木廊之上，下面流沙滚动，木
板随着脚步咔咔作响，令人不由得提心吊胆。木廊曲折迂回，隔不远就有一个井架
般的结构深入流沙之中，似乎是木廊的支撑。
LONG);
//  pick firewood here 
        
        set("indoors", "yinghe");
        set("exits",([
        "east":__DIR__"woodroad2",
        "north":__DIR__"slop",  
        ]) );
        //}} 
        setup();
        replace_program(ROOM);
} 
