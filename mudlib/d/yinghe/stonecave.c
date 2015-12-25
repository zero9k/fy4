 // Room: stonecave.c --- by MapMaker
inherit ROOM; 
void create()
{
        set("short", "松石洞"); 
        set("long", @LONG
从水汽虚幻河光中走出，这里森森的山石给人一种说不出的真实的质感。东面不
远的地方，一级级翠石台阶曲折向上。
LONG); 
        //{{ --- by MapMaker
        set("type","indoors");
        set("exits",([
        "east":__DIR__"stonestair1",
        "northwest":__DIR__"fountain",
        ]) );
        //}} 
        setup();
        replace_program(ROOM);
}      
