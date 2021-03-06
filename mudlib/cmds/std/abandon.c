 // abandon.c
#include <ansi.h>
inherit F_CLEAN_UP;
void abandon_skill(string confirm, object me, string skill);
int zero_skill(object me, string arg); 
int main(object me, string arg)
{
        string err;
        if( !arg || arg=="" ) return notify_fail("你要放弃哪一项技能？\n"); 
        //if(!find_object(SKILL_D(arg)) && !load_object(SKILL_D(arg))) {
        if(!find_object(SKILL_D(arg)) && file_size(SKILL_D(arg)+".c")<0) {
                return notify_fail("「" + arg + "」，有这种技能吗？\n");        
        }
        /*if(!load_object(SKILL_D(arg)+".c")) 
                return notify_fail("「" + arg + "」，有这种技能吗？\n");
        */      
        seteuid(getuid());
        err = catch( call_other(SKILL_D(arg)+".c", "???") );
        if (err)
                printf( "发生错误：\n%s\n", err );
                 
        if( !me->query_skill(arg,1) && !zero_skill(me,arg))
                return notify_fail("你并没有学过这项技能。\n");
        write(HIY"\n「放弃」是指将这项技能从你人物的资料中删除，如果你以后还要练，\n必须从零开始重练，请务必考虑清楚。\n"NOR);
        write("你决定放弃继续学习［"HIR + SKILL_D(arg)->name() + NOR"］，是否要继续？(yes/no)\n");
        input_to( (: abandon_skill :), me, arg);
        return 1;
} 
void abandon_skill(string confirm, object me, string skill) 
{
        if (! (confirm == "yes" || confirm == "YES")) 
                write("你出了一身冷汗，好险！\n");
        else    {
                if(me->query_skill(skill,1)>50)
                log_file("skills/ABANDON",
                  sprintf("%s(%s)在%s放弃了%d级%s。\n",
                  me->name(1),geteuid(me),ctime(time()),me->query_skill(skill,1),skill));
                me->delete_skill(skill);
                write("你决定放弃继续学习" + SKILL_D(skill)->name() + "。\n");
        }
}  
int zero_skill(object me, string arg) {
        mapping learned_skill_points;
        
        learned_skill_points=me->query_learned();
        if (!learned_skill_points[arg]) return 0;
        return 1;
}  
        
        
         
int help()
{
        write(@TEXT
指令格式：abandon <技能名称> 
放弃一项你所学的技能，注意这里所说的「放弃」是指将这项技能从你人物的资料中
删除，如果你已後还要练，必须从 0 开始重练，请务必考虑清楚。 
这个指令使用的场合通常是用来删除一些「不小心」练出来的技能，由於我们假设你
的人物随时都会从他／她的各种动作、战斗中学习，因此有些技能会因为你经常地使
用而出现在你的技能列表中，这个人物就必须花费一些精神去「记住」所学过的一切
，然而，人的资质各有不同，灵性高的人能够学习许多技能而成为多才多艺的才子，
灵性较差的人就只能专心於特定几项技能，如果你学的技能种类太多，超过你的灵性
，你会发现人物的学习速度将比只学几种技能的人慢，超过越多，学习效果低落的情
况越严重，这种情形就像是一个学期同时选修太多学分，虽然你仍然可以凭著超人的
意志力练下去，不过这将会多花费你许多宝贵的时间。
TEXT
        );
        return 1;
}       
