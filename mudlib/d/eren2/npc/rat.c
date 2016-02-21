 inherit NPC;
void create()
{
        set_name("黑鼠", ({ "rat" }) );
        set("race", "野兽");
        set("age", 5);
        set("int",10);
        set("long", "一只精圆滚壮的黑老鼠，大模大样地在你脚下窜来窜去。\n");
        set("max_kee", 100);
        set("limbs", ({ "头部", "身体", "尾巴" }) );
        set("verbs", ({ "bite" }) );
        set_skill("dodge", 80); 
        setup();
}       
