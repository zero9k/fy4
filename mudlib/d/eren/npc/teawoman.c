 inherit NPC;
inherit F_VENDOR; 
void create()
{
        set_name("老妇人", ({ "oldwoman" }) );
        set("gender", "女性" );
        set("age", 60);
        set("long",
                "老妇人扯着把竹扇坐在树荫下，面前放着个大茶壶和几个篾碗。\n");
        set("combat_exp", 5);
        set("inquiry", ([
                "小烟" : "小烟好像和几个孩子在竹林边玩",
                 "欧阳豆腐铺" : "欧阳豆腐铺生意越来越好，快盖过哈哈酒楼了。",
                "欧阳丁" :  "欧阳豆腐铺生意越来越好，快盖过哈哈酒楼了。",
                "欧阳当" :  "欧阳豆腐铺生意越来越好，快盖过哈哈酒楼了。",
                "ouyang ding" :  "欧阳豆腐铺生意越来越好，快盖过哈哈酒楼了。",
                "ouyang dang" :  "欧阳豆腐铺生意越来越好，快盖过哈哈酒楼了。",
                "哈哈酒楼": "哈哈酒楼当然是哈哈儿开的喽，听说他现在生意不好，正在为原料发愁呢。",
                "娇娇客栈": "娇娇客栈是屠娇娇的女儿开的。",
                "屠小娇": "娇娇客栈是屠娇娇的女儿屠小娇开的。",
                "恶人谷": "恶人们都跑光了，这恶人谷三字早已没人提了。",
                "燕南天": "燕大侠的名字谁人不晓，村里还有他的铁像呢。",
                "万春流": "万神医有起死回生之能。",
                "杜老爹": "杜老爹专打暗器，听说要打他的暗器，还得学好听风辨器才行。",
                "轩辕三光": "他输的只剩下那间当铺了。",
                "铁萍姑": "李大嘴的女儿，一个人住在那儿，怪可怜的。",                   
        ])); 
        set("attitude", "friendly");
        set("vendor_goods", ([
                __DIR__"obj/teapot": 10,
               __DIR__"obj/dumpling": 10,
               __DIR__"obj/fan": 10,
        ]) );
        setup();
        carry_object("/obj/armor/cloth")->wear();
} 
void init()
{
        object ob; 
        ::init();
        if( interactive(ob = this_player()) && !is_fighting() ) {
                remove_call_out("greeting");
                call_out("greeting", 1, ob);
        }
        add_action("do_vendor_list", "list");
} 
void greeting(object ob)
{
        if( !ob || environment(ob) != environment() ) return;
        switch( random(3) ) {
                case 0:
                        say( "老妇人笑咪咪地说道：这位" + RANK_D->query_respect(ob)
                                + "，过来喝杯茶，歇歇腿吧。\n");
                        break;
                case 1:
                        say( "老妇人用毛巾抹了抹篾碗说道：这位" + RANK_D->query_respect(ob)
                                + "，请坐请坐。\n");
                        break;
                case 2:
                        say( "老妇人说道：这位" + RANK_D->query_respect(ob)
                                + "，过来尝尝才采的新茶叶。哇! 好香啊!...\n");
                        break;
        }
}       
