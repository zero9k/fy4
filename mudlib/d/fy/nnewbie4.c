 inherit ROOM;
void create()
{
                object silver;
        set("short", "隧道北");
        set("long", @long
隧道内漆黑一片，但乾爽宁静。虽然横七竖八摆了很多东西，不过依然显
得很宽敞。地上还有一些湿漉漉的脚印，显然经常有人来往。偶然身边闪过一
个身影，也不觉得惶恐。人们似乎对地上的宝物并不贪婪，只取去自己所需，
便悄悄离开。
long
        );
        set("exits", ([ /* sizeof() == 4 */
"out" : __DIR__"nnewbie3",
  "enter" : __DIR__"newbiecenter",
  
]));
        set("objects", ([
                /*__DIR__"obj/gui1" : 1,
                "/d/loulan/npc/obj/sword2" :1,
"/d/cave/npc/obj/windsword" : 1,
"/d/wolfmount/npc/obj/zheshan" : 1,
"/d/qianjin/npc/obj/toysword" :1,
"/d/shaolin/npc/obj/xiesword" : 1,*/

"/d/palace/npc/obj/s_spear" :1,
"/d/palace/npc/obj/g_spear":1,
/*"/obj/weapon/sword_katana":1,
"/d/wolfmount/npc/obj/rockhammer":1,
"/d/wolfmount/npc/obj/juque":1,
"/d/palace/npc/obj/wolf_hammer":1,
"/d/fy/npc/obj/guzi": 1,*/
"/d/taishan/npc/obj/bamboo_staff":1,
"/d/songshan/npc/obj/dafeng":1,
                
                        ]) );
        set("indoors", "fengyun");
                set("no_fight",1);

        set("coor/x",0);
        set("coor/y",20);
        set("coor/z",-10);
        
        setup();
    //silver = present("guzi",this_object());
    //silver->set_amount(random(9876)+1234);    

}
