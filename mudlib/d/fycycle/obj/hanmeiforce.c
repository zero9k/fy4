 inherit ITEM;
void create()
{
        set_name("寒梅心法", ({ "book", "hanmei force", "hanmei" }));
        set_weight(600);
        if( clonep() )
            set_default_object(__FILE__);
        else {
            set("unit", "本");
            set("long",
                    "书本首页用寥寥数笔勾画出一棵雪中盛开的寒梅。\n");
            set("value", 0);
            set("no_give", 1);
            set("no_drop", 1);
            set("no_sell",1);
            set("material", "paper");
            set("skill", ([
                    "name": "hanmei-force",
                    "exp_required": 5000,
                    "sen_cost": 65,
                    "difficulty": 40,
                    "max_skill": 60,
            ]) );
        }
}
