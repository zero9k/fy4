 inherit NPC;
void create()
{
        set_name("梳头老师傅", ({ "hair oldman" }) );
        set("gender", "男性" );
        set("age", 63);
        set("long", "一个在关外小有名气的梳头师傅，长年劳累背已经驮地很厉害。\n");
        set("combat_exp", 1000);
        set("str", 27);
        set("force", 200);
        set("attitude", "friendly");
        set("max_force", 200);
        set("force_factor", 2);
        set("chat_chance", 1);
        set("chat_msg", ({
                "梳头老师傅眯着双眼，轻轻地给白飞飞梳理着云鬓秀发。\n",
        }) );
        set("inquiry", ([
                "梳头" : "嗯，你头发看上去不错，等这边事好了我帮你梳梳。\n",
        ]) );
        setup();
        carry_object("/obj/armor/cloth")->wear();
} 
int accept_object(object me, object obj)
{
        command("smile");
        command("say 多谢这位" + RANK_D->query_respect(me) + 
"，您一定会在这儿玩的开心的！");
        return 1;
}   
