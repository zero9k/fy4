#include <ansi.h>
inherit ITEM;
void create()
{
    set_name(HIC"卖身契"NOR, ({ "msqi" }) );
    set_weight(1);
    if( clonep() )
            set_default_object(__FILE__);
    else {
            set("unit", "张");
            set("material", "cloth");
            set("long", @LONG
千金楼是风云城中最富盛名的青楼，其名如雷贯耳、众人皆知，
光是从外观之，便晓得这非一般酒楼豪宅，里面更是布置的富丽
传说居住于内的年轻少女们，各个国色天香，容貌宛如仙女，并
且擅长于歌舞技艺，常使名门公爵、富家子弟们留连忘返，乐不
思蜀。
在这酷似人间天堂的千金楼中，却隐藏着一些不为人知的秘密，
其实楼中深处设有私刑房，刑房内有着一群正受严刑拷打，逼迫
凌虐的良家妇女，她们因为家庭生计负担不起，欠债甚多，或因
自暴自弃而卖身于此，岂知此处如同人间地狱，苦不堪言，正因
为不尊从命令，不愿意舍弃道德贞节而饱受摧残。这些良家妇女
们的心中只存着一丝希望，盼望着哪天有位悲天悯人、怜香惜玉
的义人，能替她们赎身，或取得她们的卖身契，使她们能够保住
贞节，并得到自由。谁知道当时所签下的卖身契，居然是左右她
们一生的束缚！
LONG);
        set("no_drop", 1);
        set("no_sell", 1);
        set("no_give", 1);
        set("no_put", 1);
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
