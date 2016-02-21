 inherit NPC;
void create()
{
        set_name("黑鼠", ({ "rat" }) );
        set("race", "野兽");
        set("age", 5);
        set("long", "一只鼠头鼠脑的黑老鼠正不怀好意地看着你，嘴里好像咬着什么东西。\n");
        set("max_kee", 100);
        set("limbs", ({ "头部", "身体", "尾巴" }) );
        set("verbs", ({ "bite" }) );
        set_skill("dodge", 80); 
        carry_object(__DIR__"obj/drug_flower");
        setup();
} 
