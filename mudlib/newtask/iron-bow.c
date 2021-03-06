#include <combat.h>
#include <ansi.h>
inherit ITEM; 
void create()
{
        set_name(HIY"五花神弓"NOR, ({ "iron-bow" }) );
        set_weight(2000);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "把");
                set("long", "这是一把由万年玄铁锻就的五花神弓，传说中的五花神箭只有和这把\n神弓配合（install）才尽显神奇威力。 \n");
                set("installed", 0);
        }
} 
void init()
{
        if(this_player()==environment())
        add_action("do_install","install");
        add_action("do_shoot","shoot");
} 
int do_install()
{
        int i,arrower=0;
        object me, *inv;
        object arrow;
        me = this_player();
        inv = all_inventory(me);
        for(i=0; i<sizeof(inv); i++)
        {
                if(inv[i]->query("name") == RED"五"BLU"花"HIG"神箭"NOR) 
                {
                        arrower = 1; 
                        arrow = inv[i];
                }
        }
        if( arrower )
        {
                destruct(arrow);
        message_vision(CYN "$N在"+this_object()->name()+CYN"上搭上一支五花神箭。\n"NOR,this_player());
           set("installed",1);
                return 1;
        }
        else 
                message_vision("$N试着拉了拉"+this_object()->name()+"，但是没有箭。\n",this_player());
                return 1;
} 
int do_shoot(string arg)
{
        object ob;
        object me;
        int dpme,dpob;
        int damage;
        if (!arg) return notify_fail("你要射谁？\n");
        if (!query("installed")) 
                return notify_fail(this_object()->name()+"不安装箭是没有办法发射的。\n");
        me=this_player();
        if( environment(me)->query("no_fight") ||
                environment(me)->query("no_magic") ||
                environment(me)->query("no_spells"))
                return notify_fail("在这不可偷袭！\n");
        ob=present(arg,environment(me));
        if (!objectp(ob) || !living(ob)) 
                return notify_fail(this_object()->name()+"只能对活的生物使用。\n");
    message_vision(CYN"\n$N长笑声中，奋起神力，将"+this_object()->name()+CYN"拉至满月．．．\n\n",me);
    message_vision(CYN"\n$N大喝一声："+RED"五～"BLU"花～"HIG"神～箭～～"NOR+"．．．\n",me);
    message_vision(HIR"\n从"+this_object()->name()+HIR"中射出一片箭光，箭头幻化五花，闪电般飞向$N．．．\n\n",ob);
        dpob=COMBAT_D->skill_power(ob, SKILL_USAGE_DODGE);
        dpme=COMBAT_D->skill_power(me, SKILL_USAGE_DODGE);
        damage=150000-dpob+dpme;
    damage/=200;
        if (damage<0) damage=0;
        if( random(me->query("combat_exp")) > (int)ob->query("combat_exp")/50 )
        {
        message_vision(HIR"$N只觉得眼前箭光闪烁，一时之间竟无从躲闪。\n"NOR,ob);
                ob->start_busy(3);
        message_vision(HIR"\n箭光闪电般射入$N的身体．．．\n" NOR,ob);
                ob->receive_wound("kee",damage,me);
                COMBAT_D->report_status(ob);
                me->start_busy(5);
   }
        else
        {
                message_vision(HIR"漫天箭雨中，$N似乎看到一丝破绽．．．\n"NOR,ob);
                message_vision(HIW"$N就地一滚，险险躲过"+RED"五"BLU"花"HIG"神箭"HIW+"的袭击．．．\n"NOR,ob);
                me->start_busy(3);
        }
        ob->kill_ob(me); 
        set("installed",0);
        return 1;
}     
