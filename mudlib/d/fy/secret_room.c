 inherit ROOM;
void create()
{
        object silver;
        set("short", "地下密室");
        set("long", @LONG
这里是一间窄小的密室，你的面前只有一个破旧的小床跟一些乾草。
LONG
        ); 
        set("objects", ([
                "/d/fy/obj/biaoyin": 1
        ]) ); 
        set("coor/x",20);
        set("coor/y",50);
        set("coor/z",-10);
        setup();
        silver = present("biaoyin",this_object());
    silver->set_amount(random(1000)+1000);    
        //silver->set("name", "镖银");
}      
