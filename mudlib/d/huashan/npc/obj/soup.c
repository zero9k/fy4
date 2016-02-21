 //
inherit ITEM;
inherit F_FOOD;
inherit F_LIQUID;
void init()
{
        if(environment()==this_player())
        add_action("do_eat", "eat");
        add_action("do_drink", "drink");
} 
void create()
{
        set_name("牛肉面", ({ "beef soup", "soup" }) );
        set_weight(400);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("long", "一碗热气腾腾的牛肉面，上面漂着一些葱花，闻起来香气扑鼻。\n");
                set("unit", "碗");
                set("value", 100);
                set("food_remaining", 6);
                set("material", "food");
                set("food_supply", 90);
        set("liquid", ([
        "type": "water",
        "name": "牛肉面汤",
        "remaining": 10,
        "drunk_apply": 6,
        ]) );   
        }
         ::init_item();
} 
int finish_eat()
{
        set_name("青花瓷碗", ({"bowl"}) );
        set("value", 10);
        set("long", "一只青花大瓷碗。\n");
        return 1;
} 
            
