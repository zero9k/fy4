 // Room: riverroad1.c --- by MapMaker
inherit ROOM; 
void create()
{
        set("short", "荧河谷地"); 
        set("long", @LONG
转过丛林，眼前豁然开阔。头顶的荧河竟然以一种奇怪角度与谷地的一条长河
在东北方向汇合。在这里，高度与空间似乎都已经不能用正常的眼光来观察。对远
近高低，你也失去了正常的判断。因为四处都是荧荧的光芒，无论是你自己还是周
围的物体都没有影子。没有了光明与黑暗的界限，只有一种虚幻离魂的感觉。
LONG); 
        //{{ --- by MapMaker
        set("indoors", "yinghe");
        set("exits",([
        "south":__DIR__"mudpath",
        "northeast":__DIR__"fountain",
        "northwest":__DIR__"riverroad2",
        ]) );
        //}} 
        setup();
        replace_program(ROOM);
}       
