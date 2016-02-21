 // tea_waiter.c
inherit NPC;
inherit F_VENDOR; 
void create()
{
        set_name("万小春", ({ "wan xiaochun","wan" }) );
        set("gender", "男性" );
        set("title", "不学无术" );
        set("age", 23);
        set("long",
                "一个愁眉苦脸，垂头丧气的家伙，自称是神医万春流的远方堂侄，\n从万春流那里偷了些灵丹卖钱。。\n");
       set("combat_exp", 200000);
        set("chat_chance", 1);
        set("chat_msg", ({
                "万小春苦着脸道：唉～～～我说柳大姐啊，这下我连回家的盘缠都没了，\n姑奶奶您就行行好吧。。\n",
                "万小春瞅了你一眼，凑上来低声道：幸好我还藏了些从我叔父那\n儿偷来的灵丹妙药，可都是神医万春流的宝啊。\n",
                "万小春一屁股坐在地上，一个劲地唉声叹气。\n", 
        }) ); 
        set("attitude", "friendly");
        set("vendor_goods", ([
                __DIR__"obj/senyao":3,
                __DIR__"obj/keeyao":3,
                __DIR__"obj/ginyao":3,
        ]) );
        setup(); 
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
        switch( random(2) ) {
                case 0:
                        say( "万小春苦着脸道：这位" + RANK_D->query_respect(ob)
                                + "，我手头这些灵丹妙药可都是无价之宝，要不\n是我全身家当被这位柳大姐。。。\n");
                        break;
                case 2:
                        say( "万小春低声说道：这位" + RANK_D->query_respect(ob)
                                + "，您别说，天底下就我这还有这几样药，哼，老万头不\n肯传我这手艺，我就把他的宝贝配方全烧了。。\n");
                        break;
        }
}         
