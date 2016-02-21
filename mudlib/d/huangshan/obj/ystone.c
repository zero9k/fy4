 inherit ITEM;
void create()
{
        set_name("碎石", ({ "suishi", "碎石", "stone", "sui shi" }) );
        set_weight(1500);
        set_max_encumbrance(100);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "块");
                set("long", "这是一块碎石头，奇怪的是，里面总是渗出冷冷的水来。
你要找个可以生火的地方才能烧烧它看。（ｂｕｒｎ）\n");
                set("value", 1);
                set("no_drop",1);
                set("no_give",1);
        }
        ::init_item();
} 
void init() {
        if (this_player() == environment() ) {
                add_action("do_burn", "burn");
        }
} 
int do_burn(string arg) {
        
        if( arg != "suishi" ) return notify_fail("你要烧什么？\n");
        environment(this_player())->burn_notify(this_object(), 0);
        return 1;
}        
