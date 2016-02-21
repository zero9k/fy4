 // Room: snakehall.c --- by MapMaker
inherit ROOM; 
void create()
{
        set("short", "玲珑珠帘"); 
        set("long", @LONG
忽然从地狱进入了天堂，一颗颗晶莹的珍珠垂挂而下，组成重重的珠帘。众蛇似乎很忌惮这
些珍珠。珠帘不但挡住了群蛇，也挡住了群蛇咻咻声音。珠帘深处似乎有柔和的光芒照来，盈盈
的珠光透射，如梦如幻，令人心意平和。
LONG); 
        set("indoors","yinghe");
        set("item_desc", ([
                "curtain" : "圆润的珠子闪着荧白色的光泽，你可以摘（ｐｉｃｋ）。\n",
                "珠帘" : "圆润的珠子闪着荧白色的光泽，你可以摘（ｐｉｃｋ）。\n",
        ]));
        set("exits",([
                "out" : __DIR__"snakehall",
                "enter" : __DIR__"snakebeauty",
        ]) );
        //}}
        set("pearl_amount", 2);
        setup(); 
} 
void init(){
        add_action("do_pick", "pick");
} 
int do_pick(string arg){
        object me, pearl;
        
        me = this_player();
        if(me->is_busy() || me->is_fighting()){
                return notify_fail("你正在忙。\n");
        }
        if(arg == "pearl" || arg == "珍珠"){
                if(!query("pearl_amount")) {
                        return notify_fail("没有可以拿的珍珠了。\n");
                }                       
                pearl = new(__DIR__"obj/pearl");
                if(objectp(pearl)){
                        message_vision("$N从珠帘的一角摘下一颗珍珠。\n", me);
                   pearl->move(me);
                        add("pearl_amount", -1);
                }
                return 1;
        } 
        return 0;
} 
void reset(){
        ::reset();
        if(!query("pearl_amount")) {
                set("pearl_amount", 2);
        }
        return;
}       
