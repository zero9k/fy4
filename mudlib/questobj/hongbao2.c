#include <ansi.h>
inherit ITEM;
void create()
{
    set_name( RED "新婚红包" NOR, ({ "hong bao" }) );
    set_weight(1);
    if( clonep() )
            set_default_object(__FILE__);
    else {
            set("unit", "个");
            set("material", "cloth");
            set("long", "一个小小的红包，上面绣着：百年好合。\n");
        

          }
    ::init_item();
} 
void init()
{ 
        if(environment()==this_player())
                add_action("do_open","open");
} 
int do_open(string arg)
{
        object gold, me;
        me = this_player();
        if(arg != "hong bao" && arg != "新婚红包") return 0;
        if(query("opened"))
                return notify_fail("你打开小红包，但里面是空的！\n");
        gold = new("/obj/money/gold");
        gold->set_amount(666);
        gold->set("name","金元宝");
        gold->set("base_unit","张");
        gold->move(this_player());
        me->add("combat_exp",88888);
        me->add("potential",3333);
        me->add("score",222);
        tell_object(me,"\n恭喜恭喜！你被奖励了：\n" + chinese_number(88888) + "点实战经验\n" + chinese_number(3333) + "点潜能\n" + chinese_number(222)+"点综合评价\n");
        set("opened",1);
        return notify_fail(HIR "\n你悄悄打开红包，两眼发光，一阵窃喜！\n\n" NOR);
}
