 inherit ITEM;
inherit F_FOOD; 
void create()
{
    set_name("小南瓜", ({ "pumpkin" }) );
    set_weight(4000);
    if( clonep() )
        set_default_object(__FILE__);
    else {
        set("long", "一个圆圆的，硬硬的小南瓜。\n");
        set("unit", "个");
        set("value", 15);
        set("food_remaining", 3);
        set("food_supply", 300);
    }
    ::init_item();
}    
