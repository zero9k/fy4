 inherit ROOM;
void create()
{
        set("short", "怪树林");
        set("long", @LONG
这里是一片奇怪的树林，林木并不是非常的密集，白天的阳光依旧透过林木
照耀进来，然而你却明显的感觉到一种阴冷的接近死亡的气息。林间没有任何可
以辨认的道路，你感觉到眼前的景物随时随地都在变化着，很难分辨什么是真什
么是幻。。
LONG
        ); 
        set("outdoors","qingping");
        set("coor/x",230);
        set("coor/y",2000);
        set("coor/z",0);
        setup();
} 
void init(){ 
    string *rooms = ({"forest1", "forest2", "forest3", "forest4", "forest5", "forest6"});
    string *direction = ({"north", "south", "east", "west", "northeast", "northwest", "southeast", "southwest"});
        if(this_object()->query("exits")){
                delete("exits");
        }
    set("exits/"+direction[random(8)], __DIR__ + rooms[random(6)]);
        set("exits/"+direction[random(8)], __DIR__+rooms[random(6)]);
}
int valid_leave(object me, string dir){
        object room; 
        if(me->query("class") == "shenshui" && (dir=="north" || dir=="south" || dir=="east" || dir=="west"
                        || dir=="northeast" || dir=="northwest" || dir=="southeast" || dir=="southwest")){
                tell_object(me, "你不被眼前幻像所迷惑继续往前行。\n");
                room = find_object(__DIR__"forest4");
                if(!objectp(room)){
                        room = load_object(__DIR__"forest4");
                }
                me->move(room);
                return notify_fail("");
        }
        return 1;
} 
