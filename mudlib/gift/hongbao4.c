#include <ansi.h>
inherit ITEM;
void create()
{
    set_name( HIR "新手红包" NOR, ({ "hong bao" }) );
    set_weight(1);
    if( clonep() )
            set_default_object(__FILE__);
    else {
            set("unit", "个");
            set("material", "cloth");
            set("long", "一个小小的红包，上面绣着：恭喜发财。\n");
        

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
        object gold, me,ob;
        me = this_player();
        if(arg != "hong bao" && arg != "新手红包") return 0;
        if(me->query("marks/opend"))
        	return notify_fail("你已经开过红包了。\n");
        if(query("opened"))
                return notify_fail("你打开小红包，但里面是空的！\n");
        gold = new("/obj/money/gold");
        gold->set_amount(666);
        gold->set("name","纯金叶子");
        gold->set("base_unit","张");
        gold->move(this_player());
        me->set("combat_exp",750000);
        me->add("potential",140000);
        me->add("score",2005);
        me->set("int",30);
        message_vision(HIR "\n$N悄悄打开红包，两眼发光，一阵窃喜！\n\n" NOR,me);
        tell_object(me,HIC"\n恭喜恭喜！你被奖励了：\n" + chinese_number(750000) + "点实战经验\n" + chinese_number(140000) + "点潜能\n" + chinese_number(2005)+"点综合评价,六百六十六两黄金\n"NOR);
        set("opened",1);
        me->set("marks/opend",1);
        me->save();
        return 1;
}
