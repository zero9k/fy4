 //Created by justdoit at May 2001
//All Rights Reserved ^_^ 
 
inherit ROOM; 
void create() 
{ 
        set("short", "���Ƶ����"); 
        set("long", @LONG 
�㼫ĿԶ�����������Ƶ�����ʮ������ĵش���ľ���죬����ԭʼɭ�֡�ɽ�� 
͹������������¥������ع��㣬ԶԶ���������˼��ɾ�������������������� 
������������ʮ�㡣С�������ʯ��ᾣ������Ļ�����ʯ���ƣ������Ѱ�������ȴ�� 
�ٻ����ޣ��̲ݸ��أ�ɷ�Ǻÿ�������������������ƣ���������ν֮���Ƶ���
LONG 
           ); 
        set("exits",  
           ([  
       "southwest" : __DIR__"flowerroad2",
       "southeast" : __DIR__"pailangya",
       "north" : __DIR__"huangsha1",
            ])); 
        set("objects",  
           ([  
       __DIR__"npc/xiu1" : 1,
       __DIR__"npc/xiu2" : 1,
       "/obj/specials/ding/ding_wm" : 1,
            ])); 
        set("outdoors", "baiyun"); 
        set("coor/x",15); 
        set("coor/y",-1550); 
        set("coor/z",0); 
        setup(); 
        replace_program(ROOM); 
}    