 inherit ITEM;
void create()
{
        set_name("白玉石地板", ({ "floor" , "jade floor", "白玉石地板"}) );
        set_weight(500);
        set_max_encumbrance(8000000);
        set("no_get", 1);
        set("no_shown", 1);
        set("prep", "on");
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "个");
                set("prep", "on");
                set("long", "光洁平整的白玉石地板，上面堆了一些东西。\n");
                set("value", 1);
        }
} 
int is_container() { return 1; }     
