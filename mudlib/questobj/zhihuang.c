#include <ansi.h>
inherit ITEM;
void create()
{
    set_name(CYN"指环儿"NOR, ({ "zhihuan" }) );
    set_weight(1);
    if( clonep() )
            set_default_object(__FILE__);
    else {
            set("unit", "个");
            set("material", "stone");
                set("long", @LONG
只要是个人，想必就一定听说过陆小凤这三个字。如果还是个武林中人的
话，那一定知道陆小凤的“灵犀一指”。据说陆小凤的指头不但可以神不
知，鬼不觉的偷走一个人口袋中的一文钱，也可以神不知，鬼不觉的偷走
一个人的脑袋。“灵犀一指”已在某种程度上成为陆小凤的象征。在陆小
凤传奇的一生中，东至幽灵山庄老刀把子，西至世外无名岛岛主，南至卧
云楼楼主，北至银钩睹坊方玉飞，都曾败在陆小凤的“灵犀一指”下。但
最传奇性的，也最负有盛名便是陆小凤用区区两根肉指夹住了“当年第一
剑客”西门吹雪的混然一剑。
还是有不少凡夫俗子说陆小凤之所以能挡住西门吹雪这一剑主要归功于他
当时戴的一个指环。其实不过是很平凡一个指环，经此一役，便被贯以神
称。岂不知纵是神兵利器，若是在一个书生手里，也有如一堆废铜烂铁一
般。反之而言，即使是一片叶子，在一位武林高手手里，同样可以飞花摘
叶。江湖上遂有人穷其所力，要得到陆小凤这个指环。梦想借此也能在武
林里一争短长。不知怎的，有人竟然拿到了这个指环。不过又有人讲是假
的。如此一来，真真假假就出现了很多这样的指环。至于真的指环在哪儿，
恐怕只有陆小凤才知道。可是真假又有何妨呢！真的本就是假的，假的又
何尝不能是真的。人本就是如此，江湖如此，人生亦是如此。
LONG);

        set("no_drop", 1);
        set("no_put", 1);
        set("no_sell", 1);
        set("no_give", 1);
          } 
    ::init_item();
} 
void owner_is_killed(object killer)
{
	if(objectp(killer))
        {
        message_vision("有样东西从尸体里跌落$N的怀中！\n\n",killer);
        this_object()->move(killer);}
        else
        {destruct(this_object()); }
}
