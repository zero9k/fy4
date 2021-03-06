 // emote.c (Mon  09-04-95)
#include <ansi.h>
inherit F_CLEAN_UP;
#define NEW_PERIOD 32400
int  check_legal_name(string name); 
int main(object me, string str)
{
    if (!str) {
        write(CYN"你看起来表情丰富。\n"NOR);
        return 1;
    }
        if(me->query("chblk_on"))
                return notify_fail("你的频道被关了！\n");
        if((int)me->query("mud_age") < NEW_PERIOD)
                return notify_fail("你只可以使用（say）。\n");
        str = replace_string(str, "$BLK$", BLK);
        str = replace_string(str, "$RED$", RED);
        str = replace_string(str, "$GRN$", GRN);
        str = replace_string(str, "$YEL$", YEL);
        str = replace_string(str, "$BLU$", BLU);
        str = replace_string(str, "$MAG$", MAG);
        str = replace_string(str, "$CYN$", CYN);
        str = replace_string(str, "$WHT$", WHT);
        str = replace_string(str, "$HIR$", HIR);
        str = replace_string(str, "$HIG$", HIG);
        str = replace_string(str, "$HIY$", HIY);
        str = replace_string(str, "$HIB$", HIB);
        str = replace_string(str, "$HIM$", HIM);
        str = replace_string(str, "$HIC$", HIC);
        str = replace_string(str, "$HIW$", HIW);
        str = replace_string(str, "$NOR$", NOR);
        if( strsrch(str, "$ME$") == -1 )
        write("你输入的字串中必需含有$ME$\n");
        else{
        str = replace_string(str, "$ME$", me->name());
        if(check_legal_name(str))
        CHANNEL_D->do_channel(me, "fy", str,1);
        } 
    return 1;
}
 
int help(object me)
{
        write(@HELP
指令格式: cfy <动作词> 
这个指令可以让你表达一个系统没有预设的动作词, 系统会将你所输入
的文字加上你的姓名後显示给所有在风云的人看． 
□例: cfy $ME$坐了下来。 
【风云】阿铁坐了下来。
其中, 阿铁就是你的名字. 
相关指令: semote, cemote
HELP
        );
        return 1;
} 
int check_legal_name(string name)
{
        int i;
        i = strlen(name);
        while(i--) {
                if( i%2==0 && !is_chinese(name[i..<0]) ) {
                        write("对不起，请您用中文。\n");
                        return 0;
                }
        }
        return 1;
}      
